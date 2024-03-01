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

    zoomx1 = 0;
    zoomy1 = 0;
    zoomx2 = 0;
    zoomy2 = 0;

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
    case Qt::Key_J:
        on_pushButtonRotPos_clicked();
        break;
    case Qt::Key_L:
        on_pushButtonRotNeg_clicked();
        break;
    case Qt::Key_S:
        zoomx1 += 10;
        zoomy1 += 10;
        zoomx2 -= 10;
        zoomy2 -= 10;
        repaint();
        break;
    case Qt::Key_W:
        zoomx1 -= 10;
        zoomy1 -= 10;
        zoomx2 += 10;
        zoomy2 += 10;
        repaint();
        break;
    case Qt::Key_A:
        zoomx2 -= 10;
        repaint();
        break;
    case Qt::Key_D:
        zoomx2 += 10;
        repaint();
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
    Fig[0][0] = 6; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 6; Fig[1][1] = 1; Fig[1][2] = 1;
    Fig[2][0] = 5; Fig[2][1] = 1; Fig[2][2] = 1;
    Fig[3][0] = 5; Fig[3][1] = 3; Fig[3][2] = 1;
    Fig[4][0] = 4; Fig[4][1] = 3; Fig[4][2] = 1;
    Fig[5][0] = 4; Fig[5][1] = 6; Fig[5][2] = 1;
    Fig[6][0] = 1; Fig[6][1] = 6; Fig[6][2] = 1;
    Fig[7][0] = 1; Fig[7][1] = 7; Fig[7][2] = 1;
    Fig[8][0] = 0; Fig[8][1] = 7; Fig[8][2] = 1;
    Fig[9][0] = 0; Fig[9][1] = 16; Fig[9][2] = 1;
    Fig[10][0] = 1; Fig[10][1] = 16; Fig[10][2] = 1;
    Fig[11][0] = 1; Fig[11][1] = 19; Fig[11][2] = 1;
    Fig[12][0] = 4; Fig[12][1] = 19; Fig[12][2] = 1;
    Fig[13][0] = 4; Fig[13][1] = 22; Fig[13][2] = 1;
    Fig[14][0] = 5; Fig[14][1] = 22; Fig[14][2] = 1;
    Fig[15][0] = 5; Fig[15][1] = 24; Fig[15][2] = 1;
    Fig[16][0] = 6; Fig[16][1] = 24; Fig[16][2] = 1;
    Fig[17][0] = 6; Fig[17][1] = 25; Fig[17][2] = 1;
    Fig[18][0] = 7; Fig[18][1] = 25; Fig[18][2] = 1;
    Fig[19][0] = 7; Fig[19][1] = 26; Fig[19][2] = 1;
    Fig[20][0] = 15; Fig[20][1] = 26; Fig[20][2] = 1;
    Fig[21][0] = 15; Fig[21][1] = 25; Fig[21][2] = 1;
    Fig[22][0] = 16; Fig[22][1] = 25; Fig[22][2] = 1;
    Fig[23][0] = 16; Fig[23][1] = 24; Fig[23][2] = 1;
    Fig[24][0] = 17; Fig[24][1] = 24; Fig[24][2] = 1;
    //------------------------Casco-------------------------------
    Fig[25][0] = 17; Fig[25][1] = 22; Fig[25][2] = 1;
    Fig[26][0] = 19; Fig[26][1] = 22; Fig[26][2] = 1;
    Fig[27][0] = 19; Fig[27][1] = 21; Fig[27][2] = 1;
    Fig[28][0] = 20; Fig[28][1] = 21; Fig[28][2] = 1;
    Fig[29][0] = 20; Fig[29][1] = 16; Fig[29][2] = 1;
    Fig[30][0] = 19; Fig[30][1] = 16; Fig[30][2] = 1;
    Fig[31][0] = 19; Fig[31][1] = 15; Fig[31][2] = 1;
    Fig[32][0] = 11; Fig[32][1] = 15; Fig[32][2] = 1;
    Fig[33][0] = 11; Fig[33][1] = 16; Fig[33][2] = 1;
    Fig[34][0] = 10; Fig[34][1] = 16; Fig[34][2] = 1;
    Fig[35][0] = 10; Fig[35][1] = 21; Fig[35][2] = 1;
    Fig[36][0] = 11; Fig[36][1] = 21; Fig[36][2] = 1;
    Fig[37][0] = 11; Fig[37][1] = 22; Fig[37][2] = 1;
    Fig[38][0] = 17; Fig[38][1] = 22; Fig[38][2] = 1;
    Fig[39][0] = 19; Fig[39][1] = 22; Fig[39][2] = 1;
    Fig[40][0] = 19; Fig[40][1] = 21; Fig[40][2] = 1;
    Fig[41][0] = 20; Fig[41][1] = 21; Fig[41][2] = 1;
    Fig[42][0] = 20; Fig[42][1] = 16; Fig[42][2] = 1;
    Fig[43][0] = 19; Fig[43][1] = 16; Fig[43][2] = 1;
    Fig[44][0] = 19; Fig[44][1] = 15; Fig[44][2] = 1;
    //------------------------Casco-------------------------------
    Fig[45][0] = 19; Fig[45][1] = 7; Fig[45][2] = 1;
    Fig[46][0] = 18; Fig[46][1] = 7; Fig[46][2] = 1;
    Fig[47][0] = 18; Fig[47][1] = 1; Fig[47][2] = 1;
    Fig[48][0] = 17; Fig[48][1] = 1; Fig[48][2] = 1;
    Fig[49][0] = 17; Fig[49][1] = 0; Fig[49][2] = 1;
    Fig[50][0] = 14; Fig[50][1] = 0; Fig[50][2] = 1;
    Fig[51][0] = 14; Fig[51][1] = 1; Fig[51][2] = 1;
    Fig[52][0] = 13; Fig[52][1] = 1; Fig[52][2] = 1;
    Fig[53][0] = 13; Fig[53][1] = 5; Fig[53][2] = 1;
    Fig[54][0] = 11; Fig[54][1] = 5; Fig[54][2] = 1;
    Fig[55][0] = 11; Fig[55][1] = 1; Fig[55][2] = 1;
    Fig[56][0] = 10; Fig[56][1] = 1; Fig[56][2] = 1;
    Fig[57][0] = 10; Fig[57][1] = 0; Fig[57][2] = 1;
    Fig[58][0] = 6; Fig[58][1] = 0; Fig[58][2] = 1;

    Fig[59][0] = 6; Fig[59][1] = 0; Fig[59][2] = 1;

    Planeta[0][0] = 160; Planeta[0][1] = -200; Planeta[0][2] = 1;
    Planeta[1][0] = 160; Planeta[1][1] = -220; Planeta[1][2] = 1;
    Planeta[2][0] = 100; Planeta[2][1] = -220; Planeta[2][2] = 1;
    Planeta[3][0] = 100; Planeta[3][1] = -240; Planeta[3][2] = 1;
    Planeta[4][0] = 80; Planeta[4][1] = -240; Planeta[4][2] = 1;
    Planeta[5][0] = 80; Planeta[5][1] = -260; Planeta[5][2] = 1;
    Planeta[6][0] = 60; Planeta[6][1] = -260; Planeta[6][2] = 1;
    Planeta[7][0] = 60; Planeta[7][1] = -280; Planeta[7][2] = 1;
    Planeta[8][0] = 40; Planeta[8][1] = -280; Planeta[8][2] = 1;
    Planeta[9][0] = 40; Planeta[9][1] = -340; Planeta[9][2] = 1;
    Planeta[10][0] = 20; Planeta[10][1] = -340; Planeta[10][2] = 1;
    Planeta[11][0] = 20; Planeta[11][1] = -420; Planeta[11][2] = 1;
    Planeta[12][0] = 40; Planeta[12][1] = -420; Planeta[12][2] = 1;
    Planeta[13][0] = 40; Planeta[13][1] = -480; Planeta[13][2] = 1;
    Planeta[14][0] = 60; Planeta[14][1] = -480; Planeta[14][2] = 1;
    Planeta[15][0] = 60; Planeta[15][1] = -500; Planeta[15][2] = 1;
    Planeta[16][0] = 80; Planeta[16][1] = -500; Planeta[16][2] = 1;
    Planeta[17][0] = 80; Planeta[17][1] = -520; Planeta[17][2] = 1;
    Planeta[18][0] = 100; Planeta[18][1] = -520; Planeta[18][2] = 1;
    Planeta[19][0] = 100; Planeta[19][1] = -540; Planeta[19][2] = 1;
    Planeta[20][0] = 160; Planeta[20][1] = -540; Planeta[20][2] = 1;
    Planeta[21][0] = 160; Planeta[21][1] = -560; Planeta[21][2] = 1;
    Planeta[22][0] = 240; Planeta[22][1] = -560; Planeta[22][2] = 1;
    Planeta[23][0] = 240; Planeta[23][1] = -540; Planeta[23][2] = 1;
    Planeta[24][0] = 300; Planeta[24][1] = -540; Planeta[24][2] = 1;
    Planeta[25][0] = 300; Planeta[25][1] = -520; Planeta[25][2] = 1;
    Planeta[26][0] = 320; Planeta[26][1] = -520; Planeta[26][2] = 1;
    Planeta[27][0] = 320; Planeta[27][1] = -500; Planeta[27][2] = 1;
    Planeta[28][0] = 340; Planeta[28][1] = -500; Planeta[28][2] = 1;
    Planeta[29][0] = 340; Planeta[29][1] = -480; Planeta[29][2] = 1;
    Planeta[30][0] = 360; Planeta[30][1] = -480; Planeta[30][2] = 1;
    Planeta[31][0] = 360; Planeta[31][1] = -420; Planeta[31][2] = 1;
    Planeta[32][0] = 380; Planeta[32][1] = -420; Planeta[32][2] = 1;
    Planeta[33][0] = 380; Planeta[33][1] = -340; Planeta[33][2] = 1;
    Planeta[34][0] = 360; Planeta[34][1] = -340; Planeta[34][2] = 1;
    Planeta[35][0] = 360; Planeta[35][1] = -280; Planeta[35][2] = 1;
    Planeta[36][0] = 340; Planeta[36][1] = -280; Planeta[36][2] = 1;
    Planeta[37][0] = 340; Planeta[37][1] = -260; Planeta[37][2] = 1;
    Planeta[38][0] = 320; Planeta[38][1] = -260; Planeta[38][2] = 1;
    Planeta[39][0] = 320; Planeta[39][1] = -240; Planeta[39][2] = 1;
    Planeta[40][0] = 300; Planeta[40][1] = -240; Planeta[40][2] = 1;
    Planeta[41][0] = 300; Planeta[41][1] = -220; Planeta[41][2] = 1;
    Planeta[42][0] = 240; Planeta[42][1] = -220; Planeta[42][2] = 1;
    Planeta[43][0] = 240; Planeta[43][1] = -200; Planeta[43][2] = 1;

    Planeta[44][0] = 160; Planeta[44][1] = -200; Planeta[44][2] = 1;

    for(int renglon = 0; renglon < tamano; renglon++)
            for(int columnas = 0; columnas < 3; columnas++)
               FigAux[renglon][columnas] = Fig[renglon][columnas];

    for(int r = 0; r < 100; r++){
            aleatorio = rand() % (500 - (-501)) - 501;
            aleatorioY = rand() % (500 - (-501)) - 501;
            puntos[r].setX(aleatorio);
            puntos[r].setY(aleatorioY);
        }

        ancho = this->size().width() - ui->widget->size().width();

        centroX = ancho / 2;
        centroY = this->size().height() / 2;

        tX = 0;
        tY = 0;
        sX = 0;
        sY = 0;
}

