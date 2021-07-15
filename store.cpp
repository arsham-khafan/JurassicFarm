#include "store.h"
#include <iostream>
#include <QMovie>
#include "ui_store.h"
using namespace std;

store::store(QWidget *parent, Data* _data) :
    QWidget(parent),
    ui(new Ui::store)
{
    data=_data;
    i=0;
    counter = 0;
    milk = new QPushButton(this);
    cow= new QPushButton(this);
    hen = new QPushButton(this);
    sheep = new QPushButton(this);
    egg = new QPushButton(this);
    pashm = new QPushButton(this);
    gandom = new QPushButton(this);
    yonje = new QPushButton(this);
    bil = new QPushButton(this);
    mikh = new QPushButton(this);


    milk->setStyleSheet("QPushButton {border-image:url(:icons/milk_.png);}"
"                           QPushButton::hover{border-image:url(:icons/milk_2.png);} ");

    cow->setStyleSheet("QPushButton {border-image:url(:icons/cow_osaurus.jpg);}"
"                           QPushButton::hover{border-image:url(:icons/cow_osaurus2.jpg);} ");

    hen->setStyleSheet("QPushButton {border-image:url(:icons/Hen_osaurus.png);}"
"                           QPushButton::hover{border-image:url(:icons/Hen _osaurus2.png);} ");

    sheep->setStyleSheet("QPushButton {border-image:url(:icons/Sheep_osaurus.png);}"
"                           QPushButton::hover{border-image:url(:icons/Sheep_osaurus2.png);} ");

    egg->setStyleSheet("QPushButton {border-image:url(:icons/egg_.png);}"
"                           QPushButton::hover{border-image:url(:icons/egg_2.png);} ");

    pashm->setStyleSheet("QPushButton {border-image:url(:icons/Pashm.png);}"
"                           QPushButton::hover{border-image:url(:icons/Pashm2.png);} ");

    bil->setStyleSheet("QPushButton {border-image:url(:icons/Bill.png);}"
"                           QPushButton::hover{border-image:url(:icons/Bill2.png);} ");

    mikh->setStyleSheet("QPushButton {border-image:url(:icons/Mikh.png);}"
"                           QPushButton::hover{border-image:url(:icons/Mikh2.png);} ");

    gandom->setStyleSheet("QPushButton {border-image:url(:icons/gandom.png);}"
"                           QPushButton::hover{border-image:url(:icons/gandom2.png);} ");

    yonje->setStyleSheet("QPushButton {border-image:url(:icons/Yon.png);}"
"                           QPushButton::hover{border-image:url(:icons/Yon2.png);} ");

    coins = new QLabel(this);
    coins->setMinimumHeight(200);
    coins->setMinimumWidth(200);
    coins->setMaximumHeight(200);
    coins->setMaximumWidth(200);
    coins->move(900, 55);
    coins->setHidden(true);
    coins->setStyleSheet("QLabel {border-image:url(:icons/coins_.png);}");

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

    milk->setMinimumHeight(90);
        milk->setMinimumWidth(90);
        milk->setMaximumHeight(90);
        milk->setMaximumWidth(90);
        milk->move(180, 460);
        milk->setToolTip("Milk: "+QString::fromLatin1(to_string(data->getAnbar()->getMilk())));
        milk->setHidden(true);


        cow->setMinimumHeight(90);
        cow->setMinimumWidth(90);
        cow->setMaximumHeight(90);
        cow->setMaximumWidth(90);
        cow->move(550, 460);
        cow->setToolTip("cow_osaurus: "+QString::fromLatin1(to_string(data->getGav()->getCount())));
        cow->setHidden(true);

        egg->setMinimumHeight(90);
        egg->setMinimumWidth(90);
        egg->setMaximumHeight(90);
        egg->setMaximumWidth(90);
        egg->move(180, 340);
        egg->setToolTip("egg: "+QString::fromLatin1(to_string(data->getAnbar()->getEgg())));
        egg->setHidden(true);

        hen->setMinimumHeight(90);
        hen->setMinimumWidth(90);
        hen->setMaximumHeight(90);
        hen->setMaximumWidth(90);
        hen->move(550, 340);
        hen->setToolTip("Hen_osaurus: "+QString::fromLatin1(to_string(data->getMorq()->getCount())));
        hen->setHidden(true);

        pashm->setMinimumHeight(90);
        pashm->setMinimumWidth(90);
        pashm->setMaximumHeight(90);
        pashm->setMaximumWidth(90);
        pashm->move(180, 600);
        pashm->setToolTip("Pashm: "+QString::fromLatin1(to_string(data->getAnbar()->getPashm())));
        pashm->setHidden(true);

        sheep->setMinimumHeight(90);
        sheep->setMinimumWidth(90);
        sheep->setMaximumHeight(90);
        sheep->setMaximumWidth(90);
        sheep->move(550, 600);
        sheep->setToolTip("Sheep_osaurus: "+QString::fromLatin1(to_string(data->getAqol()->getCount())));
        sheep->setHidden(true);

        gandom->setMinimumHeight(90);
        gandom->setMinimumWidth(90);
        gandom->setMaximumHeight(90);
        gandom->setMaximumWidth(90);
        gandom->move(180, 200);
        gandom->setToolTip("Gandom: "+QString::fromLatin1(to_string(data->getsilo()->getCount())));
        gandom->setHidden(true);

        yonje->setMinimumHeight(90);
        yonje->setMinimumWidth(90);
        yonje->setMaximumHeight(90);
        yonje->setMaximumWidth(90);
        yonje->move(550, 200);
        yonje->setToolTip("Yonje: "+QString::fromLatin1(to_string(data->getAnbar()->getYonje())));
        yonje->setHidden(true);

        bil->setMinimumHeight(90);
        bil->setMinimumWidth(90);
        bil->setMaximumHeight(90);
        bil->setMaximumWidth(90);
        bil->move(180, 40);
        bil->setToolTip("Bill: "+QString::fromLatin1(to_string(data->getAnbar()->getBil())));
        bil->setHidden(true);

        mikh->setMinimumHeight(90);
        mikh->setMinimumWidth(90);
        mikh->setMaximumHeight(90);
        mikh->setMaximumWidth(90);
        mikh->move(550, 40);
        mikh->setToolTip("Mikh: "+QString::fromLatin1(to_string(data->getAnbar()->getMikh())));
        mikh->setHidden(true);

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);
    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/store.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    ui->setupUi(this);
    ui->gandom->move(155,270);
    ui->bill->move(155,110);
    ui->yonje->move(520,270);
    ui->mikh->move(510,110);
    ui->egg->move(155,400);
    ui->hen->move(520,400);
    ui->milk->move(155,520);
    ui->cow->move(525,520);
    ui->pashm->move(155,670);
    ui->sheep->move(525,670);

    ui->egg->setHidden(true);
        ui->milk->setHidden(true);
        ui->hen->setHidden(true);
        ui->cow->setHidden(true);
        ui->pashm->setHidden(true);
        ui->sheep->setHidden(true);
        ui->gandom->setHidden(true);
        ui->yonje->setHidden(true);
        ui->bill->setHidden(true);
        ui->mikh->setHidden(true);

        ui->egg->setFixedSize(ui->hen->size());
        ui->pashm->setFixedSize(ui->hen->size());
        ui->milk->setFixedSize(ui->hen->size());
        ui->yonje->setFixedSize(ui->hen->size());

    connect(go_back,SIGNAL(clicked()),this,SLOT(map_menu()));
    connect(milk,SIGNAL(clicked()),this,SLOT(milk_()));
    connect(egg,SIGNAL(clicked()),this,SLOT(egg_()));
    connect(cow,SIGNAL(clicked()),this,SLOT(cow_()));
    connect(hen,SIGNAL(clicked()),this,SLOT(hen_()));
    connect(sheep,SIGNAL(clicked()),this,SLOT(sheep_()));
    connect(pashm,SIGNAL(clicked()),this,SLOT(pashm_()));
    connect(bil,SIGNAL(clicked()),this,SLOT(bill_()));
    connect(mikh,SIGNAL(clicked()),this,SLOT(mikh_()));
    connect(yonje,SIGNAL(clicked()),this,SLOT(yonje_()));
    connect(gandom,SIGNAL(clicked()),this,SLOT(gandom_()));

    ui->buy->setHidden(true);
    ui->sell->setHidden(true);
    ui->label->setHidden(true);
    ui->number->setHidden(true);

    tm=new QTimer;
    tm->start();
    tm->setInterval(3000);
    connect(tm,SIGNAL(timeout()),this,SLOT(show2()));

    ui->number->setGeometry(860,380,90,50);
    ui->sell->setGeometry(970,390,100,30);
    ui->buy->setGeometry(1080,390,100,30);
    ui->label->setGeometry(970,500,150,100);

    ui->co->setText("X" +QString::fromLatin1(to_string(data->getCoin())));
    ui->co->move(1100,120);
    ui->co->setHidden(true);

}

