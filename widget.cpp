#include "widget.h"
#include "storage.h"
#include <QMovie>
#include <siloo.h>
#include <aval.h>
#include <store.h>
#include <ranking.h>
#include "gandom.h"
#include "animals_place.h"
#include "msg.h"
#define AAA


void Time(Data* _data, Widget* w){
        QThread::sleep(1);
       _data->AddTime(1);

       /*if(_data->getTime_build_aqol()>0)
           _data->Add_build_aqol(-1);
       if(_data->getTime_build_aqol()==0){
            _data->getAqol()->setBuild(true);
            _data->set_build_aqol(-1);
            QString str = "Aqol build Successfully";
            msg* payam = new msg(nullptr, &str);
            payam->show();
       }

       if(_data->getTime_build_gav()>0)
           _data->Add_build_gav(-1);
       if(_data->getTime_build_gav()==0){
           _data->set_build_gav(-1);
           _data->getGav()->setBuild(true);
           QString str = "Gavdari build Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getTime_build_morq()>0)
           _data->Add_build_morq(-1);
       if(_data->getTime_build_morq()==0){
           _data->getMorq()->setBuild(true);
           _data->set_build_morq(-1);
           QString str = "Morqdari build Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getTime_build_yonje()>0)
           _data->Add_build_yonje(-1);
       if(_data->getTime_build_yonje()==0){
           _data->set_build_yonje(-1);
           _data->getYonjeLand()->setBuilds(true);
           QString str = "Yonje land build Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getAqol()->get_Time()>0)
           _data->getAqol()->Add_Time(-1);
       if(_data->getAqol()->get_Time()==0){
           ////////////////////////
           _data->getAqol()->set_Time(-1);
           QString str = "Aqol Level up Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getAqol()->get_Time_food()>0)
           _data->getAqol()->Add_Time_food(-1);
       if(_data->getAqol()->get_Time_food()==0){
           ///////////////
           _data->getAqol()->set_Time_food(-1);
           QString str = "The sheep_osarus are ready to be bred";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getGav()->get_Time()>0)
           _data->getGav()->Add_Time(-1);
       if(_data->getGav()->get_Time()==0){
           /////////////////////////
           _data->getGav()->set_Time(-1);
           QString str = "Aqol Level up Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getGav()->get_Time_food()>0)
           _data->getGav()->Add_Time_food(-1);
       if(_data->getGav()->get_Time_food()==0){
           ///////////////////////
           _data->getGav()->set_Time_food(-1);
           QString str = "The cow_osarus are ready to be bred";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getMorq()->get_Time()>0)
           _data->getMorq()->Add_Time(-1);
       if(_data->getMorq()->get_Time()==0){
           //////////////////
           _data->getMorq()->set_Time(-1);
           QString str = "Aqol Level up Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getMorq()->get_Time_food()>0)
           _data->getMorq()->Add_Time_food(-1);
       if(_data->getMorq()->get_Time_food()==0){
           //////////////////////
           _data->getMorq()->set_Time_food(-1);
           QString str = "The hen_osarus are ready to be bred";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getAnbar()->get_time()>0)
           _data->getAnbar()->AddTime(-1);
       if(_data->getAnbar()->get_time()==0){
           //////////////////////
           _data->getAnbar()->setTime(-1);
           QString str = "Storage Level up Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getsilo()->get_time()>0)
           _data->getsilo()->AddTime(-1);
       if(_data->getsilo()->get_time()==0){
           //////////////////////
           _data->getsilo()->setTime(-1);
           QString str = "Siloo Level up Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getGandomLand()->get_time()>0)
           _data->getGandomLand()->Add_Time(-1);
       if(_data->getGandomLand()->get_time()==0){
           //////////////////////
           _data->getGandomLand()->setTime(-1);
           QString str = "Gandom land Level up Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }


       if(_data->getGandomLand()->get_time_work()>0)
           _data->getGandomLand()->Add_Time_work(-1);
       if(_data->getGandomLand()->get_time_work()==0){
           //////////////////////
           _data->getGandomLand()->setTime_work(-1);
           QString str = "";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }

       if(_data->getYonjeLand()->get_time()>0)
           _data->getYonjeLand()->Add_Time(-1);
       if(_data->getYonjeLand()->get_time()==0){
           //////////////////////
           _data->getYonjeLand()->setTime(-1);
           QString str = "Yonje land Level up Successfully";
           msg* payam = new msg(nullptr, &str);
           payam->show();
       }*/

       if(_data->getYonjeLand()->get_time_work()>0)
           _data->getYonjeLand()->Add_Time_work(-1);
       if(_data->getYonjeLand()->get_time_work()==0){
           //////////////////////
           QString str;
           _data->getYonjeLand()->setTime_work(-1);
           if(_data->getYonjeLand()->isShokhm())
               str = "Yonje land was successfully plowed";
           else
               str = "Yonje was successfully cultivated";


           msg* payam = new msg(nullptr, &str);
           payam->show();
       }
        w->set();
    if(_data->getTime()>=3600){
        _data->nextDay(2);
        _data->setTime(0);
        QString str = "1 hour passed! we are in Tomorrow!!";
        msg* payam = new msg(nullptr, &str);
        payam->show();
    }
    return Time(_data,w);
}

