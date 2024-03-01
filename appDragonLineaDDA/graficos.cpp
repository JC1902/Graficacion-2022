#include "graficos.h"

Graficos::Graficos()
{

}

int Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas)
{
    int pasos;// pixeles que se van a pintar
    int dx = x2 - x1;
    int dy = y2 - y1;

    float xInc, yInc, x = x1, y = y1;

    if(abs(dx) > abs(dy))
        pasos = abs(dx);
    else
        pasos = abs(dy);

    xInc = (float)dx/pasos;
    yInc = (float)dy/pasos;
    QPen pen(QColor(0,0,255), 3);
    canvas->setPen(pen);
    canvas->drawPoint(round(x),qRound(y));

    for(int k=0; k < pasos; k++){
        x = x + xInc;
        y = y + yInc;
        canvas->drawPoint(round(x),round(y));
    }
}

int Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color)
{
    int pasos;// pixeles que se van a pintar
    int dx = x2 - x1;
    int dy = y2 - y1;

    float xInc, yInc, x = x1, y = y1;

    if(abs(dx) > abs(dy))
        pasos = abs(dx);
    else
        pasos = abs(dy);

    xInc = (float)dx/pasos;
    yInc = (float)dy/pasos;
    QPen pen(color, 1);
    canvas->setPen(pen);
    canvas->drawPoint(round(x),qRound(y));

    for(int k=0; k < pasos; k++){
        x = x + xInc;
        y = y + yInc;
        canvas->drawPoint(round(x),round(y));
    }
}
