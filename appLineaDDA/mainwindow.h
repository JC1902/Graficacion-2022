#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QtGui>
#include <QtCore>
#include <QTimer>
#include <QMouseEvent>

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    void paintEvent(QPaintEvent *e);
    QColor color;
    QPainter *canvas;
    int x1, x2, y1, y2;
    bool linea;

    QTimer *timer1;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseDoubleClickEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H
