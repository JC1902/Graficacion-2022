#ifndef GRAFICOS_H
#define GRAFICOS_H

#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QColor>

class Graficos
{
public:
    Graficos();

    int round(float n){
        return int(n+0.5);
    }

     void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas);
     void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color);
     void circunferenciaPitagoras(int xC, int yC, int r, QPainter *canvas, QColor color);
     void circunferenciaPitagoras(int xC, int yC, int r, QPainter *canvas);
     void circunferenciaCoordPolares(int xC, int yC, int r, QPainter *canvas, QColor color);
     void circunferenciaCoordPolares(int xC, int yC, int r, QPainter *canvas);

     void Circulo(int xc, int yc, int radio, QPainter *canvas);
     void Circulo(int xc, int yc, int radio, QPainter *canvas, QColor color);

     void cirucloBresenham(int x, int y, int radio, QPainter *canvas);

     void espiral1(QPainter *canvas, QColor color, double factor);
     void espiral2(QPainter *canvas, QColor color, double thetaF, double radioF);
};

#endif // GRAFICOS_H
