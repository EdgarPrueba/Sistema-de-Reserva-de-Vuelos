#include "seconddialog.h"
#include "ui_seconddialog.h"
#include <iostream>  // Para std::cout
#include <QDebug>   // Para qDebug()

secondDialog::secondDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondDialog)
{
    ui->setupUi(this);
/*
    ui->comboBox->addItem("San Jose");
    ui->comboBox->addItem("Alajuela");
    ui->comboBox->addItem("Cartago");
    ui->comboBox->addItem("Heredia");
    ui->comboBox->addItem("Limon");
    ui->comboBox->addItem("Guanacaste");

    ui->comboBox_2->addItem("Guanacaste");
    ui->comboBox_2->addItem("San Jose");
    ui->comboBox_2->addItem("Alajuela");
    ui->comboBox_2->addItem("Cartago");
    ui->comboBox_2->addItem("Heredia");
    ui->comboBox_2->addItem("Limon");

*/

    QStringList ciudades = {"San Jose", "Alajuela", "Cartago", "Heredia", "Limon", "Guanacaste"};
    ui->comboBox->addItems(ciudades);
    ui->comboBox_2->addItems(ciudades);
}

secondDialog::~secondDialog() {
    delete ui;
}

void secondDialog::agregarCiudad(QString ciudad) {
    ui->comboBox->addItem(ciudad);
    ui->comboBox_2->addItem(ciudad);
}

// Slot para eliminar ciudad
void secondDialog::eliminarCiudad(QString ciudad) {
    int index1 = ui->comboBox->findText(ciudad);
    int index2 = ui->comboBox_2->findText(ciudad);

    if (index1 != -1) ui->comboBox->removeItem(index1);
    if (index2 != -1) ui->comboBox_2->removeItem(index2);
}

void secondDialog::on_pushButton_clicked() {
    // Obtener el texto seleccionado de los comboBox
    QString origen = ui->comboBox->currentText();
    QString destino = ui->comboBox_2->currentText();

    // Imprimir en terminal usando std::cout
    //std::cout << "Origen: " << origen.toStdString() << std::endl;  //imprime en pantalla
    //std::cout << "Destino: " << destino.toStdString() << std::endl;

    // También puedes usar qDebug() (es más recomendado en Qt)
    qDebug() << "Origen: " << origen;
    qDebug() << "Destino: " << destino;
}

QStringList secondDialog::getCiudades() {
    QStringList ciudades;
    for (int i = 0; i < ui->comboBox->count(); ++i) {
        ciudades.append(ui->comboBox->itemText(i));
    }
    return ciudades;
}


