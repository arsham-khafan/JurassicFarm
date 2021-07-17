#include "gandom.h"
#include "yonje.h"
#include "msg.h"
#include "khata.h"
#include "ui_gandom.h"

void Time(Data* _data, Gandom* w){
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
           w->check();
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
           w->check();
       }


       if(_data->getGandomLand()->get_time_work()>0)
           _data->getGandomLand()->Add_Time_work(-1);
       if(_data->getGandomLand()->get_time_work()==0){
           _data->getGandomLand()->setKesht(false);
           _data->getGandomLand()->setTime_work(-1);
           str = "Gandom Land is Ready to Bardasht!!!!\n";
           _data->done(1);
           w->check();
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
    }

    return Time(_data,w);
}

Gandom::Gandom(QWidget *parent, Data* _data) :
    QWidget(parent),
    ui(new Ui::Gandom)
{
    w = 0;
    data = _data;

    ref = new QPushButton(this);
    ref->move(30,300);
    ref->setFixedSize(50,50);
    ref->setStyleSheet("QPushButton {border-image:url(:icons/ref.png);border:2px;border-radius:40px;}");


    time_build = new QLabel(this);
    time_build->setText("Time to Build: " + QString::number(data->getTime_build_yonje()/60)+":"+ QString::number(data->getTime_build_yonje()%60));
    if(data->getTime_build_yonje()<=0)
        time_build->setHidden(true);
    time_build->move(20,260);
    time_build->setFixedSize(200,30);

    this->setMinimumHeight(768);
            this->setMinimumWidth(1366);
            this->setMaximumHeight(768);
            this->setMaximumWidth(1366);
        setAutoFillBackground(true);
        QPixmap pixmap=QPixmap(":backgrounds/gandom.jpg").scaled(this->size());
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
          pb2->setStyleSheet("QPushButton {border-image:url(:backgrounds/yonjeh.jpg);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/yonjeh3.jpg);} ");
          pb2->setToolTip("alfalfa field");
          pb2->setCursor(Qt::ClosedHandCursor);
          pb1->move(10,10);
          pb1->setMinimumHeight(100);
          pb1->setMinimumWidth(100);
            pb1->setMaximumHeight(100);
            pb1->setMaximumWidth(100);
            pb1->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
        "                           QPushButton::hover{border-image:url(:icons/back22.png);} ");
            pb1->setToolTip("back to map");
            pb1->setCursor(Qt::ClosedHandCursor);

            pb3=new QPushButton;
            pb3->move (1200,10);
            pb3->setMinimumHeight(100);
            pb3->setMinimumWidth(100);
              pb3->setMaximumHeight(100);
              pb3->setMaximumWidth(100);
              pb3->setStyleSheet("QPushButton {border-image:url(:icons/kasht1.jpg);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/kasht2.jpg);} ");
              pb3->setToolTip("planting");
              pb3->setToolTip("Gandom: " + QString::number(data->getsilo()->getCount()));
              pb3->setCursor(Qt::ClosedHandCursor);

              pb4=new QPushButton;
              pb4->move (1200,290);
              pb4->setMinimumHeight(100);
              pb4->setMinimumWidth(100);
                pb4->setMaximumHeight(100);
                pb4->setMaximumWidth(100);
                pb4->setStyleSheet("QPushButton {border-image:url(:icons/masahat1.png);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/masahat2.png);} ");
                pb4->setToolTip("land area");
                up_level = new QPushButton(this);
                up_level->setMinimumHeight(166);
                up_level->setMinimumWidth(500);
                up_level->setMaximumHeight(166);
                up_level->setMaximumWidth(500);
                up_level->move(433, 100);
                up_level->setStyleSheet("QPushButton {border-image:url(:icons/upgrade.png);}"
            "                           QPushButton::hover{border-image:url(:icons/upgrade2.png);} ");
                up_level->setToolTip("Upgrade wheat field");


            connect(up_level,SIGNAL(clicked()),this,SLOT(uplevel()));
            connect(pb1, SIGNAL(clicked()), this , SLOT(back_to_map()));
            pb1->setParent(this);
            pb2->setParent(this);
            pb3->setParent(this);
            pb4->setParent(this);
            ui->setupUi(this);

            ui->sabt->setHidden(true);

            ui->area->setText("Area: " + QString::number(data->getGandomLand()->getArea()));
            ui->level->setText("Level: " + QString::number(data->getGandomLand()->getLevel()));

            ui->up->setText("Time to Level up: " + QString::number(data->getGandomLand()->get_time()/60) + ":" +
                            QString::number(data->getGandomLand()->get_time()%60));

            ui->work->setText("Time to get gandom: " + QString::number(data->getGandomLand()->get_time_work()/60) + ":" +
                            QString::number(data->getGandomLand()->get_time_work()%60));

            QFont font3 = ui->area->font();
            font3.setBold(true);
            font3.setPointSize(15);
            ui->area->setFont(font3);
            ui->up->setFont(font3);
            ui->level->setFont(font3);
            ui->work->setFont(font3);

            if(data->getGandomLand()->get_time()<0)
                ui->up->setHidden(true);
            if(data->getGandomLand()->get_time_work()<0)
                ui->work->setHidden(true);


            build = new QPushButton(this);
            build->setText("Build");
            build->setHidden(true);
            build->setEnabled(false);
            build->move(20,260);
            build->setStyleSheet("background-color: #F0AD10");

            main = new QGridLayout;
            int num = data->getGandomLand()->getArea();
            kol = new QPushButton[40];
            for(int h=0;h<num;h++){
                if(data->getGandomLand()->at(h) == 0)
                    kol[h].setStyleSheet("QPushButton {border-image:url(:icons/kh-y.jpeg);border:2px;border-radius:40px;}");
                else if(data->getGandomLand()->at(h) == 1)
                        kol[h].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
                else if(data->getGandomLand()->at(h) == 3)
                    kol[h].setStyleSheet("QPushButton {border-image:url(:icons/gando.jpg);border:2px;border-radius:40px;}"
                    " QPushButton::hover{border-image:url(:icons/gando2.jpg);}");
                main->addWidget(&kol[h],h/5,h%5);
                kol[h].setFixedSize(100,100);
                connect(&kol[h],SIGNAL(clicked()),this,SLOT(buttons()));
            }

            main->setVerticalSpacing(0);
            QWidget* w = new QWidget;
            w->setLayout(main);
            ui->scrollArea->setWidget(w);

            if(data->getLevel()<3){
                pb2->setStyleSheet("QPushButton {border-image:url(:icons/yonjeh4.jpg);border:2px;border-radius:40px;}");
            }
            else{
                if(!data->getYonjeLand()->isBuild()){
                    build->setHidden(false);
                    build->setEnabled(true);
                }
            }

            bar = new QPushButton(this);
            bar->move (1200,150);
            bar->setMinimumHeight(100);
            bar->setMinimumWidth(100);
              bar->setMaximumHeight(100);
              bar->setMaximumWidth(100);
              bar->setStyleSheet("QPushButton {border-image:url(:icons/yonjeh3.jpg);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/kasht2.jpg);} ");
              bar->setToolTip("Bardasht");
              bar->setText("Bardasht");
              bar->setCursor(Qt::ClosedHandCursor);

            connect(pb3,SIGNAL(clicked()),this,SLOT(kesht()));
            connect(ui->sabt,SIGNAL(clicked()),this,SLOT(sabt()));
            connect(bar,SIGNAL(clicked()),this,SLOT(bardasht()));
            connect(pb2,SIGNAL(clicked()),this,SLOT(go_to_yonjeh_widget()));
            connect(build,SIGNAL(clicked()),this,SLOT(build_()));
            connect(ref,SIGNAL(clicked()),this,SLOT(check2()));


            t = QThread::create(Time,data,this);
                t->start();

                QString str = data->get_Message(7);
                if(!str.isEmpty()){
                    msg* payam = new msg(nullptr,&str);
                    payam->show();
                }
    }

