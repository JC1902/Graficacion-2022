#include "dialog.h"
#include "ui_dialog.h"
#include <QMediaPlayer>
#include <QFileDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mediaPlayer = new QMediaPlayer(this); //variable donde se encuentra lo necesario para el reproductor
    timer1 = new QTimer();
    timer2 = new QTimer();
    timer3 = new QTimer();
    timer4 = new QTimer();

    //conectar el timer1 para mover la imagen del usuario y el proyectil que este dispara
    connect(timer1, SIGNAL(timeout()), this, SLOT(moverUsuario()));
    connect(timer1, SIGNAL(timeout()), this, SLOT(moverProyectil()));

    //conectar con el evento que dispara el proyectil
    connect(timer2, SIGNAL(timeout()), this, SLOT(disparar()));

    //conectar a los "enemigos" que dan los puntos para el usuario
    connect(timer3, SIGNAL(timeout()), this, SLOT(moverEnemigo()));
    connect(timer3, SIGNAL(timeout()), this, SLOT(moverEnemigo2()));
    connect(timer3, SIGNAL(timeout()), this, SLOT(moverEnemigo3()));

    //conectar para mover el obstaculo
    connect(timer4, SIGNAL(timeout()), this, SLOT(moverAliado()));

    ui->cButtonVidas->setEnabled(false);
    ui->cButtonDisp->setEnabled(false);


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_cButtonAbrir_clicked()
{
    //este metodo se usa para abrir un archivo mp3 que este en la carpeta o el en pc de forma local
    QString filename = QFileDialog::getOpenFileName(this, "Abrir");
    if(filename.isEmpty())
        return;
    mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    //se pone el volumen segun el valor del slider
    mediaPlayer->setVolume(ui->cHSliderVolumen->value());
    //se presiona el boton de play
    on_cButtonPlay_clicked();
}


void Dialog::on_cButtonPlay_clicked()
{
    mediaPlayer->play();
}


void Dialog::on_cButtonPausa_clicked()
{
    mediaPlayer->pause();
}


void Dialog::on_cButtonStop_clicked()
{
    mediaPlayer->stop();
}


void Dialog::on_cButtonMute_clicked()
{
    mediaPlayer->setMuted(true);
}


void Dialog::on_cButtonMute_2_clicked()
{
    mediaPlayer->setMuted(false);
}


void Dialog::on_cHSliderVolumen_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}

void Dialog::moverUsuario()
{
    int x = ui->clabelUsuario->geometry().x();
    static int y = 0;
    static bool banderaV = true;

    if(ui->clabelUsuario->geometry().y() < ui->widget->height()-(ui->clabelUsuario->height()) && banderaV){
        ui->clabelUsuario->setGeometry(x,y, ui->clabelUsuario->width(), ui->clabelUsuario->height());
        y += 10;
        if(ui->clabelUsuario->geometry().y() >= (ui->widget->height())-(ui->clabelUsuario->height()))
            banderaV = false;
    }
        if(!banderaV){
            y -= 10;
            ui->clabelUsuario->setGeometry(x,y,ui->clabelUsuario->width(),ui->clabelUsuario->height());
            //ui->clabelUsuario->adjustSize();
            if(y == 0)
                banderaV = true;
        }
}

void Dialog::moverProyectil()
{
    int x = ui->clabelProyectil->geometry().x();
    static int y = 0;
    static bool banderaV = true;

    if(ui->clabelProyectil->geometry().y() < ui->widget->height()-(ui->clabelProyectil->height()) && banderaV){
        ui->clabelProyectil->setGeometry(x,y, ui->clabelProyectil->width(), ui->clabelProyectil->height());
        y += 10;
        if(ui->clabelProyectil->geometry().y() >= (ui->widget->height())-(ui->clabelProyectil->height()))
            banderaV = false;
    }
        if(!banderaV){
            y -= 10;
            ui->clabelProyectil->setGeometry(x,y,ui->clabelProyectil->width(),ui->clabelProyectil->height());
            //ui->clabelUsuario->adjustSize();
            if(y == 0)
                banderaV = true;
        }
}