void store::show2(){
    QPixmap pixmap=QPixmap(":backgrounds/store2.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
    if(counter==0){
        tm1=new QTimer;
        tm1->start();
        tm1->setInterval(500);
        connect(tm1,SIGNAL(timeout()),this,SLOT(show3()));
    }

    movie = new QMovie(":gifs/d1.gif");
    label = new QLabel(this);
    label->move(30,600);
    if (!movie->isValid())
        {
            label->setText("mammad");
        }
        else{
            label->setMovie(movie);
            movie->start();
        }
}

void store::show3(){
    QFont f = ui->mikh->font();
    f.setPointSize(14);
    counter++;
    if(counter==4){
        if(!data->getGav()->isBuild()){
            milk->setStyleSheet("QPushButton {border-image:url(:icons/milk_3.png);}");
            cow->setStyleSheet("QPushButton {border-image:url(:icons/cow_osaurus3.jpg);}");
            ui->milk->setFont(f);
            ui->milk->setStyleSheet("color: #00FFFF");
            ui->cow->setFont(f);
            ui->cow->setStyleSheet("color: #00FFFF");
            if(data->getLevel()<4){
                ui->milk->setText("Locked(Level 4)");
                ui->cow->setText("Locked(Level 4)");
            }
            else{
                ui->milk->setText("Locked(Not Build)");
                ui->cow->setText("Locked(Not Build)");
            }
            milk->setEnabled(false);
            cow->setEnabled(false);
        }
        milk->setHidden(false);
        cow->setHidden(false);
        ui->milk->setHidden(false);
        ui->cow->setHidden(false);
    }
    else if(counter==3){
        if(!data->getMorq()->isBuild()){
            egg->setStyleSheet("QPushButton {border-image:url(:icons/egg_3.png);}");
            hen->setStyleSheet("QPushButton {border-image:url(:icons/Hen _osaurus3.png);}");
            ui->egg->setFont(f);
            ui->egg->setStyleSheet("color: #00FFFF");
            ui->hen->setFont(f);
            ui->hen->setStyleSheet("color: #00FFFF");
            if(data->getLevel()<2){
                ui->egg->setText("Locked(Level 2)");
                ui->hen->setText("Locked(Level 2)");
            }
            else{
                ui->egg->setText("Locked(Not Build)");
                ui->hen->setText("Locked(Not Build)");
            }
            egg->setEnabled(false);
            hen->setEnabled(false);
        }
        egg->setHidden(false);
        hen->setHidden(false);
        ui->egg->setHidden(false);
        ui->hen->setHidden(false);
    }
    else if(counter==5){
        if(!data->getGav()->isBuild()){
            pashm->setStyleSheet("QPushButton {border-image:url(:icons/Pashm3.png);}");
            sheep->setStyleSheet("QPushButton {border-image:url(:icons/Sheep_osaurus3.png);}");
            ui->pashm->setFont(f);
            ui->pashm->setStyleSheet("color: #00FFFF");
            ui->sheep->setFont(f);
            ui->sheep->setStyleSheet("color: #00FFFF");
            if(data->getLevel()<6){
                ui->pashm->setText("Locked(Level 6)");
                ui->sheep->setText("Locked(Level 6)");
            }
            else{
                ui->pashm->setText("Locked(Not Build)");
                ui->sheep->setText("Locked(Not Build)");
            }
            pashm->setEnabled(false);
            sheep->setEnabled(false);
        }
        pashm->setHidden(false);
        sheep->setHidden(false);
        ui->pashm->setHidden(false);
        ui->sheep->setHidden(false);
    }
    else if(counter==2){
        if(!data->getGav()->isBuild()){
            yonje->setStyleSheet("QPushButton {border-image:url(:icons/Yon3.png);}");
            ui->yonje->setFont(f);
            ui->yonje->setStyleSheet("color: #00FFFF");
            if(data->getLevel()<3)
                ui->yonje->setText("Locked(Level 3)");
            else
                ui->yonje->setText("Locked(Not Build)");
            yonje->setEnabled(false);
        }
        gandom->setHidden(false);
        yonje->setHidden(false);
        ui->gandom->setHidden(false);
        ui->yonje->setHidden(false);
    }
    else if(counter==1){
        bil->setHidden(false);
        mikh->setHidden(false);
        ui->bill->setHidden(false);
        ui->mikh->setHidden(false);
    }
    else if(counter==6){
        go_back->setHidden(false);
        ui->co->setHidden(false);
        coins->setHidden(false);
    }
}

void store::check_buy(){
    QString str;
    if(!ui->number->text().isEmpty()){
        int num = ui->number->value();
        if(i==1){
            if(num<=data->getAnbar()->getSpace()){
               for(int j=0; j < num ; data->AddMilk(), j++);
               str = QString::fromLatin1(to_string(num))+" Milk Successfully purchased";
               data->addExp(num*5);
            }
            else{
                for(int j=0;j < data->getAnbar()->getSpace();data->AddMilk(),j++);
                str = QString::fromLatin1(to_string(data->getAnbar()->getSpace()))+" Milk Successfully purchased\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getSpace())) +
                        " Milk No enough Space";
                data->addExp(data->getAnbar()->getSpace()*5);
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getMilk())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==2){
            if(num<=data->getGav()->getSpace()){
                if(data->getCoin()>=num*70){
                    data->getGav()->operator+=(num);
                    str = QString::fromLatin1(to_string(num))+" cow-osarus Successfully purchased";
                    data->addExp(num*10);
                }
                else{
                    QString s= "  Required: " + QString::fromLatin1(to_string(num*70)),k="No enough coins\n Mojoodi: "
                    +QString::fromLatin1(to_string(data->getCoin()));
                    str = k  + s;
                }
                ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getGav()->getCount())) + "\n\nSpace: "+
                                   QString::fromLatin1(to_string(data->getGav()->getSpace())));
            }
            else{
                if(data->getCoin()>=data->getGav()->getSpace()*70){
                    data->getGav()->operator+=(data->getGav()->getSpace());
                    str = QString::fromLatin1(to_string(data->getGav()->getSpace()))+" cow-osarus Successfully purchased\n"+
                            QString::fromLatin1(to_string(num-data->getGav()->getSpace())) +
                            " cow-osarus No enough Space";
                    data->addExp(data->getGav()->getSpace()*10);
                }
                else{
                    QString s= "  Required: " + QString::fromLatin1(to_string(num*70)),k="No enough coins\n Mojoodi: "
                    +QString::fromLatin1(to_string(data->getCoin()));
                    str = k  + s;
                }
            }
        }
        else if(i==3){
            if(num<=data->getAnbar()->getSpace()){
               data->getAnbar()->ChangeEgg(num);
               str = QString::fromLatin1(to_string(num))+" Egg(s) Successfully purchased";
               data->addExp(num*3);
            }
            else{
                data->getAnbar()->ChangeEgg(data->getAnbar()->getSpace());
                str = QString::fromLatin1(to_string(data->getAnbar()->getSpace()))+" Egg(s) Successfully purchased\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getSpace())) +
                        " Milk No enough Space";
                data->addExp(data->getAnbar()->getSpace()*3);
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getEgg())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==4){
            if(num<=data->getMorq()->getSpace()){
                if(data->getCoin()>=num*20){
                    data->getMorq()->operator+=(num);
                    str = QString::fromLatin1(to_string(num))+" hen-osarus Successfully purchased";
                    data->addExp(num*5);
                }
                else{
                    QString s= "  Required: " + QString::fromLatin1(to_string(num*20)),k="No enough coins\n Mojoodi: "
                    +QString::fromLatin1(to_string(data->getCoin()));
                    str = k  + s;
                }
                ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getMorq()->getCount())) + "\n\nSpace: "+
                                   QString::fromLatin1(to_string(data->getMorq()->getSpace())));
            }
            else{
                if(data->getCoin()>=data->getMorq()->getSpace()*20){
                    data->getMorq()->operator+=(data->getMorq()->getSpace());
                    str = QString::fromLatin1(to_string(data->getMorq()->getSpace()))+" hen-osarus Successfully purchased\n"+
                            QString::fromLatin1(to_string(num-data->getMorq()->getSpace())) +
                            " cow-osarus No enough Space";
                    data->addExp(data->getMorq()->getSpace()*5);
                }
                else{
                    QString s= "  Required: " + QString::fromLatin1(to_string(num*20)),k="No enough coins\n Mojoodi: "
                    +QString::fromLatin1(to_string(data->getCoin()));
                    str = k  + s;
                }
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getMorq()->getCount())) + "\n\nSpace: "+
                                       QString::fromLatin1(to_string(data->getMorq()->getSpace())));
        }
        else if(i==5){
            if(num<=data->getAnbar()->getSpace()){
               data->getAnbar()->ChangePashm(num);
               str = QString::fromLatin1(to_string(num))+" Pashm(s) Successfully purchased";
               data->addExp(num*10);
            }
            else{
                data->getAnbar()->ChangePashm(data->getAnbar()->getSpace());
                str = QString::fromLatin1(to_string(data->getAnbar()->getSpace()))+" Pashm(s) Successfully purchased\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getSpace())) +
                        " Milk No enough Space";
                data->addExp(data->getAnbar()->getSpace()*10);
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getPashm())) + "\n\nSpace: "+
                                       QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==6){
            if(num<=data->getAqol()->getSpace()){
                if(data->getCoin()>=num*80){
                    data->getAqol()->operator+=(num);
                    str = QString::fromLatin1(to_string(num))+" Sheep-osarus Successfully purchased";
                    data->addExp(num*15);
                }
                else{
                    QString s= "  Required: " + QString::fromLatin1(to_string(num*80)),k="No enough coins\n Mojoodi: "
                    +QString::fromLatin1(to_string(data->getCoin()));
                    str = k  + s;
                }
            }
            else{
                if(data->getCoin()>=data->getAqol()->getSpace()*80){
                    data->getAqol()->operator+=(data->getAqol()->getSpace());
                    str = QString::fromLatin1(to_string(data->getAqol()->getSpace()))+" Sheep-osarus Successfully purchased\n"+
                            QString::fromLatin1(to_string(num-data->getAqol()->getSpace())) +
                            " cow-osarus No enough Space";
                    data->addExp(data->getAqol()->getSpace()*15);
                }
                else{
                    QString s= "  Required: " + QString::fromLatin1(to_string(num*80)),k="No enough coins\n Mojoodi: "
                    +QString::fromLatin1(to_string(data->getCoin()));
                    str = k  + s;
                }
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAqol()->getCount())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAqol()->getSpace())));
        }
        else if(i==7){
            if(num<=data->getsilo()->getSpace()){
                           if(data->getCoin()>=num*3){
                               data->getsilo()->operator+=(num);
                               str = QString::fromLatin1(to_string(num))+" gandom Successfully purchased";
                               data->addExp(num);
                           }
                           else{
                               QString s= "  Required: " + QString::fromLatin1(to_string(num*3)),k="No enough coins\n Mojoodi: "
                               +QString::fromLatin1(to_string(data->getCoin()));
                               str = k  + s;
                           }
                       }
                       else{
                           if(data->getCoin()>=data->getsilo()->getSpace()*3){
                               data->getsilo()->operator+=(data->getsilo()->getSpace());
                               str = QString::fromLatin1(to_string(data->getsilo()->getSpace()))+" gandom Successfully purchased\n"+
                                       QString::fromLatin1(to_string(num-data->getsilo()->getSpace())) +
                                       " cow-osarus No enough Space";
                               data->addExp(data->getsilo()->getSpace());
                           }
                           else{
                               QString s= "  Required: " + QString::fromLatin1(to_string(num)),k="No enough coins\n Mojoodi: "
                               +QString::fromLatin1(to_string(data->getCoin()));
                               str = k  + s;
                           }
                       }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getsilo()->getCount())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getsilo()->getSpace())));
        }
        else if(i==8){
            if(num<=data->getAnbar()->getSpace()){
                           if(data->getCoin()>=num*6){
                               data->getAnbar()->ChangeYonje(num);
                               str = QString::fromLatin1(to_string(num))+" Yonje Successfully purchased";
                               data->addExp(num*2);
                           }
                           else{
                               QString s= "  Required: " + QString::fromLatin1(to_string(num*6)),k="No enough coins\n Mojoodi: "
                               +QString::fromLatin1(to_string(data->getCoin()));
                               str = k  + s;
                           }
                       }
                       else{
                           if(data->getCoin()>=data->getAnbar()->getSpace()*6){
                               data->getAnbar()->ChangeYonje(data->getAnbar()->getSpace());
                               str = QString::fromLatin1(to_string(data->getAnbar()->getSpace()))+" Yonje Successfully purchased\n"+
                                       QString::fromLatin1(to_string(num-data->getAnbar()->getSpace())) +
                                       " cow-osarus No enough Space";
                               data->addExp(data->getAnbar()->getSpace()*2);
                           }
                           else{
                               QString s= "  Required: " + QString::fromLatin1(to_string(num*6)),
                                       k="No enough coins\n Mojoodi: "+QString::fromLatin1(to_string(data->getCoin()));
                               str = k  + s;
                           }
                       }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getYonje())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==9){
            if(num<=data->getAnbar()->getSpace()){
            if(data->getCoin()>=num*50){
                data->getAnbar()->ChangeBil(num);
                str = QString::fromLatin1(to_string(num))+" Bill Successfully purchased";
                data->addExp(num*8);
            }
            else{
                QString s= "  Required: " + QString::fromLatin1(to_string(num*50)),k="No enough coins\n Mojoodi: "
                +QString::fromLatin1(to_string(data->getCoin()));
                str = k  + s;
            }
        }
        else{
            if(data->getCoin()>=data->getAnbar()->getSpace()*50){
                data->getAnbar()->ChangeBil(data->getAnbar()->getSpace());
                str = QString::fromLatin1(to_string(data->getAnbar()->getSpace()))+" Bill Successfully purchased\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getSpace())) +
                        " cow-osarus No enough Space";
                data->addExp(data->getAnbar()->getSpace()*8);
            }
            else{
                QString s= "  Required: " + QString::fromLatin1(to_string(num*50)),
                        k="No enough coins\n Mojoodi: "+QString::fromLatin1(to_string(data->getCoin()));
                str = k  + s;
            }
        }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getBil())) + "\n\nSpace: " +
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==10){
            if(num<=data->getAnbar()->getSpace()){
                           if(data->getCoin()>=num*30){
                               data->getAnbar()->ChangeMikh(num);
                               str = QString::fromLatin1(to_string(num))+" Mikh Successfully purchased";
                               data->addExp(num*4);
                           }
                           else{
                               QString s= "  Required: " + QString::fromLatin1(to_string(num*30)),k="No enough coins\n Mojoodi: "
                               +QString::fromLatin1(to_string(data->getCoin()));
                               str = k  + s;
                           }
                       }
                       else{
                           if(data->getCoin()>=data->getAnbar()->getSpace()*30){
                               data->getAnbar()->ChangeMikh(data->getAnbar()->getSpace());
                               str = QString::fromLatin1(to_string(data->getAnbar()->getSpace()))+" Mikh Successfully purchased\n"+
                                       QString::fromLatin1(to_string(num-data->getAnbar()->getSpace())) +
                                       " cow-osarus No enough Space";
                               data->addExp(data->getAnbar()->getSpace()*4);
                           }
                           else{
                               QString s= "  Required: " + QString::fromLatin1(to_string(num*30)),
                                       k="No enough coins\n Mojoodi: "+QString::fromLatin1(to_string(data->getCoin()));
                               str = k  + s;
                           }
                       }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getMikh())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        ui->co->setText("X" +QString::fromLatin1(to_string(data->getCoin())));
        ui->number->setValue(0);
    }
}

