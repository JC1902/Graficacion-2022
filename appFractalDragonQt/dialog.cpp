#include "dialog.h"
#include "ui_dialog.h"

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
    dragon();
}

void Dialog::dragon()//Representa al método main() en una app consola
{
    QPainter canvas(this);
    int i;
    paso = 4096;
    signo = -1;
    EjeX[1] = canvas.window().width()/4;
    EjeX[4097] = (3 * canvas.window().width())/4;
    EjeY[1] = EjeY[4097] = (2 * canvas.window().height())/3;
    canvas.setPen(QColor(50,50,200));
    QFont fuente = canvas.font();
    fuente.setPointSize(fuente.pointSize() * 2);
    canvas.setFont(QFont("Andy", 18));
    canvas.drawText(5,30,"Curvas fractal del dragón");
    canvas.setPen(QColor(0, QRandomGenerator::global()->bounded(100)+155,QRandomGenerator::global()->bounded(100)+155));

    canvas.drawLine(EjeX[1], EjeY[1], EjeX[4097], EjeY[4097]);

    for(i = 1; i <= 13; i++){
        generarDragon(&canvas);
        paso /= 2;
    }
}

void Dialog::generarDragon(QPainter *Canvas)
{   
    int i, j, dx, dy;
    j = paso / 2;
    Canvas->setPen(QColor(0, QRandomGenerator::global()->bounded(100)+155, QRandomGenerator::global()->bounded(100)+155));

    for(i = 1; i <= 4096; i += paso){
        dx = EjeX[paso + i] - EjeX[i];
        dy = EjeY[paso + i] - EjeY[i];
        signo *= -1;
        EjeX[i + j] = EjeX[i] + (dx + (dy * signo))/2;
        EjeY[i + j] = EjeY[i] + (dy - (dx * signo))/2;
        Canvas->drawLine(EjeX[i], EjeY[i], EjeX[i + j], EjeY[i + j]);
        Canvas->drawLine(EjeX[i + j], EjeY[i + j], EjeX[i + paso], EjeY[i + paso]);
    }
}

