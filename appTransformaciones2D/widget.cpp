#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    asignarFigura();

    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(rotarAnimacion1()));

    timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(rotarAnimacion2()));

    timer3 = new QTimer();
    connect(timer3, SIGNAL(timeout()), this, SLOT(animacionRotarNeg()));

    timer4 = new QTimer();
    connect(timer4, SIGNAL(timeout()), this, SLOT(animacionRotarMover()));

    timer5 = new QTimer();
    connect(timer5, SIGNAL(timeout()), this, SLOT(animacionEscalar()));

    timer6 = new QTimer();
    connect(timer6, SIGNAL(timeout()), this, SLOT(animacionTrasladarX()));

    timer7 = new QTimer();
    connect(timer7, SIGNAL(timeout()), this, SLOT(animacionTrasladarY()));

    timer8 = new QTimer();
    connect(timer8, SIGNAL(timeout()), this, SLOT(animacionTrasladarX()));
    connect(timer8, SIGNAL(timeout()), this, SLOT(animacionTrasladarY()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    canvas = new QPainter(this);
    dibujarFiguraMapeada();

    canvas->end();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        on_pushButtonArriba_clicked();
        break;
    case Qt::Key_Down:
        on_pushButtonAbajo_clicked();
        break;
    case Qt::Key_Right:
        on_pushButtonDerecha_clicked();
        break;
    case Qt::Key_Left:
        on_pushButtonIzquierda_clicked();
        break;
    case Qt::Key_T:
        on_pushButton_clicked();
        break;
    case Qt::Key_E:
        on_pushButtonEscalarPF_clicked();
        break;
    case Qt::Key_R:
        on_pushButtonReset_clicked();
        break;
    case Qt::Key_1:
        on_pushButtonAnimar1_clicked();
        break;
    case Qt::Key_2:
        on_pushButtonAnimar2_clicked();
        break;
    case Qt::Key_3:
        on_pushButtonAnimar3_clicked();
        break;
    case Qt::Key_4:
        on_pushButtonAnimar4_clicked();
        break;
    case Qt::Key_5:
        on_pushButtonAnimar5_clicked();
        break;
    case Qt::Key_6:
        on_pushButtonAnimar6_clicked();
        break;
    case Qt::Key_7:
        on_pushButtonAnimar7_clicked();
        break;
    case Qt::Key_8:
        on_pushButtonAnimar8_clicked();
        break;
    case Qt::Key_9:
        on_pushButtonTODAS_clicked();
        break;
    }
}


void Widget::asignarFigura()
{
        Fig[0][0] = 10; Fig[0][1] = 10; Fig[0][2] = 1;
        Fig[1][0] = 30; Fig[1][1] = 10; Fig[1][2] = 1;//triangulo
        Fig[2][0] = 10; Fig[2][1] = 30; Fig[2][2] = 1;//triangulo
        //PARA CERRAR LA FIGURA
        Fig[3][0] = 10; Fig[3][1] = 10; Fig[3][2] = 1;

        for(int renglon = 0; renglon < 4; renglon++)
            for(int columnas = 0; columnas < 3; columnas++)
               FigAux[renglon][columnas] = Fig[renglon][columnas];

        ancho = this->size().width() - ui->widget->size().width();

        centroX = ancho / 2;
        centroY = this->size().height() / 2;

        tX = 0;
        tY = 0;
        sX = 0;
        sY = 0;
}


/*void Widget::dibujarFigura()// NO SE VA A USAR
{

}*/