void Widget::dibujarFiguraMapeada()
{
    QPen pen(QColor(0,200,0), 3);
    canvas->setPen(pen);

    //SIMULA LINEAS MAS PERFECTAS
    canvas->setRenderHint(QPainter::Antialiasing, true);

    //DIBUJAR 4 CUADRANTES
    //linea horizontal
    //canvas->drawLine(0, centroY, ancho, centroY);
    //linea vertical
    //canvas->drawLine(centroX, 0, centroX, size().height());

    //utilizar la clase mapeo
    Mapeo dibujo;

    dibujo.ventana(ancho/2, 0, ancho, size().height()/2);
    dibujo.puerto(ancho/2 + zoomx1, 0 + zoomy1, ancho + zoomx2, size().height()/2 + zoomy2);
    //ORIGEN EN EL CENTRO DEL AREA DE DIBUJO
    int L = centroX;
    int M = centroY;

    canvas->setPen(QColor(255,0,0));

    int x1, y1, x2, y2;
                                //x1 y y1 son recibidos por referencia
    dibujo.mapeo(Fig[0][0], Fig[0][1], x1, y1, L, M);
    dibujo.mapeo(Fig[1][0], Fig[1][1], x2, y2, L, M);//triangulo
    canvas->drawLine(x1, y1, x2, y2);

    for(int i = 0; i < tamano-2; i++){
        dibujo.mapeo(Fig[i][0], Fig[i][1], x1, y1, L, M);
        dibujo.mapeo(Fig[i+1][0], Fig[i+1][1], x2, y2, L, M);
        canvas->drawLine(x1,y1,x2,y2);
    }

    int px1, py1, px2, py2;
    for(int i = 0; i < 44; i++){
        dibujo.mapeo(Planeta[i][0], Planeta[i][1], px1, py1, L, M);
        dibujo.mapeo(Planeta[i + 1][0], Planeta[i + 1][1], px2, py2, L, M);
        canvas->drawLine(px1, py1, px2, py2);
    }

    int p1, p2;
    QPolygon planeta;
    canvas->setPen(QPen(QColor(100,100,255),3));
    for(int i = 0; i<44; i++){
        dibujo.mapeo(Planeta[i][0], Planeta[i][1], p1, p2, L, M);
        planeta<<QPoint(p1, p2);
    }

    QPainterPath dibujoPlaneta;
    dibujoPlaneta.addPolygon(planeta);
    canvas->drawPolygon(planeta);
    canvas->fillPath(dibujoPlaneta, QBrush(QColor(100,105,255), Qt::SolidPattern));

    int x, y;
    canvas->setPen(QPen(QColor(255, 255, 255),3));
    for(int i = 0; i < 100; i++){
        dibujo.mapeo(puntos[i].x(), puntos[i].y(), x, y, L, M);
        canvas->drawPoint(x, y);
    }

    int xx2, yy2;
    QPolygon dibujoSus;
    canvas->setPen(QPen(QColor(255, 255, 255),3));
    for(int i = 0; i <= tamano-2; i++){
        dibujo.mapeo(Fig[i][0], Fig[i][1], xx2, yy2, L, M);
        dibujoSus <<QPoint(xx2, yy2);
    }

    QPainterPath caminoC;
    caminoC.addPolygon(dibujoSus);
    canvas->drawPolygon(dibujoSus);
    canvas->fillPath(caminoC, QBrush(QColor(255,105,97), Qt::SolidPattern));

    int xx1, yy1;
    QPolygon casco;
    //canvas->setPen(QPen(QColor(176,224,230),3));
    for(int i = 0; i <= 13; i++){
        dibujo.mapeo(Fig[25+i][0], Fig[25+i][1], xx1, yy1, L, M);
        casco <<QPoint(xx1, yy1);
    }

    QPainterPath camino;
    camino.addPolygon(casco);
    canvas->drawPolygon(casco);
    canvas->fillPath(camino, QBrush(QColor(176,224,230), Qt::SolidPattern));
}