void Gandom::back_to_map(){
        Widget* temp = new Widget(nullptr, data);
        temp->showFullScreen();
        t->terminate();
        this->destroy();
}

void Gandom::go_to_yonjeh_widget(){
    if(data->getLevel()>=3){
        if(data->getYonjeLand()->isBuild() && data->getTime_build_yonje()<0){
            Yonje* temp = new Yonje(nullptr, data);
            temp->showFullScreen();
            t->terminate();
            this->destroy();
        }
        else{
            khata* payam = new khata(nullptr,"Not Build yet");
            payam->show();
        }
    }
    else{
        khata* payam = new khata(nullptr,"open in level 3");
        payam->show();
    }
}

void Gandom::buttons(){
    QPushButton* button = (QPushButton*)sender();
    int i;
    for(i=0;i<10;i++){
        if(button==&kol[i])
            break;
    }

    if(w == 1){
        if(data->getsilo()->getCount()){
            data->getGandomLand()->setAt(i,1);
            kol[i].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
            data->getGandomLand()->setKesht(true);
            data->getGandomLand()->setBardasht(false);
            data->getsilo()->operator-=(1);
            data->addExp(1);
            pb3->setToolTip("Gandom: " + QString::fromLatin1(to_string(data->getsilo()->getCount())));
        }
        else{
            khata* payam = new khata(nullptr,"there is no gandom in siloo");
            payam->show();
        }
    }
    else if(w == 2){
        if(data->getGandomLand()->at(i)==3){
            if(data->getsilo()->getSpace()>=2){
                kol[i].setStyleSheet("QPushButton {border-image:url(:icons/kh-y.jpeg);border:2px;border-radius:40px;}");
                data->getsilo()->operator+=(2);
                pb3->setToolTip("Gandom: " + QString::fromLatin1(to_string(data->getsilo()->getCount())));
                data->getGandomLand()->setAt(i,0);
            }
            else{
                khata* payam = new khata(nullptr,"No Space in siloo");
                payam->show();
            }

        }
    }
}

