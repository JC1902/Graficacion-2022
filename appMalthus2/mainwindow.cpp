#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer();

    connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
    timer1->start(1000);

    ui->statusbar->addPermanentWidget(ui->label, 1);

    /*QMovie *movie = new QMovie("C:\\Users\\dell\\Documents\\Graficacion\\appMalthus2\\fractal.gif");
    ui->label_2->setMovie(movie);
    movie->start();
    ui->label_2->setScaledContents(true); código para colocar un GIF en el frame*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_S){
            close();
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    malthus2();
}

void MainWindow::extranioConfinador(QPainter *canvas)
{
    int i, j, k, contador;
    double pobAnt, pobNueva, X, Y, razon;

    maxX = canvas->window().width();
    maxY = canvas->window().height();

    pobAnt = pobNueva = 0.0;
    razon = 2.3;
    Y = 0;

    canvas->setPen(QColor(QRandomGenerator::global()->bounded(100)+155
                          , 0
                          , QRandomGenerator::global()->bounded(100)+155));

    for(j = 1; j <= 15; j++){
        for(k = 1; k <= 10; k++){
            contador = 0;
            razon += 0.01;
            pobAnt = 0.01;
            for(i = 1; i <= 1000; i++){
                pobNueva = razon * (pobAnt * (1 - pobAnt));
                X = pobNueva - pobAnt;
                canvas->drawPoint((X * maxX / 2) + maxX / 2, (maxY / 2) - (Y * maxY / 2));
                if(pobAnt == pobNueva)
                    contador++;
                else
                    contador = 0;

                if(contador > 100)
                    i = 10000;
                pobAnt = pobNueva;
                Y = X;
            }
        }
    }
}

void MainWindow::malthus2()
{
    QPainter canvas(this);
    extranioConfinador(&canvas);

    QFont fuente = canvas.font();
    fuente.setPointSize(fuente.pointSize() * 2);
    canvas.setFont(QFont("Andy", 18));
    canvas.drawText(5,30,"Malthus 2");
}

