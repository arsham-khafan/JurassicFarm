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
                pb4->setCursor(Qt::ClosedHandCursor);
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

            time_bar->setToolTip("time passed: "/* + QString::number(data->getsilo()->getLevel())*/);

            connect(pb1, SIGNAL(clicked()), this , SLOT(back_to_map()));
            pb1->setParent(this);
            pb2->setParent(this);
            pb3->setParent(this);
            pb4->setParent(this);
            time_bar->setParent(this);
            ui->setupUi(this);

            ui->sabt->setStyleSheet("QPushButton {border:2px;border-radius:40px;}");

            gan = new QPushButton(this);
            gan->move(20,300);
            gan->setText(QString::fromLatin1(to_string(data->getsilo()->getCount())));

            build = new QPushButton(this);
            build->setText("Build");
            build->setHidden(true);

            main = new QGridLayout;
            int num = data->getGandomLand()->getArea();
            kol = new QPushButton[num];
            for(int h=0;h<num;h++){
                if(data->getGandomLand()->at(h) == 0)
                    setStyleSheet("QPushButton {border-image:url(:icons/masahat1.png);border:2px;border-radius:40px;}");
                else if(data->getGandomLand()->at(h) == 1){
                    if(time_bar->value()>=50)
                        setStyleSheet("QPushButton {border-image:url(:icons/masahat1.png);border:2px;border-radius:40px;}");
                    else if(time_bar->value()>0 && time_bar->value()<50)
                        setStyleSheet("QPushButton {border-image:url(:icons/masahat1.png);border:2px;border-radius:40px;}");
                }
                else if(data->getGandomLand()->at(h) == 3)
                    setStyleSheet("QPushButton {border-image:url(:icons/masahat1.png);border:2px;border-radius:40px;}");
            }


    }

void Gandom::back_to_map(){
        Widget* temp = new Widget(nullptr, data);
        temp->showFullScreen();
        this->destroy();
}

void Gandom::go_to_yonjeh_widget(){
        Yonje* temp = new Yonje(nullptr, data);
        temp->showFullScreen();
        this->destroy();
}

void Gandom::buttons(){
    QPushButton* button = (QPushButton*)sender();
    int i;
    for(i=0;i<10;i++){
        if(button==&kol[i])
            break;
    }

    if(w == 1){
        data->getGandomLand()->setAt(i,1);
        kol[i].setStyleSheet("background-color: Yellow");
        data->getGandomLand()->setKesht(true);
        data->getGandomLand()->setBardasht(true);
    }
    else if(w == 2){
        if(data->getGandomLand()->at(i)==3){
            if(data->getsilo()->getSpace()>=2){
                kol[i].setStyleSheet("background-color: Yellow");
                data->getsilo()->operator+=(2);
                gan->setText(QString::fromLatin1(to_string(data->getsilo()->getCount())));
                data->getGandomLand()->setAt(i,0);
            }
            else{
                khata* payam = new khata(this,"No Space in siloo");
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

}

void Gandom::kesht(){

}

void Gandom::bardasht(){

}

Gandom::~Gandom()
{
    delete ui;
}
