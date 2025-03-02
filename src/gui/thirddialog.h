#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class thirdDialog;
}

class thirdDialog : public QDialog {
    Q_OBJECT

public:
    explicit thirdDialog(QWidget *parent = nullptr);
    ~thirdDialog();

private:
    Ui::thirdDialog *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;

    void loadGraph();  // Cargar y dibujar el grafo dinámico
    QPointF randomPosition(); // Generar posiciones aleatorias para ciudades
};

#endif // THIRDDIALOG_H
