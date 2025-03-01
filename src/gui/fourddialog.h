#ifndef FOURDDIALOG_H
#define FOURDDIALOG_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class fourdDialog;
}

class fourdDialog : public QDialog {
    Q_OBJECT

public:
    explicit fourdDialog(QWidget *parent = nullptr);
    ~fourdDialog();

private:
    Ui::fourdDialog *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;

    void loadGraph();  // Cargar y dibujar el grafo dinámico
    QPointF randomPosition(); // Generar posiciones aleatorias para ciudades
    void agregarFlecha(QPointF start, QPointF end);
};

#endif // FOURDDIALOG_H
