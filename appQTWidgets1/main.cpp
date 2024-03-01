//#include <QCoreApplication>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget ventana;
    QVBoxLayout *mainLayout = new QVBoxLayout(&ventana);
    //QHBoxLayout *mainLayout = new QHBoxLayout(&ventana);

    QLabel *label1 = new QLabel("<h1><i> ETIQUETA 1, PRACTICANDO CON </i>""<font color = #ff00ff>QT</font></h1>");

    label1 -> setFrameStyle(QFrame::Panel  | QFrame::Raised);

    QLabel *label2 = new QLabel("<h2><i>Tec</i>" "<font color = blue> Laguna</font></h2>");
    QLabel *label3 = new QLabel("Torreon");

    label2->setAlignment(Qt::AlignBottom | Qt::AlignCenter);

    mainLayout->addWidget(label1);
    mainLayout->addWidget(label2);
    mainLayout->addWidget(label3);

    ventana.resize(300,300);
    ventana.show();

    return a.exec();
}
