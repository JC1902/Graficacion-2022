#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    cantRojo = ui->Rojo->value();
    cantVerde = ui->Verde->value();
    cantAzul = ui->Azul->value();
    cantRGB = ui->RGB->value();

    ui->Rojo->setEnabled(false);
    ui->Verde->setEnabled(false);
    ui->Azul->setEnabled(false);
    ui->RGB->setEnabled(false);

    ui->cButtonInvertido->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton_3->setEnabled(false);
    ui->radioButton_4->setEnabled(false);
    ui->radioButton_5->setEnabled(false);

    QImage img(":/unnamed");
    ui->megaImagen->setPixmap(QPixmap::fromImage(img));
    ui->megaImagen->setScaledContents(true);
}

Dialog::~Dialog()
{
    delete ui;
}

QImage Dialog::editRGB(const QImage &in)
{
    //ASIGNAR EL TAMAÑO DE LA IMAGEN DE LA ENTRADA IN
    QImage out(in.size(), in.format());
    int red;
    int green;
    int blue;
    //Reccorrer el arreglo de pixeles
    for(int line=0; line < in.height(); line++){
        //pixeles de entrada
        const QRgb* inPixeles = reinterpret_cast<const QRgb*>(in.scanLine(line));
        //pixeles de salida, estos son los que se van a modificar
        QRgb* outPixels = reinterpret_cast<QRgb*>(out.scanLine(line));
        for(int pos  = 0; pos < in.width(); pos++){
            red = qRed(inPixeles[pos]);
            green = qGreen(inPixeles[pos]);
            blue = qBlue(inPixeles[pos]);
            int alpha = qAlpha(inPixeles[pos]);

            if(ui->checkBox->isChecked() == true){
                ui->checkBox_2->setChecked(false);
                outPixels[pos] = qRgba(red+cantRojo, green+cantVerde, blue+cantAzul, alpha);
            }
            if(ui->checkBox_2->isChecked() == true){
                ui->checkBox->setChecked(false);
                outPixels[pos] = qRgba(red+cantRGB, green+cantRGB, blue+cantRGB, alpha);
            }
        }
    }
    ui->lcdNumber->display(QString::number(cantRojo));
    ui->lcdNumber_2->display(QString::number(cantVerde));
    ui->lcdNumber_3->display(QString::number(cantAzul));
    return out;
}

QImage Dialog::editBGR(const QImage &in)
{
    //ASIGNAR EL TAMAÑO DE LA IMAGEN DE LA ENTRADA IN
    QImage out(in.size(), in.format());
    int red;
    int green;
    int blue;
    //Reccorrer el arreglo de pixeles
    for(int line=0; line < in.height(); line++){
        //pixeles de entrada
        const QRgb* inPixeles = reinterpret_cast<const QRgb*>(in.scanLine(line));
        //pixeles de salida, estos son los que se van a modificar
        QRgb* outPixels = reinterpret_cast<QRgb*>(out.scanLine(line));
        for(int pos  = 0; pos < in.width(); pos++){
            red = qRed(inPixeles[pos]);
            green = qGreen(inPixeles[pos]);
            blue = qBlue(inPixeles[pos]);
            int alpha = qAlpha(inPixeles[pos]);

            if(ui->radioButton->isChecked() == true)
                outPixels[pos] = qRgba(~red+cantRojo, ~green+cantVerde, ~blue+cantAzul, alpha);
            if(ui->radioButton_2->isChecked()==true)
                outPixels[pos] = qRgba(blue, blue, blue, alpha);
            if(ui->radioButton_3->isChecked() == true)
                outPixels[pos] = qRgba(red | 0x0000ff, red | 0x00ff00, red | 0xff0000, alpha);
            if(ui->radioButton_4->isChecked() == true)
                outPixels[pos] = qRgba(red & 0xff00ff, green | 0x00ff00, red | 0xff0000, alpha);
            if(ui->radioButton_5->isChecked() == true)
                outPixels[pos] = qRgba(red & 0xff00ff, blue | 0x00ff00, green | 0xff0000, alpha);
        }
    }
    return out;
}


void Dialog::on_Rojo_valueChanged(int value)
{
    cantRojo = value;
    this->on_pushButton_clicked();
}


void Dialog::on_pushButton_clicked()
{
    QImage img(":/unnamed");
    img = editRGB(img);
    ui->megaImagen->setPixmap(QPixmap::fromImage(img));
    ui->megaImagen->setScaledContents(true);

    ui->Rojo->setEnabled(true);
    ui->Verde->setEnabled(true);
    ui->Azul->setEnabled(true);
    ui->RGB->setEnabled(true);

    ui->cButtonInvertido->setEnabled(true);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->radioButton_3->setEnabled(true);
    ui->radioButton_4->setEnabled(true);
    ui->radioButton_5->setEnabled(true);
}


void Dialog::on_Verde_valueChanged(int value)
{
    cantVerde = value;
    this->on_pushButton_clicked();
}


void Dialog::on_Azul_valueChanged(int value)
{
    cantAzul = value;
    this->on_pushButton_clicked();
}


void Dialog::on_RGB_valueChanged(int value)
{
    cantRGB = value;
    this->on_pushButton_clicked();
}


void Dialog::on_pushButton_2_clicked()
{
    close();
}


void Dialog::on_cButtonInvertido_clicked()
{
    QImage img(":/unnamed");
    img = editBGR(img);
    ui->megaImagen->setPixmap(QPixmap::fromImage(img));
    ui->megaImagen->setScaledContents(true);

    ui->Rojo->setEnabled(true);
    ui->Verde->setEnabled(true);
    ui->Azul->setEnabled(true);
    ui->RGB->setEnabled(true);
}


void Dialog::on_pushButton_3_clicked()
{
    QImage img(":/unnamed");
    ui->megaImagen->setPixmap(QPixmap::fromImage(img));
    ui->megaImagen->setScaledContents(true);

    ui->Rojo->setValue(0);
    ui->Verde->setValue(0);
    ui->Azul->setValue(0);
    ui->RGB->setValue(0);
}

