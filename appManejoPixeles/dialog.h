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
    QImage rotarRGB(const QImage &in);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

    int red;
    int green;
    int blue;
};
#endif // DIALOG_H
