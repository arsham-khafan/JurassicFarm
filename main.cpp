#include "widget.h"
#include "storage.h"
#include <QApplication>
#include "yonje.h"
#include "gandom.h"
#include "aval.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
