#pragma once
#include "ranking.h"
#include <iostream>
#include <QMovie>
#include "ui_ranking.h"
using namespace std;


void Time(Data* _data, Ranking* w){
        QThread::sleep(1);
       _data->AddTime(1);

       QString str;

       if(_data->getTime_build_aqol()>0)
                  _data->Add_build_aqol(-1);
              if(_data->getTime_build_aqol()==0){
                   _data->getAqol()->setBuild(true);
                   _data->set_build_aqol(-1);
                   str = "Aqol build Successfully\n";
                   _data->Add_message(str,1);
              }

              if(_data->getTime_build_gav()>0)
                  _data->Add_build_gav(-1);
              if(_data->getTime_build_gav()==0){
                  _data->set_build_gav(-1);
                  _data->getGav()->setBuild(true);
                  str = "Gavdari build Successfully\n";
                  _data->Add_message(str,1);
              }

              if(_data->getTime_build_morq()>0)
                  _data->Add_build_morq(-1);
              if(_data->getTime_build_morq()==0){
                  _data->getMorq()->setBuild(true);
                  _data->set_build_morq(-1);
                  str = "Morqdari build Successfully\n";
                  _data->Add_message(str,1);
              }

              if(_data->getTime_build_yonje()>0)
                  _data->Add_build_yonje(-1);
              if(_data->getTime_build_yonje()==0){
                  _data->set_build_yonje(-1);
                  _data->getYonjeLand()->setBuilds(true);
                  str = "Yonje land build Successfully\n";
                  _data->Add_message(str,7);
              }

              if(_data->getAqol()->get_Time()>0)
                  _data->getAqol()->Add_Time(-1);
              if(_data->getAqol()->get_Time()==0){
                  _data->getAqol()->UpLevel();
                  _data->getAqol()->set_Time(-1);
                  str = "Aqol SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getAqol()->getLevel())
                          + "\n New Area: " + QString::number(_data->getAqol()->getCapacity()) + "\n";
                  _data->Add_message(str,2);
              }

              if(_data->getAqol()->get_Time_food()>0)
                  _data->getAqol()->Add_Time_food(-1);
              if(_data->getAqol()->get_Time_food()==0){
                  _data->getAqol()->setExist(true);
                  _data->getAqol()->setFood(false);
                  _data->getAqol()->set_Time_food(-1);
                  str = "The sheep_osarus are ready to be bred\n";
                  _data->Add_message(str,2);
              }

              if(_data->getGav()->get_Time()>0)
                  _data->getGav()->Add_Time(-1);
              if(_data->getGav()->get_Time()==0){
                  _data->getGav()->UpLevel();
                  _data->getGav()->set_Time(-1);
                  str = "Gavdari SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getGav()->getLevel())
                                     + "\n New Area: " + QString::number(_data->getGav()->getCapacity()) + "\n";
                  _data->Add_message(str,3);
              }

              if(_data->getGav()->get_Time_food()>0)
                  _data->getGav()->Add_Time_food(-1);
              if(_data->getGav()->get_Time_food()==0){
                  _data->getGav()->setExist(true);
                  _data->getGav()->setFood(false);
                  _data->getGav()->set_Time_food(-1);
                  str = "The cow_osarus are ready to be bred\n";
                  _data->Add_message(str,3);
              }

              if(_data->getMorq()->get_Time()>0)
                  _data->getMorq()->Add_Time(-1);
              if(_data->getMorq()->get_Time()==0){
                  _data->getMorq()->UpLevel();
                  _data->getMorq()->set_Time(-1);
                  str = "Morqdari SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getMorq()->getLevel())
                                     + "\n New Area: " + QString::number(_data->getMorq()->getCapacity()) + "\n";
                  _data->Add_message(str,4);
              }

              if(_data->getMorq()->get_Time_food()>0)
                  _data->getMorq()->Add_Time_food(-1);
              if(_data->getMorq()->get_Time_food()==0){
                  _data->getMorq()->setExist(true);
                  _data->getMorq()->setFood(false);
                  _data->getMorq()->set_Time_food(-1);
                  str = "The hen_osarus are ready to be bred\n";
                  _data->Add_message(str,4);
              }

              if(_data->getAnbar()->get_time()>0)
                  _data->getAnbar()->AddTime(-1);
              if(_data->getAnbar()->get_time()==0){
                  _data->getAnbar()->UpLevel(2);
                  _data->getAnbar()->setTime(-1);
                  str = "STORAGE SUCCESSFULLY UPGRADED!\n Level: " + QString::fromLatin1(to_string(_data->getAnbar()->getLevel()))
                          + "\n New Capacity: " + QString::fromLatin1(to_string(_data->getAnbar()->getCapacity())) + "\n";
                  _data->Add_message(str,5);
              }

              if(_data->getsilo()->get_time()>0)
                  _data->getsilo()->AddTime(-1);
              if(_data->getsilo()->get_time()==0){
                  _data->getsilo()->UpLevel();
                  _data->getsilo()->setTime(-1);
                  str = "SILOO SUCCESSFULLY UPGRADED!\n Level: " + QString::fromLatin1(to_string(_data->getsilo()->getLevel()))
                          + "\n New Capacity: " + QString::fromLatin1(to_string(_data->getsilo()->getCapacity())) + "\n";
                  _data->Add_message(str,6);
              }

              if(_data->getGandomLand()->get_time()>0)
                  _data->getGandomLand()->Add_Time(-1);
              if(_data->getGandomLand()->get_time()==0){
                  _data->getGandomLand()->UpLevel();
                  _data->getGandomLand()->setTime(-1);
                  str = "Gandom land Level up Successfully\n";
                  _data->Add_message(str,7);
              }


              if(_data->getGandomLand()->get_time_work()>0)
                  _data->getGandomLand()->Add_Time_work(-1);
              if(_data->getGandomLand()->get_time_work()==0){
                  _data->getGandomLand()->setKesht(false);
                  _data->getGandomLand()->setTime_work(-1);
                  str = "Gandom Land is Ready to Bardasht!!!!\n";
                  _data->Add_message(str,7);
                  _data->done(1);
              }

              if(_data->getYonjeLand()->get_time()>0)
                  _data->getYonjeLand()->Add_Time(-1);
              if(_data->getYonjeLand()->get_time()==0){
                  _data->getYonjeLand()->UpLevel();
                  _data->getYonjeLand()->setTime(-1);
                  str = "Yonje Land SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getYonjeLand()->getLevel())
                          + "\n New Area: " + QString::number(_data->getYonjeLand()->getArea()) + "\n";
                  _data->Add_message(str,8);
              }

              if(_data->getYonjeLand()->get_time_work()>0)
                         _data->getYonjeLand()->Add_Time_work(-1);
                     if(_data->getYonjeLand()->get_time_work()==0){
                         _data->getYonjeLand()->setTime_work(-1);
                         if(_data->getYonjeLand()->isShokhm()){
                             str = "Yonje land was successfully plowed\n";
                             _data->getYonjeLand()->setShokhm(false);
                             _data->Add_message(str,8);
                             _data->shokhm();
                         }
                         else{
                             _data->getYonjeLand()->setKesht(false);
                             _data->getYonjeLand()->setBardasht(false);
                             str = "Yonje was successfully cultivated\n";
                             _data->Add_message(str,8);
                             _data->done(2);
                         }
                     }

    if(_data->getTime()>=60){
        _data->nextDay(2);
        _data->setTime(0);
        str = "1 day passed! we are in Tomorrow!!";
        _data->Add_message(str,0);
    }

    return Time(_data,w);
}

