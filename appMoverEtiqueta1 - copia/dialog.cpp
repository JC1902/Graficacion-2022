#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
//int x = 0;

string Dialog::Invertir(string fuente)
{
    string destino;
    for(int i = 0, j = fuente.length()-1; i < (int)fuente.length(); i++, j--)
        //destino[j] = fuente[j];
        destino += fuente[j];
    return destino;
}

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
    velocidadBarra = ui->horizontalSlider->value();
    velocidadSpin = ui->spinBox->value();

    //ui->lcdNumber->display(velocidadDial);
    //ui->lcdNumber->display(velocidadBarra);
    ui->lcdNumber->display(velocidadSpin);

}

Dialog::~Dialog()
{
    delete ui;
}

/*string Invertir(string texto){
    string cadInvertir;
    int j = 0;
    for(int i = texto.length()-1; i >= 0; i--){
        texto[i] = cadInvertir[j];
        j++;
    }
    return cadInvertir;
}*/

//MOVIMIENTO HORIONTAL
void Dialog::on_pushButton_clicked()
{
    timer1->start(velocidadSpin); //velocidadBarra); //velocidadDial);//30);
    timer2->start(velocidadSpin);
    ui->dial->setEnabled(true);
    ui->horizontalSlider->setEnabled(true);
    ui->spinBox->setEnabled(true);
}

//MOVIMIENTO VERTICAL
void Dialog::on_pushButton_2_clicked()
{
    timer1->stop();
    timer2->stop();
}

//DETENER TIMER
void Dialog::on_pushButton_3_clicked()
{
    close();
}

void Dialog::moverEtiquetaH()
{
    int y = ui->label->geometry().y();
    static int x = 0; //las varianles static solo se inicializan una vez al principio de la ejecuacion del programa, despues se
    //modifica su valor de acuerdo a lo requerido, mantienne su valor en sucesivas llamadas

    QString texto = ui->label->text();

    string textoInv = texto.toStdString();
    string destino;
    //string textoInv = ui->label->text().toStdString();

    static bool bandera = true;
    if(ui->label->geometry().x() <= ui->widget->width()-(ui->label->width()) && bandera){
        ui->label->setGeometry(x,y, ui->label->width(), ui->label->height());
        x += 10;
        if(ui->label->geometry().x() > ui->widget->width()-(ui->label->width())){
            bandera = false;
            //reverse(textoInv.begin(),textoInv.end());
            //ui->label->setText(QString::fromStdString(textoInv));
            destino = Invertir(textoInv);
            ui->label->setText(QString::fromStdString(destino));
        }
    }
        if(!bandera){
            x -= 10;
            ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
            if(x == 0){
                bandera = true;
                //reverse(textoInv.begin(),textoInv.end());
                //ui->label->setText(QString::fromStdString(textoInv));
                destino = Invertir(textoInv);
                ui->label->setText(QString::fromStdString(destino));
            }
        }
}

void Dialog::moverEtiquetaV()
{
    int x = ui->label->geometry().x();
    static int y = 0;
    static bool banderaV = true;

    if(ui->label->geometry().y() < ui->widget->height()-(ui->label->height()) && banderaV){
        ui->label->setGeometry(x,y, ui->label->width(), ui->label->height());
        y += 10;
        if(ui->label->geometry().y() > ui->widget->height()-(ui->label->height()))
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


void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    ui->label->setText(arg1);
    ui->label->adjustSize();
}


void Dialog::on_dial_sliderMoved(int position)
{
    velocidadDial = position;
    ui->lcdNumber->display(QString::number(position));
    this->on_pushButton_clicked();
}


void Dialog::on_spinBox_valueChanged(int arg1)
{
    velocidadSpin = arg1;
    ui->lcdNumber->display(QString::number(arg1));
    this->on_pushButton_clicked();
}


void Dialog::on_horizontalSlider_valueChanged(int value)
{
    velocidadBarra = value;
    ui->lcdNumber->display(QString::number(value));
    this->on_pushButton_clicked();
}

