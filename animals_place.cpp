#include "animals_place.h"
#include "msg.h"


void Time(Data* _data, Animals_Place* w){
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
            w->check();
       }

       if(_data->getTime_build_gav()>0)
           _data->Add_build_gav(-1);
       if(_data->getTime_build_gav()==0){
           _data->set_build_gav(-1);
           _data->getGav()->setBuild(true);
           str = "Gavdari build Successfully\n";
           _data->Add_message(str,1);
           w->check();
       }

       if(_data->getTime_build_morq()>0)
           _data->Add_build_morq(-1);
       if(_data->getTime_build_morq()==0){
           _data->getMorq()->setBuild(true);
           _data->set_build_morq(-1);
           str = "Morqdari build Successfully\n";
           _data->Add_message(str,1);
           w->check();
       }

       if(_data->getTime_build_yonje()>0)
           _data->Add_build_yonje(-1);
       if(_data->getTime_build_yonje()==0){
           _data->set_build_yonje(-1);
           _data->getYonjeLand()->setBuilds(true);
           str = "Yonje land build Successfully\n";
           _data->Add_message(str,1);
       }

       if(_data->getAqol()->get_Time()>0)
           _data->getAqol()->Add_Time(-1);
       if(_data->getAqol()->get_Time()==0){
           _data->getAqol()->UpLevel();
           _data->getAqol()->set_Time(-1);
           str = "Aqol SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getAqol()->getLevel())
                   + "\n New Area: " + QString::number(_data->getAqol()->getCapacity()) + "\n";
           _data->Add_message(str,7);
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
           str = "Morqdari SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getMorq()->getLevel())
                              + "\n New Area: " + QString::number(_data->getMorq()->getCapacity()) + "\n";
           _data->Add_message(str,3);
       }

       if(_data->getMorq()->get_Time()>0)
           _data->getMorq()->Add_Time(-1);
       if(_data->getMorq()->get_Time()==0){
           _data->getMorq()->UpLevel();
           _data->getMorq()->set_Time(-1);
           str = "Aqol Level up Successfully\n";
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

Animals_Place::Animals_Place(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Animals Place");
    data = _data;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/animals_place.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    pbnGav = new QPushButton( this);
    pbnGav->setMinimumHeight(485);
    pbnGav->setMinimumWidth(600);
    pbnGav->setMaximumHeight(485);
    pbnGav->setMaximumWidth(600);
    pbnGav->move(130, 100);
    pbnGav->setStyleSheet("QPushButton{background:transparent;}");
    pbnGav->setCursor(Qt::PointingHandCursor);
//    if (data->getGav()->isBuild() == 1)
        pbnGav->setEnabled(true);
//    else
//        pbnGav->setEnabled(false);

//    build1 = new QPushButton("Build", this);
//    build1->setMinimumHeight(50);
//    build1->setMinimumWidth(100);
//    build1->setMaximumHeight(50);
//    build1->setMaximumWidth(100);
//    build1->move(710, 200);
//    build1->setStyleSheet("QPushButton{background:#80c342;}");
//    build1->setCursor(Qt::PointingHandCursor);
//    if (data->isCanBuildMorqdari() == 1)
//        build1->setEnabled(true);
//    else
//        build1->setEnabled(false);

    pbnMorgh = new QPushButton(this);
    pbnMorgh->setMinimumHeight(183);
    pbnMorgh->setMinimumWidth(860);
    pbnMorgh->setMaximumHeight(183);
    pbnMorgh->setMaximumWidth(860);
    pbnMorgh->move(470, 605);
    pbnMorgh->setStyleSheet("QPushButton{background: transparent;}");
    pbnMorgh->setCursor(Qt::PointingHandCursor);
//    if (data->getMorq()->isBuild() == 1)
        pbnMorgh->setEnabled(true);
//    else
//        pbnMorgh->setEnabled(false);

//   build2 = new QPushButton("Build", this);
//   build2->setMinimumHeight(50);
//   build2->setMinimumWidth(100);
//   build2->setMaximumHeight(50);
//   build2->setMaximumWidth(100);
//   build2->move(710, 260);
//   build2->setStyleSheet("QPushButton{background:#80c342;}");
//   build2->setCursor(Qt::PointingHandCursor);
//   if (data->isCanBuildGavdari() == 1)
//        build2->setEnabled(true);
//    else
//        build2->setEnabled(false);

    pbnGusfand = new QPushButton(this);
    pbnGusfand->setMinimumHeight(200);
    pbnGusfand->setMinimumWidth(270);
    pbnGusfand->setMaximumHeight(200);
    pbnGusfand->setMaximumWidth(270);
    pbnGusfand->move(1000, 270);
    pbnGusfand->setStyleSheet("QPushButton{background:transparent;}");
    pbnGusfand->setCursor(Qt::PointingHandCursor);
//    if (data->getAqol()->isBuild() == 1)
        pbnGusfand->setEnabled(true);
//    else
//        pbnGusfand->setEnabled(false);

//    build3 = new QPushButton("Build", this);
//    build3->setMinimumHeight(50);
//    build3->setMinimumWidth(100);
//    build3->setMaximumHeight(50);
//    build3->setMaximumWidth(100);
//    build3->move(710, 320);
//    build3->setStyleSheet("QPushButton{background:#80c342;}");
//    build3->setCursor(Qt::PointingHandCursor);
//    if (data->isCanBuildAqol())
//        build3->setEnabled(true);
//    else
//        build3->setEnabled(false);

    pbnBack = new QPushButton(this);
    pbnBack->setMinimumHeight(90);
    pbnBack->setMinimumWidth(90);
    pbnBack->setMaximumHeight(90);
    pbnBack->setMaximumWidth(90);
    pbnBack->move(20, 30);
    pbnBack->setCursor(Qt::PointingHandCursor);
    pbnBack->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
"                           QPushButton::hover{border-image:url(:icons/back22.png);} ");

    connect(pbnMorgh, SIGNAL(clicked()), this, SLOT(showMorghdari()));
    connect(pbnGav, SIGNAL(clicked()), this, SLOT(showGavdari()));
    connect(pbnGusfand, SIGNAL(clicked()), this, SLOT(showAghol()));
    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));

    QString str = data->get_Message(1);
    if(!str.isEmpty()){
        msg* payam = new msg(nullptr,&str);
        payam->show();
    }

    t = QThread::create(Time,data,this);
        t->start();

        build_Aqol = new QLabel("days passed goes here!",this);
            QFont font3 = build_Aqol->font();
            font3.setBold(true);
            font3.setPointSize(15);

            build_Aqol->setFont(font3);
            build_Aqol->setStyleSheet("color: rgb(153,153,0)");
            build_Aqol->move(20,150);

            build_Aqol->setText("Time to Build Sheep_osrous: " + QString::number(data->getTime_build_aqol()/60) +
                                                    ":" + QString::number(data->getTime_build_aqol()%60));

            if(data->getTime_build_aqol()<0)
                build_Aqol->setHidden(true);


            build_morq = new QLabel("days passed goes here!",this);

                build_morq->setFont(font3);
                build_morq->setStyleSheet("color: rgb(153,153,0)");
                build_morq->move(20,170);

                build_morq->setText("Time to Build Hen_osrous: " + QString::number(data->getTime_build_morq()/60) +
                                                        ":" + QString::number(data->getTime_build_morq()%60));

                if(data->getTime_build_morq()<0)
                    build_morq->setHidden(true);


                build_gav = new QLabel("days passed goes here!",this);

                    build_gav->setFont(font3);
                    build_gav->setStyleSheet("color: rgb(153,153,0)");
                    build_gav->move(20,190);

                    build_gav->setText("Time to Build Cow_osrous: " + QString::number(data->getTime_build_gav()/60) +
                                                            ":" + QString::number(data->getTime_build_gav()%60));

                    if(data->getTime_build_gav()<0)
                        build_gav->setHidden(true);
}

