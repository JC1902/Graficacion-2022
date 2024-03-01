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

    rX = rY = rZ = false;
    anguloX = anguloY = anguloZ = 0;


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
        tY += 5;
    break;
   case Qt::Key_Down:
        tY -= 5;
    break;
    case Qt::Key_Right:
        tX += 5;
    break;
    case Qt::Key_Left:
        tX -= 5;
    break;
    case Qt::Key_N:
        tZ += 5;
        break;
    case Qt::Key_M:
        tZ -= 5;
    break;
        //Rotacion
    case Qt::Key_D:
        anguloX+=5;
        rX = true;
        rY = false;
        rZ = false;
        break;
    case Qt::Key_A:
        anguloX-=5;
        rX = true;
        rY = false;
        rZ = false;
        break;
    case Qt::Key_W:
        anguloY+=5;
        rY = true;
        rX = false;
        rZ = false;
        break;
    case Qt::Key_S:
        anguloY-=5;
        rY = true;
        rX = false;
        rZ = false;
        break;
    case Qt::Key_Q:
        anguloZ-=5;
        rZ = true;
        rX = false;
        rY = false;
        break;
    case Qt::Key_E:
        anguloZ+=5;
        rZ = true;
        rX = false;
        rY = false;
        break;
    case Qt::Key_R:
        on_pushButton_clicked();
        break;
    }

    update();
}

void Widget::asignarCubo()
{
    Puntos3D cuboBase[] = {{100, 50, 0, 0}, {200,50,0,1}, {200,150,0,1}, {100,150,0,1},
                           {100, 50, 0, 1}, {100, 50, 100, 1}, {200, 50, 100, 1}, {200, 150, 100,1},
                           {200, 150, 0, 1}, {200, 50, 0, 0}, {200, 50, 100, 1}, {100, 50, 100, 0},
                           {100, 150, 100, 1}, {100, 150, 0, 1}, {100, 150, 100, 0}, {200, 150, 100, 1}};

    cubo =new Puntos3D[16]; // PARA COPIAR EL cuboBase porque es el que se va a manipular

    for(int i = 0; i < 16; i++)
        cubo[i] = cuboBase[i];

    inicializaPuerto();
    ancho = this->size().width() - ui->widget->size().width();
}

