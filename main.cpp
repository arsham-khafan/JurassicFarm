#include <QApplication>
#include "aval.h"
#include "mainwindow.h"
#include"signupp.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
