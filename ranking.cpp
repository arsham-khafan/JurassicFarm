#pragma once
#include "ranking.h"
#include <iostream>
#include <QMovie>
#include "ui_ranking.h"
using namespace std;

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
        sort[*val]=o["name"].toString();
    }


    QMovie* movie = new QMovie(":gifs/d2.gif");
    QLabel* label = new QLabel(this);
    if (!movie->isValid())
    {
        label->setText("mammad");
    }
    else{
        label->setMovie(movie);
        movie->start();
    }
    label->move(1000,10);
    label->setFixedSize(300,300);

    setStyleSheet("background-color: #FF007F");

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

            picture = new QLabel(this);
            picture->setToolTip("");
            QPixmap* temp = new QPixmap(":backgrounds/Rank2.jpg");
            picture->setPixmap(temp->scaled(QSize(450,450)));
            picture->move(950,300);

    ui->setupUi(this);
    Row* r = new Row;
    map<pair<int,int>,QString>::iterator  p = sort.begin();
    for(int i=1;p!=sort.end();p++,i++){
       pair<pair<int,int>,QString> value = *p;
       r->add(value.first.first,i,value.first.second,value.second,data->getName());
    }

    ui->scrollArea->setWidget(r);
}

void Ranking::map_menu(){
    Widget* temp = new Widget(nullptr, data);
    temp->showFullScreen();
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
    name->setFixedSize(120,60);
    level->setFixedSize(60,60);
    exp->setFixedSize(500,30);

    name->setAlignment(Qt::AlignCenter);
    level->setAlignment(Qt::AlignCenter);
    rank->setAlignment(Qt::AlignCenter);

    name->setStyleSheet("color: #00FFFF");
    level->setStyleSheet("color: #0000CC");

    if(rank_>3 && name_==gold)
        level->setStyleSheet("background-color: #FFFF00");
    if(name_==gold){
        name->setStyleSheet("background-color: #FFFF00");
        level->setStyleSheet("background-color: #FFFF00");
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
    main->addRow(h);
}
