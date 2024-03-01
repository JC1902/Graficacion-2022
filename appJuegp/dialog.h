#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void keyPressEvent(QKeyEvent *evento);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_cButBorrar_clicked();

    void on_botonSuma_clicked();

    void on_pushButton_10_clicked();

    void on_botonResta_clicked();

    void on_botonMulti_clicked();

    void on_botonDivdir_clicked();

    void on_Raiz_clicked();

    void on_Potencia_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
