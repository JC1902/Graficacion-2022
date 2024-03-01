#include "dialog.h"
#include "ui_dialog.h"
#include <math.h>

QString pantalla;
double num1, num2, resultado, angulo;
int operacion;
const double PI = 3.14159265;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    pantalla = "0";
    ui->lcdNumber->display(pantalla);
    ui->labelMostrar->setText("0");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_0){
        pantalla = pantalla + "0";
        int aux = pantalla.toInt();
        pantalla = QString::number(aux);
        ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_1){
        pantalla = pantalla + "1";
        int aux = pantalla.toInt();
        pantalla = QString::number(aux);
        ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_2){
        pantalla = pantalla + "2";
        int aux = pantalla.toInt();
        pantalla = QString::number(aux);
        ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_3){
        pantalla = pantalla + "3";
        int aux = pantalla.toInt();
        pantalla = QString::number(aux);
        ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_4){
        pantalla = pantalla + "4";
        int aux = pantalla.toInt();
        pantalla = QString::number(aux);
        ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_5 ){
            pantalla = pantalla + "5";
            int aux = pantalla.toInt();
            pantalla = QString::number(aux);
            ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_6 ){
            pantalla = pantalla + "6";
            int aux = pantalla.toInt();
            pantalla = QString::number(aux);
            ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_7){
            pantalla = pantalla + "7";
            int aux = pantalla.toInt();
            pantalla = QString::number(aux);
            ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_8){
            pantalla = pantalla + "8";
            int aux = pantalla.toInt();
            pantalla = QString::number(aux);
            ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_9){
            pantalla = pantalla + "9";
            int aux = pantalla.toInt();
            pantalla = QString::number(aux);
            ui->lcdNumber->display(pantalla);
    }
    if(evento->key() == Qt::Key_Escape){
        close();
    }
    if(evento->key() == Qt::Key_Equal){
        on_pushButton_10_clicked();
    }
    if(evento->key() == Qt::Key_Plus){
        on_botonSuma_clicked();
    }
    if(evento->key() == Qt::Key_Minus){
        on_botonResta_clicked();
    }
    if(evento->key() == Qt::Key_Asterisk){
        on_botonMulti_clicked();
    }
    if(evento->key() == Qt::Key_Slash){
        on_botonDivdir_clicked();
    }
    if(evento->key() == Qt::Key_P){
        on_Potencia_clicked();
    }
    if(evento->key() == Qt::Key_R){
        on_Raiz_clicked();
    }
    if(evento->key() == Qt::Key_Backspace){
        on_cButBorrar_clicked();
    }
}

//esta funcion la uso por si existe un numero negativo que se multiplique por -1 y de su valor positivo
int absoluto(double num){
    if(num >= 0)
        return num;
    else
        return (num * -1);
}

