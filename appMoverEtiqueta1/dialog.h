#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

//int x = 0;

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void moverEtiquetaH();

    void moverEtiquetaV();
    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;

    QTimer *timer1;

    QTimer *timer2;
};
#endif // DIALOG_H