void Widget::dibujarFiguraMapeada()
{
    QPen pen(QColor(0,200,0), 3);
    canvas->setPen(pen);

    //SIMULA LINEAS MAS PERFECTAS
    canvas->setRenderHint(QPainter::Antialiasing, true);

    //DIBUJAR 4 CUADRANTES
    //linea horizontal
    canvas->drawLine(0, centroY, ancho, centroY);
    //linea vertical
    canvas->drawLine(centroX, 0, centroX, size().height());

    //utilizar la clase mapeo
    Mapeo dibujo;

    dibujo.ventana(ancho/2, 0, ancho, size().height()/2);
    dibujo.puerto(ancho/2, 0, ancho, size().height()/2);
    //ORIGEN EN EL CENTRO DEL AREA DE DIBUJO
    int L = centroX;
    int M = centroY;

    int xp, yp;
    canvas->setPen(QColor(255,0,0));
    dibujo.mapeo(16,16,xp,yp, L,M);
    canvas->drawPoint(xp, yp);

    int x1, y1, x2, y2;
                                //x1 y y1 son recibidos por referencia
    dibujo.mapeo(Fig[0][0], Fig[0][1], x1, y1, L, M);
    dibujo.mapeo(Fig[2][0], Fig[2][1], x2, y2, L, M);//triangulo
    canvas->drawLine(x1, y1, x2, y2);

    for(int i = 0; i < 2; i++){
        dibujo.mapeo(Fig[i][0], Fig[i][1], x1, y1, L, M);
        dibujo.mapeo(Fig[i+1][0], Fig[i+1][1], x2, y2, L, M);
        canvas->drawLine(x1,y1,x2,y2);
    }
}


void Widget::trasladar( int tx, int ty )
{
    Matrix fig, id, figres;

    fig.Inicializa(4,3);
    figres.Inicializa(4,3);
    id.Inicializa(3,3);

    //ASIGNAR PUNTOS
    for(int i = 0; i < fig.numRen(); i++)
        for(int j = 0; j < fig.numCol(); j++)
            fig.SET(i,j,Fig[i][j]);

    //APLICAR TRASLACIÓN
    figres.Traslacion(fig, id, tx, ty);

    for( int i = 0; i < figres.numRen(); i++)
        for ( int j = 0; j < figres.numCol(); j++)
            Fig[i][j] = figres.GET(i,j);

    update();
}

void Widget::escalar(double sx, double sy)// ESCALAR NORMAL
{
    Matrix fig, id, figres;

    fig.Inicializa(4,3);
    figres.Inicializa(4,3);
    id.Inicializa(3,3);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            fig.SET(r, c, Fig[r][c]);

    figres.Escalacion(fig, id, sx, sy);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            Fig[r][c] = figres.GET(r,c);

    repaint();
}

void Widget::escalarPF(int tx, int ty, double sx, double sy)// ESCALAR CON PUNTO FIJO
{
    Matrix fig, id, figres;

    fig.Inicializa(4, 3);
    figres.Inicializa(4, 3);
    id.Inicializa(3, 3);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            fig.SET(r, c, Fig[r][c]);

    figres.EscalacionPF(fig, id, tx, ty, sx, sy);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            Fig[r][c] = figres.GET(r,c);

    repaint();
}

void Widget::rotar(double ang)
{
    Matrix fig, id, figres;

    fig.Inicializa(4, 3);
    figres.Inicializa(4, 3);
    id.Inicializa(3, 3);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            fig.SET(r, c, Fig[r][c]);

    figres.Rotacion(fig, id, ang);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            Fig[r][c] = figres.GET(r,c);

    repaint();
}

void Widget::rotar2(double ang)
{
    Matrix fig, id, figres;

    fig.Inicializa(4, 3);
    figres.Inicializa(4, 3);
    id.Inicializa(3, 3);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            fig.SET(r, c, Fig[r][c]);

    figres.Rotacion2(fig, id, ang);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            Fig[r][c] = figres.GET(r,c);

    repaint();
}

void Widget::rotarPF(double tx, double ty, double ang)
{
    Matrix fig, id, figres;

    fig.Inicializa(4, 3);
    figres.Inicializa(4, 3);
    id.Inicializa(3, 3);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            fig.SET(r, c, Fig[r][c]);

    figres.RotacionPF(fig, id, ang, tx, ty);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            Fig[r][c] = figres.GET(r,c);

    repaint();
}

void Widget::rotarPF2(double tx, double ty, double ang)
{
    Matrix fig, id, figres;

    fig.Inicializa(4, 3);
    figres.Inicializa(4, 3);
    id.Inicializa(3, 3);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            fig.SET(r, c, Fig[r][c]);

    figres.RotacionPF2(fig, id, tx, ty, ang);

    for(int r = 0; r < fig.numRen(); r++)
        for(int c = 0; c < fig.numCol(); c++)
            Fig[r][c] = figres.GET(r,c);

    repaint();
}


