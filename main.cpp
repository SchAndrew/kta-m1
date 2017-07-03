#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QCoreApplication::setApplicationName("kta-m1");
    QCoreApplication::setApplicationVersion("0.5");
    QCoreApplication::setOrganizationName("ADASTRA-M");
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
