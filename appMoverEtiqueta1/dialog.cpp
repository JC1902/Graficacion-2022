#include "dialog.h"
#include "ui_dialog.h"
#include  <QTimer>

//int x = 0;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer1 = new QTimer();
    timer2 = new QTimer();

    connect(timer1, SIGNAL(timeout()), this, SLOT(moverEtiquetaH()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(moverEtiquetaV()));

    ui->label_2->setText("0");
}

Dialog::~Dialog()
{
    delete ui;
}

//MOVIMIENTO HORIONTAL
void Dialog::on_pushButton_clicked()
{
    timer1->start(30);
}

//MOVIMIENTO VERTICAL
void Dialog::on_pushButton_2_clicked()
{
    timer2->start(30);
}

//DETENER TIMER
void Dialog::on_pushButton_3_clicked()
{
    timer1->stop();
    timer2->stop();
}

void Dialog::moverEtiquetaH()
{
    int y = ui->label->geometry().y();
    static int x = 0; //las varianles static solo se inicializan una vez al principio de la ejecuacion del programa, despues se
    //modifica su valor de acuerdo a lo requerido, mantienne su valor en sucesivas llamadas

    static bool bandera = true;
    if(ui->label->geometry().x() < this->width()-(ui->label->width()) && bandera){
        ui->label->setGeometry(x,y, ui->label->width(), ui->label->height());
        x += 10;
        if(ui->label->geometry().x() > this->width()-(ui->label->width()))
            bandera = false;
    }
        if(!bandera){
            x -= 10;
            ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
            if(x == 0)
                bandera = true;
        }
    static int contador = 0;
    ui->label_2->setText(QString::number(contador++));
}

void Dialog::moverEtiquetaV()
{
    int x = ui->label->geometry().x();
    static int y = 0;
    static bool banderaV = true;

    if(ui->label->geometry().y() < this->height()-(ui->label->height()) && banderaV){
        ui->label->setGeometry(x,y, ui->label->width(), ui->label->height());
        y += 10;
        if(ui->label->geometry().y() > (ui->pushButton->geometry().y())-(ui->label->height()))
            banderaV = false;
    }
        if(!banderaV){
            y -= 10;
            ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
            ui->label->adjustSize();
            if(y == 0)
                banderaV = true;
        }
}


void Dialog::on_pushButton_4_clicked()
{
    timer1->start(30);
    timer2->start(30);
}

