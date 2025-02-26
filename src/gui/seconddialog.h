#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>

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


public slots:
    //void on_pushButton_clicked();
    void agregarCiudad(QString ciudad);
    void eliminarCiudad(QString ciudad);

private slots:  // 🔹 Agregar esto
    void on_pushButton_clicked();


private:
    Ui::secondDialog *ui;
};

#endif // SECONDDIALOG_H
