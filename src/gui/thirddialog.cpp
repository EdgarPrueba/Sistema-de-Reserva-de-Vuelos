#include "thirddialog.h"
#include "ui_thirddialog.h"
#include "FileManager.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>
#include <QFont>

thirdDialog::thirdDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::thirdDialog) {
    ui->setupUi(this);
    setWindowTitle("Mapa de Vuelos");
    resize(700, 500);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    loadGraph();  // Cargar y mostrar el grafo en el mapa
}

thirdDialog::~thirdDialog() {
    delete ui;
}

void thirdDialog::loadGraph() {
    qDebug() << "Intentando cargar grafo desde ciudades.csv...";

    // Copiar ciudades.csv al ejecutable
    QFile::remove("/home/cristhian01/Sistema-de-Reserva-de-Vuelos/src/build-interfaz-Desktop-Debug/ciudades.csv");
    QFile::copy("/home/cristhian01/Sistema-de-Reserva-de-Vuelos/src/gui/ciudades.csv",
                "/home/cristhian01/Sistema-de-Reserva-de-Vuelos/src/build-interfaz-Desktop-Debug/ciudades.csv");

    QFile csvFile("ciudades.csv");
    if (!csvFile.exists()) {
        qDebug() << "Error: El archivo ciudades.csv no existe en la ruta esperada.";
        return;
    }
    qDebug() << "Archivo ciudades.csv encontrado. Cargando datos...";

    Graph graph = FileManager().loadGraphFromCSV("ciudades.csv");
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
                qDebug() << "Error: Una de las ciudades no tiene posición asignada:" << city1 << "->" << city2;
                continue;
            }

            QPointF pos1 = cityPositions[QString::fromStdString(city1)];
            QPointF pos2 = cityPositions[QString::fromStdString(city2)];

            QGraphicsLineItem *line = new QGraphicsLineItem(pos1.x() + 10, pos1.y() + 10, pos2.x() + 10, pos2.y() + 10);
            line->setPen(QPen(Qt::black, 2));
            scene->addItem(line);
            qDebug() << "Dibujando conexión:" << QString::fromStdString(city1) << "->" << QString::fromStdString(city2);
        }
    }
    qDebug() << "Total de elementos en la escena después de agregar conexiones:" << scene->items().size();

    for (auto it = cityPositions.begin(); it != cityPositions.end(); ++it) {
        // Crear el nodo azul
        QGraphicsEllipseItem *node = new QGraphicsEllipseItem(it.value().x(), it.value().y(), 20, 20);
        node->setBrush(Qt::blue);
        scene->addItem(node);

        // Crear la etiqueta con el nombre de la ciudad
        QGraphicsTextItem *label = new QGraphicsTextItem(it.key());
        label->setFont(QFont("Arial", 10));
        label->setDefaultTextColor(Qt::white); // Color del texto
        label->setPos(it.value().x() + 5, it.value().y() - 20); // Ajuste de posición
        scene->addItem(label);

        qDebug() << "Dibujando ciudad:" << it.key() << " en posición:" << it.value();
    }
    qDebug() << "Total de elementos en la escena después de agregar nodos:" << scene->items().size();
}

QPointF thirdDialog::randomPosition() {
    int x = QRandomGenerator::global()->bounded(50, 650); // Evitar bordes
    int y = QRandomGenerator::global()->bounded(50, 450);
    return QPointF(x, y);
}




