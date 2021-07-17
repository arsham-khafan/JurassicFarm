#include "siloo.h"
#include <QMovie>
#include <QLabel>
#include "widget.h"
#include "msg.h"


void Time(Data* _data, siloo* w){
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
                  str = "Aqol Level up Successfully\n";
                  _data->Add_message(str,4);
              }

              if(_data->getMorq()->get_Time_food()>0)
                  _data->getMorq()->Add_Time_food(-1);
              if(_data->getMorq()->get_Time_food()==0){
                  _data->getMorq()->setExist(true);
                  _data->getMorq()->setFood(false);
                  _data->getMorq()->set_Time_food(-1);
                  str = "Morqdari SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getMorq()->getLevel())
                                     + "\n New Area: " + QString::number(_data->getMorq()->getCapacity()) + "\n";
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
                  w->check();
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

siloo::siloo(QWidget *parent, Data* _data) : QWidget(parent)
{
    data = _data;
    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/silo.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    main_bar = new QProgressBar(this);
    main_bar->setOrientation(Qt::Vertical);
    main_bar->move(250,140);
    main_bar->setMinimumHeight(514);
    main_bar->setMinimumWidth(599);
    main_bar->setMaximumHeight(514);
    main_bar->setMaximumWidth(599);
    main_bar->setStyleSheet("QProgressBar { border-image: url(:icons/silomask2.png); }"
                            "QProgressBar::chunk { background-image: url(:backgrounds/weat.jpg); }");
    main_bar->setTextVisible(false);
    main_bar->setValue((data->getsilo()->getCount() * 68)/data->getsilo()->getCapacity());
    main_bar->setToolTip("silo level: " + QString::number(data->getsilo()->getLevel()) + "\n" + "weat volume: " + QString::number(data->getsilo()->getCount()) + "\n" + "silo capacity: " + QString::number(data->getsilo()->getCapacity()));
///////////////////////////////////////////////////////
    QMovie* movie = new QMovie(":gifs/farmg1.gif");
    QLabel* label = new QLabel(this);
    label->move(30,560);
    // Make sure the GIF was loaded correctly
    if (!movie->isValid())
    {
        label->setText("mammad");
    }
    else{
        label->setMovie(movie);
        movie->start();
    }
///////////////////////////////////////////////////////
    QMovie* movie2 = new QMovie(":gifs/farmg2.gif");
    QLabel* label2 = new QLabel(this);
    label2->move(1000,500);
    // Make sure the GIF was loaded correctly
    if (!movie2->isValid())
    {
        label2->setText("mammad");
    }
    else{
        label2->setMovie(movie2);
        movie2->start();
    }
///////////////////////////////////////////////////////
    go_back = new QPushButton(this);
    go_back->setMinimumHeight(90);
    go_back->setMinimumWidth(90);
    go_back->setMaximumHeight(90);
    go_back->setMaximumWidth(90);
    go_back->move(20, 30);
    go_back->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
"                           QPushButton::hover{border-image:url(:icons/back22.png);} ");
    go_back->setToolTip("back to map");

    upgrade = new QPushButton(this);
    upgrade->setMinimumHeight(90);
    upgrade->setMinimumWidth(90);
    upgrade->setMaximumHeight(90);
    upgrade->setMaximumWidth(90);
    upgrade->move(20, 150);
    upgrade->setStyleSheet("QPushButton {border-image:url(:icons/uplevel.png);}"
"                           QPushButton::hover{border-image:url(:icons/uplevel2.png);} ");
    upgrade->setToolTip("level up silo");

    connect(go_back, SIGNAL(clicked()), this, SLOT(back_to_map()));
    connect(upgrade, SIGNAL(clicked()), this, SLOT(upgrade_slot()));

    time_lbl = new QLabel("days passed goes here!",this);
    QFont font3 = time_lbl->font();
    font3.setBold(true);
    font3.setPointSize(15);
    time_lbl->setFont(font3);
    time_lbl->setStyleSheet("color: rgb(153,153,0)");
    time_lbl->move(20,370);
    if(data->getsilo()->get_time()<0)
        time_lbl->setHidden(true);

    time_lbl->setText("Time to Upgrade: " + QString::number(data->getsilo()->get_time()/60) +
                                        ":" + QString::number(data->getsilo()->get_time()%60));

    time_lbl->setFixedSize(300,40);

//    time_bar = new QProgressBar(this);
//    time_bar->setToolTip("Time 😥😥");
//    time_bar->setMinimumHeight(12);
//    time_bar->setMinimumWidth(90);
//    time_bar->setMaximumHeight(12);
//    time_bar->setMaximumWidth(90);
//    time_bar->move(20,270);
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

    QString str = data->get_Message(6);
    if(!str.isEmpty()){
        msg* payam = new msg(nullptr,&str);
        payam->show();
    }

    t = QThread::create(Time,data,this);
        t->start();
}

void siloo::back_to_map(){
    Widget* temp = new Widget(nullptr, data);
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}

void siloo::upgrade_slot(){
    if(data->getsilo()->get_time()<0){
    QMessageBox* msgBox = new QMessageBox;
//     msgBox.setText("are you sure you want to upgrade?");
    msgBox->setText("are you sure you want to upgrade?");
    msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox->setDefaultButton(QMessageBox::Yes);
    msgBox->setStyleSheet("color : white; background-color : red");
    int ret = msgBox->exec();

     switch (ret) {
        case QMessageBox::Yes:
         if( data->isCanAddLevelSilo()){
             int x = data->getAnbar()->getLevel();
             data->operator-= (100 * (int)qPow((2 * x), 2));
             data->getAnbar()->ChangeMikh(x*-2);
             data->getAnbar()->ChangeBil(-(x - 2));
             data->addExp(data->getsilo()->getLevel() * 2);
             data->getsilo()->setTime(4*60);
             time_lbl->setHidden(false);
             QString str = "SILOO WILL BE UPGRADED IN 4 DAYS!";
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
            break;
        default:
            // should never be reached
            break;
      }
    }
    else{
        QString str = "SILOO ALREADY IS UPGRADING!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
}
