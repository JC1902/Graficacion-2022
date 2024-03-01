#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QtGui>
#include <QtCore>
#include <QTimer>

#include "graficos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int EjeX[4098], EjeY[4098], paso;
    int signo;

    void keyPressEvent(QKeyEvent *evento);

private slots:
    void dragon(int limite, QPainter *canvas); //representa a main()
    void generarDragon(QPainter *Canvas);

private:
    Ui::MainWindow *ui;

    void paintEvent(QPaintEvent *e);
    QColor color;
    QColor color2;
    QPainter *canvas;

    QTimer *timer1;

    int li, ls; //INDICAN LOS LIMITES PARA LA GENERACION DE LA CURVA DEL DRAGON
    bool band;
};
#endif // MAINWINDOW_H
