#include "signupp.h"
#include <time.h>
#include "ui_signupp.h"
signupp::signupp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signupp)
{
    ui->setupUi(this);
    i=0;

    QFont f("Comic Sans MS");
        f.setPointSize(15);
        f.setBold(true);


    this->setMinimumHeight(768);
        this->setMinimumWidth(1366);
        this->setMaximumHeight(768);
        this->setMaximumWidth(1366);
    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/sighnup.jpeg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
    li1=new QLineEdit;
    li2=new QLineEdit;
    li3=new QLineEdit;
    li4=new QLineEdit;
    li5=new QLineEdit;
    li1->setFont(f);
    li2->setFont(f);
    li3->setFont(f);
    li4->setFont(f);
    li5->setFont(f);
    lb1=new QLabel("<b>FIRST NAME AND LAST NAME</b>");
    lb2=new QLabel("<b>USER NAME</b>");
    lb3=new QLabel("<b>PASSWORD</b>");
    lb4=new QLabel("<b>PASSWORD(repeat)</b>");
    lb5=new QLabel("<b>EMAIL ADDRESS(optional)</b>");
    lb1->setFont(f);
    lb2->setFont(f);
    lb3->setFont(f);
    lb4->setFont(f);
    lb5->setFont(f);
    pb1=new QPushButton;
    pb2=new QPushButton;
     li1->setFixedSize(350,50);
      li2->setFixedSize(350,50);
       li3->setFixedSize(350,50);
        li4->setFixedSize(350,50);
         li5->setFixedSize(350,50);
         li1->setHidden(true);
         li2->setHidden(true);
         li3->setHidden(true);
         li4->setHidden(true);
         li5->setHidden(true);
         lb1->setHidden(true);
         lb2->setHidden(true);
         lb3->setHidden(true);
         lb4->setHidden(true);
         lb5->setHidden(true);
         pb1->setHidden(true);
         pb2->setHidden(true);
         lb1->setStyleSheet("color:pink;" "font-size:17px;");
         lb2->setStyleSheet("color:pink;" "font-size:20px;");
         lb3->setStyleSheet("color:pink;" "font-size:20px;");
         lb4->setStyleSheet("color:pink;" "font-size:20px;");
         lb5->setStyleSheet("color:pink;" "font-size:20px;");
         li3->setEchoMode(QLineEdit::Password);
         li4->setEchoMode(QLineEdit::Password);
         lb1->move(400,110);
         lb2->move(400,210);
         lb3->move(400,310);
         lb4->move(400,410);
         lb5->move(400,510);
         li1->move(700,110);
         li2->move(700,210);
         li3->move(700,310);
         li4->move(700,410);
         li5->move(700,510);
         pb1->setToolTip("confirm information");
         pb2->setToolTip("back");
         li1->setStyleSheet("background-color:skyblue;""color:red;""font-size:20px");
         li2->setStyleSheet("background-color:skyblue;""color:red;""font-size:20px");
         li3->setStyleSheet("background-color:skyblue;""color:red;""font-size:20px");
         li4->setStyleSheet("background-color:skyblue;""color:red;""font-size:20px");
         li5->setStyleSheet("background-color:skyblue;""color:red;""font-size:20px");


         pb2->setMinimumHeight(90);
         pb2->setMinimumWidth(90);
         pb2->setMaximumHeight(90);
         pb2->setMaximumWidth(90);
         pb2->move(20, 40);
         pb2->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
     "                           QPushButton::hover{border-image:url(:icons/back22.png);} ");
         pb2->setToolTip("back to map");
            pb1->move(1250,20);
            pb1->setMinimumHeight(110);
            pb1->setMinimumWidth(110);
              pb1->setMaximumHeight(110);
              pb1->setMaximumWidth(110);
               pb1->setStyleSheet("QPushButton {border-image:url(:icons/save.jpg);border:2px;border-radius:40px;}""QPushButton::hover{border-image:url(:icons/saveee.jpg);} ");

          tm=new QTimer;
         tm->start();
         tm->setInterval(100);
         connect(pb1,SIGNAL(clicked()),this,SLOT(sett()));
         connect(pb2,SIGNAL(clicked()),this,SLOT(backk()));
         connect(tm,SIGNAL(timeout()),this,SLOT(opdatee()));
    li1->setParent(this);
    li2->setParent(this);
    li3->setParent(this);
    li4->setParent(this);
    li5->setParent(this);
    lb1->setParent(this);
    lb2->setParent(this);
    lb3->setParent(this);
    lb4->setParent(this);
    lb5->setParent(this);
    pb1->setParent(this);
    pb2->setParent(this);

}

