#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void paintEvent(QPaintEvent *canvas);

private:
    Ui::MainWindow *ui;

    int x1, x2, y1, y2;
    void dibujarRecta(x1, x2, y1, y2);
};
#endif // MAINWINDOW_H
