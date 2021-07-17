#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"aval.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setMinimumHeight(768);
        this->setMinimumWidth(1366);
        this->setMaximumHeight(768);
        this->setMaximumWidth(1366);
    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/khali.jpeg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
    tm=new QTimer;
    tm->start();
    tm->setInterval(100);
    connect(tm,SIGNAL(timeout()),this,SLOT(opdatee()));
    pb=new QProgressBar;
    pb->setMaximum(101);
    pb->setValue(0);
    pb->setStyleSheet(  "background-color: #74c8ff;"
                           "color: #0a9dff;"
                           "border-style: outset;"
                           "border-width: 2px;"
                           "border-color: #74c8ff;"
                           "border-radius: 7px;"
                           "text-align: right;");
    pb->setFixedSize(600,30);
    pb->move(400,20);
    talk = new QLabel;
    QPixmap* temp = new QPixmap(":backgrounds/logo1.PNG");
    talk->setPixmap(temp->scaled(QSize(600,400)));
    talk->move(430,350);
    talk->setHidden(true);
    pb->setParent(this);
    talk->setParent(this);
}
void MainWindow::opdatee(){
    pb->setValue(pb->value()+1);
    if(pb->value()==50)
    {
       talk->setHidden(false);
    }
   if(pb->value()==100)
   {
       aval *av;
       av=new aval;
       av->showFullScreen();
     this->close();
   }
}
MainWindow::~MainWindow()
{
    delete ui;
}

