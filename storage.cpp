#include "storage.h"
#include "widget.h"
#include <QMovie>
#include <msg.h>
#include <QMessageBox>

void Time(Data* _data, storage* w){
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
           w->check();
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
        w->set();
    if(_data->getTime()>=60){
        _data->nextDay(2);
        _data->setTime(0);
        str += "1 day passed! we are in Tomorrow!!";
        _data->Add_message(str,0);
    }

    return Time(_data,w);
}

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
        whool_txt->move(1150,660);
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

    time_lbl = new QLabel("days passed goes here!",this);
    QFont font3 = time_lbl->font();
    font3.setBold(true);
    font3.setPointSize(15);
    time_lbl->setFont(font3);
    time_lbl->setStyleSheet("color: rgb(153,153,0)");
    time_lbl->move(20,150);

    time_lbl->setText("Time to Upgrade: " + QString::number(data->getAnbar()->get_time()/60) +
                                            ":" + QString::number(data->getAnbar()->get_time()%60));

    if(data->getAnbar()->get_time()<0)
        time_lbl->setHidden(true);

//    time_bar = new QProgressBar(this);
//    time_bar->setToolTip("Time 😥😥");
//    time_bar->setMinimumHeight(12);
//    time_bar->setMinimumWidth(90);
//    time_bar->setMaximumHeight(12);
//    time_bar->setMaximumWidth(90);
//    time_bar->move(20,150);
//    time_bar->setStyleSheet("QProgressBar {"
//                          "background-color: #EEC677;"
//                          "color: #FFFFFF;"
//                          "border-style: outset;"
//                          "border-width: 2px;"
//                          "border-color: #176C5B;"
//                          "border-radius: 7px;"
//                          "text-align: left; }"

//                          "QProgressBar::chunk {"
//                          "background-color: #176C5B; }");

    t = QThread::create(Time,data,this);
    t->start();

    QString str = data->get_Message(5);
    if(!str.isEmpty()){
        msg* payam = new msg(nullptr,&str);
        payam->show();
    }
}

void storage::map_menu(){
    Widget* temp = new Widget(nullptr, data);
    t->terminate();
    temp->showFullScreen();
    this->destroy();
}

void storage::upgrade_slot(){
    if(data->getAnbar()->get_time()<0){
     QMessageBox msgBox;
//     msgBox.setText("are you sure you want to upgrade?");
     msgBox.setInformativeText("are you sure you want to upgrade?");
     msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
     msgBox.setDefaultButton(QMessageBox::Yes);
     msgBox.setStyleSheet("color : white; background-color : red");
     int ret = msgBox.exec();

     switch (ret) {
        case QMessageBox::Yes:

         if(data->isCanAddLevelAnbar()){
             data->operator-=((int)qPow(data->getAnbar()->getLevel(), 3) * 10);
             data->addExp(data->getAnbar()->getLevel() * 3);
             data->getAnbar()->UpLevel(1);
             data->getAnbar()->setTime(5*60);
             time_lbl->setHidden(false);
             QString str = "STORAGE WILL BE UPGRADED IN 5 DAYS!";
             msg* temp = new msg(nullptr , &str);
             temp->show();
         }
         else{
             QString str = "CHECK YOUR RESOURCES OR LEVEL FIRST!!";
             msg* temp = new msg(nullptr , &str);
             temp->show();
         }
            break;
        case QMessageBox::Cancel:
            return;
            // Don't Save was clicked
            break;
        default:
            // should never be reached
            break;
      }
    }
     else{
         QString str = "STORAGE ALREADY IS UPGRADING!!";
         msg* temp = new msg(nullptr , &str);
         temp->show();
     }
}
