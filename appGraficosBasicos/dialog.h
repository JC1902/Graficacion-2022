#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QtGui>
#include <QtCore>
#include <QTimer>
#include <QMouseEvent>

#include "graficos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButLinea_clicked();

    void on_pushButColor_clicked();

    void on_pushButPolares_clicked();

    void on_pushButPitagoras_clicked();

    void on_pushButCirculo_clicked();

    void on_pushButEspiral1_clicked();

    void on_pushButEspiral2_clicked();

    void on_doubleSpinFactor_valueChanged(double arg1);

    void on_doubleSpinTheta_valueChanged(double arg1);

    void on_doubleSpinRadio_valueChanged(double arg1);

private:
    Ui::Dialog *ui;

    void paintEvent(QPaintEvent *e);
    QColor color;
    QPainter *canvas;
    int x1, x2, y1, y2;
    int xc, yc, radio;
    double factor, thetaF, radioF;

    bool linea = false;
    bool circuloPitagoras = false;
    bool circuloPolares = false;
    bool circulo1 = false;
    bool espiral1 =false, espiral2 = false;

    QTimer *timer1;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseDoubleClickEvent(QMouseEvent *event) override;
};
#endif // DIALOG_H