void Widget::trasladar( int tx, int ty )
{
    Matrix fig, id, figres;

    fig.Inicializa(59,3);
    figres.Inicializa(59,3);
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

    fig.Inicializa(59,3);
    figres.Inicializa(59,3);
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

    fig.Inicializa(59, 3);
    figres.Inicializa(59, 3);
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

void Widget::rotar(int ang)
{
    Matrix fig, id, figres;

    fig.Inicializa(59, 3);
    figres.Inicializa(59, 3);
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

void Widget::rotar2(int ang)
{
    Matrix fig, id, figres;

    fig.Inicializa(59, 3);
    figres.Inicializa(59, 3);
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

    fig.Inicializa(59, 3);
    figres.Inicializa(59, 3);
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

    fig.Inicializa(59, 3);
    figres.Inicializa(59, 3);
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


void Widget::on_pushButton_clicked()
{
    escalar( sX + ui->doubleSpinBoxSx->value(), sY + ui->doubleSpinBoxSy->value());
}


void Widget::on_pushButtonEscalarPF_clicked()
{
    escalarPF(tX + ui->spinBoxPFX->value(), tY + ui->spinBoxPFY->value(),
              sX + ui->doubleSpinBoxSx->value(), sY + ui->doubleSpinBoxSy->value());
}


void Widget::on_pushButtonRotPos_clicked()
{
    //rotar(an + ui->spinBox->value());
    rotarPF(tX + ui->spinBoxPfxRt->value(), tY + ui->spinBoxPfyRt->value(),
                    an + ui->spinBox->value());
}


void Widget::on_pushButtonRotNeg_clicked()
{
    //rotar2(an + ui->spinBox->value());
    rotarPF2(tX + ui->spinBoxPfxRt->value(), tY + ui->spinBoxPfyRt->value(),
             an + ui->spinBox->value());
}


void Widget::on_pushButtonReset_clicked()
{
    for( int r = 0; r < tamano; r++)
        for( int c = 0; c < 3; c++)
            Fig[r][c] = FigAux[r][c];

    tX = tY = 0;
    sX = sY = 0;
    an = 0;

    zoomx1 = 0;
    zoomy1 = 0;
    zoomx2 = 0;
    zoomy2 = 0;

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


void Widget::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0)
        ui->widget->setEnabled(true);
    else
        ui->widget->setEnabled(false);
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
    static double pfx = 0;
    static double pfy = 0;
    if(cont <= 250){
        angulo = ui->spinBox->value();
        if(cont == 250)
        {
            angulo = 0;
            cont = 0;
            contX = 0;
        }
        pfx = ui->spinBoxPFX->value();
        pfy = ui->spinBoxPFY->value();
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
    int pfx = ui->spinBoxPFX->value();
    int pfy = ui->spinBoxPFY->value();
    if(cont <= 30 && peque == true){
        escX = ui->doubleSpinBoxSx->value();
        escY = ui->doubleSpinBoxSy->value();      
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
        escalarPF(pfx, pfy, 0.5, 0.5);
        cont++;
        if(cont == 20){
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


