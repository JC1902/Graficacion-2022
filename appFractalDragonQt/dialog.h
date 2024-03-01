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
    int EjeX[4098], EjeY[4098], paso;
    int signo;
private slots:
    void on_pushButton_clicked();

    void paintEvent(QPaintEvent *e) override;
    void dragon(); //representa a main()
    void generarDragon(QPainter *Canvas);


private:
    Ui::Dialog *ui;

    QTimer *timer1;
};
#endif // DIALOG_H
