#include "aghol.h"
#include "msg.h"

Aghol::Aghol(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle(("Sheep_osaurus Place"));
    data = _data;

    time_level = new QLabel;
    time_food = new QLabel;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

   setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":icons/sheep.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    lblLvl = new QLabel("Level: ", this);
    lblLvl2 = new QLabel(this);
    lblLvl2->setNum(data->getAqol()->getLevel());
    lblLvl->move(10, 250);
    lblLvl2->move(70, 250);

    lblCpc = new QLabel("Capacity: ", this);
    lblCpc2 = new QLabel(this);
    lblCpc2->setNum(data->getAqol()->getCapacity());
    lblCpc->move(10, 280);
    lblCpc2->move(70, 280);

    lblNum = new QLabel("Number: ", this);
    lblNum2 = new QLabel(this);
    lblNum2->setNum(data->getAqol()->getCount());
    lblNum->move(10, 310);
    lblNum2->move(70, 310);

    pbnUpgrd = new QPushButton("Upgrade", this);
    pbnUpgrd->setMinimumHeight(40);
    pbnUpgrd->setMinimumWidth(100);
    pbnUpgrd->setMaximumHeight(40);
    pbnUpgrd->setMaximumWidth(100);
    pbnUpgrd->move(1250, 250);
    pbnUpgrd->setCursor(Qt::PointingHandCursor);

    pbnFeed = new QPushButton("Feeding", this);
    pbnFeed->setMinimumHeight(40);
    pbnFeed->setMinimumWidth(100);
    pbnFeed->setMaximumHeight(40);
    pbnFeed->setMaximumWidth(100);
    pbnFeed->move(1250, 300);
    pbnFeed->setCursor(Qt::PointingHandCursor);

    pbnShr = new QPushButton("Shearing", this);
    pbnShr->setMinimumHeight(40);
    pbnShr->setMinimumWidth(100);
    pbnShr->setMaximumHeight(40);
    pbnShr->setMaximumWidth(100);
    pbnShr->move(1250, 350);
    pbnShr->setCursor(Qt::PointingHandCursor);

    pbnBack = new QPushButton("Back", this);
    pbnBack->setMinimumHeight(40);
    pbnBack->setMinimumWidth(100);
    pbnBack->setMaximumHeight(40);
    pbnBack->setMaximumWidth(100);
    pbnBack->move(10, 710);
    pbnBack->setCursor(Qt::PointingHandCursor);

    connect(pbnUpgrd, SIGNAL(clicked()), this, SLOT(upgrd()));
    connect(pbnFeed, SIGNAL(clicked()), this, SLOT(feed()));
    connect(pbnShr, SIGNAL(clicked()), this, SLOT(shr()));
    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));

}

void Aghol::upgrd()
{
    if(data->getAqol()->get_Time()<0){
    QMessageBox msgBox;
//     msgBox.setText("are you sure you want to upgrade?");
    msgBox.setInformativeText("are you sure you want to upgrade?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setStyleSheet("color : white; background-color : red");
    int ret = msgBox.exec();

    switch (ret) {
       case QMessageBox::Yes:

        if(data->isCanAddLevelAqol()){
            data->getAnbar()->ChangeBil(-1);
            data->getAnbar()->ChangeMikh(-3);
            data->operator-=(50);
            data->addExp(15);
            data->getAqol()->set_Time(540);
            time_level->setText("Time to Level up: " + QString::number(data->getAqol()->get_Time()/60) + ":"
                             +QString::number(data->getAqol()->get_Time()%60));
                            time_level->setHidden(false);
            QString str = "Aqol WILL BE UPGRADED IN 9 DAYS!";
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
            QString str = "Aqol ALREADY IS UPGRADING!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
}

void Aghol::feed()
{
    if(data->getAqol()->isFood()){
        QString str = "The animals have eaten!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
    else{
        if(data->getAnbar()->getYonje()>=data->getAqol()->getCount()){
            data->getAqol()->setFood(true);
            QString str = "The animals ate successfully!!";
            data->getAnbar()->ChangeYonje(data->getAqol()->getCount()*-1);
            data->addExp(7);
            data->getAqol()->set_Time_food(600);
            time_food->setText("Time to Egg: " + QString::number(data->getAqol()->get_Time_food()/60) + ":"
                         +QString::number(data->getAqol()->get_Time_food()%60));
                        time_food->setHidden(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "NO ENOUGH YONJE IN STORAGE";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
}

void Aghol::shr()
{
    if(data->getAqol()->isExist()){
        if(data->getCoin()>=data->getAqol()->getCount()){
            QString str = "The sheep were successfully bred!!";
            data->operator-=(data->getAqol()->getCount());
            data->getAnbar()->ChangePashm(data->getAqol()->getCount());
            data->addExp(9);
            data->getAqol()->setExist(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "NO ENOUGH COINS!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
    else{
        if(data->getAqol()->get_Time_food()>=0){
            QString str = "It is not time to give wool!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "Animals are not fed!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
}

void Aghol::back()
{
    Animals_Place* animals = new Animals_Place(nullptr, data);
    animals->showFullScreen();
    this->close();
}
