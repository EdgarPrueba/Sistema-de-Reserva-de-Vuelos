#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "Graph.h"
#include "Dijkstra.h"
#include "FileManager.h"

#include <iostream>  // Para std::cout
#include <QDebug>   // Para qDebug()
#include <QMessageBox>
#include "QFile"

using namespace std;

secondDialog::secondDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondDialog)
    , ventanaMapa(nullptr)
    , ventanaSubMapa(nullptr)
{
    ui->setupUi(this);

    //Rutas de archivos
    QString archivoCopia = "../gui/ciudades_copy.csv";
    QString archivoOriginal = "../gui/ciudades.csv";

    // Si existe ciudades_copy.csv, cargarlo; si no, cargar ciudades.csv
    if (QFile::exists(archivoCopia)) {
        std::cout << "Cargando grafo desde ciudades_copy.csv" << std::endl;
        grafo = FileManager::loadGraphFromCSV(archivoCopia.toStdString());
    } else {
        std::cout << "Cargando grafo desde ciudades.csv" << std::endl;
        grafo = FileManager::loadGraphFromCSV(archivoOriginal.toStdString());
    }

    // Verificar qué nodos se cargaron
    std::cout << "Ciudades cargadas en el grafo tras abrir la ventana:" << std::endl;
    for (const auto& ciudad : grafo.getNodes()) {
        std::cout << ciudad << "," << std::endl;
    }

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
    // Eliminar el archivo ciudades_copy.csv al cerrar la ventana de usuario
    QFile archivo("../gui/ciudades_copy.csv");

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
    for (const auto& nodo : subgrafo.getNodes()) {
        // Agregar cada nodo a la ruta
        ruta.push_back(nodo);
    }

    // Verificar si hay una ruta válida
    if (ruta.empty()) {
        // Borrar CSV si no hay ruta
        QFile archivo("../gui/subgrafo_viaje.csv");
        archivo.remove();
        QMessageBox::warning(this, "Error", "No se encontró una ruta.");
        return;
    }

    // Guardar el subgrafo en un archivo CSV
    FileManager::saveGraphToCSV(subgrafo, "../gui/subgrafo_viaje.csv");

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




void secondDialog::on_pushButton_2_clicked()
{
    if (!ventanaMapa) {
        ventanaMapa = new thirdDialog(this);
    }
    ventanaMapa->show();


}

void secondDialog::on_pushButton_3_clicked()
{
    if (ventanaSubMapa) {
        delete ventanaSubMapa;
        ventanaSubMapa = nullptr;
    }
    // Mostrar ventana si existe subMapa
    QString subMapa = "../gui/subgrafo_viaje.csv";

    if (!QFile::exists(subMapa)) {
        QMessageBox::warning(this, "Error", "No se ha seleccionado una ruta existente.");
        return;
    }
    ventanaSubMapa = new fourdDialog(this);
    ventanaSubMapa->show();
}
