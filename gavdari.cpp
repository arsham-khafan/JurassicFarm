#include "gavdari.h"
#include "msg.h"

void Time(Data* _data, Gavdari* w){
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
           w->check();
       }

       if(_data->getGav()->get_Time_food()>0)
           _data->getGav()->Add_Time_food(-1);
       if(_data->getGav()->get_Time_food()==0){
           _data->getGav()->setExist(true);
           _data->getGav()->setFood(false);
           _data->getGav()->set_Time_food(-1);
           str = "The cow_osarus are ready to be bred\n";
           _data->Add_message(str,3);
           w->check();
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
                  }
                  else{
                      _data->getYonjeLand()->setKesht(false);
                      _data->getYonjeLand()->setBardasht(false);
                      str = "Yonje was successfully cultivated\n";
                      _data->Add_message(str,8);
                  }
              }

        w->set();
    if(_data->getTime()>=60){
        _data->nextDay(2);
        _data->setTime(0);
        str += "1 day passed! we are in Tomorrow!!";
    }

    return Time(_data,w);
}

Gavdari::Gavdari(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Cow_osaurus Place");
    data = _data;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

   setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/cow.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    lblLvl = new QLabel("Level: ", this);
    lblLvl2 = new QLabel(this);
    lblLvl2->setNum(data->getGav()->getLevel());
    lblLvl->move(620, 10);
    lblLvl2->move(680, 10);

    lblCpc = new QLabel("Capacity: ", this);
    lblCpc2 = new QLabel(this);
    lblCpc2->setNum(data->getGav()->getCapacity());
    lblCpc->move(620, 40);
    lblCpc2->move(680, 40);

    lblNum = new QLabel("Number: ", this);
    lblNum2 = new QLabel(this);
    lblNum2->setNum(data->getGav()->getCount());
    lblNum->move(620, 70);
    lblNum2->move(680, 70);

    pbnUpgrd = new QPushButton("Upgrade", this);
    pbnUpgrd->setMinimumHeight(40);
    pbnUpgrd->setMinimumWidth(100);
    pbnUpgrd->setMaximumHeight(40);
    pbnUpgrd->setMaximumWidth(100);
    pbnUpgrd->move(650, 500);
    pbnUpgrd->setCursor(Qt::PointingHandCursor);

    pbnFeed = new QPushButton("Feeding", this);
    pbnFeed->setMinimumHeight(40);
    pbnFeed->setMinimumWidth(100);
    pbnFeed->setMaximumHeight(40);
    pbnFeed->setMaximumWidth(100);
    pbnFeed->move(650, 550);
    pbnFeed->setCursor(Qt::PointingHandCursor);

    pbnMilk = new QPushButton("Collecting Milk", this);
    pbnMilk->setMinimumHeight(40);
    pbnMilk->setMinimumWidth(100);
    pbnMilk->setMaximumHeight(40);
    pbnMilk->setMaximumWidth(100);
    pbnMilk->move(650, 600);
    pbnMilk->setCursor(Qt::PointingHandCursor);

    pbnBack = new QPushButton("Back", this);
    pbnBack->setMinimumHeight(40);
    pbnBack->setMinimumWidth(100);
    pbnBack->setMaximumHeight(40);
    pbnBack->setMaximumWidth(100);
    pbnBack->move(10, 710);
    pbnBack->setCursor(Qt::PointingHandCursor);

    connect(pbnUpgrd, SIGNAL(clicked()), this, SLOT(upgrd()));
    connect(pbnFeed, SIGNAL(clicked()), this, SLOT(feed()));
    connect(pbnMilk, SIGNAL(clicked()), this, SLOT(milk()));
    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));

    time_level = new QLabel("days passed goes here!",this);
        QFont font3 = time_level->font();
        font3.setBold(true);
        font3.setPointSize(15);

        time_level->setFont(font3);
        time_level->setStyleSheet("color: rgb(153,153,0)");
        time_level->move(20,150);

        time_level->setText("Time to Upgrade: " + QString::number(data->getGav()->get_Time()/60) +
                                                ":" + QString::number(data->getGav()->get_Time()%60));

        if(data->getGav()->get_Time_food()<0)
            time_level->setHidden(true);

        time_food = new QLabel("days passed goes here!",this);
        time_food->setFont(font3);
        time_food->setStyleSheet("color: rgb(153,153,0)");
        time_food->move(20,170);

        time_food->setText("Time to Upgrade: " + QString::number(data->getGav()->get_Time_food()/60) +
                                                ":" + QString::number(data->getGav()->get_Time_food()%60));

        if(data->getGav()->get_Time_food()<0)
            time_food->setHidden(true);

        QString str = data->get_Message(3);
        if(!str.isEmpty()){
            msg* payam = new msg(nullptr,&str);
            payam->show();
        }

        t = QThread::create(Time,data,this);
            t->start();

}

void Gavdari::upgrd()
{
    if(data->getGav()->get_Time()<0){
    QMessageBox msgBox;
//     msgBox.setText("are you sure you want to upgrade?");
    msgBox.setInformativeText("are you sure you want to upgrade?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setStyleSheet("color : white; background-color : red");
    int ret = msgBox.exec();

    switch (ret) {
       case QMessageBox::Yes:

        if(data->isCanAddLevelGavdari()){
            data->getAnbar()->ChangeMikh(-2);
            data->operator-=(15);
            data->addExp(6);
            data->getGav()->set_Time(300);
            time_level->setText("Time to Level up: " + QString::number(data->getMorq()->get_Time()/60) + ":"
            +QString::number(data->getMorq()->get_Time()%60));
            time_level->setHidden(false);
            QString str = "Aqol WILL BE UPGRADED IN 5 DAYS!";
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
            QString str = "GAVDARI ALREADY IS UPGRADING!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }

}

void Gavdari::feed()
{
    if(data->getGav()->isFood()){
        QString str = "The animals have eaten!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
    else{
        if(data->getAnbar()->getYonje()>=data->getGav()->getCount()*2){
            data->getMorq()->setFood(true);
            QString str = "The animals ate successfully!!";
            data->getAnbar()->ChangeYonje(data->getGav()->getCount()*-2);
            data->addExp(3);
            data->getGav()->set_Time_food(120);
            time_food->setText("Time to Egg: " + QString::number(data->getGav()->get_Time_food()/60) + ":"
            +QString::number(data->getGav()->get_Time_food()%60));
            time_food->setHidden(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "NO ENOUGH YONJE IN STORAGE";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
}

void Gavdari::milk()
{
    if(data->getGav()->isExist()){
            QString str = "The milks were collected successfully!!";
            int num = data->getGav()->getCount();
            for(int i = 0;i<num;data->AddMilk(),i++);
            data->addExp(5);
            data->getGav()->setExist(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
    }
    else{
        if(data->getGav()->get_Time_food()>=0){
            QString str = "It is not time to give MILK!!";
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

void Gavdari::back()
{
    Animals_Place* animals = new Animals_Place(nullptr, data);
    this->close();
    t->terminate();
    animals->showFullScreen();
}
