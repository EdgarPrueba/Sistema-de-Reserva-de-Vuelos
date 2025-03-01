#include "fourddialog.h"
#include "ui_fourddialog.h"
#include "FileManager.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>  //Para dibujar flechas
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>
#include <QFont>
#include <QMessageBox>
#include <cmath>  //Para cálculos trigonométricos

fourdDialog::fourdDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fourdDialog) {
    ui->setupUi(this);
    setWindowTitle("Mapa del Vuelo Programado");
    resize(700, 500);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    loadGraph();  // Cargar y mostrar el grafo en el mapa
}

fourdDialog::~fourdDialog() {
    delete ui;
}

void fourdDialog::loadGraph() {
    Graph graph;
    QString archivoRuta = "../gui/subgrafo_viaje.csv";

    if (QFile::exists(archivoRuta)) {
        std::cout << "Cargando grafo desde subgrafo_viaje.csv" << std::endl;
        graph = FileManager::loadGraphFromCSV(archivoRuta.toStdString());
    } else {
        QMessageBox::warning(this, "Error", "No se encontró el archivo subgrafo_viaje.csv.");
        return;
    }

    qDebug() << "Número de nodos en el grafo:" << graph.getNodes().size();
    qDebug() << "Número de conexiones en el grafo:" << graph.getEdges().size();

    QMap<QString, QPointF> cityPositions;
    for (const auto& city : graph.getNodes()) {
        if (!cityPositions.contains(QString::fromStdString(city))) {
            QPointF pos = randomPosition();
            cityPositions[QString::fromStdString(city)] = pos;
            qDebug() << "Ciudad:" << QString::fromStdString(city) << "Posición:" << pos;
        }
    }

    for (const auto& [city1, edges] : graph.getEdges()) {
        for (const auto& [city2, weight] : edges) {
            if (!cityPositions.contains(QString::fromStdString(city1)) ||
                !cityPositions.contains(QString::fromStdString(city2))) {
                qDebug() << "Error: Una de las ciudades no tiene posición asignada:"
                         << QString::fromStdString(city1) << "->" << QString::fromStdString(city2);
                continue;
            }

            QPointF pos1 = cityPositions[QString::fromStdString(city1)];
            QPointF pos2 = cityPositions[QString::fromStdString(city2)];

            //Dibujar la línea de conexión (arista dirigida)
            QGraphicsLineItem *line = new QGraphicsLineItem(pos1.x() + 10, pos1.y() + 10, pos2.x() + 10, pos2.y() + 10);
            line->setPen(QPen(Qt::black, 2));
            scene->addItem(line);

            //Dibujar flecha de dirección
            agregarFlecha(pos1, pos2);

            //Dibujar el peso en el centro de la línea
            QPointF midPoint = (pos1 + pos2) / 2;
            QString weightText = QString::number(weight) + " km";
            QGraphicsTextItem *weightLabel = new QGraphicsTextItem(weightText);

            //Calcular el ángulo de la línea
            double angle = std::atan2(pos2.y() - pos1.y(), pos2.x() - pos1.x()) * 180 / M_PI;
            if (angle > 90 || angle < -90) {
                angle += 180;
            }
            weightLabel->setRotation(angle);

            //Ajustar la posición del peso para evitar superposiciones
            double offset = 10;
            QPointF perpendicularOffset(-offset * sin(angle * M_PI / 180), offset * cos(angle * M_PI / 180));
            weightLabel->setPos(midPoint + perpendicularOffset);

            scene->addItem(weightLabel);

            qDebug() << "Dibujando conexión:" << QString::fromStdString(city1)
                     << "->" << QString::fromStdString(city2) << " con peso:" << weight;
        }
    }

    qDebug() << "Total de elementos en la escena después de agregar conexiones:" << scene->items().size();

    for (auto it = cityPositions.begin(); it != cityPositions.end(); ++it) {
        //Crear el nodo azul (ciudad)
        QGraphicsEllipseItem *node = new QGraphicsEllipseItem(it.value().x(), it.value().y(), 20, 20);
        node->setBrush(Qt::blue);
        scene->addItem(node);

        //Crear la etiqueta con el nombre de la ciudad
        QGraphicsTextItem *label = new QGraphicsTextItem(it.key());
        label->setFont(QFont("Arial", 10));
        label->setDefaultTextColor(Qt::red);
        label->setPos(it.value().x() + 5, it.value().y() - 20);
        scene->addItem(label);

        qDebug() << "Dibujando ciudad:" << it.key() << " en posición:" << it.value();
    }

    qDebug() << "Total de elementos en la escena después de agregar nodos:" << scene->items().size();
}

//Función para agregar flechas a las conexiones
void fourdDialog::agregarFlecha(QPointF start, QPointF end) {
    QLineF line(start, end);

    // 🔹 Calcular el ángulo de la línea en radianes
    double angle = std::atan2(line.dy(), line.dx());

    // 🔹 Definir la forma de la flecha
    QPolygonF arrowHead;
    arrowHead << QPointF(0, 0)
              << QPointF(-12, -4)  // Tamaño ajustado
              << QPointF(-12, 4);

    // 🔹 Ajustar la posición de la flecha **antes del nodo destino**
    QLineF arrowLine = line;
    arrowLine.setLength(arrowLine.length() - 12);  // Retroceder la flecha para no cubrir el nodo

    // 🔹 Transformación para alinear la flecha con la arista
    QTransform transform;
    transform.translate(arrowLine.p2().x(), arrowLine.p2().y());  // Posicionar al final de la línea
    transform.rotateRadians(angle);  // Rotar en la dirección de la línea

    // 🔹 Dibujar la flecha sobre la arista
    QGraphicsPolygonItem *arrow = new QGraphicsPolygonItem(transform.map(arrowHead));
    arrow->setBrush(Qt::black);
    scene->addItem(arrow);
}

QPointF fourdDialog::randomPosition() {
    int x = QRandomGenerator::global()->bounded(50, 650); // Evitar bordes
    int y = QRandomGenerator::global()->bounded(50, 450);
    return QPointF(x, y);
}
