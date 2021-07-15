#include "gandom.h"
#include "yonje.h"
#include "msg.h"
#include "khata.h"
#include "ui_gandom.h"

Gandom::Gandom(QWidget *parent, Data* _data) :
    QWidget(parent),
    ui(new Ui::Gandom)
{
    w = 0;
    data = _data;
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
          connect(pb2, SIGNAL(clicked()), this , SLOT(go_to_yonjeh_widget()));
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
              pb3->setCursor(Qt::ClosedHandCursor);

              pb4=new QPushButton;
              pb4->move (1200,150);
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
                time_bar = new QProgressBar(this);
                time_bar->setMinimumHeight(25);
                time_bar->setMinimumWidth(700);
                time_bar->setMaximumHeight(25);
                time_bar->setMaximumWidth(700);
                time_bar->move(323,30);
                time_bar->setStyleSheet("QProgressBar {"
                                      "background-color: #EEC677;"
                                      "color: #FFFFFF;"
                                      "border-style: outset;"
                                      "border-width: 2px;"
                                      "border-color: #176C5B;"
                                      "border-radius: 7px;"
                                      "text-align: left; }"

                                      "QProgressBar::chunk {"
                                      "background-color: #176C5B; }");



            connect(pb1, SIGNAL(clicked()), this , SLOT(back_to_map()));
            pb1->setParent(this);
            pb2->setParent(this);
            pb3->setParent(this);
            pb4->setParent(this);
            time_bar->setParent(this);
            ui->setupUi(this);

            ui->sabt->setHidden(true);

            gan = new QPushButton(this);
            gan->move(20,300);
            gan->setText(QString::fromLatin1(to_string(data->getsilo()->getCount())));

            build = new QPushButton(this);
            build->setText("Build");
            build->setHidden(true);
            build->setEnabled(false);

            main = new QGridLayout;
            int num = data->getGandomLand()->getArea();
            kol = new QPushButton[num];
            for(int h=0;h<num;h++){
                if(data->getGandomLand()->at(h) == 0)
                    kol[h].setStyleSheet("QPushButton {border-image:url(:icons/kh-y.jpeg);border:2px;border-radius:40px;}");
                else if(data->getGandomLand()->at(h) == 1)
                        kol[h].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
                else if(data->getGandomLand()->at(h) == 3)
                    kol[h].setStyleSheet("QPushButton {border-image:url(:icons/gando.jpg);border:2px;border-radius:40px;}"
                    " QPushButton::hover{border-image:url(:icons/gando2.jpg);}");
                main->addWidget(&kol[h],h/5,h%5);
                kol[h].setFixedSize(80,80);
                connect(&kol[h],SIGNAL(clicked()),this,SLOT(buttons()));
            }

            ui->scrollArea->setLayout(main);
            main->setSpacing(0);

            if(data->getLevel()<3){
                pb2->setStyleSheet("QPushButton {border-image:url(:backgrounds/yonjeh4.jpg);border:2px;border-radius:40px;}");
            }
            else{
                if(!data->getYonjeLand()->isBuild()){
                    build->setHidden(false);
                    build->setEnabled(true);
                }
            }

            connect(pb3,SIGNAL(clicked()),this,SLOT(kesht()));
            connect(ui->sabt,SIGNAL(clicked()),this,SLOT(sabt()));
            //connect(pb3,SIGNAL(clicked()),this,SLOT(bardasht()));
    }

void Gandom::back_to_map(){
        Widget* temp = new Widget(nullptr, data);
        temp->showFullScreen();
        this->destroy();
}

void Gandom::go_to_yonjeh_widget(){
    if(data->getLevel()>=3){
        if(data->getYonjeLand()->isBuild()){
            Yonje* temp = new Yonje(nullptr, data);
            temp->showFullScreen();
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
            gan->setText(QString::fromLatin1(to_string(data->getsilo()->getCount())));
        }
        else{
            khata* payam = new khata(nullptr,"there is no gandom in siloo");
            payam->show();
        }
    }
    else if(w == 2){
        if(data->getGandomLand()->at(i)==3){
            if(data->getsilo()->getSpace()>=2){
                kol[i].setStyleSheet("QPushButton {border-image:url(:icons/y1.jfif);border:2px;border-radius:40px;}");
                data->getsilo()->operator+=(2);
                gan->setText(QString::fromLatin1(to_string(data->getsilo()->getCount())));
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
        pb2->setEnabled(true);
        build->setEnabled(true);
        pb3->setEnabled(true);
        int num = data->getGandomLand()->getArea();
        for(int j=0;j<num;kol[j].setEnabled(false),j++);
        ui->sabt->setHidden(true);
    }
}

void Gandom::build_(){
    if(data->getTime_build_yonje()>0){

    }
}

void Gandom::uplevel(){
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


Gandom::~Gandom()
{
    delete ui;
}
