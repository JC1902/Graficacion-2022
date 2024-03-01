#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer1 = new QTimer();

    timer2 = new QTimer();

    connect(timer1, SIGNAL(timeout()), this, SLOT(moverEtiquetaH()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(moverEtiquetaV()));

    velocidadDial = ui->dial->value();
    velocidadBarra = ui->verticalSlider->value();

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_cButtonIniciar_clicked()
{
    timer1->start(velocidadBarra); //v);//30);
    timer2->start(velocidadDial);
    ui->dial->setEnabled(true);
    ui->verticalSlider->setEnabled(true);
}


void Dialog::on_cButtonDetener_clicked()
{
    timer1->stop();
    timer2->stop();
}


void Dialog::on_cButtonCerrar_clicked()
{
    close();
}

void Dialog::moverEtiquetaH(){
        int y = ui->label->geometry().y();
        static int x = ui->label->geometry().x(); //las varianles static solo se inicializan una vez al principio de la ejecuacion del programa, despues se
        //modifica su valor de acuerdo a lo requerido, mantienne su valor en sucesivas llamadas

        static bool bandera = true;        
        if(ui->label->geometry().x() <= ui->widget->width()-(ui->label->width()) && bandera){
            ui->label->setGeometry(x,y, ui->label->width(), ui->label->height());
            x += 10;
            if(ui->label->geometry().x() > ui->widget->width()-(ui->label->width())){
                bandera = false;
                ui->label->setStyleSheet("background-image: url(:/imgs/GokuyGohan.png)");
            }
        }
            if(!bandera){
                x -= 10;
                ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
                if(x == 0){
                    bandera = true;
                    ui->label->setStyleSheet("background-image: url(:/imgs/GokuyGohanReves.png)");
                }
            }
}

void Dialog::moverEtiquetaV()
{
    int x = ui->label->geometry().x();
    static int y = ui->label->geometry().y();
    static bool banderaV = true;

    if(ui->label->geometry().y() < ui->widget->height()-(ui->label->height()) && banderaV){
        ui->label->setGeometry(x,y, ui->label->width(), ui->label->height());
        y += 10;
        if(ui->label->geometry().y() >= (ui->widget->height())-(ui->label->height())){
            banderaV = false;
        }
    }
        if(!banderaV){
            y -= 10;
            ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
            if(y == 0){
                banderaV = true;
            }
        }
}


void Dialog::on_verticalSlider_valueChanged(int value)
{
    velocidadBarra = value;
    //ui->lcdNumber->display(QString::number(value));
    this->on_cButtonIniciar_clicked();
}


void Dialog::on_dial_sliderMoved(int position)
{
    velocidadDial = position;
    //ui->lcdNumber->display(QString::number(position));
    this->on_cButtonIniciar_clicked();
}

