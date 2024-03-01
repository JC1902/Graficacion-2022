#include "dialog.h"
#include "ui_dialog.h"
//Jorge Cisneros de la Torre 20130789
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mandelbrot()
{
    QPainter canvas(this);
    maxX = canvas.window().width();
    maxY = canvas.window().height();
    limite = 100;

    origX = -2.0;
    origY = -1.25;
    dimX = 0.5;
    dimY = 1.25;

    pasoX = (dimX - origX) / maxX;
    pasoY = (dimY - origY) / maxY;

    for(i = 0; i <= maxX; i++)
        for(j = 0; j <= maxY; j++){
            posX = origX + i * pasoX;
            posY = origY + j * pasoY;

            iterX = 0.0;
            iterY = 0.0;

            terminar = pasos = 0;

            while(!terminar){
                tempX = (iterX * iterX) - (iterY * iterY) + posX;
                iterY = 2 * (iterX * iterY) + posY;//cambiar el número entero hará que el fractal tenga otra forma
                iterX = tempX;
                pasos++;
                if(hypot(fabs(iterX), fabs(iterY)) >= 2.0)
                    terminar++;
                if(pasos >= limite)
                    terminar++;
            }
            if(pasos < limite){
                canvas.setPen(QColor(0,0,0));
                canvas.drawPoint(i, j);
            }
        }
    canvas.setPen(QColor(0,200,200));
    QFont fuente = canvas.font();
    fuente.setPointSize(fuente.pointSize() * 2);
    canvas.setFont(QFont("Andy", 18));
    canvas.drawText(5,30,"Conjunto de Mandelbrot");
}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    mandelbrot();
}


void Dialog::on_pushButton_clicked()
{
    close();
}

