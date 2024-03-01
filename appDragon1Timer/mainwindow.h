#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *evento);

private slots:
    void dragon(int limite, QPainter *);


private:
    Ui::MainWindow *ui;

    QTimer *timer;

    void paintEvent(QPaintEvent *e);

    void generarDragon(QPainter *Canvas);

    int EjeX[4098], EjeY[4098], signo, paso;

    int li, ls; //INDICAN LOS LIMITES PARA LA GENERACION DE LA CURVA DEL DRAGON
    bool band;
};
#endif // MAINWINDOW_H
