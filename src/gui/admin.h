#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    void actualizarCiudades(QStringList ciudades); //Método para actualizar lista

signals:
    void agregarCiudad(QString ciudad);  // Señal para agregar ciudad
    void eliminarCiudad(QString ciudad); // Señal para eliminar ciudad

private slots:
    void on_btnAgregar_clicked();
    void on_btnEliminar_clicked();


private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
