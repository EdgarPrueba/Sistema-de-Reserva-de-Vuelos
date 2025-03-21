#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "seconddialog.h"
#include "admin.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    secondDialog *ventanaUsuario;  // Instancia persistente de la ventana del usuario
    Admin *ventanaAdmin;
};
#endif // MAINWINDOW_H