void Widget::on_pushButtonArriba_clicked()
{
    trasladar(0, tY + ui->spinBoxY->value());
}


void Widget::on_pushButtonAbajo_clicked()
{
    trasladar(0, tY - ui->spinBoxY->value());
}


void Widget::on_pushButtonDerecha_clicked()
{
    trasladar( tX + ui->spinBoxX->value(), 0);
}


void Widget::on_pushButtonIzquierda_clicked()
{
    trasladar( tX - ui->spinBoxX->value(), 0 );
}

//REINICIAR AL ESTADO ORIGINAL DE LA FIGURA
void Widget::on_pushButtonReset_clicked()
{
    for( int r = 0; r < 4; r++)
        for( int c = 0; c < 3; c++)
            Fig[r][c] = FigAux[r][c];

    tX = tY = 0;
    sX = sY = 0;
    an = 0;

    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    timer5->stop();
    timer6->stop();
    timer7->stop();
    timer8->stop();

    update();
}

// TAREA PARA MAÑANA : ESCALACION SIMPLE

// TAREA PARA DOMINGO : ESCALACION PUNTO FIJO APLICAR LAS MATRICES VISTAS EL DIA DE HOY

void Widget::on_pushButton_clicked()
{
    escalar( sX + ui->doubleSpinBoxSx->value(), sY + ui->doubleSpinBoxSy->value());
}


void Widget::on_pushButtonEscalarPF_clicked()
{
    escalarPF(tX + ui->spinBoxPFX->value(), tY + ui->spinBoxPFY->value(),
              sX + ui->doubleSpinBoxSx->value(), sY + ui->doubleSpinBoxSy->value());
}


void Widget::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->widget->setEnabled(true);
    else
        ui->widget->setEnabled(false);
}


void Widget::on_pushButtonRotPos_clicked()
{
    //rotar(an + ui->spinBox->value());
    rotarPF(tX + ui->spinBoxPFX->value(), tY + ui->spinBoxPFY->value(),
                    an + ui->spinBox->value());
}


void Widget::on_pushButtonRotNeg_clicked()
{
    //rotar2(an + ui->spinBox->value());
    rotarPF2(tX + ui->spinBoxPFX->value(), tY + ui->spinBoxPFY->value(),
             an + ui->spinBox->value());
}

void Widget::rotarAnimacion1()
{
    static int angulo = 0;
    static int cont = 0;
    if(cont <= 8){
        angulo = 45;
        if(cont == 8)
        {
            angulo = 0;
            cont = 0;
        }
        double pfx = 20;
        double pfy = 30;
        rotarPF(pfx, pfy, angulo);
        cont++;
    }
}

void Widget::rotarAnimacion2()
{
    static bool dir = true;
    static int angulo = 0;
    static int cont = 0;

    if(cont <= 9 && dir == true){
        angulo = 45;
        double pfx = 20;
        double pfy = 10;
        rotarPF(pfx, pfy, angulo);
        cont++;
        if(cont == 9 ){
            angulo = 0;
            cont = 0;
            dir = false;
        }
    }
    if(!dir){
        angulo -= 45;
        double pfx = 10;
        double pfy = 10;
        rotarPF(pfx, pfy, angulo);
        cont++;
        if(cont == 9){
            angulo = 0;
            cont = 0;
            dir = true;
        }
    }
}

void Widget::animacionRotarNeg()
{
    static int angulo = 0;
    static int cont = 0;
    if(cont <= 8){
        angulo = ui->spinBox->value();
        if(cont == 8)
        {
            angulo = 0;
            cont = 0;
        }
        double pfx = ui->spinBoxPFX->value();
        double pfy = ui->spinBoxPFY->value();
        rotarPF2(pfx, pfy, angulo);
        cont++;
    }
}

void Widget::animacionRotarMover()
{
    static int angulo = 0;
    static int cont = 0;
    static int contX = 0;
    if(cont <= 100){
        angulo = ui->spinBox->value();
        if(cont == 100)
        {
            angulo = 0;
            cont = 0;
            contX = 0;
        }
        double pfx = ui->spinBoxPFX->value();
        double pfy = ui->spinBoxPFY->value();
        rotarPF(pfx + contX, pfy, angulo);
        contX++;
        cont++;
    }
}

