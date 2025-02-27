#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "Graph.h"
#include "Dijkstra.h"
#include "FileManager.h"

#include <iostream>  // Para std::cout
#include <QDebug>   // Para qDebug()
#include <QMessageBox>

using namespace std;

secondDialog::secondDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondDialog)
{
    ui->setupUi(this);

    // Cargar grafo desde el archivo CSV
    grafo = FileManager::loadGraphFromCSV("../gui/cuidades.csv");

    // Obtener los nodos del grafo
    vector<string> ciudades = grafo.getNodes();

    // Convertir vector<string> a QStringList para usar en Qt
    QStringList listaCiudades;
    for (const string &ciudad : ciudades) {
        listaCiudades.append(QString::fromStdString(ciudad));
    }

    // Agregar las ciudades a los ComboBox
    ui->comboBox->addItems(listaCiudades);
    ui->comboBox_2->addItems(listaCiudades);
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

    std::string origenStr = origen.toStdString();
    std::string destinoStr = destino.toStdString();

    // Mostrar las ciudades del grafo original en la consola
    std::cout << "Ciudades cargadas en el grafo original:" << std::endl;
    for (const auto& ciudad : grafo.getNodes()) {
        std::cout << ciudad <<","<< std::endl;
    }

    // Imprimir las ciudades seleccionadas en consola
    std::cout << "Ciudad origen seleccionada (QString):" << origen.toUtf8().constData() <<","<< std::endl;
    std::cout << "Ciudad destino seleccionada (QString):" << destino.toUtf8().constData() <<","<< std::endl;
    std::cout << "Ciudad origen convertida a std::string:" << origenStr << ","<< std::endl;
    std::cout << "Ciudad destino convertida a std::string:" << destinoStr << ","<< std::endl;


    if (origen == destino) {
    QMessageBox::warning(this, "Error", "El origen y destino no pueden ser iguales.");
    return;
    }

    // Ejecutar el algoritmo de Dijkstra
    auto result = dijkstra(grafo, origen.toStdString(), destino.toStdString());
    // double distancia = result.first;                // Distancia total

    // Obtener el subgrafo
    Graph subgrafo = result.second;

    std::vector<std::string> ruta;
    for (const auto& nodo : subgrafo.getNodes()) {  // getNodes es solo un ejemplo, adapta según tu implementación
        // Agregar cada nodo a la ruta
        ruta.push_back(nodo);
    }


    // Verificar si hay una ruta válida
    if (ruta.empty()) {
        QMessageBox::warning(this, "Error", "No se encontró una ruta.");
        return;
    }

    // Invertir la ruta para que coincida con la salida correcta de Dijkstra
    std::reverse(ruta.begin(), ruta.end());

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


