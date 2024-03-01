#include "graficos.h"

Graficos::Graficos()
{

}

void Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas)
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
    QPen pen(QColor(0,0,255), 5);
    canvas->setPen(pen);
    canvas->drawPoint(round(x),qRound(y));

    for(int k=0; k < pasos; k++){
        x = x + xInc;
        y = y + yInc;
        canvas->drawPoint(round(x),round(y));
    }
}

void Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color)
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
    QPen pen(color, 3);
    canvas->setPen(pen);
    canvas->drawPoint(round(x),qRound(y));

    for(int k=0; k < pasos; k++){
        x = x + xInc;
        y = y + yInc;
        canvas->drawPoint(round(x),round(y));
    }
}

void Graficos::circunferenciaPitagoras(int xC, int yC, int r, QPainter *canvas, QColor color)
{
    float y;
    QPen pen(color,5);
    canvas->setPen(pen);

    for(int x = xC-r; x<= xC+r; x++){
        y=yC + sqrt(pow(r,2.0) - pow((x-xC),2.0)) ;
        canvas->drawPoint(x, round(y));
        y=yC - sqrt(pow(r,2.0) - pow((x-xC),2.0)) ;
        canvas->drawPoint(x, round(y));
    }
}

void Graficos::circunferenciaPitagoras(int xC, int yC, int r, QPainter *canvas)
{
    float y;
    QPen pen(QColor(65,40,200),5);
    canvas->setPen(pen);

    for(int x = xC-r; x<= xC+r; x++){
        y=yC + pow((r*r) - pow((x-xC),2.0), 0.5);
        canvas->drawPoint(x, round(y));
        y=yC - sqrt(pow(r,2.0) - pow((x-xC),2.0)) ;
        canvas->drawPoint(x, round(y));
    }
}

void Graficos::circunferenciaCoordPolares(int xC, int yC, int r, QPainter *canvas, QColor color)
{
    float dt, ct, st, x, y, xtemp;

    dt = 1.0/r;

    ct = cos(dt);
    st = sin(dt);

    x = 0;
    y = r;

    QPen pen(color);
    canvas->setPen(pen);
    while(y >= x){
        canvas->drawPoint(round((xC+x)), round((yC+y)));
        canvas->drawPoint(round((xC-x)), round((yC+y)));
        canvas->drawPoint(round((xC+x)), round((yC-y)));
        canvas->drawPoint(round((xC-x)), round((yC-y)));

        xtemp = x;
        x = x*ct - y*st;
        y = y*ct + xtemp*st;
    }
}

void Graficos::circunferenciaCoordPolares(int xC, int yC, int r, QPainter *canvas)
{
    float dt, ct, st, x, y, xtemp;

    dt = 1.0/r;

    ct = cos(dt);
    st = sin(dt);

    x = 0;
    y = r;

    QPen pen(QColor(0,0,255),5);
    canvas->setPen(pen);
    while(y >= x){
        canvas->drawPoint(floor((xC+x)+0.5), floor((yC+y)+0.5));
        canvas->drawPoint(floor((xC-x)+0.5), floor((yC+y)+0.5));
        canvas->drawPoint(floor((xC+x)+0.5), floor((yC-y)+0.5));
        canvas->drawPoint(floor((xC-x)+0.5), floor((yC-y)+0.5));

        xtemp = x;
        x = x*ct - y*st;
        y = y*ct + xtemp*st;
    }
}

void Graficos::Circulo(int xc, int yc, int radio, QPainter *canvas)
{
    QPen pen(QColor(0,0,200));
    pen.setWidth(5);
    canvas->setPen(pen);

    int x,y;
    for(int a = 0; a < 360; a+=2){
                            //CONVERTIR A RADIANES
        x = xc + radio * cos(a / 180.0 * M_PI);
        y = yc + radio * sin(a / 180.0 * M_PI);
            //canvas->drawPoint(x-1,y-1);
        canvas->drawPoint(x,y);
            //canvas->drawPoint(x+1,y+1);
    }
}

void Graficos::Circulo(int xc, int yc, int radio, QPainter *canvas, QColor color)
{
    QPen pen(color);
    pen.setWidth(5);
    canvas->setPen(pen);

    int x,y;
    for(int a = 0; a < 360; a+=2){
                            //CONVERTIR A RADIANES
        x = xc + radio * cos(a / 180.0 * M_PI);
        y = yc + radio * sin(a / 180.0 * M_PI);
            //canvas->drawPoint(x-1,y-1);
        canvas->drawPoint(x,y);
            //canvas->drawPoint(x+1,y+1);
    }
}

void Graficos::cirucloBresenham(int x, int y, int radio, QPainter *canvas)
{
    QPen pen(QColor(255,0,0),5);
    canvas->setPen(pen);

    int tx, ty, d;
    tx = 0;
    ty = radio;
    d = 3 - 2 * radio;

    while(tx <= ty){
        canvas->drawPoint(x + tx, y + ty);
        canvas->drawPoint(x + tx, y - ty);
        canvas->drawPoint(x - tx, y + ty);
        canvas->drawPoint(x - tx, y - ty);
        canvas->drawPoint(x + ty, y + tx);
        canvas->drawPoint(x + ty, y - tx);
        canvas->drawPoint(x - ty, y + tx);
        canvas->drawPoint(x - ty, y - tx);

        if(d < 0)
            d += 4 * tx + 6;
        else
            d += 4 * (tx-ty) + 10, ty--;

        tx++;
    }
}

void Graficos::espiral1(QPainter *canvas, QColor color, double factor)
{
    int xc = canvas->window().width() / 3;
    int yc = canvas->window().height() / 2;
    int radio = 5;
    const double dosPI = M_PI * 2;
    canvas->setPen(color);
    int cont;
    double dth, cdth, sdth, x, y, xtemp, xt, yt;

    dth = dosPI / (factor * radio);
    //dth = dosPI / (8 * radio);
    //dth = dosPI / 16 * radio;
    //dth = dosPI / (.5 * radio);//estrella
    cdth = cos(dth);
    sdth = sin(dth);

    x = 0.0;
    y = radio;
    cont = 0;
    xt = xc + x;
    yt = yc + y;

    do{
        xtemp = x;
        x = x * cdth - y * sdth;
        y = y * cdth + xtemp * sdth;
        if(x > 0){
            x += 0.5;
        }
        else{
            x -= 0.5;
        }
        if(y > 0){
            y += 0.5;
        }
        else{
            y -= 0.5;
        }

        //canvas->drawPoint(xt + 0.5, round(yt + .5));
        lineaDDA(round(xt), yt + .5, xc+x+.5, yc+y+.5, canvas, color);

        xt = xc + x;
        yt = yc + y;
        cont++;
    }while(cont < 250);
}

void Graficos::espiral2(QPainter *canvas, QColor color, double thetaF, double radioF)
{
    int xc = canvas->window().width() / 3;
    int yc = canvas->window().height() / 2;
    double th, x, y, xt, yt;

    float radio = 1.0;
    canvas->setPen(color);
    th = 0.0;

    x = radio * cos(th);
    y = radio * sin(th);
    xt = xc + x;
    yt = yc + y;

    while(radio < 250){
        th += thetaF;
        //th += 1.7;
        //th += 2.4;
        radio += radioF;
        //radio += 1.3;
        //radio += 3.2;
        x = radio * cos(th);
        y = radio * sin(th);

        lineaDDA(xt +.5, yt + .5, xc + x +.5, yc + y + .5, canvas, color);
        xt = xc +x;
        yt = yc + y;
    }
}

//investigar alternativa para dibujar circulos
