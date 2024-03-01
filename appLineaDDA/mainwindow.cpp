#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;

    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
    timer1->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    x1 = ui->lineEdit->text().toInt();
    y1 = ui->lineEdit_2->text().toInt();
    x2 = ui->lineEdit_3->text().toInt();
    y2 = ui->lineEdit_4->text().toInt();
    linea = true;

    update();
}


void MainWindow::on_pushButton_2_clicked()
{
    QColor color_seleccionado = QColorDialog::getColor(Qt::white, this, "Selecciona el color...");
    if(color_seleccionado.isValid()){
        color = color_seleccionado;
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    canvas = new QPainter(this);

    //OBJETO ESTATICO
    //Graficos graficos;
    //graficos.lineaDDA(x1,y1,x2,y2,canvas);

    Graficos *graficos = new Graficos();
    if(linea){
        //graficos->lineaDDA(x1, y1, x2, y2, canvas);
        graficos->lineaDDA(x1, y1, x2, y2, canvas, color);
    }
    canvas->end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //x1
    ui->lineEdit->setText(QString::number(event->pos().x()));
    //y1
    ui->lineEdit_2->setText(QString::number(event->pos().y()));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //x2
    ui->lineEdit_3->setText(QString::number(event->pos().x()));
    //y2
    ui->lineEdit_4->setText(QString::number(event->pos().y()));

    this->on_pushButton_clicked();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    ui->lineEdit_3->setText(QString::number(event->pos().x()));
    ui->lineEdit_4->setText(QString::number(event->pos().y()));

    this->on_pushButton_clicked();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{

}

