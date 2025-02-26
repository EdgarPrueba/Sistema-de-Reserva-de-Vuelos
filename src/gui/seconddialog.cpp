#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "Graph.h"
#include "Dijkstra.h"
#include <iostream>  // Para std::cout
#include <QDebug>   // Para qDebug()
#include <QMessageBox>


secondDialog::secondDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondDialog)
{
    ui->setupUi(this);

    grafo.addVertex("San Jose");
    grafo.addVertex("Alajuela");
    grafo.addVertex("Cartago");
    grafo.addVertex("Heredia");
    grafo.addVertex("Limon");
    grafo.addVertex("Guanacaste");

    grafo.addEdge("San Jose", "Alajuela", 10);
    grafo.addEdge("San Jose", "Cartago", 15);
    grafo.addEdge("Alajuela", "Cartago", 5);
    grafo.addEdge("Cartago", "Heredia", 7);
    grafo.addEdge("Heredia", "Limon", 20);
    grafo.addEdge("Limon", "Guanacaste", 25);

    QStringList ciudades = {"San Jose", "Alajuela", "Cartago", "Heredia", "Limon", "Guanacaste"};
    ui->comboBox->addItems(ciudades);
    ui->comboBox_2->addItems(ciudades);
}

secondDialog::~secondDialog() {
    delete ui;
}

void secondDialog::agregarCiudad(QString ciudad) {

    grafo.addVertex(ciudad.toStdString()); //agrega una ciudad al grafo
    ui->comboBox->addItem(ciudad);
    ui->comboBox_2->addItem(ciudad);
}

// Slot para eliminar ciudad
void secondDialog::eliminarCiudad(QString ciudad) {
    grafo.removeVertex(ciudad.toStdString()); //elimina una ciudad del grafo

    int index1 = ui->comboBox->findText(ciudad);
    int index2 = ui->comboBox_2->findText(ciudad);

    if (index1 != -1) ui->comboBox->removeItem(index1);
    if (index2 != -1) ui->comboBox_2->removeItem(index2);
}

void secondDialog::on_pushButton_clicked() {
    // Obtener el texto seleccionado de los comboBox
    QString origen = ui->comboBox->currentText();
    QString destino = ui->comboBox_2->currentText();

    if (origen == destino) {
    QMessageBox::warning(this, "Error", "El origen y destino no pueden ser iguales.");
    return;
    }
    std::vector<std::string> ruta;
    //Ejecutar el algoritmo de Dijkstra
    //std::vector<std::string> ruta = dijkstra(grafo, origen.toStdString(), destino.toStdString());
    double distancia = dijkstra(grafo, origen.toStdString(), destino.toStdString());

    //std::vector<std::string> ruta = grafo.dijkstra(origen.toStdString(), destino.toStdString());
    //std::vector<std::string> ruta = dijkstra(origen.toStdString(), destino.toStdString());


    if (ruta.empty()) {
        QMessageBox::warning(this, "Error", "No se encontró una ruta.");
        return;
    }

    //Mostrar la ruta en un QMessageBox
    QString mensaje = "Ruta óptima:\n";
    for (const auto &ciudad : ruta) {
        mensaje += QString::fromStdString(ciudad) + " -> ";
    }
    mensaje.chop(4); // Eliminar la última flecha

    QMessageBox::information(this, "Ruta Calculada", mensaje);
}


QStringList secondDialog::getCiudades() {
    QStringList ciudades;
    for (int i = 0; i < ui->comboBox->count(); ++i) {
        ciudades.append(ui->comboBox->itemText(i));
    }
    return ciudades;
}


