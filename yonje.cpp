#include "yonje.h"
#include "gandom.h"
#include "ui_yonje.h"
#include<QMovie>
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

          pb4=new QPushButton;
          pb4->move (1200,150);
          pb4->setMinimumHeight(100);
          pb4->setMinimumWidth(100);
            pb4->setMaximumHeight(100);
            pb4->setMaximumWidth(100);
            pb4->setStyleSheet("QPushButton {border-image:url(:icons/masahat1.png);border:2px;border-radius:40px;}" "QPushButton::hover{border-image:url(:icons/masahat2.png);} ");
            pb4->setToolTip("land area");
            pb4->setCursor(Qt::ClosedHandCursor);

            pb5=new QPushButton;
            pb5->move (1100,10);
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

        QMovie* movie = new QMovie(":gifs/yonjeh.gif");
        QLabel* label = new QLabel(this);
        label->move(0,400);
        // Make sure the GIF was loaded correctly
        if (!movie->isValid())
        {
            label->setText("mammad");
        }
        else{
            label->setMovie(movie);
            movie->start();
        }

        pb1->setParent(this);
       pb2->setParent(this);
       pb3->setParent(this);
       pb4->setParent(this);
       pb5->setParent(this);
       time_bar->setParent(this);

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
