#include <QApplication>
#include "aval.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    aval w;
    w.showFullScreen();
    return a.exec();
}