Ranking::Ranking(QWidget *parent ,Data* _data) :
    QWidget(parent),
    ui(new Ui::Ranking)
{
    data = _data;

    QFile f("Ap project.Json");
    f.open(QIODevice::ReadWrite);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject total = d.object();
    QJsonObject o;
    for(QJsonObject::iterator  p = total.begin();p!=total.end();p++){
        o = p.value().toObject();
        pair<int,int>* val = new pair<int,int>(o["level"].toInt(),o["experience"].toInt());
        pair<pair<int,int>,QString>* v = new pair<pair<int,int>,QString>(*val,o["name"].toString());
        sort.insert(*v);
    }



    this->setMinimumHeight(768);
        this->setMinimumWidth(1366);
        this->setMaximumHeight(768);
        this->setMaximumWidth(1366);
    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/Rank.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

        go_back = new QPushButton(this);
        go_back->setMinimumHeight(90);
        go_back->setMinimumWidth(90);
        go_back->setMaximumHeight(90);
        go_back->setMaximumWidth(90);
        go_back->move(20, 40);
        go_back->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
    "                           QPushButton::hover{border-image:url(:icons/back22.png);} ");
        go_back->setToolTip("back to map");

        connect(go_back, SIGNAL(clicked()), this , SLOT(map_menu()));

    ui->setupUi(this);

    Row* r = new Row;
    multimap<pair<int,int>,QString>::iterator  p = sort.begin();
    for(int i=sort.size();p!=sort.end();p++,i--){
       pair<pair<int,int>,QString> value = *p;
       r->add(value.first.first,i,value.first.second,value.second,data->getName());
    }

    ui->scrollArea->setWidget(r);

    t = QThread::create(Time,data,this);
        t->start();
}