void Dialog::moverEnemigo()
{
    int x = ui->clabelEn1->geometry().x();
    static int y = 0;
    static bool banderaV = true;

    if(ui->clabelEn1->geometry().y() < ui->widget->height()-(ui->clabelEn1->height()) && banderaV){
        ui->clabelEn1->setGeometry(x,y, ui->clabelEn1->width(), ui->clabelEn1->height());
        y += 10;
        if(ui->clabelEn1->geometry().y() >= (ui->widget->height())-(ui->clabelEn1->height()))
            banderaV = false;
    }
        if(!banderaV){
            y -= 10;
            ui->clabelEn1->setGeometry(x,y,ui->clabelEn1->width(),ui->clabelEn1->height());
            //ui->clabelUsuario->adjustSize();
            if(y == 0)
                banderaV = true;
        }
}

void Dialog::moverEnemigo2()
{
    int x = ui->clabelEn2->geometry().x();
    static int y = ui->clabelEn2->geometry().y();
    static bool banderaV = true;

    if(ui->clabelEn2->geometry().y() < ui->widget->height()-(ui->clabelEn2->height()) && banderaV){
        ui->clabelEn2->setGeometry(x,y, ui->clabelEn2->width(), ui->clabelEn2->height());
        y += 10;
        if(ui->clabelEn2->geometry().y() >= (ui->widget->height())-(ui->clabelEn2->height()))
            banderaV = false;
    }
        if(!banderaV){
            y -= 10;
            ui->clabelEn2->setGeometry(x,y,ui->clabelEn2->width(),ui->clabelEn2->height());
            //ui->clabelUsuario->adjustSize();
            if(y == 0)
                banderaV = true;
        }
}

void Dialog::moverEnemigo3()
{
    int x = ui->clabelEn3->geometry().x();
    static int y = 0;
    static bool banderaV = true;

    if(ui->clabelEn3->geometry().y() < ui->widget->height()-(ui->clabelEn3->height()) && banderaV){
        ui->clabelEn3->setGeometry(x,y, ui->clabelEn3->width(), ui->clabelEn3->height());
        y += 10;
        if(ui->clabelEn3->geometry().y() >= (ui->widget->height())-(ui->clabelEn3->height()))
            banderaV = false;
    }
        if(!banderaV){
            y -= 10;
            ui->clabelEn3->setGeometry(x,y,ui->clabelEn3->width(),ui->clabelEn3->height());
            //ui->clabelUsuario->adjustSize();
            if(y == 0)
                banderaV = true;
        }
}

