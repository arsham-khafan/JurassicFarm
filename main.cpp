#include "widget.h"
#include "storage.h"
#include <QApplication>
#include "yonje.h"
#include "gandom.h"
#include "aval.h"
#include "mainwindow.h"
#include "gavdari.h"
#include "morghdari.h"
#include "aghol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    aval w;
    w.showFullScreen();
    return a.exec();
}
