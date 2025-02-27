#include <QMessageBox>
#include "admin.h"
#include "ui_admin.h"
#include "Graph.h"

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

void Admin::edgesToString() {
    QStringList ciudades;

    // Obtener la lista de ciudades desde el grafo
    for (const auto& element : grafoCiudades.getEdges()) {
        ciudades.append(QString::fromStdString(element.first));
    }

    // Llamar a la función original que actualiza el ComboBox
    actualizarCiudades(ciudades);
}

// Actualizar ComboBox con la lista de ciudades del usuario
void Admin::actualizarCiudades(QStringList ciudades) {
    // Limpiar antes de actualizar
    ui->comboBoxCiudades->clear();
    ui->comboBoxCiudadDestino->clear();

    // Actualizar comboBoxes
    ui->comboBoxCiudades->addItems(ciudades);
    ui->comboBoxCiudadOrigen->addItems(ciudades);
    ui->comboBoxCiudadDestino->addItems(ciudades);
}

// Botón para agregar ciudad
void Admin::on_btnAgregar_clicked() {
    QString nuevaCiudad = ui->lineEditCiudad->text().trimmed();

    if (!nuevaCiudad.isEmpty()) {
        std::string ciudadStr = nuevaCiudad.toStdString();

        if (grafoCiudades.addVertex(ciudadStr)) {  // Agregar la ciudad al grafo
            edgesToString();  // Actualizar el ComboBox con las ciudades del grafo
            ui->lineEditCiudad->clear();  // Limpiar el campo
        } else {
            QMessageBox::warning(this, "Error", "La ciudad ya existe en el grafo.");
        }
    }
}

void Admin::on_btnEliminar_clicked() {
    QString ciudadEliminar = ui->comboBoxCiudades->currentText();

    if (!ciudadEliminar.isEmpty()) {
        // Crear un cuadro de diálogo de confirmación
        QMessageBox confirmBox;
        confirmBox.setIcon(QMessageBox::Warning);
        confirmBox.setWindowTitle("Confirmar eliminación");
        confirmBox.setText("¿Estás seguro de que deseas eliminar la ciudad '" + ciudadEliminar + "'?");
        confirmBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        confirmBox.setDefaultButton(QMessageBox::No);

        // Limpia las opciones de los comboBox para que ya no aparezca la que se elimina
        ui->comboBoxCiudadOrigen->clear();
        ui->comboBoxCiudadDestino->clear();

        // Verificar la respuesta del usuario
        if (confirmBox.exec() == QMessageBox::Yes) {
            std::string ciudadStr = ciudadEliminar.toStdString();

            if (grafoCiudades.removeVertex(ciudadStr)) {  // Eliminar del grafo
                edgesToString();  // Actualizar el ComboBox
            } else {
                QMessageBox::warning(this, "Error", "La ciudad no existe en el grafo.");
            }
        }
    }
}

void Admin::on_pushButton_clicked()
{
    // Guardar la selección del administrador en variables
    QString qstrciudadOrigen = ui->comboBoxCiudadOrigen->currentText();
    QString qstrciudadDestino = ui->comboBoxCiudadDestino->currentText();
    QString qstrDistancia = ui->lineEditDistancia->text();

    // Convertir de QString a string convencional
    std::string strCiudadOrigen = qstrciudadOrigen.toStdString();
    std::string strCiudadDestino = qstrciudadDestino.toStdString();
    double distancia = qstrDistancia.toDouble();

    // Mensaje para confirmar creación de conexión entre dos ciudades
    QMessageBox connectionConfirmationBox;
    connectionConfirmationBox.setIcon(QMessageBox::Warning);
    connectionConfirmationBox.setWindowTitle("Confirmar conexión");
    connectionConfirmationBox.setText(QString("¿Estás seguro que deseas crear esta conexión?\nCiudad Origen: %1\nCiudad Destino: %2")
            .arg(qstrciudadOrigen)
            .arg(qstrciudadDestino)
    );
    connectionConfirmationBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    connectionConfirmationBox.setDefaultButton(QMessageBox::No);

    // Verificar la respuesta del usuario
    if (connectionConfirmationBox.exec() == QMessageBox::Yes) {
        QMessageBox confirmationMessage;
        if (strCiudadOrigen == strCiudadDestino) {
            // Mensaje de error
            QMessageBox::critical(this, "Error", "No se puede conectar una ciudad a sí misma.");
        } else if (!distancia) {
            // Mensaje de error
            QMessageBox::critical(this, "Error", "La distancia entre dos ciudades no puede ser 0 km.");
        } else {
            // Añadir conexión al grafo
            grafoCiudades.addEdge(strCiudadOrigen, strCiudadDestino, distancia);

            // Mensaje de confirmación
            QMessageBox::information(this, "Confirmación", "Esta conexión fue agregada con éxito.");
        }
    }

}

