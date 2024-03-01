#include "mapeo.h"

/*Mapeo::Mapeo()
{
}*/

void Mapeo::ventana(float wx1, float wy1, float wx2, float wy2)
{//mundo real
    xwMin = wx1;
    ywMin = wy1;
    xwMax = wx2;
    ywMax = wy2;
}

void Mapeo::puerto(int pvX1, int pvY1, int pvX2, int pvY2)
{//ventana
    xpvMin = pvX1;
    ypvMin = pvY1;
    xpvMax = pvX2;
    ypvMax = pvY2;
}

void Mapeo::mapeo(int x, int y, int &xT, int &yT, int L, int M)
{
    float sX, sY;
    //escalación en X
    sX = (xpvMax - xpvMin)/(xwMax - xwMin);
    //escalación en Y
    sY = (ypvMax-ypvMin)/(ywMax - ywMin);

    //por la referencia regresamos la xT y yT
    xT = int (floor(sX * (x-xwMin) + xpvMin + L));
    yT = int (floor( sY * (ywMin - y) - ypvMin + M));
}