void Widget::proyeccionCubo()
{
    canvas = new QPainter(this);
    canvas->setRenderHint(QPainter::Antialiasing, true);
    canvas->setPen(QPen(QColor(100,255,100),3));
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

    coseno = cos(qDegreesToRadians(ui->doubleSpinBoxAng->value()));
    seno = sin(qDegreesToRadians(ui->doubleSpinBoxAng->value()));
    xc = ui->spinBoxXC->value();
    yc = ui->spinBoxYC->value();
    zc = ui->spinBoxZC->value();

    int x, y, z;
        for(int i = 0; i < 16; i++){
            x = cubo[i].x;
            y = cubo[i].y;
            z = cubo[i].z;
            if(rX){
                x = cubo[i].x;
                y = round(cubo[i].y - yc) * cos(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloX)) + round(cubo[i].z - zc) * sin(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloX)) + yc;
                z = round(cubo[i].z - zc) * cos(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloX)) - round(cubo[i].y - yc) * sin(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloX)) + zc;
            }
            if(rY){
                x = round(cubo[i].x - xc) * cos(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloY)) - round(cubo[i].z - zc) * sin(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloY)) + xc;
                y = cubo[i].y;
                z = round(cubo[i].x - xc) * sin(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloY)) + round(cubo[i].z - zc) * cos(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloY)) + zc;
            }
            if(rZ){
                x = round(cubo[i].x-xc) * cos(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloZ)) - round(cubo[i].y-yc) * sin(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloZ)) +xc;
                y = round(cubo[i].y-yc) * cos(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloZ)) + round(cubo[i].x-xc) * sin(qDegreesToRadians(ui->doubleSpinBoxAng->value()+anguloZ))  + yc;
                z = cubo[i].z;
            }
        if(cubo[i].opcion)
                lineTo3D(x + tX, y +tY, z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
        else
            moveTo3D(x + tX, y +tY, z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
        }

    /*if(ui->checkBoxRX->isChecked()==false && ui->checkBoxRY->isChecked()==false&&ui->checkBoxRZ->isChecked()==false){
        for(int i = 0; i < 16; i++)
        if(cubo[i].opcion)
                lineTo3D(cubo[i].x + tX, cubo[i].y +tY, cubo[i].z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
        else
            moveTo3D(cubo[i].x + tX, cubo[i].y +tY, cubo[i].z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
    }
    // ---------------------------------------------------------------------------------------ROTACION EN X-------------------------------------------------------
    if(ui->checkBoxRX->isChecked() == true){
    for(int i = 0; i < 16; i++)
        if(cubo[i].opcion)
                lineTo3D(cubo[i].x + tX, ((cubo[i].y - yc)*coseno + (cubo[i].z - zc)*seno + yc) + tY,
                         ((cubo[i].z - zc)*coseno - (cubo[i].y - yc)*seno +zc) + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
        else
            moveTo3D(cubo[i].x + tX, ((cubo[i].y-yc)*coseno+(cubo[i].z-zc)*seno+yc)+tY,
                     ((cubo[i].z - zc)*coseno - (cubo[i].y - yc)*seno +zc) + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
    }
    // ---------------------------------------------------------------------------------------ROTACION EN Y-------------------------------------------------------
    if(ui->checkBoxRY->isChecked() == true){
    for(int i = 0; i < 16; i++)
        if(cubo[i].opcion)
                lineTo3D(((cubo[i].x - xc)*coseno - (cubo[i].z - zc)*seno + xc) + tX, cubo[i].y + tY,
                         ((cubo[i].x - xc)*seno + (cubo[i].z - zc)*coseno + zc) + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
        else
            moveTo3D(((cubo[i].x - xc)*coseno - (cubo[i].z - zc)*seno + xc) + tX, cubo[i].y + tY,
                     ((cubo[i].x - xc)*seno + (cubo[i].z - zc)*coseno + zc) + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
    }
    // ---------------------------------------------------------------------------------------ROTACION EN Z-------------------------------------------------------
    if(ui->checkBoxRZ->isChecked() == true){
    for(int i = 0; i < 16; i++)
        if(cubo[i].opcion)
                lineTo3D(((cubo[i].x-xc)*coseno-(cubo[i].y-yc)*seno+xc)+tX,
                      ((cubo[i].y-yc)*coseno+(cubo[i].x-xc)*seno+yc)+tY, cubo[i].z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
        else
            moveTo3D(((cubo[i].x-xc)*coseno-(cubo[i].y-yc)*seno+xc)+tX,
                      ((cubo[i].y-yc)*coseno+(cubo[i].x-xc)*seno+yc)+tY, cubo[i].z + tZ, qDegreesToRadians(alpha), qDegreesToRadians(phi), i);
    }*/
    canvas->setPen(QPen(QColor(100,100,255),3));

    dibujarCubo();

    canvas->end();
}

void Widget::dibujarCubo()
{
    //canvas->eraseRect(0, 0, 500, 500);
    for(int i = 0; i < 15; i++){
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
    alpha = value;
    ui->lcdNumber->display(ui->dialAlpha->value());

    inicializaPuerto();
    update();
}


void Widget::on_dialPhi_valueChanged(int value)
{
    phi = value;
    ui->lcdNumber_2->display(ui->dialPhi->value());

    inicializaPuerto();
    repaint();
}


void Widget::on_spinBoxXC_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    update();
}


void Widget::on_doubleSpinBoxAng_valueChanged(double arg1)
{
    Q_UNUSED(arg1);
    update();
}


void Widget::on_spinBoxYC_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    update();
}


void Widget::on_pushButton_clicked()
{
    anguloX = anguloY = anguloZ = 0;
    tX = tY = tZ = 0;
    rX = rY = rZ = false;
    dibujarCubo();

    update();
}

