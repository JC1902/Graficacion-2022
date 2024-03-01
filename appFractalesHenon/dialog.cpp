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

void Dialog::extranioConfinador(QPainter *Canvas)
{
    int i, color, posX, posY;
    double xAnt, xNueva, yAnt, yNueva;

    maxX = Canvas->window().width();
    maxY = Canvas->window().height();
    xAnt = xNueva = yAnt = yNueva = 0;

    for(color = 1; color <= 20; color++)
        for(i = 1; i <= 0x02FF; i++){
            xNueva = yAnt + 1 - (1.4 * xAnt * xAnt);
            yNueva = 0.3 * xAnt;

            posX = (xNueva * maxX / 3 * escalaX) + maxX / 2 + despX;
            posY = (yNueva * maxY * escalaY) + maxY / 2 + despY;

            if((posX >= 0) && (posX <= maxX) && (posY >= 0) && (posY <= maxY)){
                Canvas->setPen(QColor(QRandomGenerator::global()->bounded(100)+155, 0,QRandomGenerator::global()->bounded(100)+155));
                Canvas->drawPoint(posX, posY);
            }
            yAnt = yNueva;
            xAnt = xNueva;
        }
}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    henon();
}

void Dialog::henon()
{
    QPainter canvas(this);

    escalaX = 1;
    escalaY = 1;
    despX = 0;
    despY = 0;
    extranioConfinador(&canvas);
    QFont fuente = canvas.font();
    fuente.setPointSize(fuente.pointSize() * 2);
    canvas.setFont(QFont("Andy", 18));
    canvas.drawText(5,30,"Curva de Henon");
}