Widget::Widget(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    data = _data;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/farm3.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    siloo_butt = new QPushButton(this);
    siloo_butt->setMinimumHeight(40);
    siloo_butt->setMinimumWidth(100);
    siloo_butt->setMaximumHeight(40);
    siloo_butt->setMaximumWidth(100);
    siloo_butt->move(611,600);
    siloo_butt->setStyleSheet("QPushButton{background:transparent;}");
    siloo_butt->setCursor(Qt::PointingHandCursor);

    store_butt = new QPushButton(this);
    store_butt->setMinimumHeight(120);
    store_butt->setMinimumWidth(80);
    store_butt->setMaximumHeight(120);
    store_butt->setMaximumWidth(80);
    store_butt->move(644,100);
    store_butt->setStyleSheet("QPushButton{background:transparent;}");
    store_butt->setCursor(Qt::PointingHandCursor);

    places_butt = new QPushButton(this);
    places_butt->setMinimumHeight(180);
    places_butt->setMinimumWidth(200);
    places_butt->setMaximumHeight(180);
    places_butt->setMaximumWidth(200);
    places_butt->move(600,228);
    places_butt->setStyleSheet("QPushButton{background:transparent;}");
    places_butt->setCursor(Qt::PointingHandCursor);

    lands_butt = new QPushButton(this);
    lands_butt->setMinimumHeight(150);
    lands_butt->setMinimumWidth(220);
    lands_butt->setMaximumHeight(150);
    lands_butt->setMaximumWidth(220);
    lands_butt->move(200,280);
    lands_butt->setStyleSheet("QPushButton{background:transparent;}");
    lands_butt->setCursor(Qt::PointingHandCursor);

    storage_butt = new QPushButton(this);
    storage_butt->setMinimumHeight(100);
    storage_butt->setMinimumWidth(100);
    storage_butt->setMaximumHeight(100);
    storage_butt->setMaximumWidth(100);
    storage_butt->move(745,470);
    storage_butt->setStyleSheet("QPushButton{background:transparent;}");
    storage_butt->setCursor(Qt::PointingHandCursor);

    coins_pic = new QLabel(this);
    coins_pic->setToolTip("number of coins");
    QPixmap* temp = new QPixmap(":icons/coins.png");
    coins_pic->setPixmap(temp->scaled(QSize(40,40)));
    coins_pic->move(20,20);

    coins_txt = new QLabel(this);
    coins_txt->setText("1000000000000");
#ifdef AAA
    coins_txt->setText(QString::number(data->getCoin()));
#endif
    QFont font3 = coins_txt->font();
    font3.setBold(true);
    font3.setPointSize(15);
    coins_txt->setFont(font3);
    coins_txt->setStyleSheet("color: rgb(153,153,0)");
    coins_txt->move(75,20);

    time_pic = new QLabel(this);
    time_pic->setToolTip("number of days passed");
    QPixmap* temp2 = new QPixmap(":icons/time.png");
    time_pic->setPixmap(temp2->scaled(QSize(40,40)));
    time_pic->move(20,75);

    xp_ = new QLabel(this);
    xp_->setToolTip("experience");
    QPixmap* temp5 = new QPixmap(":icons/xp.png");
    xp_->setPixmap(temp5->scaled(QSize(40,40)));
    xp_->move(20,132);

    lvl_ = new QLabel(this);
    QPixmap* temp6 = new QPixmap(":icons/up.png");
    lvl_->setPixmap(temp6->scaled(QSize(48,48)));
    lvl_->move(20,183);
    lvl_->setToolTip("level");

    lvl_txt = new QLabel( this);
    lvl_txt->setText("20");

#ifdef AAA
    lvl_txt->setText(QString::number(data->getLevel()));
#endif

    font3 = lvl_txt->font();
    font3.setBold(true);
    font3.setPointSize(15);
    lvl_txt->setFont(font3);
    lvl_txt->setStyleSheet("color: #176C5B");
    lvl_txt->move(75,193);

    back_to_main_menu = new QPushButton(this);
    back_to_main_menu->setMinimumHeight(48);
    back_to_main_menu->setMinimumWidth(48);
    back_to_main_menu->setMaximumHeight(48);
    back_to_main_menu->setMaximumWidth(48);
    back_to_main_menu->move(1300, 75);
    back_to_main_menu->setStyleSheet("QPushButton {border-image:url(:icons/back.png);}"
                                      );
    back_to_main_menu->setToolTip("Back to main menu");
    back_to_main_menu->setCursor(Qt::PointingHandCursor);

    one_day_forward = new QPushButton(this);
    one_day_forward->setMinimumHeight(40);
    one_day_forward->setMinimumWidth(40);
    one_day_forward->setMaximumHeight(40);
    one_day_forward->setMaximumWidth(40);
    one_day_forward->move(1300, 20);
    one_day_forward->setCursor(Qt::PointingHandCursor);
    one_day_forward->setStyleSheet("QPushButton {border-image:url(:icons/forward.png);}");
    one_day_forward->setToolTip("One Day Forward");

    rankings = new QPushButton(this);
    rankings->setMinimumHeight(40);
    rankings->setMinimumWidth(40);
    rankings->setMaximumHeight(40);
    rankings->setMaximumWidth(40);
    rankings->move(1300, 130);
    rankings->setCursor(Qt::PointingHandCursor);
    rankings->setStyleSheet("QPushButton {border-image:url(:icons/rank.png);}");
    rankings->setToolTip("see players rankings");

    exp_bar = new QProgressBar(this);
    exp_bar->setMinimumHeight(12);
    exp_bar->setMinimumWidth(160);
    exp_bar->setMaximumHeight(12);
    exp_bar->setMaximumWidth(160);
    exp_bar->move(75,150);
    exp_bar->setStyleSheet("QProgressBar {"
                          "background-color: #EEC677;"
                          "color: #FFFFFF;"
                          "border-style: outset;"
                          "border-width: 2px;"
                          "border-color: #176C5B;"
                          "border-radius: 7px;"
                          "text-align: left; }"

                          "QProgressBar::chunk {"
                          "background-color: #176C5B; }");
    exp_bar->setValue(80);


#ifdef AAA
    exp_bar->setValue((data->getTime() * 100)/3600);
    exp_bar->setValue((data->getExperience() * 100)/data->getCapacity());
#endif

    time_bar = new QProgressBar(this);
    time_bar->setMinimumHeight(12);
    time_bar->setMinimumWidth(160);
    time_bar->setMaximumHeight(12);
    time_bar->setMaximumWidth(160);
    time_bar->move(75,92);
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

    connect(storage_butt, SIGNAL(clicked()), this, SLOT(storage_slot()));

    QMovie* movie = new QMovie(":gifs/dave.gif");
    QLabel* label = new QLabel(this);
    label->move(30,600);
    // Make sure the GIF was loaded correctly
    if (!movie->isValid())
    {
        label->setText("mammad");
    }
    else{
        label->setMovie(movie);
        movie->start();
    }

    QLabel* talk = new QLabel(this);
    QPixmap* temp7 = new QPixmap(":icons/talk1.png");
    talk->setPixmap(temp7->scaled(QSize(200,185)));
    talk->move(170,480);

    connect(siloo_butt, SIGNAL(clicked()), this, SLOT(siloo_slot()));
    connect(back_to_main_menu, SIGNAL(clicked()), this, SLOT(back_slot()));
    connect(store_butt, SIGNAL(clicked()), this, SLOT(store_slot()));
    connect(rankings, SIGNAL(clicked()), this, SLOT(rank_slot()));
    connect(lands_butt, SIGNAL(clicked()), this, SLOT(lands_slot()));
    connect(places_butt, SIGNAL(clicked()), this, SLOT(animals_slot()));

    t = QThread::create(Time,data,this);
    t->start();

}

Widget::~Widget()
{

}

void Widget::storage_slot(){
    storage* temp = new storage(nullptr, data);
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}

void Widget::siloo_slot(){
    siloo* temp = new siloo(nullptr, data);
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}

void Widget::back_slot(){
    aval* temp = new aval;
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}

void Widget::store_slot(){
   store* temp = new store(nullptr, data);
   temp->showFullScreen();
   t->terminate();
   this->destroy();
}

void Widget::rank_slot(){
    Ranking* temp = new Ranking(nullptr, data);
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}

void Widget::lands_slot(){
    Gandom* temp = new Gandom(nullptr, data);
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}

void Widget::animals_slot(){
    Animals_Place* temp = new Animals_Place(nullptr,data);
    temp->showFullScreen();
    t->terminate();
    this->destroy();
}
