#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QImage editRGB(const QImage &in);
    QImage editBGR(const QImage &in);
private slots:
    void on_Rojo_valueChanged(int value);

    void on_pushButton_clicked();

    void on_Verde_valueChanged(int value);

    void on_Azul_valueChanged(int value);

    void on_RGB_valueChanged(int value);


    void on_pushButton_2_clicked();

    void on_cButtonInvertido_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;

    int cantRojo;
    int cantVerde;
    int cantAzul;
    int cantRGB;
};
#endif // DIALOG_H