void store::check_sell(){
    QString str;
    if(!ui->number->text().isEmpty()){
        int num = ui->number->value();
        if(i==1){
            if(num<=data->getAnbar()->getMilk()){
               for(int j=0; j < num ; data->RemvoMilk(), j++);
               str = QString::fromLatin1(to_string(num))+" Milk Sold successfully";
               data->addExp(6);
               data->operator+=(12*num);
            }
            else{
                for(int j=0; j < data->getAnbar()->getMilk() ; data->RemvoMilk(), j++);
                str = QString::fromLatin1(to_string(data->getAnbar()->getMilk()))+" Milk Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getMilk())) +
                        " Milk No enough Space";
                data->addExp(6);
                data->operator+=(12*data->getAnbar()->getMilk());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getMilk())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==2){
            if(num<=data->getGav()->getCount()){
               data->getGav()->operator-=(num);
               str = QString::fromLatin1(to_string(num))+" cow-osarus Sold successfully";
               data->addExp(6);
               data->operator+=(50*num);
            }
            else{
                data->getGav()->operator-=(data->getGav()->getCount());
                str = QString::fromLatin1(to_string(data->getGav()->getCount()))+" cow-osarus Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getGav()->getCount())) +
                        " cow-osarus No enough Space";
                data->addExp(6);
                data->operator+=(50*data->getGav()->getCount());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getGav()->getCount())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getGav()->getSpace())));
        }
        else if(i==3){
            if(num<=data->getAnbar()->getEgg()){
               data->getAnbar()->ChangeEgg(-1*num);
               str = QString::fromLatin1(to_string(num))+" egg Sold successfully";
               data->addExp(6);
               data->operator+=(8*num);
            }
            else{
                data->getAnbar()->ChangeEgg(-1*data->getAnbar()->getEgg());
                str = QString::fromLatin1(to_string(data->getAnbar()->getEgg()))+" egg Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getEgg())) +
                        " egg No enough Space";
                data->addExp(6);
                data->operator+=(8*data->getAnbar()->getEgg());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getEgg())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==4){
            if(num<=data->getMorq()->getCount()){
               data->getMorq()->operator-=(num);
               str = QString::fromLatin1(to_string(num))+" hen-osarus Sold successfully";
               data->addExp(6);
               data->operator+=(15*num);
            }
            else{
                data->getMorq()->operator-=(data->getMorq()->getCount());
                str = QString::fromLatin1(to_string(data->getMorq()->getCount()))+" hen-osarus Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getMorq()->getCount())) +
                        " hen-osarus No enough Space";
                data->addExp(6);
                data->operator+=(15*data->getMorq()->getCount());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getMorq()->getCount())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getMorq()->getSpace())));
        }
        else if(i==5){
            if(num<=data->getAnbar()->getPashm()){
               data->getAnbar()->ChangePashm(-1*num);
               str = QString::fromLatin1(to_string(num))+" Pashm Sold successfully";
               data->addExp(6);
               data->operator+=(23*num);
            }
            else{
                data->getAnbar()->ChangePashm(-1*data->getAnbar()->getPashm());
                str = QString::fromLatin1(to_string(data->getAnbar()->getPashm()))+" Pashm Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getPashm())) +
                        " Pashm No enough Space";
                data->addExp(6);
                data->operator+=(23*data->getAnbar()->getPashm());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getPashm())) + "\n\nSpace: "+
                                       QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==6){
            if(num<=data->getAqol()->getCount()){
               data->getAqol()->operator-=(num);
               str = QString::fromLatin1(to_string(num))+" Sheep-osarus Sold successfully";
               data->addExp(6);
               data->operator+=(70*num);
            }
            else{
                data->getAqol()->operator-=(data->getAqol()->getCount());
                str = QString::fromLatin1(to_string(data->getAqol()->getCount()))+" Sheep-osarus Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getAqol()->getCount())) +
                        " Sheep-osarus No enough Space";
                data->addExp(6);
                data->operator+=(70*data->getAqol()->getCount());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAqol()->getCount())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAqol()->getSpace())));
        }
        else if(i==7){
            if(num<=data->getsilo()->getCount()){
               data->getsilo()->operator-=(num);
               str = QString::fromLatin1(to_string(num))+" gandom Sold successfully";
               data->addExp(6);
               data->operator+=(2*num);
            }
            else{
                data->getsilo()->operator-=(data->getsilo()->getCount());
                str = QString::fromLatin1(to_string(data->getsilo()->getCount()))+" gandom Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getsilo()->getCount())) +
                        " gandom No enough Space";
                data->addExp(6);
                data->operator+=(2*data->getsilo()->getCount());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getsilo()->getCount())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getsilo()->getSpace())));
        }
        else if(i==8){
            if(num<=data->getAnbar()->getYonje()){
               data->getAnbar()->ChangeYonje(-1*num);
               str = QString::fromLatin1(to_string(num))+" Yonje Sold successfully";
               data->addExp(6);
               data->operator+=(4*num);
            }
            else{
                data->getAnbar()->ChangeYonje(-1*data->getAnbar()->getYonje());
                str = QString::fromLatin1(to_string(data->getAnbar()->getYonje()))+" Yonje Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getYonje())) +
                        " Yonje No enough Space";
                data->addExp(6);
                data->operator+=(4*data->getAnbar()->getYonje());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getYonje())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==9){
            if(num<=data->getAnbar()->getBil()){
               data->getAnbar()->ChangeBil(-1*num);
               str = QString::fromLatin1(to_string(num))+" bill Sold successfully";
               data->addExp(6);
               data->operator+=(30*num);
            }
            else{
                data->getAnbar()->ChangeBil(-1*data->getAnbar()->getBil());
                str = QString::fromLatin1(to_string(data->getAnbar()->getBil()))+" bill Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getBil())) +
                        " bill No enough Space";
                data->addExp(6);
                data->operator+=(30*data->getAnbar()->getBil());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getBil())) + "\n\nSpace: " +
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        else if(i==10){
            if(num<=data->getAnbar()->getMikh()){
               data->getAnbar()->ChangeMikh(-1*num);
               str = QString::fromLatin1(to_string(num))+" mikh Sold successfully";
               data->addExp(6);
               data->operator+=(20*num);
            }
            else{
                data->getAnbar()->ChangeMikh(-1*data->getAnbar()->getPashm());
                str = QString::fromLatin1(to_string(data->getAnbar()->getPashm()))+" mikh Sold successfully\n"+
                        QString::fromLatin1(to_string(num-data->getAnbar()->getPashm())) +
                        " mikh No enough Space";
                data->addExp(6);
                data->operator+=(20*data->getAnbar()->getPashm());
            }
            ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getMikh())) + "\n\nSpace: "+
                               QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
        }
        ui->co->setText("X" +QString::fromLatin1(to_string(data->getCoin())));
        ui->number->setValue(0);
    }
}