void Gandom::sabt(){
    pb2->setEnabled(true);
    build->setEnabled(true);
    int num = data->getGandomLand()->getArea();
    for(int j=0;j<num;kol[j].setEnabled(false),j++);
    ui->sabt->setHidden(true);
    if(w==2){
        int n=1;
        for(int j=0;j<num;j++){
            if(data->getGandomLand()->at(j)==1){
                n=0;
                break;
            }
        }
        if(n) data->getGandomLand()->setBardasht(true);
    }
    if(w==1 && data->getGandomLand()->isKesht()){
        data->getGandomLand()->setTime_work(120);
        ui->work->setText("Time to get gandom: " + QString::number(data->getGandomLand()->get_time_work()/60) + ":" +
                        QString::number(data->getGandomLand()->get_time_work()%60));
        ui->work->setHidden(false);
    }
}

void Gandom::kesht(){
    if(data->getGandomLand()->isKesht()){
        khata* payam = new khata(nullptr,"You have already planted gandom");
        payam->show();
    }
    else if(!data->getGandomLand()->isBardasht()){
        khata* payam = new khata(nullptr,"You have not yet fully harvested the gandom");
        payam->show();
    }
    else{
        if(ui->sabt->isHidden()){
            w=1;
            pb2->setEnabled(false);
            build->setEnabled(false);
            int num = data->getGandomLand()->getArea();
            for(int j=0;j<num;kol[j].setEnabled(true),j++);
            ui->sabt->setHidden(false);
        }
        else if(w==2){
            khata* payam = new khata(nullptr,"First Accept changes");
            payam->show();
        }
    }
}

