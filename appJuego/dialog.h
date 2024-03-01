#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class QMediaPlayer;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_cButtonAbrir_clicked();

    void on_cButtonPlay_clicked();

    void on_cButtonPausa_clicked();

    void on_cButtonStop_clicked();

    void on_cButtonMute_clicked();

    void on_cButtonMute_2_clicked();

    void on_cHSliderVolumen_valueChanged(int value);

    void moverUsuario();
    void moverProyectil();

    void moverEnemigo();
    void moverEnemigo2();
    void moverEnemigo3();

    void disparar();

    void moverAliado();

    void on_pushButton_clicked();

    void on_cButtonDisp_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QMediaPlayer *mediaPlayer;

    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;

    int vidas = 3;
    int aux = 0;
};
#endif // DIALOG_H