void Ranking::map_menu(){
    Widget* temp = new Widget(nullptr, data);
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}

Ranking::~Ranking()
{
    delete ui;
}

Row::Row(){
    main = new QFormLayout;
    main->setSpacing(46);
    setLayout(main);
}

void Row::add(int level_, int rank_, int exp_, QString name_, QString gold){
    rank = new QLabel;
    h = new QHBoxLayout;
    name = new QLabel(name_);
    exp = new QProgressBar;
    level = new QLabel("level: " + QString::fromLatin1(to_string(level_)));

    rank->setFixedSize(50,60);
    name->setFixedSize(160,60);
    level->setFixedSize(60,60);
    exp->setFixedSize(450,30);

    name->setAlignment(Qt::AlignCenter);
    level->setAlignment(Qt::AlignCenter);
    rank->setAlignment(Qt::AlignCenter);

    name->setStyleSheet("color: #C609CD");
    level->setStyleSheet("color: #C609CD");

    if(rank_>3 && name_==gold)
        rank->setStyleSheet("background-color: #E8CA09");
    if(name_==gold){
        name->setStyleSheet("color: #E8CA09");
        level->setStyleSheet("color: #E8CA09");
    }

    QFont fo,g;
    fo.setBold(true);
    fo.setPointSize(13);
    g.setBold(true);
    g.setPointSize(20);

    name->setFont(fo);
    level->setFont(fo);
    rank->setFont(g);

    if(rank_ == 1){
        rank->setToolTip("1");
        QPixmap* temp = new QPixmap(":icons/1.ico");
        rank->setPixmap(temp->scaled(QSize(40,40)));
        rank->move(20,20);
    }
    else if(rank_==2){
        rank->setToolTip("2");
        QPixmap* temp = new QPixmap(":icons/2.ico");
        rank->setPixmap(temp->scaled(QSize(40,40)));
        rank->move(20,20);
    }
    else if(rank_==3){
        rank->setToolTip("3");
        QPixmap* temp = new QPixmap(":icons/3.ico");
        rank->setPixmap(temp->scaled(QSize(40,40)));
        rank->move(20,20);
    }
    else
        rank->setText(QString::fromLatin1(to_string(rank_)));
    exp->setMaximum(100);
    exp->setMinimum(0);
    exp->setValue(exp_);
    exp->setStyleSheet("QProgressBar {"
                              "background-color: #EEC677;"
                              "color: #FFFFFF;"
                              "border-style: outset;"
                              "border-width: 2px;"
                              "border-color: #176C5B;"
                              "border-radius: 7px;"
                              "text-align: left; }"

                              "QProgressBar::chunk {"
                              "background-color: #176C5B; }");
    h->setSpacing(10);
    h->addWidget(rank);
    h->addWidget(level);
    h->addWidget(name);
    h->addWidget(exp);
    main->insertRow(0,h);
}
