#include "yonje.h"
#include "gandom.h"
#include "ui_yonje.h"
#include "msg.h"
#include "khata.h"

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

       yon = new QPushButton(this);
       yon->move(20,300);
       yon->setText("Yonje: " + QString::number(data->getsilo()->getCount()));

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
           kol[h].setFixedSize(80,80);
           connect(&kol[h],SIGNAL(clicked()),this,SLOT(buttons()));
       }

       ui->scrollArea->setLayout(main);
       ui->area->setText("area: " + QString::number(data->getYonjeLand()->getArea()));
       ui->level->setText("level: " + QString::number(data->getYonjeLand()->getLevel()));
       main->setSpacing(0);

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
                yon->setText("Yonje: " + QString::number(data->getAnbar()->getYonje()));
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
                yon->setText(QString::number(data->getAnbar()->getYonje()));
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

void Yonje::go_to_gandom_widget(){
   Gandom* temp = new Gandom(nullptr, data);
   temp->showFullScreen();
   this->destroy();
}

Yonje::~Yonje()
{
    delete ui;
}
