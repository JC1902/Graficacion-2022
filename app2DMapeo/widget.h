#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

#include "mapeo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *event);
    void asignarFigura();
    void dibujarFigura();
    void dibujarFiguraMapeada();

private slots:
    void on_pushButNormal_clicked();

    void on_pushButMapeado_clicked();

private:
    Ui::Widget *ui;

    QPainter *canvas;
    //Triangulo
    //float Figura[6][3];
    //float FiguraAux[6][3];

    float Figura[6][3];
    float FiguraAux[6][3];
    float miFigura[59][3];
    float miFiguraAux[59][3];
    int ancho;
    int centroX, centroY;
    int i = 150, j = 100, ix = 350, jy = 400;
    int tamano = sizeof(miFigura)/sizeof (miFigura[0]);//obtener el número de puntos

    bool dibujoOrientacionNormal;
    bool dibujoMapeado;
};
#endif // WIDGET_H
