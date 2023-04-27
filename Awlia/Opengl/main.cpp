#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // start the Mainwindow
    MainWindow w;
    w.show();

    return a.exec();
}
