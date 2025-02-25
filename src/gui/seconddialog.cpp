#include "seconddialog.h"
#include "ui_seconddialog.h"
///////////////////////////////////////
///                                 ///
///          USUARIO                ///
///                                 ///
///////////////////////////////////////




secondDialog::secondDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondDialog)
{
    ui->setupUi(this);
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

}

secondDialog::~secondDialog()
{
    delete ui;
}
