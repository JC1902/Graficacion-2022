#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    dibujoOrientacionNormal = dibujoMapeado = false;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    canvas = new QPainter(this);

    if(dibujoOrientacionNormal)
        dibujarFigura();
    else if(dibujoMapeado)
        dibujarFiguraMapeada();

    canvas->end();

    ui->label_2->setText(QString::number(i));
    ui->label_3->setText(QString::number(j));
    ui->label_4->setText(QString::number(ix));
    ui->label_5->setText(QString::number(jy));
    ui->label_6->setText(QString::number(tamano));
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() ==  Qt::Key_S){
        ix = ix - 10;
        jy = jy - 10;
        i = i + 10;
        j = j + 10;
        repaint();
    }
    if(event->key() == Qt::Key_W){
        i = i - 10;
        j = j - 10;
        ix = ix + 10;
        jy = jy + 10;
        repaint();
    }
    if(event->key() == Qt::Key_D){
        ix = ix + 10;
        repaint();
    }
    if(event->key() == Qt::Key_A){
        ix = ix - 10;
        repaint();
    }
}

void Widget::asignarFigura()
{
    /*Figura[0][0] = 10; Figura[0][1] = 10; Figura[0][2] = 1;
    Figura[1][0] = 30; Figura[1][1] = 10; Figura[1][2] = 1;//triangulo
    Figura[2][0] = 10; Figura[2][1] = 30; Figura[2][2] = 1;//triangulo
    //PARA CERRAR LA FIGURA
    Figura[3][0] = 10; Figura[3][1] = 10; Figura[3][2] = 1;//triangulo*/

    /*Figura[0][0] = -1.5; Figura[0][1] = -1.5; Figura[0][2] = 1;
    Figura[1][0] = 9.5; Figura[1][1] = -1.5; Figura[1][2] = 1;//triangulo
    Figura[2][0] = 9.5; Figura[2][1] = 9.5; Figura[2][2] = 1;//triangulo
    //PARA CERRAR LA FIGURA
    Figura[3][0] = -1.5; Figura[3][1] = -1.5; Figura[3][2] = 1;//triangulo*/

    /*Figura[0][0] = -3.5; Figura[0][1] = -3.5; Figura[0][2] = 1;
    Figura[1][0] = 21.5; Figura[1][1] = -3.5; Figura[1][2] = 1;//triangulo
    Figura[2][0] = 21.5; Figura[2][1] = 27.5; Figura[2][2] = 1;//triangulo
    //PARA CERRAR LA FIGURA
    Figura[3][0] = -3.5; Figura[3][1] = -3.5; Figura[3][2] = 1;//triangulo*/

    Figura[0][0] = 0; Figura[0][1] = 0; Figura[0][2] = 1;
    Figura[1][0] = 22/2; Figura[1][1] = 28; Figura[1][2] = 1;
    Figura[2][0] = 22; Figura[2][1] = 0; Figura[2][2] = 1;
    Figura[3][0] = 0; Figura[3][1] = 28/2; Figura[3][2] = 1;
    Figura[4][0] = 22; Figura[4][1] = 28/2; Figura[4][2] = 1;

    Figura[5][0] = 0; Figura[5][1] = 0; Figura[5][2] = 1;

    //Para mañana 18 de mayo
    miFigura[0][0] = 6; miFigura[0][1] = 0; miFigura[0][2] = 1;
    miFigura[1][0] = 6; miFigura[1][1] = 1; miFigura[1][2] = 1;
    miFigura[2][0] = 5; miFigura[2][1] = 1; miFigura[2][2] = 1;
    miFigura[3][0] = 5; miFigura[3][1] = 3; miFigura[3][2] = 1;
    miFigura[4][0] = 4; miFigura[4][1] = 3; miFigura[4][2] = 1;
    miFigura[5][0] = 4; miFigura[5][1] = 6; miFigura[5][2] = 1;
    miFigura[6][0] = 1; miFigura[6][1] = 6; miFigura[6][2] = 1;
    miFigura[7][0] = 1; miFigura[7][1] = 7; miFigura[7][2] = 1;
    miFigura[8][0] = 0; miFigura[8][1] = 7; miFigura[8][2] = 1;
    miFigura[9][0] = 0; miFigura[9][1] = 16; miFigura[9][2] = 1;
    miFigura[10][0] = 1; miFigura[10][1] = 16; miFigura[10][2] = 1;
    miFigura[11][0] = 1; miFigura[11][1] = 19; miFigura[11][2] = 1;
    miFigura[12][0] = 4; miFigura[12][1] = 19; miFigura[12][2] = 1;
    miFigura[13][0] = 4; miFigura[13][1] = 22; miFigura[13][2] = 1;
    miFigura[14][0] = 5; miFigura[14][1] = 22; miFigura[14][2] = 1;
    miFigura[15][0] = 5; miFigura[15][1] = 24; miFigura[15][2] = 1;
    miFigura[16][0] = 6; miFigura[16][1] = 24; miFigura[16][2] = 1;
    miFigura[17][0] = 6; miFigura[17][1] = 25; miFigura[17][2] = 1;
    miFigura[18][0] = 7; miFigura[18][1] = 25; miFigura[18][2] = 1;
    miFigura[19][0] = 7; miFigura[19][1] = 26; miFigura[19][2] = 1;
    miFigura[20][0] = 15; miFigura[20][1] = 26; miFigura[20][2] = 1;
    miFigura[21][0] = 15; miFigura[21][1] = 25; miFigura[21][2] = 1;
    miFigura[22][0] = 16; miFigura[22][1] = 25; miFigura[22][2] = 1;
    miFigura[23][0] = 16; miFigura[23][1] = 24; miFigura[23][2] = 1;
    miFigura[24][0] = 17; miFigura[24][1] = 24; miFigura[24][2] = 1;
    //Casco
    miFigura[25][0] = 17; miFigura[25][1] = 22; miFigura[25][2] = 1;
    miFigura[26][0] = 19; miFigura[26][1] = 22; miFigura[26][2] = 1;
    miFigura[27][0] = 19; miFigura[27][1] = 21; miFigura[27][2] = 1;
    miFigura[28][0] = 20; miFigura[28][1] = 21; miFigura[28][2] = 1;
    miFigura[29][0] = 20; miFigura[29][1] = 16; miFigura[29][2] = 1;
    miFigura[30][0] = 19; miFigura[30][1] = 16; miFigura[30][2] = 1;
    miFigura[31][0] = 19; miFigura[31][1] = 15; miFigura[31][2] = 1;
    miFigura[32][0] = 11; miFigura[32][1] = 15; miFigura[32][2] = 1;
    miFigura[33][0] = 11; miFigura[33][1] = 16; miFigura[33][2] = 1;
    miFigura[34][0] = 10; miFigura[34][1] = 16; miFigura[34][2] = 1;
    miFigura[35][0] = 10; miFigura[35][1] = 21; miFigura[35][2] = 1;
    miFigura[36][0] = 11; miFigura[36][1] = 21; miFigura[36][2] = 1;
    miFigura[37][0] = 11; miFigura[37][1] = 22; miFigura[37][2] = 1;
    miFigura[38][0] = 19; miFigura[38][1] = 22; miFigura[38][2] = 1;
    miFigura[39][0] = 19; miFigura[39][1] = 21; miFigura[39][2] = 1;
    miFigura[40][0] = 20; miFigura[40][1] = 21; miFigura[40][2] = 1;
    miFigura[41][0] = 20; miFigura[41][1] = 16; miFigura[41][2] = 1;
    miFigura[42][0] = 19; miFigura[42][1] = 16; miFigura[42][2] = 1;
    miFigura[43][0] = 19; miFigura[43][1] = 15; miFigura[43][2] = 1;
    //Casco
    miFigura[44][0] = 19; miFigura[44][1] = 7; miFigura[44][2] = 1;
    miFigura[45][0] = 18; miFigura[45][1] = 7; miFigura[45][2] = 1;
    miFigura[46][0] = 18; miFigura[46][1] = 1; miFigura[46][2] = 1;
    miFigura[47][0] = 17; miFigura[47][1] = 1; miFigura[47][2] = 1;
    miFigura[48][0] = 17; miFigura[48][1] = 0; miFigura[48][2] = 1;
    miFigura[49][0] = 14; miFigura[49][1] = 0; miFigura[49][2] = 1;
    miFigura[50][0] = 14; miFigura[50][1] = 1; miFigura[50][2] = 1;
    miFigura[51][0] = 13; miFigura[51][1] = 1; miFigura[51][2] = 1;
    miFigura[52][0] = 13; miFigura[52][1] = 5; miFigura[52][2] = 1;
    miFigura[53][0] = 11; miFigura[53][1] = 5; miFigura[53][2] = 1;
    miFigura[54][0] = 11; miFigura[54][1] = 1; miFigura[54][2] = 1;
    miFigura[55][0] = 10; miFigura[55][1] = 1; miFigura[55][2] = 1;
    miFigura[56][0] = 10; miFigura[56][1] = 0; miFigura[56][2] = 1;
    miFigura[57][0] = 6; miFigura[57][1] = 0; miFigura[57][2] = 1;

    miFigura[58][0] = 6; miFigura[58][1] = 0; miFigura[58][2] = 1;

    //RESPALDAR LOS VALORES DEL POLIGONO EN FIGURAAUX
    for(int renglon = 0; renglon < tamano; renglon++)
        for(int columnas = 0; columnas < 3; columnas++)
           miFiguraAux[renglon][columnas] = miFigura[renglon][columnas];

    //RESPALDAR LOS VALORES DEL POLIGONO EN FIGURAAUX
    for(int renglon = 0; renglon < 5; renglon++)
        for(int columnas = 0; columnas < 3; columnas++)
           FiguraAux[renglon][columnas] = Figura[renglon][columnas];

    ancho = this->size().width() - ui->widget->size().width();

    centroX = ancho / 2;
    centroY = this->size().height() / 2;
}