void signupp::backk(){
    aval *av;
    av=new aval;
    av->showFullScreen();
  this->close();
}

void signupp::opdatee(){
    i++;
    if(i==20)
    {
        li1->setHidden(false);
        lb1->setHidden(false);

    }
    if(i==25)
    {
        li2->setHidden(false);
        lb2->setHidden(false);
    }
    if(i==30)
    {
        li3->setHidden(false);
        lb3->setHidden(false);
    }
    if(i==35)
    {
        li4->setHidden(false);
        lb4->setHidden(false);
    }
    if(i==40)
    {
        li5->setHidden(false);
        lb5->setHidden(false);
    }
    if(i==40)
    {
       pb1->setHidden(false);
       pb2->setHidden(false);
    }
}

void signupp::sett() {
    QFile f("Ap project.Json");
    f.open(QIODevice::ReadWrite);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject data, aq, gav, morq, An, sil, gandom, yonje;
    QJsonObject total = d.object();
    if((li1->text()=="")||(li2->text()=="")||(li3->text()=="")) {
        khata*ab=new khata(NULL,"Compulsory fields are empty");
        ab->show();
    }
    else if(li3->text()!=li4->text()){
        khata*ab=new khata(NULL,"Password and password repetition are not the same");
        ab->show();
    }
    else {
        QJsonObject::iterator  p = total.find(li2->text());
    if (p == total.end()) {
        data["password"] = li3->text();
        data["name"] = li1->text();
        data["username"] = li2->text();
        data["email"] = li5->text();
        data["coins"] = 20;
        data["experience"] = 0;
        data["capacity"] = 10;
        data["level"] = 1;

        QJsonArray milk;

        An["bil"] = 0;
        An["mikh"] = 1;
        An["yonje"] = 1;
        An["level"] = 1;
        An["count"] = 2;
        An["capacity"] = 5;
        An["egg"] = 0;             //level 2
        An["milk"] = milk;           //level 4
        An["pashm"] = 0;         //level 6
        An["time"] = -1;

        sil["capacity"] = 10;
        sil["count"] = 1;
        sil["level"] = 1;
        sil["time"] = -1;

        QJsonArray yon = {0,0,0,0} , gan = {0,0,0,0,0};
        gandom["area"] = gan;
        gandom["level_time"] = -1;
        gandom["time"] = -1;
        gandom["level"] = 1;
        gandom["isbuild"] = true;
        gandom["iskasht"] = false;
        gandom["isbardasht"] = true;

        yonje["area"] = yon;
        yonje["level_time"] = -1;
        yonje["level"] = 1;
        yonje["time"] = -1;
        yonje["isbuild"] = false;
        yonje["isshokhm"] = true;
        yonje["iskasht"] = false;
        yonje["isbardasht"] = true;

        aq["count"] = 0;
        aq["capacity"] = 2;
        aq["level"] = 1;
        aq["BeginAndLastFood"] = -1;
        aq["level_time"] = -1;
        aq["isfooded"] = false;
        aq["isexist"] = false;
        aq["isbuild"] = false;

        gav["count"] = 0;
        gav["capacity"] = 2;
        gav["level"] = 1;
        gav["BeginAndLastFood"] = -1;
        gav["level_time"] = -1;
        gav["isfooded"] = false;
        gav["isexist"] = false;
        gav["isbuild"] = false;

        morq["count"] = 0;
        morq["capacity"] = 2;
        morq["level"] = 1;
        morq["BeginAndLastFood"] = -1;
        morq["level_time"] = -1;
        morq["isfooded"] = false;
        morq["isexist"] = false;
        morq["isbuild"] = false;

        data["aqol"] = aq;
        data["gavdari"] = gav;
        data["morqdari"] = morq;
        data["anbar"] = An;
        data["silo"] = sil;
        data["gandomland"] = gandom;
        data["yonjeland"] = yonje;

        data["days"] = 0;
        data["time"] = 0;

        data["build_morq"] = -1;
        data["build_gav"] = -1;
        data["build_aqol"] = -1;
        data["build_yonje"] = -1;

        total[li2->text()] = data;

        qDebug() << total;
        f.close();
        f.open(QIODevice::WriteOnly);
        b = f.readAll();
        d = QJsonDocument::fromJson(b);
        d.setObject(total);
        f.write(d.toJson());
        aval *av;
        av=new aval;
        av->showFullScreen();
      this->close();
    }
    else{
        khata*ab=new khata(NULL,"A user with this username has already registered");
        ab->show();
    }
  }
  f.close();
}

signupp::~signupp()
{
    delete ui;
}
