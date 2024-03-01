#include "mainwindow.h"
#include "ui_mainwindow.h"
//Jorge Cisneros de la Torre
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    li = 0;
    ls = 12;
    band = false;

    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));

    //colocar las etiquetas en el statusbar
    ui->statusbar->addPermanentWidget(ui->label_4, 1);
    ui->statusbar->addPermanentWidget(ui->label_5, 2);
    ui->statusbar->addPermanentWidget(ui->label_2, 3);
    ui->statusbar->addPermanentWidget(ui->label_3, 4);
    ui->statusbar->addPermanentWidget(ui->label, 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_C){//abrir un ColorDialog para el color del dragón
        QColor color_seleccionado = QColorDialog::getColor(Qt::white, this, "Selecciona el color del Dragón");
        if(color_seleccionado.isValid()){
            color = color_seleccionado;
        }
    }
    if(evento->key() == Qt::Key_T){//abrir un ColorDialog para el color del texto
        QColor color_seleccionado2 = QColorDialog::getColor(Qt::white, this, "Selecciona el color del Texto");
        if(color_seleccionado2.isValid()){
            color2 = color_seleccionado2;
        }
    }
    if(evento->key() == Qt::Key_I){//iniciar a formar el dragón
            band = true;
            timer1->start(90);
            /*update();*/ repaint();
    }
    if(evento->key() == Qt::Key_D){//se detiene la "animación"
            timer1->stop();
    }
    if(evento->key() == Qt::Key_S){//cerrar el frame
            close();
    }
}

void MainWindow::generarDragon(QPainter *Canvas)
{
    int i, j, dx, dy;
    Graficos *graficos = new Graficos();
        j = paso / 2;
        //Canvas->setPen(QColor(0, QRandomGenerator::global()->bounded(100)+155, QRandomGenerator::global()->bounded(100)+155));

        for(i = 1; i <= 4096; i += paso){
            dx = EjeX[paso + i] - EjeX[i];
            dy = EjeY[paso + i] - EjeY[i];
            //comentar signo *= -1 para ver el arabesco
            signo *= -1;
            //la siguiente linea coloca al arabesco al reves y en la parte de arriba
            //signo = 1;
            EjeX[i + j] = EjeX[i] + (dx + (dy * signo))/2;
            EjeY[i + j] = EjeY[i] + (dy - (dx * signo))/2;
            //graficos->lineaDDA(EjeX[i], EjeY[i], EjeX[i + j], EjeY[i + j], Canvas);
            //graficos->lineaDDA(EjeX[i + j], EjeY[i + j], EjeX[i + paso], EjeY[i + paso], Canvas);
            graficos->lineaDDA(EjeX[i], EjeY[i], EjeX[i + j], EjeY[i + j], Canvas, color);
            graficos->lineaDDA(EjeX[i + j], EjeY[i + j], EjeX[i + paso], EjeY[i + paso], Canvas, color);
        }
}

void MainWindow::dragon(int limite, QPainter *canvas)
{//el código en dragon() es el mismo solo hay que cambiar el canvas->drawLine por graficos->lineaDDA para hacer el dragón
    Graficos *graficos = new Graficos();
        int i;
        paso = 4096;
        signo = -1;
        EjeX[1] = canvas->window().width()/4;
        EjeX[4097] = (3 * canvas->window().width())/4;
        EjeY[1] = EjeY[4097] = (2 * canvas->window().height())/3;
        canvas->setPen(color2);//la variable color2 que contiene el color del QColorDialog para el título
        QFont fuente = canvas->font();
        fuente.setPointSize(fuente.pointSize() * 2);
        canvas->setFont(QFont("Andy", 18));
        canvas->drawText(5,30,"Curvas fractal del dragón");

        //canvas->setPen(QColor(0, QRandomGenerator::global()->bounded(100)+155,QRandomGenerator::global()->bounded(100)+155));
        //graficos->lineaDDA(EjeX[1], EjeY[1], EjeX[4097], EjeY[4097], canvas);

        graficos->lineaDDA(EjeX[1], EjeY[1], EjeX[4097], EjeY[4097], canvas, color);

        for(i = 1; i <= limite; i++){
            generarDragon(canvas);
            paso /= 2;
        }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter *canvas = new QPainter(this);
        if(band){
            if(li <= ls){
                dragon(li, canvas);
                li++;
            }
            else
                band = false;
        }
        if(!band){
            li--;
            dragon(li, canvas);
            if(li == 0){
                band = true;
            }
        }
        canvas->end();
}

