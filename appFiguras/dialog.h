#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QPainter>
#include <QPainterPath>

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
    void on_cButtonInicio_clicked();

    void on_cButtonPausa_clicked();

    void on_cButtonSalir_clicked();

private:
    Ui::Dialog *ui;

    QTimer *timer1;

    void paintEvent(QPaintEvent *evt);

    void figurasGeometricas();
};
#endif // DIALOG_H