void Gandom::bardasht(){
    if(data->getGandomLand()->isKesht()){
        khata* payam = new khata(nullptr,"Wait until the gandom is done");
        payam->show();
    }
    else{
        w=2;
        pb2->setEnabled(false);
        build->setEnabled(false);
         data->addExp(1);
        int num = data->getGandomLand()->getArea();
        for(int j=0;j<num;kol[j].setEnabled(true),j++);
        ui->sabt->setHidden(false);
    }
}

void Gandom::build_(){
    if(data->getTime_build_yonje()>0){
        khata* payam = new khata(nullptr,"Already is Building");
        payam->show();
    }
    else if(data->isCanBuildYonje()){
        QMessageBox msgBox;
        msgBox.setInformativeText("Hen-saurus holding is not built yet do you want to build it? ");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Yes);
        msgBox.setStyleSheet("color : white; background-color : green");
        int ret = msgBox.exec();

        switch (ret) {
           case QMessageBox::Yes:
                data->BuildYonje();
                data->getYonjeLand()->setBuilds(true);
                data->set_build_yonje(180);
                data->addExp(6);
                build->setHidden(true);
                time_build->setHidden(false);
               break;
           case QMessageBox::Cancel:
               return;
               break;
           default:
               break;
         }
    }
    else{
        khata* payam = new khata(nullptr,"No Can Build");
        payam->show();
    }
}

void Gandom::uplevel(){
    if(data->getGandomLand()->get_time()<0){
    QMessageBox msgBox;
//     msgBox.setText("are you sure you want to upgrade?");
    msgBox.setInformativeText("are you sure you want to upgrade?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setStyleSheet("color : white; background-color : red");
    int ret = msgBox.exec();

    switch (ret) {
       case QMessageBox::Yes:

        if(data->isCanAddLevelgandom()){
            data->getAnbar()->ChangeBil(-2);
            data->operator-=(5);
            data->addExp(3);
            data->getGandomLand()->setTime(120);
            ui->up->setHidden(false);
            QString str = "Gandom LAND WILL BE UPGRADED IN 2 DAYS!";
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

void Gandom::set(){
    ui->area->setText("Area: " + QString::number(data->getGandomLand()->getArea()));
    ui->level->setText("Level: " + QString::number(data->getGandomLand()->getLevel()));


    if(data->getGandomLand()->get_time()<=0)
        ui->up->setText("");
    else
        ui->up->setText("Time to Level up: " + QString::number(data->getGandomLand()->get_time()/60) + ":" +
                        QString::number(data->getGandomLand()->get_time()%60));

    if(data->getGandomLand()->get_time_work()<=0)
        ui->work->setText("");
    else
        ui->work->setText("Time to get gandom: " + QString::number(data->getGandomLand()->get_time_work()/60) + ":" +
                        QString::number(data->getGandomLand()->get_time_work()%60));

    if(data->getTime_build_yonje()<=0)
            time_build->setText("");
    else
        time_build->setText("Time to Build: " + QString::number(data->getTime_build_yonje()/60)+":"+ QString::number(data->getTime_build_yonje()%60));

}

void Gandom::check(){
    if(data->getGandomLand()->get_time()<=0)
        ui->up->setText("");
    if(data->getGandomLand()->get_time_work()<=0)
        ui->work->setText("");

    if(data->getTime_build_yonje()<=0)
            time_build->setText("");
}

void Gandom::check2(){
    int num = data->getGandomLand()->getArea();
    for(int h=0;h<num;h++){
        if(data->getGandomLand()->at(h) == 0)
        kol[h].setStyleSheet("QPushButton {border-image:url(:icons/kh-y.jpeg);border:2px;border-radius:40px;}");
    else if(data->getGandomLand()->at(h) == 1)
            kol[h].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
    else if(data->getGandomLand()->at(h) == 3)
        kol[h].setStyleSheet("QPushButton {border-image:url(:icons/gando.jpg);border:2px;border-radius:40px;}"
        " QPushButton::hover{border-image:url(:icons/gando2.jpg);}");
    }
}

Gandom::~Gandom()
{
    delete ui;
}
