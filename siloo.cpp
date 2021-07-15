#include "siloo.h"
#include <QMovie>
#include <QLabel>
#include "widget.h"
#include "msg.h"

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
}

void siloo::back_to_map(){
    Widget* temp = new Widget(nullptr, data);
    temp->showFullScreen();
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
