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

QImage Dialog::rotarRGB(const QImage &in)
{
    //ASIGNAR EL TAMAÑO DE LA IMAGEN DE LA ENTRADA IN
    QImage out(in.size(), in.format());
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

            //outPixels[pos] = qRgba(red , red, red, alpha);
            //outPixels[pos] = qRgba(green , green, green, alpha);
            //outPixels[pos] = qRgba(blue , blue, blue, alpha);

            //outPixels[pos] = qRgba(red ^ 0xff0000, green ^ 0x00ff00, blue ^ 0x0000ff, alpha);
            //outPixels[pos] = qRgba(red | 0x0000ff, green | 0x00ff00, blue | 0xff0000, alpha);
            //outPixels[pos] = qRgba(red & 0xff00ff, blue | 0x00ff00, red | 0xff0000, alpha);MORADO CON TONALIDADES DE VERDE
            outPixels[pos] = qRgba(red & 0xff00ff, blue | 0x00ff00, green | 0xff0000, alpha);
            //outPixels[pos] = qRgba(red & 0xff0000, green & 0x00ff00, blue & 0x0000ff, alpha);
            //outPixels[pos] = qRgba(~red, ~green, ~blue, alpha);
            //outPixels[pos] = qRgba(red<<2, green<<2, blue>>2, alpha);
            //outPixels[pos] = qRgba(blue, 0, blue, alpha);

            //outPixels[pos] = qRgba(red, green, blue, alpha);
            //outPixels[pos] = qRgba(blue, red, green,alpha);
            //outPixels[pos] = qRgba(green, blue, red,alpha);

            //outPixels[pos] = qRgba(155, 155, 155, alpha);
            //outPixels[pos] = qRgba(blue, green, red, alpha);
            //outPixels[pos] = qRgba(green, green, green, alpha);
        }
    }
    return out;
}


void Dialog::on_pushButton_clicked()
{
    QImage img(":/pez (1)");

    img = rotarRGB(img);
    ui->label_2->setPixmap(QPixmap::fromImage(img));
    ui->label_2->setScaledContents(true);

    img = rotarRGB(img);
    ui->label_3->setPixmap(QPixmap::fromImage(img));
    ui->label_3->setScaledContents(true);

    img = rotarRGB(img);
    ui->label_4->setPixmap(QPixmap::fromImage(img));
    ui->label_4->setScaledContents(true);
}

/*TAREA: APP INTERACTIVA (EL USUARIO TENDRA DIFERENTES OPCIONES PARA MANIPULAR UNA IMAGEN Y MOSTRARLA
 * MINIMO CON UNA SALIDA USAR SLIDERS, DIALS, MOSTRAR VALORES EN LCD'S, SPINNER)
*/
