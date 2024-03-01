#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QKeyEvent>

#include "mapeo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//#define radianes(g) ((double)(g) * M_PI/180.0);

//double radianes(double g){
  //  return g * M_PI / 180.0;
//}

struct Puntos3D
{
    int x,y,z;
    bool opcion; // 1 = LINETO3D, 0 = MOVETO3D
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *evt);
    void asignarCubo();
    void proyeccionCubo();
    void dibujarCubo();
    void inicializaPuerto();

    void lineTo3D(int x, int y, int z, float alpha, float phi, int i);
    void moveTo3D(int x, int y, int z, float alpha, float phi, int i);

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_dialAlpha_valueChanged(int value);

    void on_dialPhi_valueChanged(int value);

    void on_spinBoxXC_valueChanged(int arg1);

    void on_doubleSpinBoxAng_valueChanged(double arg1);

    void on_spinBoxYC_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    QPainter *canvas;
    Puntos3D *cubo;
    QPointF points[16]; // AQUI SE GUARDAN LOS PUNTOS PARA DIBUJAR CON dibujarCubo

    Mapeo mapeo;
    int L, M;
    int ancho;

    //ROTACION
    bool rX, rY, rZ;
    int anguloX, anguloY, anguloZ;

    double seno, coseno;
    int xc, yc, zc;
    int tX, tY, tZ, ang;
    float alpha;
    float phi;
};
#endif // WIDGET_H
