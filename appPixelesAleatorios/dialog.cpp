#include "dialog.h"
#include "ui_dialog.h"
#include <QPainterPath>
//Jorge Cisneros de la Torre 20130789
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    timer1->start(30);
}


void Dialog::on_pushButton_2_clicked()
{
    timer1->stop();
}


void Dialog::on_pushButton_3_clicked()
{
    close();
}

void Dialog::paintEvent(QPaintEvent *evt)
{
    Q_UNUSED(evt);
    /*QPainter canvas(this);
    for(int i = 0; i < 100000; i++){
        //QPen pen1(QColor(rand()%155+100,rand()%155+100,rand()%155+100));
        QPen pen1(QColor(255/2,255/2,255/2));
        //pen1.setWidth(5);
        canvas.setPen(pen1);
        canvas.drawPoint(rand()%this->width(), rand()%this->height()-50);
    }*/
    pixeles();
    //figurasGeometricas();
}

void Dialog::pixeles()
{
    QPainter canvas(this);//Objeto static
    int y = this->height()/2;
    int y2 = y - (ui->pushButton->height()+5);
    int x = this->width()/2;
        for(int i = 0; i < 10000; i++){
            QPen pen1(QColor(rand()%155+100,0,0));//rojo
            //QPen pen1(QColor(255/2,255/2,255/2));
            //pen1.setWidth(5)
            canvas.setPen(pen1);
            canvas.drawPoint(rand()%this->width()+x, rand()%y2+y);
        }
        for(int i=0 ; i < 10000; i++){
            QPen penW(QColor(255,255,255));//blanco
            canvas.setPen(penW);
            canvas.drawPoint(rand()%this->width()-(x), rand()%this->height()-(y));
        }
        for(int i=0 ; i < 10000; i++){
            QPen penW(QColor(0,rand()%155+100,0));//verde
            canvas.setPen(penW);
            canvas.drawPoint(rand()%this->width()+(x), rand()%this->height()-y);
        }
        for(int i=0 ; i < 10000; i++){
            QPen penW(QColor(0,0,rand()%155+100));//azul
            canvas.setPen(penW);
            canvas.drawPoint(rand()%this->width()-(x), rand()%y2+(y));
        }
}

/*void Dialog::figurasGeometricas()
{
    QPainter canvas(this);// = new QPainter(this);
    QPen pluma(QColor(rand()%155+100,rand()%155+100,rand()%155+100));

    canvas.setPen(pluma);
    pluma.setWidth(5);
    //canvas.drawLine(0,0, this->width(), this->height());
    //canvas.drawLine(this->width(),0,0, this->height());

    QPoint punto1 = {rand()%width(), rand()%this->height()-70};
    QPoint punto2 = {rand()%width(), rand()%this->height()-70};
    canvas.drawLine(punto1, punto2);

    QPoint puntoX = {QPoint(20,20)};
    QSize size = QSize(100,100);
    QRect rect = QRect(puntoX,size);
    canvas.drawRect(rect);

    //POLIGONO
    QPoint puntosPoligono[4] = {QPoint(20,100), QPoint(250,100),
                                       QPoint(250,250), QPoint(20,250)};

    canvas.drawPolygon(puntosPoligono,4);
    //INVESTIGAR LAS OPCIONES QUE SE PUEDEN USAR CON UN OBJETO PEN
    QPen plumaN(Qt::green, 3 ,Qt::DashLine,Qt::RoundCap,Qt::RoundJoin);
    canvas.setPen(plumaN);

    QBrush brocha(QColor(250,0,0), Qt::SolidPattern);
    //QBrush brocha;
    //brocha.setColor(Qt::green);
    //brocha.setStyle(Qt::SolidPattern);

    QPolygon poligono2;
    poligono2<<QPoint(200,10)<<QPoint(300,10)<<QPoint(300,20)<<QPoint(200,200)<<QPoint(200,100);

    QPainterPath path;
    path.addPolygon(poligono2);
    canvas.drawPolygon(poligono2);
    canvas.fillPath(path,brocha);

    //dibujar un pentagono, octagono, rombo, trapecio
}*/





