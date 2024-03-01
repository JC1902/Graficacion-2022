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
    int maxX;
    int maxY;
    double escalaX, escalaY, despX, despY;

private slots:
    void on_pushButton_clicked();

    void extranioConfinador(QPainter *Canvas);
    void paintEvent(QPaintEvent *e) override;
    void henon();

private:
    Ui::Dialog *ui;

    QTimer *timer1;
};
#endif // DIALOG_H
