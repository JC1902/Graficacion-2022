#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QMovie>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *evento) override;

private slots:
    void paintEvent(QPaintEvent *e) override;
    void extranioConfinador(QPainter *canvas);
    void malthus2();

private:
    Ui::MainWindow *ui;

    int maxX, maxY;

    QTimer *timer1;
};
#endif // MAINWINDOW_H