void Animals_Place::showMorghdari(){
    if (data->getMorq()->isBuild() == 1)
    {
        if(data->getTime_build_morq()<0){
            Morghdari* morgh = new Morghdari(nullptr, data);
            this->close();
            morgh->showFullScreen();
            t->terminate();
        }
        else{
            QString str = "Wait until the construction time is complete!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }
    else{
        if ((data->isCanBuildMorqdari() == 1) && (data->getLevel())>=2)
        {
            QMessageBox msgBox;
            msgBox.setInformativeText("Hen-saurus holding is not built yet do you want to build it? ");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setStyleSheet("color : white; background-color : green");
            int ret = msgBox.exec();

            switch (ret) {
               case QMessageBox::Yes:
                    data->BuildMorq();
                    data->getMorq()->setBuild(true);
                    data->set_build_morq(3*60);
                    build_morq->setHidden(false);
                   break;
               case QMessageBox::Cancel:
                   return;
                   break;
               default:
                   break;
             }
        }
        else{
            QString str = "Hen-saurus holding is not built yet and you don't have the ability to build it yet!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }
}

void Animals_Place::showGavdari(){
    if (data->getGav()->isBuild() == 1)
    {
        if(data->getTime_build_gav()<0){
            Gavdari* gav = new Gavdari(nullptr, data);
            this->close();
            gav->showFullScreen();
            t->terminate();
        }
        else{
                    QString str = "Wait until the construction time is complete!";
                    msg* message = new msg(nullptr, &str);
                    message->show();
            }
    }
    else{
        if (data->isCanBuildGavdari() == 1 && data->getLevel()>=4)
        {
            QMessageBox msgBox;
            msgBox.setInformativeText("Cow-saurus holding is not built yet do you want to build it? ");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setStyleSheet("color : white; background-color : green");
            int ret = msgBox.exec();

            switch (ret) {
               case QMessageBox::Yes:
                    data->BuildGav();
                    data->getGav()->setBuild(true);
                    data->set_build_gav(5*60);
                    build_gav->setHidden(false);
                   break;
               case QMessageBox::Cancel:
                   return;
                   break;
               default:
                   break;
             }
        }
        else{
            QString str = "Cow-saurus holding is not built yet and you don't have the ability to build it yet!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }
}

void Animals_Place::check(){
    if(data->getTime_build_aqol()==0) build_Aqol->setHidden(true);
    if(data->getTime_build_morq()==0) build_morq->setHidden(true);
    if(data->getTime_build_gav()==0) build_gav->setHidden(true);
}

void Animals_Place::showAghol(){
    if (data->getAqol()->isBuild() == 1)
    {
        if(data->getTime_build_aqol()<0){
            Aghol* gusfand = new Aghol(nullptr, data);
            this->close();
            gusfand->showFullScreen();
            t->terminate();
        }
        else{
                    QString str = "Wait until the construction time is complete!";
                    msg* message = new msg(nullptr, &str);
                    message->show();
            }
    }
    else{
        if (data->isCanBuildAqol() == 1 && data->getLevel()>=6)
        {
            QMessageBox msgBox;
            msgBox.setInformativeText("Sheep-saurus(Aqol) holding is not built yet do you want to build it? ");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setStyleSheet("color : white; background-color : green");
            int ret = msgBox.exec();

            switch (ret) {
               case QMessageBox::Yes:
                    data->BuildAqol();
                    data->getAqol()->setBuild(true);
                    data->set_build_aqol(600);
                    build_Aqol->setHidden(false);
                   break;
               case QMessageBox::Cancel:
                   return;
                   break;
               default:
                   break;
             }
        }
        else{
            QString str = "Sheep-saurus holding(Aqol) is not built yet and you don't have the ability to build it yet!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }


}

void Animals_Place::back()
{
    Widget* w = new Widget(nullptr, data);
    this->close();
    t->terminate();
    w->showFullScreen();
}

Animals_Place::~Animals_Place()
{

}