void Widget::dibujarFigura()
{
    QPen pen(QColor(0,200,0), 3);
    canvas->setPen(pen);

    //Dibujar el primer cuadrante
    //linea horizontal
    canvas->drawLine(0, centroY, ancho, centroY);
    //linea vertical
    canvas->drawLine(centroX, 0, centroX, size().height());

    canvas->setPen(QColor(0,0,255));
    for(int i = 0; i < 3; i++)
                                            //punto inicial                       punto final
        //canvas->drawLine(Figura[i][0], Figura[i][1], Figura[i+1][0], Figura[i+1][1]);
        canvas->drawLine(centroX + Figura[i][0], centroY +  Figura[i][1], centroX + Figura[i+1][0], centroY + Figura[i+1][1]);
}

void Widget::dibujarFiguraMapeada()
{
    QPen pen(QColor(0,200,0), 3);
    canvas->setPen(pen);

    //Dibujar el primer cuadrante con orientacion normal (Y hacia arriba)
    //linea horizontal
    //canvas->drawLine(0, this->size().height(), ancho, size().height());
    //linea vertical
    //canvas->drawLine(0, 0, 0, size().height());

    /*//DIBUJAR 4 CUADRANTES
    //linea horizontal
    canvas->drawLine(0, centroY, ancho, centroY);
    //linea vertical
    canvas->drawLine(centroX, 0, centroX, size().height());*/

    //utilizar la clase mapeo
    Mapeo dibujo;//500     0,         500          500
    //dibujo.ventana(ancho/2, 0, ancho, size().height()/2);
    //dibujo.ventana(0, 0, ancho, size().height());
    //dibujo.ventana(0, 0, 10000, 10000);
    //dibujo.ventana(0, 0, 10, 10);

    //Tamaño de la Hoja de máquina
    dibujo.ventana(0, 0, 22, 28);

               //xpvMin ofrece un factor de traslación
    //PRUEBA DE ESCRITORIO UTILIZANDO EL VALOR DE XPVMIN  Y L=0
    //dibujo.puerto(ancho/2, 0, ancho, size().height()/2);
    //PRUEBA DE ESCRITORIO UTILIZANDO EL VALOR DE XPVMIN=0  Y L=CENTROX=ANCHO/2=250
    //dibujo.puerto(0, 0, ancho/2, size().height()/2);

    //Simulación de una hoja de máquina en el puerto de visión
                                //ypvMin            ypvMax
    dibujo.puerto(i, j, ix, jy);

    //origen en la esquina inferiror izquierda
    //int L = 0;
    //int M = this->size().height();

    //ORIGEN EN EL CENTRO DEL AREA DE DIBUJO
    //int L = centroX;
    //int M = centroY;

    //Origen para simular la hoja de máquina
    int L = 0;
    int M = j + jy; // se debe sumar ypvmin + ypvmax

    canvas->drawRect(150, 100, 200, 300);

    canvas->setPen(QColor(255,0,0));

    int x1, y1, x2, y2;
                                //x1 y y1 son recibidos por referencia
    /*dibujo.mapeo(Figura[0][0], Figura[0][1], x1, y1, L, M);
    dibujo.mapeo(Figura[4][0], Figura[4][1], x2, y2, L, M);//triangulo
    canvas->drawLine(x1, y1, x2, y2);

    for(int i = 0; i < 4; i++){//Triangulo
    //for(int i = 0; i < 4; i++){
        dibujo.mapeo(Figura[i][0], Figura[i][1], x1, y1, L, M);
        dibujo.mapeo(Figura[i+1][0], Figura[i+1][1], x2, y2, L, M);
        canvas->drawLine(x1,y1,x2,y2);
    }*/

    dibujo.mapeo(miFigura[0][0], miFigura[0][1], x1, y1, L, M);
    dibujo.mapeo(miFigura[1][0], miFigura[1][1], x2, y2, L, M);//triangulo
    canvas->drawLine(x1, y1, x2, y2);

    for(int i = 0; i < 57; i++){//Triangulo
    //for(int i = 0; i < 4; i++){
        dibujo.mapeo(miFigura[i][0], miFigura[i][1], x1, y1, L, M);
        dibujo.mapeo(miFigura[i+1][0], miFigura[i+1][1], x2, y2, L, M);
        canvas->drawLine(x1,y1,x2,y2);
    }
}


void Widget::on_pushButNormal_clicked()
{
    asignarFigura();
    dibujoOrientacionNormal = true;
    dibujoMapeado = false;

    repaint();
}


void Widget::on_pushButMapeado_clicked()
{
    asignarFigura();
    dibujoMapeado = true;
    dibujoOrientacionNormal = false;

    repaint();
}

