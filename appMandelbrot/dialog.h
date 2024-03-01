#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    int maxX, maxY, limite, i, j, pasos, terminar;
    double pasoX, pasoY, posX, posY, origX, origY, dimX, dimY, iterX, iterY, tempX;

private slots:
    void mandelbrot();
    void paintEvent(QPaintEvent *e);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

    QTimer *timer;
};
#endif // DIALOG_H
