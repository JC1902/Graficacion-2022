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

    int lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas);
    int lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color);
};

#endif // GRAFICOS_H
