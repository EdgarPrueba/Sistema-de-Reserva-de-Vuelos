#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include "Graph.h"
#include "Dijkstra.h"
#include "thirddialog.h"
#include "fourddialog.h"


namespace Ui {
class secondDialog;
}

class secondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secondDialog(QWidget *parent = nullptr);
    ~secondDialog();

public:
    QStringList getCiudades();

private slots:  //
    void on_pushButton_clicked(); // Botón para calcular la ruta más corta


    void on_pushButton_2_clicked(); // Botón para abrir la ventana de mapa

    void on_pushButton_3_clicked(); // Botón para abrir la ventana del mapa

private:
    Ui::secondDialog *ui;
    Graph grafo;  //
    thirdDialog *ventanaMapa;
    fourdDialog *ventanaSubMapa;
};

#endif // SECONDDIALOG_H
