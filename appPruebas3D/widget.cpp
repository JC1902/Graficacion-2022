#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    alpha = 63.4;
    phi = 30;
    ui->lcdNumber->display(ui->dialAlpha->value());
    ui->lcdNumber_2->display(ui->dialPhi->value());


    tX = 0;
    tY = 0;
    tZ = 0;
    valordialA = valordialP = 0;
    asignarCubo();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    inicializaPuerto();
    proyeccionCubo();


}

void Widget::keyPressEvent(QKeyEvent *evt)
{
    switch (evt->key()) {
    case Qt::Key_Up:
        tY += 4;
        update();
    break;
   case Qt::Key_Down:
        tY -= 4;
        update();
    break;
    case Qt::Key_Right:
        tX += 4;
        update();
    break;
    case Qt::Key_Left:
        tX -= 4;
        update();
    break;
    case Qt::Key_N:
        tZ += 4;
        update();
    break;
    case Qt::Key_M:
        tZ -= 4;
        update();
    break;
    case Qt::Key_W:
        valordialA += 2;
        break;
    case Qt::Key_S:
        valordialA -= 2;
        break;
    case Qt::Key_D:
        valordialP += 2;
        break;
    case Qt::Key_A:
        valordialP -= 2;
        break;
    }
}

void Widget::asignarCubo()
{
    Puntos3D piramideBase[] = {{100, 50, 0, 0}, {200, 50, 0, 1}, {150, 150, 50, 1}, {100, 50, 0, 1}, {100, 50, 100, 1},
                               {200, 50, 100, 1}, {200, 50, 0, 1}, {200, 50, 100, 0}, {150, 150, 50, 1}, {100, 50, 100, 1}};

    piramide =new Puntos3D[10]; // PARA COPIAR EL cuboBase porque es el que se va a manipular

    for(int i = 0; i < 10; i++)
        piramide[i] = piramideBase[i];

    inicializaPuerto();
    ancho = this->size().width() - ui->widget->size().width();
}

void Widget::proyeccionCubo()
{
    canvas = new QPainter(this);
    canvas->setRenderHint(QPainter::Antialiasing, true);
    canvas->setPen(QPen(Qt::black,3));
    // EJE HORIZONTAL; EJE X
    canvas->drawLine(0, size().height()-1, ancho, size().height()-1);
    // EJE VERTICAL; EJE Y
    canvas->drawLine(1, 0, 1, size().height());

    int zx1 = 0;
    int zy1 = 0;
    int zx2 = ancho * cos(qDegreesToRadians(phi));
    int zy2 = ancho * sin(qDegreesToRadians(phi));

    // EJE Z
    int x1, y1, x2, y2;
    mapeo.mapeo(zx1, zy1, x1, y1, L, M);
    mapeo.mapeo(zx2, zy2, x2, y2, L, M);

    canvas->drawLine(x1, y1, x2, y2);


    for(int i = 0; i < 10; i++)
        if(piramide[i].opcion)
                lineTo3D(piramide[i].x + tX, piramide[i].y + tY, piramide[i].z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
        else
            moveTo3D(piramide[i].x + tX, piramide[i].y + tY, piramide[i].z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);

    canvas->setPen(QPen(Qt::blue,3));

    dibujarCubo();

    canvas->end();
}

void Widget::dibujarCubo()
{
    //canvas->eraseRect(0, 0, 500, 500);
    for(int i = 0; i < 9; i++){
        canvas->drawLine(points[i].x(), points[i].y(), points[i+1].x(), points[i+1].y());
    }
}

void Widget::inicializaPuerto()
{
    mapeo.ventana(0, 0, size().width() - ancho, size().height());
    mapeo.puerto(0, 0, size().width() - ancho, size().height());

    L = 0;
    M = size().height();
}

void Widget::lineTo3D(int x, int y, int z, float alpha, float phi, int i)
{
        int xp, yp;
        int longitud; // L
        float tanalpha;
        if((tanalpha = tan(alpha)) != 0)
                longitud = (int)(z/tanalpha);
        else
                longitud = 0;

         xp = x + (longitud * cos(phi));
         yp = y + (longitud * sin(phi));

        int x1, y1;
         mapeo.mapeo(xp, yp, x1, y1, L, M);

         points[i].setX(x1);
         points[i].setY(y1);
}

void Widget::moveTo3D(int x, int y, int z, float alpha, float phi, int i)
{
                int xp, yp;
                int longitud; // L
                float tanalpha;
                if((tanalpha = tan(alpha)) != 0)
                        longitud = (int)(z/tanalpha);
                else
                        longitud = 0;

                 xp = x + (longitud * cos(phi));
                 yp = y + (longitud * sin(phi));

                int x1, y1;
                 mapeo.mapeo(xp, yp, x1, y1, L, M);

                 points[i].setX(x1);
                 points[i].setY(y1);
}


void Widget::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->widget->setEnabled(true);
    else
        ui->widget->setEnabled(false);
}


void Widget::on_dialAlpha_valueChanged(int value)
{
    alpha = value + valordialA;
    ui->lcdNumber->display(ui->dialAlpha->value());

    inicializaPuerto();
    update();
}


void Widget::on_dialPhi_valueChanged(int value)
{
    phi = value + valordialP;
    ui->lcdNumber_2->display(ui->dialPhi->value());

    inicializaPuerto();
    repaint();
}

