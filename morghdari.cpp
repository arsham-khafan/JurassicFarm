#include "morghdari.h"
#include "msg.h"

void Time(Data* _data, Morghdari* w){
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
           w->check();
       }

       if(_data->getMorq()->get_Time_food()>0)
           _data->getMorq()->Add_Time_food(-1);
       if(_data->getMorq()->get_Time_food()==0){
           _data->getMorq()->setExist(true);
           _data->getMorq()->setFood(false);
           _data->getMorq()->set_Time_food(-1);
           str = "The hen_osarus are ready to be bred\n";
           w->check();
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
        w->set();
    if(_data->getTime()>=60){
        _data->nextDay(2);
        _data->setTime(0);
        str += "1 day passed! we are in Tomorrow!!";
        _data->Add_message(str,0);
    }

    return Time(_data,w);
}

Morghdari::Morghdari(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Hen_osaurus Place");
    data = _data;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/ddd.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    lblLvl = new QLabel("Level: ", this);
    lblLvl2 = new QLabel(this);
    lblLvl2->setNum(data->getMorq()->getLevel());
    lblLvl->move(1200, 370);
    lblLvl2->move(1260, 370);

    lblCpc = new QLabel("Capacity: ", this);
    lblCpc2 = new QLabel(this);
    lblCpc2->setNum(data->getMorq()->getCapacity());
    lblCpc->move(1200, 400);
    lblCpc2->move(1300, 400);

    lblNum = new QLabel("Number: ", this);
    lblNum2 = new QLabel(this);
    lblNum2->setNum(data->getMorq()->getCount());
    lblNum->move(1200, 430);
    lblNum2->move(1300, 430);

    QFont f("Comic Sans MS");
    f.setPointSize(15);
    f.setBold(true);
    lblLvl->setFont(f);
    lblLvl2->setFont(f);
    lblCpc->setFont(f);
    lblCpc2->setFont(f);
    lblNum->setFont(f);
    lblNum2->setFont(f);

    lblLvl->setStyleSheet("color: rgb(153,153,0)");
    lblLvl2->setStyleSheet("color: rgb(153,153,0)");
    lblCpc->setStyleSheet("color: rgb(153,153,0)");
    lblCpc2->setStyleSheet("color: rgb(153,153,0)");
    lblNum->setStyleSheet("color: rgb(153,153,0)");
    lblNum2->setStyleSheet("color: rgb(153,153,0)");

    pbnUpgrd = new QPushButton(this);
        pbnUpgrd->setMinimumHeight(90);
        pbnUpgrd->setMinimumWidth(90);
        pbnUpgrd->setMaximumHeight(90);
        pbnUpgrd->setMaximumWidth(90);
        pbnUpgrd->move(20, 150);
        pbnUpgrd->setStyleSheet("QPushButton {border-image:url(:icons/uplevel.png);}"
    "                           QPushButton::hover{border-image:url(:icons/uplevel2.png);} ");
        pbnUpgrd->setToolTip("level up silo");
    pbnUpgrd->setCursor(Qt::PointingHandCursor);

    pbnFeed = new QPushButton(this);
    pbnFeed->setFixedSize(100,100);
    pbnFeed->move(1200, 200);
    pbnFeed->setStyleSheet("QPushButton {border-image:url(:icons/food_hen.jpg);border:2px;border-radius:40px;}");
    pbnFeed->setToolTip("feeding");
    pbnFeed->setCursor(Qt::PointingHandCursor);

    pbnEgg = new QPushButton(this);
    pbnEgg->setFixedSize(100,100);
    pbnEgg->move(1200, 80);
    pbnEgg->setStyleSheet("QPushButton {border-image:url(:icons/tokhm1.jpg);border:2px;border-radius:40px;}"
"                           QPushButton::hover{border-image:url(:icons/tokhm2.jpg);} ");
    pbnEgg->setToolTip("collect eggs");
    pbnEgg->setCursor(Qt::PointingHandCursor);

    pbnBack = new QPushButton(this);
    pbnBack->move(10,10);
    pbnBack->setMinimumHeight(100);
    pbnBack->setMinimumWidth(100);
      pbnBack->setMaximumHeight(100);
      pbnBack->setMaximumWidth(100);
      pbnBack->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}""QPushButton::hover{border-image:url(:icons/back22.png);} ");
      pbnBack->setToolTip("back to map");
      pbnBack->setCursor(Qt::ClosedHandCursor);

    connect(pbnUpgrd, SIGNAL(clicked()), this, SLOT(upgrd()));
    connect(pbnFeed, SIGNAL(clicked()), this, SLOT(feed()));
    connect(pbnEgg, SIGNAL(clicked()), this, SLOT(egg()));
    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));

    time_level = new QLabel("days passed goes here!",this);
    QFont font3 = time_level->font();
    font3.setBold(true);
    font3.setPointSize(15);

    time_level->setFont(font3);
    time_level->setStyleSheet("color: rgb(153,153,0)");
    time_level->move(20,300);
    time_level->setFixedSize(300,40);
    time_level->setText("Time to Upgrade: " + QString::number(data->getMorq()->get_Time()/60) +
                                            ":" + QString::number(data->getMorq()->get_Time()%60));

    if(data->getMorq()->get_Time_food()<0)
        time_level->setHidden(true);

    time_food = new QLabel("days passed goes here!",this);
    time_food->setFont(font3);
    time_food->setStyleSheet("color: rgb(153,153,0)");
    time_food->move(20,400);
    time_food->setFixedSize(300,40);
    time_food->setText("Time to egg: " + QString::number(data->getMorq()->get_Time_food()/60) +
                                            ":" + QString::number(data->getMorq()->get_Time_food()%60));

    if(data->getMorq()->get_Time_food()<0)
        time_food->setHidden(true);

    QString str = data->get_Message(4);
    if(!str.isEmpty()){
        msg* payam = new msg(nullptr,&str);
        payam->show();
    }

    t = QThread::create(Time,data,this);
        t->start();

}

