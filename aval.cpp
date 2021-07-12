#include "aval.h"
#include "ui_aval.h"
//#include <Windows.h>
#include <thread>

void Time(Data* _data, Widget* w){
       //Sleep(1000);
        std::this_thread::sleep_for(1000ms);
       _data->AddTime(1);
       w->set();
       if(_data->getTime()>=3600)
           _data->setTime(0);
       Time(_data,w);

}

aval::aval(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aval)
{
    this->setMinimumHeight(768);
        this->setMinimumWidth(1366);
        this->setMaximumHeight(768);
        this->setMaximumWidth(1366);
    setAutoFillBackground(true);

    QPixmap pixmap=QPixmap(":backgrounds/aval.jpeg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
     lb1=new QLabel("User name");
    lb2=new QLabel("Password");
     lv1=new QLineEdit;
     lv2=new QLineEdit;
     lb1->setHidden(true);
     lb2->setHidden(true);
     lv1->setHidden(true);
     lv2->setHidden(true);
     lb1->move(400,200);
     lb2->move(400,300);
     lv1->move(700,210);
     lv2->move(700,310);
     lb1->setParent(this);
     lb2->setParent(this);
     lv1->setFixedSize(400,30);
      lv2->setFixedSize(400,30);
      lb1->setStyleSheet("color:blue;" "font-size:40px;");
      lv1->setStyleSheet("background-color:skyblue;");
      lv2->setStyleSheet("background-color:pink;");
       lb2->setStyleSheet("color:red;" "font-size:40px;");
     lv1->setParent(this);
     lv2->setParent(this);
    lg1=new QPushButton("Login");
    lg1->move(450,100);
    lg1->setFixedSize(500,60);
    lg1->setCursor(Qt::ClosedHandCursor);
    lg1->setParent(this);
    connect(lg1,SIGNAL(clicked()),this,SLOT(loginn()));
    lg2=new QPushButton("Sign up");
     connect(lg2,SIGNAL(clicked()),this,SLOT(signn()));
    lg2->move(450,200);
    lg2->setFixedSize(500,60);
    lg2->setCursor(Qt::ClosedHandCursor);
    lg2->setParent(this);
    lg3=new QPushButton("Exit");
    lg4=new QPushButton("check information");
    lg4->move(500,400);
    lg4->setStyleSheet("QPushButton{background-color:red;color:white;font-size:28px;border:0px;border-radius:40px;min-height:80px; min-width:80px}\QPushButton::hover{color:black;background-color:yellow}");
    lg4->setHidden(true);
    lg4->setFixedSize(600,80);
    lg4->setCursor(Qt::ClosedHandCursor);
    lg4->setParent(this);
     connect(lg4,SIGNAL(clicked()),this,SLOT(vorood()));
    lg1->setStyleSheet("QPushButton{background-color:black;color:white;font-size:28px;border:0px;border-radius:40px;min-height:80px; min-width:80px}\QPushButton::hover{color:black;background-color:white}");
    lg2->setStyleSheet("QPushButton{background-color:black;color:white;font-size:28px;border:0px;border-radius:40px;min-height:80px; min-width:80px}\QPushButton::hover{color:black;background-color:white}");
    lg3->setStyleSheet("QPushButton{background-color:black;color:white;font-size:28px;border:0px;border-radius:40px;min-height:80px; min-width:80px}\QPushButton::hover{color:black;background-color:white}");
    lg3->move(450,300);
    lg3->setFixedSize(500,60);
    lg3->setCursor(Qt::ClosedHandCursor);
    lg3->setParent(this);
    connect(lg3,SIGNAL(clicked()),this,SLOT(close()));
    ui->setupUi(this);


    go_back = new QPushButton(this);
    go_back->setMinimumHeight(90);
    go_back->setMinimumWidth(90);
    go_back->setMaximumHeight(90);
    go_back->setMaximumWidth(90);
    go_back->move(20, 40);
    go_back->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
"                           QPushButton::hover{border-image:url(:icons/back22.png);} ");
    go_back->setToolTip("back to map");
    go_back->setHidden(true);

    connect(go_back,SIGNAL(clicked()),this,SLOT(back()));

}

void aval::back(){
    lg1->setHidden(false);
    lg2->setHidden(false);
    lg3->setHidden(false);
    go_back->setHidden(true);
    lb1->setHidden(true);
    lb2->setHidden(true);
    lv1->setHidden(true);
    lv2->setHidden(true);
    lg4->setHidden(true);
}

void aval::loginn(){
    lg1->setHidden(true);
    lg2->setHidden(true);
    lg3->setHidden(true);
    go_back->setHidden(false);
    lb1->setHidden(false);
    lb2->setHidden(false);
    lv1->setHidden(false);
    lv2->setHidden(false);
    lg4->setHidden(false);
}

void aval::signn(){
signupp*a;
a=new signupp();
a->showFullScreen();
this->close();
}

void aval::vorood() {

    QFile f("Ap project.Json");
    if (!lv1->text().isEmpty() && !lv2->text().isEmpty()) {
        f.open(QIODevice::ReadWrite);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject total = d.object();
        QJsonObject::iterator  p = total.find(lv1->text());
        qDebug() << *p;
        if (p != total.end()) {
            QJsonObject o = p.value().toObject();
            if (o["password"].toString() == lv2->text()) {
               Data* _Data= new Data(o);
               Widget* temp=new Widget(nullptr, _Data);
               std::thread time(Time,_Data,temp);
                this->close();
                f.close();
                temp->showFullScreen();
            }
        }
        else{
            khata* abc=new khata(NULL,"User or Password is incorrect");
            abc->show();
        }
    }
    else
    {
        khata* abc=new khata(NULL,"Some fields are not filled out");
        abc->show();
    }
    f.close();
}

aval::~aval()
{
   delete ui;
}
