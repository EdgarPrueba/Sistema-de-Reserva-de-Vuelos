#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

// Actualizar ComboBox con la lista de ciudades del usuario
void Admin::actualizarCiudades(QStringList ciudades) {
    ui->comboBoxCiudades->clear();  // Limpiar antes de actualizar
    ui->comboBoxCiudades->addItems(ciudades);
}

// Botón para agregar ciudad
void Admin::on_btnAgregar_clicked() {
    QString nuevaCiudad = ui->lineEditCiudad->text().trimmed();
    if (!nuevaCiudad.isEmpty()) {
        emit agregarCiudad(nuevaCiudad);  // Enviar la señal a secondDialog
        ui->comboBoxCiudades->addItem(nuevaCiudad); // Agregar a la lista del admin
        ui->lineEditCiudad->clear();  // Limpiar el campo
    }
}

// Botón para eliminar ciudad
void Admin::on_btnEliminar_clicked() {
    QString ciudadEliminar = ui->comboBoxCiudades->currentText();
    if (!ciudadEliminar.isEmpty()) {
        emit eliminarCiudad(ciudadEliminar);  // Enviar la señal a secondDialog
        int index = ui->comboBoxCiudades->findText(ciudadEliminar);
        if (index != -1) {
            ui->comboBoxCiudades->removeItem(index); // Eliminar de la lista del admin
        }
    }
}
