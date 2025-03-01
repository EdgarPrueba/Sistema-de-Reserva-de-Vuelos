#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "seconddialog.h"
#include "admin.h"
#include "QFile"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ventanaUsuario(nullptr)
    , ventanaAdmin(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ventanaUsuario;
    delete ventanaAdmin;

    // Eliminar ciudades_copy.csv y subgrafo_viaje.csv al cerrar la aplicación
    QString copiaArchivo = "../gui/ciudades_copy.csv";
    QString subgrafoArchivo = "../gui/subgrafo_viaje.csv";

    if (QFile::exists(subgrafoArchivo)) {
        QFile::remove(subgrafoArchivo);
    }

    if (QFile::exists(copiaArchivo)) {
        QFile::remove(copiaArchivo);
    }
}

void MainWindow::on_pushButton_2_clicked()//este es el boton del usuario
{
    // Botón para abrir la ventana del usuario
    if (ventanaUsuario) {
        delete ventanaUsuario;  // Eliminar la instancia anterior
        ventanaUsuario = nullptr;
        
        // Eliminar el subgrafo_viaje.csv al cerrar la ventana del usuario
        QString subgrafoArchivo = "../gui/subgrafo_viaje.csv";
        if (QFile::exists(subgrafoArchivo)) {
            QFile::remove(subgrafoArchivo);
        }
    }

    ventanaUsuario = new secondDialog(this);
    ventanaUsuario->show();

    /*
    hide();
    secondDialog segundodialog;
    segundodialog.setModal(true);
    segundodialog.exec();

*/
}


void MainWindow::on_pushButton_clicked()//este es el boton del administrador
{

    if (!ventanaAdmin) {
        ventanaAdmin = new Admin(this);
    }

    // Conectar las señales de Admin con los slots de secondDialog
    if (ventanaUsuario) {
        QStringList ciudades;
        for (int i = 0; i < ventanaUsuario->getCiudades().size(); ++i) {
            ciudades.append(ventanaUsuario->getCiudades().at(i));
        }

        // Pasar las ciudades al Admin
        ventanaAdmin->actualizarCiudades(ciudades);
    }

    ventanaAdmin->show();

    /*
    hide();
    Admin Wadmin;
    Wadmin.setModal(true);
    Wadmin.exec();
    */
}