void store::milk_(){
    if(i!=1){
        i=1;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getMilk())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::cow_(){
    if(i!=2){
        i=2;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getGav()->getCount())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getGav()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::pashm_(){
    if(i!=5){
        i=5;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getPashm())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::hen_(){
    if(i!=4){
        i=4;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getMorq()->getCount())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getMorq()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::egg_(){
    if(i!=3){
        i=3;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getEgg())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::sheep_(){
    if(i!=6){
        i=6;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAqol()->getCount())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getAqol()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::bill_(){
    if(i!=9){
        i=9;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getBil())) + "\n\nSpace: " +
                           QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::mikh_(){
    if(i!=10){
        i=10;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getMikh())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::yonje_(){
    if(i!=8){
        i=8;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getAnbar()->getYonje())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getAnbar()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::gandom_(){
    if(i!=7){
        i=7;
        ui->number->setHidden(false);
        ui->buy->setHidden(false);
        ui->sell->setHidden(false);
        ui->label->setHidden(false);
        ui->label->setText("Mojoodi: "+ QString::fromLatin1(to_string(data->getsilo()->getCount())) + "\n\nSpace: "+
                           QString::fromLatin1(to_string(data->getsilo()->getSpace())));
    }
    else{
        i=0;
        ui->number->setHidden(true);
        ui->buy->setHidden(true);
        ui->sell->setHidden(true);
        ui->label->setHidden(true);
    }
}

void store::map_menu(){
    Widget* temp = new Widget(nullptr, data);
    temp->showFullScreen();
    this->destroy();
}

store::~store()
{
    delete ui;
}
