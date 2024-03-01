#include "dialog.h"
#include "ui_dialog.h"
//Jorge Cisneros de la Torre 20130789

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer1 = new QTimer();

    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *evt)
{
    Q_UNUSED(evt);
    figurasGeometricas();
}

void Dialog::figurasGeometricas()
{
    QPainter canvas(this);
    //dibujar un pentagono, octagono, rombo, trapecio

    //se dibuja el trapecio
    QPen pen(Qt::blue, 3, Qt::DotLine, Qt::RoundCap, Qt::MiterJoin);
    canvas.setPen(pen);
    QPoint puntosTrapecio[4] = {QPoint(50,100), QPoint(300,100), QPoint(320,250), QPoint(30,250)};
    canvas.drawPolygon(puntosTrapecio,4);

    //se dibuja el rombo
    QPen pen2(Qt::red, 5, Qt::DashDotDotLine, Qt::SquareCap, Qt::BevelJoin);
    canvas.setPen(pen2);
    //QPoint puntosRombo[4] = {QPoint(500,150), QPoint(500,250), QPoint(350, 75), QPoint(650, 75)};
    QPoint puntosRombo[4] = {QPoint(500,100), QPoint(600,200), QPoint(500, 300), QPoint(400, 200)};
    canvas.drawPolygon(puntosRombo, 4);

    //se dibuja el pentagono
    QPen pen3(Qt::magenta, 5, Qt::DashLine, Qt::FlatCap, Qt::RoundJoin);
    canvas.setPen(pen3);
    QPoint puntosPentagono[5] = {QPoint(100,500), QPoint(200,400), QPoint(300,500), QPoint(250,600), QPoint(150,600)};
    canvas.drawPolygon(puntosPentagono, 5);

    //se dibuja el octagono
    QPen pen4(Qt::green, 3, Qt::CustomDashLine, Qt::RoundCap, Qt::MiterJoin);
    QVector<qreal> guiones;
    qreal espacios = 4;//espacio que hay entre cada línea
    guiones<<1<<espacios<<3<<espacios<<9<<espacios<<1<<espacios<<3<<espacios<<9<<espacios<<1<<espacios<<3<<espacios;
    pen4.setDashPattern(guiones);//se le da el patron a la pluma
    canvas.setPen(pen4);
    QPoint puntosOctagono[8] = {QPoint(500,500), QPoint(550,400), QPoint(650,350), QPoint(750,400),
                                        QPoint(800,500), QPoint(750,600), QPoint(650,650), QPoint(550,600)};
    canvas.drawPolygon(puntosOctagono, 8);

    //se dibuja y rellena el poligono que tiene colores diferentes
    QPen pen5(Qt::black, 5, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    canvas.setPen(pen5);
    QBrush brocha(QColor(rand()%155+100,rand()%155+100,rand()%155+100), Qt::SolidPattern);
    QPolygon Figura;
    Figura<<QPoint(320,250)<<QPoint(500,300)<<QPoint(550,400)<<QPoint(300,500);
    QPainterPath camino;
    camino.addPolygon(Figura);
    canvas.drawPolygon(Figura);
    canvas.fillPath(camino, brocha);

    //se dibuja el triangulo con brocha de patron en cruz, tiene un contorno que cambia de colores
    QPen pen6(QColor(rand()%155+100,rand()%155+100,rand()%155+100), 5, Qt::DashDotLine, Qt::SquareCap, Qt::BevelJoin);
    canvas.setPen(pen6);
    QBrush brocha2(Qt::darkMagenta, Qt::CrossPattern);
    QPolygon Figura2;
    Figura2<<QPoint(250,600)<<QPoint(500,500)<<QPoint(600,800);
    QPainterPath camino2;
    camino2.addPolygon(Figura2);
    canvas.drawPolygon(Figura2);
    canvas.fillPath(camino2,brocha2);

    //se dibuja el circulo y cuadrado con una brocha con patron vertical
    QPen pen7(Qt::darkCyan, 4, Qt::DashLine, Qt::RoundCap, Qt::MiterJoin);
    canvas.setPen(pen7);
    //Se usa para dibujar el circulo usando una recta con ángulos
    QRectF rectangle(650, 100, 200, 200);
    int startAngle = 16 * 360;
    int spanAngle = 16 * 360;
    QBrush brocha3(Qt::darkRed, Qt::VerPattern);//aqui se le da el color y el tipo de patron a la brocha
    canvas.fillRect(650, 100, 200, 200, brocha3);
    canvas.drawRect(650, 100, 200, 200);
    canvas.drawArc(rectangle, startAngle, spanAngle);
}


void Dialog::on_cButtonInicio_clicked()
{
    timer1->start(30);
}


void Dialog::on_cButtonPausa_clicked()
{
    timer1->stop();
}


void Dialog::on_cButtonSalir_clicked()
{
    close();
}

