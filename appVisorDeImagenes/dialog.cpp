#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    /*QImage imagen ("C:\\Users\\dell\\Pictures\\Screenshots\\Captura de pantalla (81).png");
    ui->label->setPixmap(QPixmap::fromImage(imagen));
    ui->label->setScaledContents(true);*/

    QFileDialog dialogo(this);
    dialogo.setNameFilter("Imagenes(*.png *.jpg *.jpeg *.bmp)");
    dialogo.setViewMode(QFileDialog::Detail);
    QString nomarch = QFileDialog::getOpenFileName(this, "Abrir Imagenes", "C:\\Users\\dell\\Documents\\Graficacion\\appVisorDeImagenes",
                                                   "Archivos IMGS(*.jpg *.png *.bmp *.jpeg)");
    if(!nomarch.isEmpty()){
        QImage imagen (nomarch);
        ui->label->setPixmap(QPixmap::fromImage(imagen));
        ui->label->setScaledContents(true);
    }
}

