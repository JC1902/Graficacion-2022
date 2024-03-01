#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
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

private slots:


    void on_cButtonIniciar_clicked();

    void on_cButtonDetener_clicked();

    void on_cButtonCerrar_clicked();

    void moverEtiquetaH();

    void moverEtiquetaV();

    void on_verticalSlider_valueChanged(int value);

    void on_dial_sliderMoved(int position);

private:
    Ui::Dialog *ui;

    QTimer *timer1;
    QTimer *timer2;

    int velocidadDial;
    int velocidadBarra;
};
#endif // DIALOG_H
