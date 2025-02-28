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

    Graph graph;
    //Rutas de archivos
    QString archivoCopia = "../gui/ciudades_copy.csv";
    QString archivoOriginal = "../gui/ciudades.csv";

    // Si existe ciudades_copy.csv, cargarlo; si no, cargar ciudades.csv
    if (QFile::exists(archivoCopia)) {
        std::cout << "Cargando grafo desde ciudades_copy.csv" << std::endl;
        graph = FileManager::loadGraphFromCSV(archivoCopia.toStdString());
    } else {
        std::cout << "Cargando grafo desde ciudades.csv" << std::endl;
        graph = FileManager::loadGraphFromCSV(archivoOriginal.toStdString());
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

            // Dibujar la línea de conexión
            QGraphicsLineItem *line = new QGraphicsLineItem(pos1.x() + 10, pos1.y() + 10, pos2.x() + 10, pos2.y() + 10);
            line->setPen(QPen(Qt::black, 2));
            scene->addItem(line);

            // Dibujar el peso en el centro de la línea
            QPointF midPoint = (pos1 + pos2) / 2;  // Punto medio entre los nodos
            QString weightText = QString::number(weight) + " km"; // Agregar "km" al peso
            QGraphicsTextItem *weightLabel = new QGraphicsTextItem(weightText);

            // Calcular el ángulo de la línea
            double angle = std::atan2(pos2.y() - pos1.y(), pos2.x() - pos1.x()) * 180 / M_PI;
            if (angle > 90 || angle < -90) {
                angle += 180;  // Girar el texto para que siempre sea legible
            }
            weightLabel->setRotation(angle);
    
            // **Desplazar peso para evitar superposición**
            double offset = 10; // Distancia de separación
            QPointF perpendicularOffset(-offset * sin(angle * M_PI / 180), offset * cos(angle * M_PI / 180));
    
            // Alternar la posición de los pesos para evitar superposición
            if (city1 < city2) {  // Ordenar para que los pesos de direcciones opuestas no se sobrepongan
                weightLabel->setPos(midPoint + perpendicularOffset);
            } else {
                weightLabel->setPos(midPoint - perpendicularOffset);
            }
            
            scene->addItem(weightLabel);


            qDebug() << "Dibujando conexión:" << QString::fromStdString(city1) 
            << "->" << QString::fromStdString(city2) << " con peso:" << weight;
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
        label->setDefaultTextColor(Qt::red); // Color del texto
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




