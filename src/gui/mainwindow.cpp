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

    // Eliminar ciudades_copy.csv al cerrar la aplicación
    QString copiaArchivo = "../gui/ciudades_copy.csv";
    if (QFile::exists(copiaArchivo)) {
        QFile::remove(copiaArchivo);
    }
}

void MainWindow::on_pushButton_2_clicked()//este es el boton del usuario
{
    // Botón para abrir la ventana del usuario
        if (!ventanaUsuario) {
            ventanaUsuario = new secondDialog(this);
        }
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


        // Desconectar señales previas antes de volver a conectar
        disconnect(ventanaAdmin, &Admin::agregarCiudad, ventanaUsuario, &secondDialog::agregarCiudad);
        disconnect(ventanaAdmin, &Admin::eliminarCiudad, ventanaUsuario, &secondDialog::eliminarCiudad);

        // Conectar señales solo una vez
        connect(ventanaAdmin, &Admin::agregarCiudad, ventanaUsuario, &secondDialog::agregarCiudad);
        connect(ventanaAdmin, &Admin::eliminarCiudad, ventanaUsuario, &secondDialog::eliminarCiudad);
    }

    ventanaAdmin->show();

    /*
    hide();
    Admin Wadmin;
    Wadmin.setModal(true);
    Wadmin.exec();
    */
}

