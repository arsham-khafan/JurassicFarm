#include "storage.h"
#include "widget.h"
#include <QMovie>
#include <msg.h>

storage::storage(QWidget *parent, Data* _data) : QWidget(parent)
{
    data = _data;
    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/storage.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    nail = new QLabel(this);
    nail->setToolTip("number of nails");
    QPixmap* temp = new QPixmap(":icons/nail.png");
    nail->setPixmap(temp->scaled(QSize(90,90)));
    nail->move(1246,30);
    nail_txt = new QLabel(QString::number(data->getAnbar()->getMikh()) + "   X  " ,this);
    nail_txt->setStyleSheet("color : white;"
                            "font: 18pt;");
    nail_txt->move(1150,60);

    shovel = new QLabel(this);
    shovel->setToolTip("number of shovels");
    QPixmap* temp2 = new QPixmap(":icons/shovel.png");
    shovel->setPixmap(temp2->scaled(QSize(90,90)));
    shovel->move(1246,150);
    shovel_txt = new QLabel(QString::number(data->getAnbar()->getBil()) + "   X  " ,this);
    shovel_txt->setStyleSheet("color : white;"
                            "font: 18pt;");
    shovel_txt->move(1150,180);

    yonje = new QLabel(this);
    yonje->setToolTip("volume of yonje");
    QPixmap* temp4 = new QPixmap(":icons/yonje.png");
    yonje->setPixmap(temp4->scaled(QSize(90,90)));
    yonje->move(1246,270);
    yonje_txt = new QLabel(QString::number(data->getAnbar()->getYonje()) + "   X  " ,this);
    yonje_txt->setStyleSheet("color : white;"
                            "font: 18pt;");
    yonje_txt->move(1150,300);

    if(data->getLevel() >= 2){
        egg = new QLabel(this);
        egg->setToolTip("number of dinasuar eggs");
        QPixmap* temp3 = new QPixmap(":icons/egg.png");
        egg->setPixmap(temp3->scaled(QSize(90,90)));
        egg->move(1246,390);

        egg_txt = new QLabel(QString::number(data->getAnbar()->getEgg()) + "   X  " ,this);
        egg_txt->setStyleSheet("color : white;"
                                "font: 18pt;");
        egg_txt->move(1150,420);
    }
    else{
        egg = new QLabel(this);
        egg->setToolTip("number of dinasuar eggs(opens in lvl 2)");
        QPixmap* temp3 = new QPixmap(":icons/egg2.png");
        egg->setPixmap(temp3->scaled(QSize(90,90)));
        egg->move(1246,390);

        egg_txt = new QLabel("LOCKED" ,this);
        egg_txt->setStyleSheet("color : white;"
                                "font: 18pt;");
        egg_txt->move(1120,420);
    }

    if(data->getLevel() >= 4){
        milk = new QLabel(this);
        milk->setToolTip("volume of milk");
        QPixmap* temp5 = new QPixmap(":icons/milk.png");
        milk->setPixmap(temp5->scaled(QSize(90,90)));
        milk->move(1246,510);

        milk_txt = new QLabel(QString::number(data->getAnbar()->getMilk()) + "   X  " ,this);
        milk_txt->setStyleSheet("color : white;"
                                "font: 18pt;");
        milk_txt->move(1150,540);

    }
    else{
        milk = new QLabel(this);
        milk->setToolTip("volume of milk(opens in lvl 4)");
        QPixmap* temp5 = new QPixmap(":icons/milk2.png");
        milk->setPixmap(temp5->scaled(QSize(90,90)));
        milk->move(1246,510);

        milk_txt = new QLabel("LOCKED" ,this);
        milk_txt->setStyleSheet("color : white;"
                                "font: 18pt;");
        milk_txt->move(1120,540);
    }

    whool = new QLabel(this);

    QPixmap* temp6;
    if(data->getLevel() >= 6){
        temp6 = new QPixmap(":icons/whool.png");
        whool->setToolTip("volume of whool");

        whool_txt = new QLabel(QString::number(data->getAnbar()->getPashm()) + "   X  " ,this);
        whool_txt->setStyleSheet("color : white;"
                                "font: 18pt;");
        whool_txt->move(1150,540);
    }
    else{
        temp6 = new QPixmap(":icons/whool2.png");
        whool->setToolTip("volume of whool(opens in lvl 6");

        whool_txt = new QLabel("LOCKED" ,this);
        whool_txt->setStyleSheet("color : white;"
                                "font: 18pt;");
        whool_txt->move(1120,660);
    }
    whool->setPixmap(temp6->scaled(QSize(90,90)));
    whool->move(1246,630);

    go_back = new QPushButton(this);
    go_back->setMinimumHeight(90);
    go_back->setMinimumWidth(90);
    go_back->setMaximumHeight(90);
    go_back->setMaximumWidth(90);
    go_back->move(20, 30);
    go_back->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
"                           QPushButton::hover{border-image:url(:icons/back22.png);} ");
    go_back->setToolTip("back to map");

    up_level = new QPushButton(this);
    up_level->setMinimumHeight(166);
    up_level->setMinimumWidth(500);
    up_level->setMaximumHeight(166);
    up_level->setMaximumWidth(500);
    up_level->move(433, 580);
    up_level->setStyleSheet("QPushButton {border-image:url(:icons/upgrade.png);}"
"                           QPushButton::hover{border-image:url(:icons/upgrade2.png);} ");
    up_level->setToolTip("Upgrade Storage");

    connect(go_back, SIGNAL(clicked()), this , SLOT(map_menu()));
    connect(up_level, SIGNAL(clicked()), this , SLOT(upgrade_slot()));

    cpc_bar = new QProgressBar(this);
    cpc_bar->setMinimumHeight(25);
    cpc_bar->setMinimumWidth(700);
    cpc_bar->setMaximumHeight(25);
    cpc_bar->setMaximumWidth(700);
    cpc_bar->move(323,30);
    cpc_bar->setStyleSheet("QProgressBar {"
                          "background-color: #EEC677;"
                          "color: #FFFFFF;"
                          "border-style: outset;"
                          "border-width: 2px;"
                          "border-color: #176C5B;"
                          "border-radius: 7px;"
                          "text-align: left; }"

                          "QProgressBar::chunk {"
                          "background-color: #176C5B; }");

    cpc_bar->setValue(((data->getAnbar()->getCount())* 100 )/ (data->getAnbar()->getCapacity()));

    cpc_bar->setToolTip("Storage level: " + QString::number(data->getAnbar()->getLevel()) + "\n" + "Items Count: " + QString::number(data->getAnbar()->getCount()) + "\n" + "Storage Capacity: " + QString::number(data->getAnbar()->getCapacity()));
    QMovie* movie = new QMovie(":gifs/pulp.gif");
    QLabel* label = new QLabel(this);
    label->move(-40,400);
    // Make sure the GIF was loaded correctly
    if (!movie->isValid())
    {
        label->setText("mammad");
    }
    else{
        label->setMovie(movie);
        movie->start();
    }


}

void storage::map_menu(){
    Widget* temp = new Widget(nullptr, data);
    temp->showFullScreen();
    this->destroy();
}

void storage::upgrade_slot(){
    if(data->isCanAddLevelAnbar()){
        data->operator-= ((int)qPow(data->getAnbar()->getLevel(), 3) * 10);
        if (data->addExp(data->getAnbar()->getLevel() * 3))
          data->UpLevel();
        data->getAnbar()->UpLevel();
        QString str = "SUCCESSFULLY UPGRADED!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
    else{
        QString str = "CHECK YOUR RESOURCES OR LEVEL FIRST!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
}
