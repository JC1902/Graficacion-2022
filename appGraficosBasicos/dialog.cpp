#include "dialog.h"
#include "ui_dialog.h"
//REDISEÑAR LA INTERFACE

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;

    timer1 = new QTimer();
    //connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
    //timer1->start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButColor_clicked()
{
    QColor color_seleccionado = QColorDialog::getColor(Qt::white, this, "Selecciona el color...");
    if(color_seleccionado.isValid()){
        color = color_seleccionado;
    }
}

void Dialog::paintEvent(QPaintEvent *e)
{
    canvas = new QPainter(this);

    //OBJETO ESTATICO
    //Graficos graficos;
    //graficos.lineaDDA(x1,y1,x2,y2,canvas);

    Graficos *graficos = new Graficos();
    if(linea)
            graficos->lineaDDA(x1, y1, x2, y2, canvas, color);
    else if(circuloPolares)
            graficos->circunferenciaCoordPolares(xc, yc, radio, canvas, color);
    else if(circuloPitagoras)
            graficos->circunferenciaPitagoras(xc, yc, radio, canvas, color);
    else if(circulo1)
            graficos->Circulo(xc, yc, radio, canvas, color);
            //graficos->cirucloBresenham(10,10,10,canvas);
    else if(espiral1)
            graficos->espiral1(canvas, color, factor);
    else if(espiral2)
            graficos->espiral2(canvas,color, thetaF, radioF);
    if(ui->checkBoxCM->isChecked()==true){
        graficos->lineaDDA(x1, y1, x2, y2, canvas, color);
        graficos->circunferenciaCoordPolares(xc, yc, radio, canvas, color);
    }

    linea = circuloPitagoras = circuloPolares = circulo1 = espiral1 = espiral2 = false;

    canvas->end();
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    //x1
    ui->lineEditX1->setText(QString::number(event->pos().x()));
    //y1
    ui->lineEditY1->setText(QString::number(event->pos().y()));
    if(ui->checkBoxCM->isChecked() == true){
    //xc
    ui->spinBoxCentroX->setValue(event->pos().x());
    //yc
    ui->spinBoxCentroY->setValue(event->pos().y());
    }

}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    //x2
    ui->lineEditX2->setText(QString::number(event->pos().x()));
    //y2
    ui->lineEditY2->setText(QString::number(event->pos().y()));

    if(ui->checkBoxCM->isChecked() == true){
        int x = ui->lineEditX2->text().toInt();
        int y = ui->lineEditY2->text().toInt();

        int distanciaR= sqrt(pow((xc-x),2)+pow((yc-y),2));
        ui->spinBoxRadio->setValue(distanciaR);

        this->on_pushButPolares_clicked();
    }
    this->on_pushButLinea_clicked();
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    ui->lineEditX2->setText(QString::number(event->pos().x()));
    ui->lineEditY2->setText(QString::number(event->pos().y()));

    if(ui->checkBoxCM->isChecked() == true){
        int x = ui->lineEditX2->text().toInt();
        int y = ui->lineEditY2->text().toInt();

        int distanciaR= sqrt(pow((xc-x),2)+pow((yc-y),2));
        ui->spinBoxRadio->setValue(distanciaR);

        this->on_pushButPolares_clicked();
    }
    this->on_pushButLinea_clicked();
}

void Dialog::mouseDoubleClickEvent(QMouseEvent *event)
{
}


void Dialog::on_pushButLinea_clicked()
{
    x1 = ui->lineEditX1->text().toInt();
    y1 = ui->lineEditY1->text().toInt();
    x2 = ui->lineEditX2->text().toInt();
    y2 = ui->lineEditY2->text().toInt();

    linea = true;
    update();
}


void Dialog::on_pushButPolares_clicked()
{
    //coord polares
    xc = ui->spinBoxCentroX->value();
    yc = ui->spinBoxCentroY->value();
    radio = ui->spinBoxRadio->value();

    circuloPolares = true;
    update();
}


void Dialog::on_pushButPitagoras_clicked()
{
    //pitágoras
    xc = ui->spinBoxCentroX->value();
    yc = ui->spinBoxCentroY->value();
    radio = ui->spinBoxRadio->value();

    circuloPitagoras = true;
    update();
}


void Dialog::on_pushButCirculo_clicked()
{
    //circulo
    xc = ui->spinBoxCentroX->value();
    yc = ui->spinBoxCentroY->value();
    radio = ui->spinBoxRadio->value();

    circulo1 = true;
    update();
}


void Dialog::on_pushButEspiral1_clicked()
{
    factor = ui->doubleSpinFactor->value();

    espiral1 = true;
    update();
}


void Dialog::on_pushButEspiral2_clicked()
{
    thetaF = ui->doubleSpinTheta->value();
    radioF = ui->doubleSpinRadio->value();

    espiral2 = true;
    update();
}


void Dialog::on_doubleSpinFactor_valueChanged(double arg1)
{
    Q_UNUSED(arg1);
    on_pushButEspiral1_clicked();
}


void Dialog::on_doubleSpinTheta_valueChanged(double arg1)
{
    Q_UNUSED(arg1);
    on_pushButEspiral2_clicked();
}


void Dialog::on_doubleSpinRadio_valueChanged(double arg1)
{
    Q_UNUSED(arg1);
    on_pushButEspiral2_clicked();
}

