#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

#include <QTimer>

#include "matrix.h"
#include "mapeo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void asignarFigura();

    void dibujarFigura();
    void dibujarFiguraMapeada();

    //TRANSFORMACIONES 2D
    void trasladar( int tx, int ty );

    void escalar( double sx, double sy );

    void escalarPF( int tx, int ty, double sx, double sy);

    void rotar(double ang);

    void rotar2(double ang);

    void rotarPF(double tx, double ty, double ang);

    void rotarPF2(double tx, double ty, double ang);

private slots:
    void on_pushButtonArriba_clicked();

    void on_pushButtonAbajo_clicked();

    void on_pushButtonDerecha_clicked();

    void on_pushButtonIzquierda_clicked();

    void on_pushButtonReset_clicked();

    void on_pushButton_clicked();

    void on_pushButtonEscalarPF_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButtonRotPos_clicked();

    void on_pushButtonRotNeg_clicked();

    void rotarAnimacion1();

    void rotarAnimacion2();

    void animacionRotarNeg();

    void animacionRotarMover();

    void animacionEscalar();

    void animacionTrasladarX();

    void animacionTrasladarY();

    void on_pushButtonAnimar1_clicked();

    void on_pushButtonAnimar2_clicked();

    void on_pushButtonAnimar3_clicked();

    void on_pushButtonAnimar4_clicked();

    void on_pushButtonAnimar5_clicked();

    void on_pushButtonAnimar6_clicked();

    void on_pushButtonAnimar7_clicked();

    void on_pushButtonAnimar8_clicked();

    void on_pushButtonTODAS_clicked();

private:
    Ui::Widget *ui;

    QPainter *canvas;

    float Fig[4][3]; // FIGURA ORIGINAL
    float FigAux[4][3]; // FIGURA DE RESPALDO

    int ancho;
    int centroX;
    int centroY;

    int tX, tY, sX, sY, an;

    QTimer *timer1, *timer2, *timer3, *timer4, *timer5, *timer6, *timer7, *timer8;
};
#endif // WIDGET_H