void Morghdari::upgrd()
{
    if(data->getMorq()->get_Time()<0){
        QMessageBox msgBox;
    //     msgBox.setText("are you sure you want to upgrade?");
        msgBox.setInformativeText("are you sure you want to upgrade?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Yes);
        msgBox.setStyleSheet("color : white; background-color : red");
        int ret = msgBox.exec();

        switch (ret) {
           case QMessageBox::Yes:

            if(data->isCanAddLevelMorqdari()){
                data->getAnbar()->ChangeMikh(-1);
                data->operator-=(10);
                data->addExp(5);
                data->getMorq()->set_Time(180);
                time_level->setText("Time to Level up: " + QString::number(data->getMorq()->get_Time()/60) + ":"
                 +QString::number(data->getMorq()->get_Time()%60));
                time_level->setHidden(false);
                QString str = "Aqol WILL BE UPGRADED IN 3 DAYS!";
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
                QString str = "MORGHDARI ALREADY IS UPGRADING!!";
                msg* temp = new msg(nullptr , &str);
                temp->show();
            }

}

void Morghdari::feed()
{
    if(data->getAqol()->getCount()>0){
    if(data->getMorq()->isFood()){
        QString str = "The animals have eaten!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
    else if(data->getMorq()->isExist()){
            QString str = "First collect!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    else{
        if(data->getsilo()->getCount()>=data->getMorq()->getCount()){
            data->getMorq()->setFood(true);
            QString str = "The animals ate successfully!!";
            data->getsilo()->operator-=(data->getMorq()->getCount());
            data->addExp(1);
            data->getMorq()->set_Time_food(120);
            time_food->setText("Time to Egg: " + QString::number(data->getMorq()->get_Time_food()/60) + ":"
             +QString::number(data->getMorq()->get_Time_food()%60));
            time_food->setHidden(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "NO ENOUGH GANDOM IN Anbar";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
    }
        else{
            QString str = "NO Sheep-osarous yet";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
}

void Morghdari::egg()
{
    if(data->getMorq()->isExist()){
        if(data->getAnbar()->getSpace()>=data->getMorq()->getCount()){
            QString str = "The eggs were collected successfully!!";
            data->getAnbar()->ChangeEgg(data->getMorq()->getCount());
            data->addExp(2);
            data->getMorq()->setExist(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "NO Space in Storage!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
    else{
        if(data->getMorq()->get_Time_food()>=0){
            QString str = "It is not time to give egg!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "Animals are not fed!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
}

void Morghdari::back()
{
    Animals_Place* animals = new Animals_Place(nullptr,data);
    this->close();
    t->terminate();
    animals->showFullScreen();
}
