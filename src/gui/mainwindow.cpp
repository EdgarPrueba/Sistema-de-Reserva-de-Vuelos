#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "seconddialog.h"
#include "admin.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()//este es el boton del usuario
{

    hide();
    secondDialog segundodialog;
    segundodialog.setModal(true);
    segundodialog.exec();
}


void MainWindow::on_pushButton_clicked()//este es el boton del administrador
{
    hide();
    Admin Wadmin;
    Wadmin.setModal(true);
    Wadmin.exec();
}