void Widget::animacionEscalar()
{
    static double escX = 0;
    static double escY = 0;
    static int cont = 0;
    static bool peque = true;
    if(cont <= 30 && peque == true){
        escX = ui->doubleSpinBoxSx->value();
        escY = ui->doubleSpinBoxSy->value();
        int pfx = ui->spinBoxPFX->value();
        int pfy = ui->spinBoxPFY->value();
        escalarPF(pfx, pfy, escX, escY);
        cont++;
        if(cont == 30){
            escX = 0;
            escY = 0;
            cont = 0;
            peque = false;
        }
    }
    if(!peque){
        escX = 0.5;
        escY = 0.5;
        int pfx = ui->spinBoxPFX->value();
        int pfy = ui->spinBoxPFY->value();
        escalarPF(pfx, pfy, escX, escY);
        cont++;
        if(cont == 30){
            escX = 0;
            escY = 0;
            cont = 0;
            peque = true;
        }
    }
}

void Widget::animacionTrasladarX()
{
    static int tx = 0;
    static int cont = 0;
    static bool dirX = true;
    if(cont <= 30 && dirX == true ){
        tx = ui->spinBoxX->value();
        trasladar(tx, 0);
        cont++;
        if(cont == 30){
            tx = 0;
            cont = 0;
            dirX = false;
        }
    }
    if(!dirX){
        tx = ui->spinBoxX->value();
        trasladar( tX - tx, 0);
        cont++;
        if(cont == 30){
            tx = 0;
            cont = 0;
            dirX = true;
        }
    }
}

void Widget::animacionTrasladarY()
{
    static int ty = 0;
    static int cont = 0;
    static bool dirY = true;
    if(cont <= 30 && dirY == true ){
        ty = ui->spinBoxY->value();
        trasladar(0, ty);
        cont++;
        if(cont == 30){
            ty = 0;
            cont = 0;
            dirY = false;
        }
    }
    if(!dirY){
        ty = ui->spinBoxX->value();
        trasladar(0, tY - ty);
        cont++;
        if(cont == 30){
            ty = 0;
            cont = 0;
            dirY = true;
        }
    }
}


void Widget::on_pushButtonAnimar1_clicked()
{
    timer1->start(30);
    timer4->stop();
    timer2->stop();
    timer3->stop();
    timer5->stop();
    timer6->stop();
    timer7->stop();
    timer8->stop();
}


void Widget::on_pushButtonAnimar2_clicked()
{
    timer2->start(30);
    timer1->stop();
    timer4->stop();
    timer3->stop();
    timer5->stop();
    timer6->stop();
    timer7->stop();
    timer8->stop();
}


void Widget::on_pushButtonAnimar3_clicked()
{
    timer3->start(30);
    timer1->stop();
    timer2->stop();
    timer4->stop();
    timer5->stop();
    timer6->stop();
    timer7->stop();
    timer8->stop();
}


void Widget::on_pushButtonAnimar4_clicked()
{
    timer4->start(30);
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer5->stop();
    timer6->stop();
    timer7->stop();
    timer8->stop();
}


void Widget::on_pushButtonAnimar5_clicked()
{
    timer5->start(50);
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    timer6->stop();
    timer7->stop();
    timer8->stop();
}


void Widget::on_pushButtonAnimar6_clicked()
{
    timer6->start(50);
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    timer5->stop();
    timer7->stop();
    timer8->stop();
}


void Widget::on_pushButtonAnimar7_clicked()
{
    timer7->start(30);
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    timer5->stop();
    timer6->stop();
    timer8->stop();
}


void Widget::on_pushButtonAnimar8_clicked()
{
    timer8->start(30);
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    timer5->stop();
    timer6->stop();
    timer7->stop();
}


void Widget::on_pushButtonTODAS_clicked()
{
    timer1->start(30);
    timer2->start(30);
    timer3->start(30);
    timer4->start(30);
    timer5->start(30);
    timer6->start(30);
    timer7->start(30);
    timer8->start(30);
}