void Dialog::disparar()
{
        int y = ui->clabelProyectil->geometry().y();
        static int x = ui->clabelProyectil->geometry().x(); //las varianles static solo se inicializan una vez al principio de la ejecuacion del programa, despues se
        //modifica su valor de acuerdo a lo requerido, mantienne su valor en sucesivas llamadas
        int point = ui->widget->geometry().x()+ui->clabelUsuario->width();
        static bool bandera = true;
        int puntaje = 0;

        if(ui->clabelProyectil->geometry().x() < ui->widget->width()-(ui->clabelProyectil->width()) && bandera){
            ui->clabelProyectil->setGeometry(x,y, ui->clabelProyectil->width(), ui->clabelProyectil->height());
            x += 10;
            if(ui->clabelProyectil->geometry().x() >= ui->clabelEn1->geometry().x()-(ui->clabelProyectil->width()) &&
                    ui->clabelProyectil->geometry().y() == ui->clabelEn1->geometry().y()){
                puntaje += 300;
                aux += puntaje;
                ui->lcdNumber->display(QString::number(aux));
                bandera = false;
            }
            if(ui->clabelProyectil->geometry().x() >= ui->clabelEn2->geometry().x()-(ui->clabelProyectil->width()) &&
                    ui->clabelProyectil->geometry().y() == ui->clabelEn2->geometry().y()){
                puntaje += 200;
                aux += puntaje;
                ui->lcdNumber->display(QString::number(aux));
                bandera = false;
            }
            if(ui->clabelProyectil->geometry().x() >= ui->clabelEn3->geometry().x()-(ui->clabelProyectil->width()) &&
                    ui->clabelProyectil->geometry().y() == ui->clabelEn3->geometry().y()){
                puntaje += 100;
                aux += puntaje;
                ui->lcdNumber->display(QString::number(aux));
                bandera = false;
            }
            //en este punto se cuentan las vidas se va restanto 1 cada que el proyectil choca contra el "aliado"
            //la imagen va cambiando y al llegar a cero se para todo
            if(ui->clabelProyectil->geometry().x() >= ui->clabelAlly->geometry().x()-(ui->clabelProyectil->width()) &&
                                ui->clabelProyectil->geometry().y() == ui->clabelAlly->geometry().y()){
                            bandera = false;
                            vidas -= 1;
                            switch (vidas) {
                                case 1: ui->cButtonVidas->setStyleSheet("background-image: url(:/imgs/1vida.png)");
                                ui->cButtonVidas->setGeometry(ui->cButtonVidas->geometry().x(),ui->cButtonVidas->geometry().y(),135,133);
                                break;
                                case 2: ui->cButtonVidas->setStyleSheet("background-image: url(:/imgs/2vidas.png)");
                                ui->cButtonVidas->setGeometry(ui->cButtonVidas->geometry().x(),ui->cButtonVidas->geometry().y(),270,140);
                                break;
                                case 3: ui->cButtonVidas->setStyleSheet("background-image: url(:/imgs/3vidas.png)");
                                ui->cButtonVidas->setGeometry(ui->cButtonVidas->geometry().x(),ui->cButtonVidas->geometry().y(),270,94);
                                break;
                                default:
                                    if(vidas == 0){
                                        ui->cButtonVidas->setStyleSheet("background-image: url(:/imgs/GO.png)");
                                        ui->cButtonVidas->setGeometry(ui->cButtonVidas->geometry().x(),ui->cButtonVidas->geometry().y(),270,91);
                                        timer1->stop();
                                        timer2->stop();
                                        timer3->stop();
                                        timer4->stop();
                                    }
                                break;
                            }
            }
            if(ui->clabelProyectil->geometry().x() >= ui->widget->width()-(ui->clabelProyectil->width())){
                bandera = false;
            }
        }
            if(!bandera){//aqui en lugar de hacer que regrese poco a poco, regresa a su posicion inicial
                int x2 = ui->clabelUsuario->width();
                ui->clabelProyectil->setGeometry(x2,y,ui->clabelProyectil->width(),ui->clabelProyectil->height());
                x = point;
                if(x == point){
                    timer2->stop();
                    bandera = true;
                    timer1->start(30);
                    if(vidas==0)
                        timer1->stop();
                }
            }
}

void Dialog::moverAliado()
{
    int x = ui->clabelAlly->geometry().x();
    static int y = ui->clabelAlly->geometry().y();
    static bool banderaV = true;

    if(ui->clabelAlly->geometry().y() < ui->widget->height()-(ui->clabelAlly->height()) && banderaV){
        ui->clabelAlly->setGeometry(x,y, ui->clabelAlly->width(), ui->clabelAlly->height());
        y += 10;
        if(ui->clabelAlly->geometry().y() >= (ui->widget->height())-(ui->clabelAlly->height()))
            banderaV = false;
    }
        if(!banderaV){
            y -= 10;
            ui->clabelAlly->setGeometry(x,y,ui->clabelAlly->width(),ui->clabelAlly->height());
            //ui->clabelUsuario->adjustSize();
            if(y == 0)
                banderaV = true;
        }
}


void Dialog::on_pushButton_clicked()
{
    timer1->start(30);
    timer3->start(20);
    timer4->start(20);
    ui->cButtonDisp->setEnabled(true);
    vidas = 3;
    aux = 0;
    ui->lcdNumber->display(QString::number(aux));
    ui->cButtonVidas->setStyleSheet("background-image: url(:/imgs/3vidas.png)");
    ui->cButtonVidas->setGeometry(ui->cButtonVidas->geometry().x(),ui->cButtonVidas->geometry().y(),270,94);
}


void Dialog::on_cButtonDisp_clicked()
{
    timer1->stop();
    timer2->start(25);
}


void Dialog::on_pushButton_2_clicked()
{
    close();
}

