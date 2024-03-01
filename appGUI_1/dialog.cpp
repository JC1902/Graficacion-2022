#include "dialog.h"
#include "ui_dialog.h"

#include <math.h>

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
    QString cadena = "HOLA";
    ui->label->setText(cadena + "  "+ui->lineEdit->text().toUpper());
    //ui->label1->text() +",  HOLA";
    //ui->label1->setText(cadena);
    ui->label->adjustSize();
}

void Dialog::on_pushButton_3_clicked()
{
    QString dato = ui->lineEdit_2->text();

    int base = dato.toInt();
    double potencia = ui->doubleSpinBox->text().toDouble();
            //ui->dial->value();
            //ui->lineEdit_3->text().toDouble();

    double resultado = pow(base,potencia);

    ui->label_4->setText("RESULTADO: ");
    ui->label_4->setText(ui->label_4->text()+"  "+QString::number(resultado));
    ui->label_4->adjustSize();
}


void Dialog::on_dial_sliderMoved(int position)
{
    ui->lineEdit_3->setText(QString::number(position));
}


void Dialog::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->lineEdit_3->setText(QString::number(arg1));
}

