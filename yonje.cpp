#include "yonje.h"
#include "gandom.h"
#include "ui_yonje.h"
#include "msg.h"
#include "khata.h"

void Time(Data* _data, Yonje* w){
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
           _data->done(1);
       }

       if(_data->getYonjeLand()->get_time()>0)
           _data->getYonjeLand()->Add_Time(-1);
       if(_data->getYonjeLand()->get_time()==0){
           _data->getYonjeLand()->UpLevel();
           _data->getYonjeLand()->setTime(-1);
           str = "Yonje Land SUCCESSFULLY UPGRADED!\n Level: " + QString::number(_data->getYonjeLand()->getLevel())
                   + "\n New Area: " + QString::number(_data->getYonjeLand()->getArea()) + "\n";
           w->check();
       }

       if(_data->getYonjeLand()->get_time_work()>0)
                  _data->getYonjeLand()->Add_Time_work(-1);
              if(_data->getYonjeLand()->get_time_work()==0){
                  _data->getYonjeLand()->setTime_work(-1);
                  if(_data->getYonjeLand()->isShokhm()){
                      str = "Yonje land was successfully plowed\n";
                      _data->getYonjeLand()->setShokhm(false);
                      _data->shokhm();
                      w->check();
                  }
                  else{
                      _data->getYonjeLand()->setKesht(false);
                      _data->getYonjeLand()->setBardasht(false);
                      str = "Yonje was successfully cultivated\n";
                      _data->done(2);
                      w->check();
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

Yonje::Yonje(QWidget *parent, Data*_data) :
    QWidget(parent),
    ui(new Ui::Yonje)
{
    ui->setupUi(this);
    data = _data;
   this->setMinimumHeight(768);
   this->setMinimumWidth(1366);
   this->setMaximumHeight(768);
    this->setMaximumWidth(1366);
   setAutoFillBackground(true);
   QPixmap pixmap=QPixmap(":backgrounds/yonjeh.jpg").scaled(this->size());
   QPalette palette(this->palette());
   palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
   this->setPalette(palette);
   pb1=new QPushButton;
   pb2=new QPushButton;
   pb2->move (10,150);
   pb2->setMinimumHeight(100);
   pb2->setMinimumWidth(100);
     pb2->setMaximumHeight(100);
     pb2->setMaximumWidth(100);
     pb2->setStyleSheet("QPushButton {border-image:url(:backgrounds/gandom.jpg);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/gandom2.jpg);} ");
     pb2->setToolTip("wheat field");
     pb2->setCursor(Qt::ClosedHandCursor);
     connect(pb2, SIGNAL(clicked()), this , SLOT(go_to_gandom_widget()));
     pb1->move(10,10);
     pb1->setMinimumHeight(100);
     pb1->setMinimumWidth(100);
       pb1->setMaximumHeight(100);
       pb1->setMaximumWidth(100);
       pb1->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
   "                           QPushButton::hover{border-image:url(:icons/back22.png);} ");
       pb1->setToolTip("back to map");
       pb1->setCursor(Qt::ClosedHandCursor);
        connect(pb1, SIGNAL(clicked()), this , SLOT(back_to_map()));
        pb3=new QPushButton;
        pb3->move (1200,10);
        pb3->setMinimumHeight(100);
        pb3->setMinimumWidth(100);
          pb3->setMaximumHeight(100);
          pb3->setMaximumWidth(100);
          pb3->setStyleSheet("QPushButton {border-image:url(:icons/kasht1.jpg);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/kasht2.jpg);} ");
          pb3->setToolTip("planting");
          pb3->setCursor(Qt::ClosedHandCursor);

          bardasht = new QPushButton(this);
          bardasht->move (1200,150);
          bardasht->setMinimumHeight(100);
          bardasht->setMinimumWidth(100);
            bardasht->setMaximumHeight(100);
            bardasht->setMaximumWidth(100);
            bardasht->setStyleSheet("QPushButton {border-image:url(:icons/yonjeh3.jpg);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/kasht2.jpg);} ");
            bardasht->setToolTip("Bardasht");
            bardasht->setCursor(Qt::ClosedHandCursor);

          pb4=new QPushButton;
          pb4->move (1200,430);
          pb4->setMinimumHeight(100);
          pb4->setMinimumWidth(100);
            pb4->setMaximumHeight(100);
            pb4->setMaximumWidth(100);
            pb4->setStyleSheet("QPushButton {border-image:url(:icons/masahat1.png);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/masahat2.png);} ");
            pb4->setToolTip("land area");
            pb4->setCursor(Qt::ClosedHandCursor);

            pb5=new QPushButton;
            pb5->move (1200,290);
            pb5->setMinimumHeight(100);
            pb5->setMinimumWidth(100);
              pb5->setMaximumHeight(100);
              pb5->setMaximumWidth(100);
             pb5->setStyleSheet("QPushButton {border-image:url(:icons/shokhm1.jpeg);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/shokhm2.jpg);} ");
              pb5->setToolTip("plowing the field");
              pb5->setCursor(Qt::ClosedHandCursor);
            up_level = new QPushButton(this);
            up_level->setMinimumHeight(166);
            up_level->setMinimumWidth(500);
            up_level->setMaximumHeight(166);
            up_level->setMaximumWidth(500);
            up_level->move(433, 100);
            up_level->setStyleSheet("QPushButton {border-image:url(:icons/upgrade.png);}"
        "                           QPushButton::hover{border-image:url(:icons/upgrade2.png);} ");
            up_level->setToolTip("Upgrade alfalfa field");

       pb1->setParent(this);
       pb2->setParent(this);
       pb3->setParent(this);
       pb4->setParent(this);
       pb5->setParent(this);

       ui->sabt->setHidden(true);

       main = new QGridLayout;
       int num = data->getYonjeLand()->getArea();
       kol = new QPushButton[num];
       for(int h=0;h<num;h++){
           if(data->getYonjeLand()->at(h) == 0)
               kol[h].setStyleSheet("QPushButton {border-image:url(:icons/khack.jpg);border:2px;border-radius:40px;}");
           else if(data->getYonjeLand()->at(h) == 1){
                   kol[h].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
           }
           else if(data->getYonjeLand()->at(h) == 2)
               kol[h].setStyleSheet("QPushButton {border-image:url(:icons/shokhm.jpg);border:2px;border-radius:40px;}");
           else if(data->getYonjeLand()->at(h) == 3)
               kol[h].setStyleSheet("QPushButton {border-image:url(:icons/Yon_last.jpg);border:2px;border-radius:40px;}");
           main->addWidget(&kol[h],h/5,h%5);
           kol[h].setFixedSize(100,100);
           connect(&kol[h],SIGNAL(clicked()),this,SLOT(buttons()));
       }

       ui->scrollArea->setLayout(main);
       ui->area->setText("area: " + QString::number(data->getYonjeLand()->getArea()));
       ui->level->setText("level: " + QString::number(data->getYonjeLand()->getLevel()));

       main->setVerticalSpacing(0);
       QWidget* w = new QWidget;
       w->setLayout(main);
       ui->scrollArea->setWidget(w);

       if(!data->getYonjeLand()->isKesht() && !data->getYonjeLand()->isShokhm())
           ui->work->setHidden(true);

       if(data->getYonjeLand()->get_time()<0)
           ui->up->setHidden(true);

       pb3->setText("kasht");
       pb5->setText("shokhm");
       bardasht->setText("Bardasht");

       connect(pb3,SIGNAL(clicked()),this,SLOT(kesht()));
       connect(pb5,SIGNAL(clicked()),this,SLOT(shokhm()));
       connect(ui->sabt,SIGNAL(clicked()),this,SLOT(sabt()));
       connect(bardasht,SIGNAL(clicked()),this,SLOT(bardasht_()));
       connect(up_level,SIGNAL(clicked()),this,SLOT(uplevel()));

}

void Yonje::buttons(){
    QPushButton* button = (QPushButton*)sender();
    int i;
    for(i=0;i<10;i++){
        if(button==&kol[i])
            break;
    }

    if(w == 1){
        if(data->getYonjeLand()->at(i)==2){
            if(data->getAnbar()->getYonje()){
                data->getYonjeLand()->setAt(i,1);
                kol[i].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
                data->getYonjeLand()->setKesht(true);
                data->getYonjeLand()->setShokhm(false);
                data->getYonjeLand()->setBardasht(false);
                data->getAnbar()->ChangeYonje(-1);
                pb3->setToolTip("Yonje: " + QString::number(data->getAnbar()->getYonje()));
            }
            else{
                khata* payam = new khata(nullptr,"there is no Yonje in Storage");
                payam->show();
            }
        }
        else{
            khata* payam = new khata(nullptr,"This part has not been plowed yet");
            payam->show();
        }
    }

    else if(w == 2){
        if(data->getYonjeLand()->at(i)==3){
            if(data->getsilo()->getSpace()>=2){
                kol[i].setStyleSheet("QPushButton {border-image:url(:icons/khack.jpeg);border:2px;border-radius:40px;}");
                data->getAnbar()->ChangeYonje(2);
                pb3->setToolTip("Yonje: " + QString::number(data->getAnbar()->getYonje()));
                data->getYonjeLand()->setAt(i,0);
            }
            else{
                khata* payam = new khata(nullptr,"No Space in Anbar");
                payam->show();
            }

        }
    }

    else if(w == 3){
        if(data->getCoin()>=5){
            data->getYonjeLand()->setAt(i,2);
            kol[i].setStyleSheet("QPushButton {border-image:url(:icons/shokhm.jpg);border:2px;border-radius:40px;}");
            data->getYonjeLand()->setKesht(false);
            data->getYonjeLand()->setShokhm(true);
            data->getYonjeLand()->setBardasht(false);
            data->operator-=(5);
        }
        else{
            khata* payam = new khata(nullptr,"No enough coins");
            payam->show();
        }
    }
}

void Yonje::sabt(){
    int num = data->getYonjeLand()->getArea();
    for(int j=0;j<num;kol[j].setEnabled(false),j++);
    ui->sabt->setHidden(true);
    if(w==2){
        int n=1;
        for(int j=0;j<num;j++){
            if(data->getYonjeLand()->at(j)==3){
                n=0;
                break;
            }
        }
        if(n) data->getYonjeLand()->setBardasht(true);
    }
    if(w==1 && data->getYonjeLand()->isKesht()){
        data->getYonjeLand()->setTime_work(4*60);
    }
    else if(w==3 && data->getYonjeLand()->isShokhm()){
        data->getYonjeLand()->setTime_work(60);
    }
}

void Yonje::kesht(){
    if(data->getYonjeLand()->isKesht()){
        khata* payam = new khata(nullptr,"You have already planted yonje");
        payam->show();
    }
    else if(data->getYonjeLand()->isShokhm()){
        khata* payam = new khata(nullptr,"The farm is plowing");
        payam->show();
    }
    else if(!data->getYonjeLand()->isBardasht()){
        khata* payam = new khata(nullptr,"You have not yet fully harvested the gandom");
        payam->show();
    }
    else{
        if(ui->sabt->isHidden()){
            w=1;
            int num = data->getYonjeLand()->getArea();
            for(int j=0;j<num;kol[j].setEnabled(true),j++);
            ui->sabt->setHidden(false);
        }
        else{
            khata* payam = new khata(nullptr,"First Accept changes");
            payam->show();
        }
    }
}

void Yonje::shokhm(){
    if(data->getYonjeLand()->isKesht()){
        khata* payam = new khata(nullptr,"You have already planted yonje");
        payam->show();
    }
    else if(data->getYonjeLand()->isShokhm()){
        khata* payam = new khata(nullptr,"The farm is plowing");
        payam->show();
    }
    else if(!data->getYonjeLand()->isBardasht()){
        khata* payam = new khata(nullptr,"You have not yet fully harvested the gandom");
        payam->show();
    }
    else{
        if(ui->sabt->isHidden()){
            w=3;
            int num = data->getYonjeLand()->getArea();
            for(int j=0;j<num;kol[j].setEnabled(true),j++);
            ui->sabt->setHidden(false);
        }
        else {
            khata* payam = new khata(nullptr,"First Accept changes");
            payam->show();
        }
    }
}

void Yonje::bardasht_(){
    if(data->getYonjeLand()->isKesht()){
        khata* payam = new khata(nullptr,"Wait until the gandom is done");
        payam->show();
    }
    else{
        w=2;
        int num = data->getYonjeLand()->getArea();
        for(int j=0;j<num;kol[j].setEnabled(true),j++);
        ui->sabt->setHidden(false);
    }
}

void Yonje::uplevel(){
    if(data->getYonjeLand()->get_time()<0){
    QMessageBox msgBox;
//     msgBox.setText("are you sure you want to upgrade?");
    msgBox.setInformativeText("are you sure you want to upgrade?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setStyleSheet("color : white; background-color : red");
    int ret = msgBox.exec();

    switch (ret) {
       case QMessageBox::Yes:

        if(data->isCanAddLevelYonje()){
            data->getAnbar()->ChangeBil(-2);
            data->operator-=(5);
            data->addExp(3);
            data->getYonjeLand()->setTime(180);
            QString str = "YONJE LAND WILL BE UPGRADED IN 3 DAYS!";
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
        QString str = "YONJE LAND ALREADY IS UPGRADING!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
}

void Yonje::back_to_map(){
   Widget* temp = new Widget(nullptr, data);
   temp->showFullScreen();
   this->destroy();
}

void Yonje::set(){
    ui->area->setText("Area: " + QString::number(data->getYonjeLand()->getArea()));
    ui->level->setText("Level: " + QString::number(data->getYonjeLand()->getLevel()));

    ui->up->setText("Time to Level up: " + QString::number(data->getYonjeLand()->get_time()/60) + ":" +
                    QString::number(data->getYonjeLand()->get_time()%60));

    ui->work->setText("Time to get Yonje: " + QString::number(data->getYonjeLand()->get_time_work()/60) + ":" +
                    QString::number(data->getYonjeLand()->get_time_work()%60));
}

void Yonje::check(){
    if(data->getYonjeLand()->get_time()<=0)
        ui->up->setHidden(true);
    if(data->getYonjeLand()->get_time_work()<=0)
        ui->work->setHidden(true);

    int num = data->getYonjeLand()->getArea();
    for(int h=0;h<num;h++){
               if(data->getYonjeLand()->at(h) == 0)
                   kol[h].setStyleSheet("QPushButton {border-image:url(:icons/khack.jpg);border:2px;border-radius:40px;}");
               else if(data->getYonjeLand()->at(h) == 1){
                       kol[h].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
               }
               else if(data->getYonjeLand()->at(h) == 2)
                   kol[h].setStyleSheet("QPushButton {border-image:url(:icons/shokhm.jpg);border:2px;border-radius:40px;}");
               else if(data->getYonjeLand()->at(h) == 3)
                   kol[h].setStyleSheet("QPushButton {border-image:url(:icons/Yon_last.jpg);border:2px;border-radius:40px;}");
    }
}


void Yonje::go_to_gandom_widget(){
   Gandom* temp = new Gandom(nullptr, data);
   temp->showFullScreen();
   this->destroy();
}

Yonje::~Yonje()
{
    delete ui;
}
