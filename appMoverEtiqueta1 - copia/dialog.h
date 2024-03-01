#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <string>

using namespace :: std;

//int x = 0;

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

    string Invertir(string );

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void moverEtiquetaH();

    void moverEtiquetaV();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_dial_sliderMoved(int position);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Dialog *ui;

    QTimer *timer1;
    QTimer *timer2;

    int velocidadDial;

    int velocidadBarra;

    int velocidadSpin;
};
#endif // DIALOG_H