void Dialog::on_pushButton_clicked()
{
    pantalla = pantalla + "1";//escribe el numero 1 en la pantalla
    int aux = pantalla.toInt();//lo convierte de string a entero
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_2_pressed()
{
    pantalla = pantalla + "2";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_3_clicked()
{
    pantalla = pantalla + "3";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_4_clicked()
{
    pantalla = pantalla + "4";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}


void Dialog::on_pushButton_5_clicked()
{
    pantalla = pantalla + "5";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_6_clicked()
{
    pantalla = pantalla + "6";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_7_clicked()
{
    pantalla = pantalla + "7";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_8_clicked()
{
    pantalla = pantalla + "8";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_9_clicked()
{
    pantalla = pantalla + "9";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_pushButton_14_clicked()
{
    pantalla = pantalla + "0";
    int aux = pantalla.toInt();
    pantalla = QString::number(aux);
    ui->lcdNumber->display(pantalla);
}

void Dialog::on_cButBorrar_clicked()
{
    pantalla = "0";
    ui->lcdNumber->display(pantalla);
    num1 = 0;
    num2 = 0;
    resultado = 0;
    operacion = 0;
    ui->labelMostrar->setText("0");
    ui->tangente->setChecked(false);
    ui->coseno->setChecked(false);
    ui->seno->setChecked(false);
}

void Dialog::on_botonSuma_clicked()//en este boton solo se registra el primer numero ingresado ya que el segundo es leido al momento de clickear el boton =
{
    num1 = pantalla.toInt();
    ui->labelMostrar->setText(pantalla);
    pantalla = "0";
    ui->lcdNumber->display(pantalla);
    operacion = 1;
}

/*este evento es para el boton igual utilice un switch con la variable operacion para saber que se va a hacer, ya que
 * switch solo acepta un entero para saber que va a hacer.
 */
void Dialog::on_pushButton_10_clicked()
{
    switch(operacion){
    case 1:num2 = pantalla.toInt();
        resultado = num1 + num2;
        ui->lcdNumber->display(QString::number(resultado));
        break;
    case 2:num2 = pantalla.toInt();
        resultado = num1 - num2;
        ui->lcdNumber->display(QString::number(resultado));
        break;
    case 3:num2 = pantalla.toInt();
        resultado = num1 * num2;
        ui->lcdNumber->display(QString::number(resultado));
        break;
    case 4:num2 = pantalla.toInt();
        if(num2 == 0)
            ui->lcdNumber->display("ERROR");
        else{
        resultado = num1 / num2;
        ui->lcdNumber->display(QString::number(resultado));
        }
        break;
    case 5:num2 = pantalla.toInt();
        resultado = pow(num1,num2);
        ui->lcdNumber->display(QString::number(resultado));
        break;
    case 0:if(ui->seno->isChecked()==true  && operacion == 0){
            num1 = pantalla.toInt();
            angulo = (num1*PI)/180;
            resultado = sin(angulo);
            ui->lcdNumber->display(QString::number(resultado));
        }else
            if(ui->coseno->isChecked()==true  && operacion == 0){
                num1 = pantalla.toInt();
                angulo = (num1*PI)/180;
                resultado = cos(angulo);
                ui->lcdNumber->display(QString::number(resultado));
            }else
                if(ui->tangente->isChecked()==true  && operacion == 0){
                    num1 = pantalla.toInt();
                    angulo = (num1*PI)/180;
                    resultado = tan(angulo);
                    ui->lcdNumber->display(QString::number(resultado));
                }
        break;
    }
}

/* en los siguientes tres botones ocurre lo mismo, se lee el primer numero, ademas de que la variable operacion ayuda al
 * boton '=' a identificar que operacion es.
*/
void Dialog::on_botonResta_clicked()
{
    num1 = pantalla.toInt();
    ui->labelMostrar->setText(pantalla);
    pantalla = "0";
    ui->lcdNumber->display(pantalla);
    operacion = 2;
}


void Dialog::on_botonMulti_clicked()
{
    num1 = pantalla.toInt();
    ui->labelMostrar->setText(pantalla);
    pantalla = "0";
    ui->lcdNumber->display(pantalla);
    operacion = 3;
}


void Dialog::on_botonDivdir_clicked()
{
    num1 = pantalla.toInt();
    ui->labelMostrar->setText(pantalla);
    pantalla = "0";
    ui->lcdNumber->display(pantalla);
    operacion = 4;
}

/*el boton raiz realiza el calculo y muestra el resultado por si mismo sin la necesidad de presionar el boton '='*/
void Dialog::on_Raiz_clicked()
{
    num1=pantalla.toFloat();
    if(num1 < 0 || resultado < 0)//verifica si el numero es menor a cero o si el resultado de una operacion es menor a cero
            ui->lcdNumber->display("Math ERROR");
        else{
            resultado = sqrt(num1);
            ui->lcdNumber->display(QString::number(resultado));
        }
}


void Dialog::on_Potencia_clicked()
{
    num1 = pantalla.toInt();
    ui->labelMostrar->setText(pantalla);
    pantalla = "0";
    ui->lcdNumber->display(pantalla);
    operacion = 5;
}

