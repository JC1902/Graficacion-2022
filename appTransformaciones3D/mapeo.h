#ifndef MAPEO_H
#define MAPEO_H

#include <math.h>

class Mapeo
{
    float xwMin, xwMax, ywMin, ywMax;//VENTANA, ESPACIO DEL MUNDO REAL
    int xpvMin, xpvMax, ypvMin, ypvMax;//PUERTO DE VISON, ESPACIO DONDE SE DIBUJARA EN LA PANTALLA
public:
    //Mapeo();
    //la ventana puede utilizar cualquier sistema de medidas km, m, cm, mm, millas, ft, yd
    void ventana(float wx1, float wy1, float wx2, float wy2);
    //el puerto utiliza pixeles o puntos para dibujar en la pantalla
    void puerto(int pvX1, int pvY1, int pvX2, int pvY2);
    //atraves de las referencias manejamos la salida del punto transformado
    void mapeo(int x, int y, int &xT, int &yT, int L, int M);
    //L Y M representan el origen a partir del cual se dibujará
};

#endif // MAPEO_H
