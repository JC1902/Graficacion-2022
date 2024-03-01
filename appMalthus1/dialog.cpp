#include "dialog.h"
#include "ui_dialog.h"
//Jorge Cisneros de la Torre 20130789
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
    timer1->start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    close();
}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    malthus1();
}

void Dialog::extranioConfinador(QPainter *canvas)
{
    int i, j, contador, x, y;
    double pobAnt, pobNueva, razon;

    pobNueva = 0.0;
    razon = 2.3;
    maxX = canvas->window().width();
    maxY = canvas->window().height();

    for(j = 1; j <= 151;  j++){
        contador = 0;
        razon += 0.01;
        pobAnt = 0.01;
        for(i = 1; i <= maxGen; i++){
            pobNueva = razon * (pobAnt * (1 - pobAnt));
            x = pobAnt * maxX;
            y = maxY - (pobNueva * maxY);
            canvas->setPen(QColor(QRandomGenerator::global()->bounded(100)+155
                                  , QRandomGenerator::global()->bounded(100)+155
                                  , 0));
            canvas->drawPoint(x, y);
            if(pobAnt == pobNueva)
                contador++;
            else
                contador = 0;
            if(contador > 10)
                i = maxGen;

            pobAnt = pobNueva;
        }
    }
}

void Dialog::malthus1()
{
    QPainter canvas(this);
    extranioConfinador(&canvas);

    QFont fuente = canvas.font();
    fuente.setPointSize(fuente.pointSize() * 2);
    canvas.setFont(QFont("Andy", 18));
    canvas.drawText(5,30,"Malthus 1");
}

