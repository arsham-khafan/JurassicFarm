#include "morghdari.h"
#include "msg.h"

Morghdari::Morghdari(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Hen_osaurus Place");
    data = _data;

    time_level = new QLabel;
    time_food = new QLabel;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":icons/hen.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    lblLvl = new QLabel("Level: ", this);
    lblLvl2 = new QLabel(this);
    lblLvl2->setNum(data->getMorq()->getLevel());
    lblLvl->move(150, 130);
    lblLvl2->move(220, 130);

    lblCpc = new QLabel("Capacity: ", this);
    lblCpc2 = new QLabel(this);
    lblCpc2->setNum(data->getMorq()->getCapacity());
    lblCpc->move(150, 160);
    lblCpc2->move(220, 160);

    lblNum = new QLabel("Number: ", this);
    lblNum2 = new QLabel(this);
    lblNum2->setNum(data->getMorq()->getCount());
    lblNum->move(150, 190);
    lblNum2->move(220, 190);

    pbnUpgrd = new QPushButton("Upgrade", this);
    pbnUpgrd->setMinimumHeight(40);
    pbnUpgrd->setMinimumWidth(100);
    pbnUpgrd->setMaximumHeight(40);
    pbnUpgrd->setMaximumWidth(100);
    pbnUpgrd->move(1250, 100);
    pbnUpgrd->setCursor(Qt::PointingHandCursor);

    pbnFeed = new QPushButton("Feeding", this);
    pbnFeed->setMinimumHeight(40);
    pbnFeed->setMinimumWidth(100);
    pbnFeed->setMaximumHeight(40);
    pbnFeed->setMaximumWidth(100);
    pbnFeed->move(1250, 150);
    pbnFeed->setCursor(Qt::PointingHandCursor);

    pbnEgg = new QPushButton("Collecting Eggs", this);
    pbnEgg->setMinimumHeight(40);
    pbnEgg->setMinimumWidth(100);
    pbnEgg->setMaximumHeight(40);
    pbnEgg->setMaximumWidth(100);
    pbnEgg->move(1250, 200);
    pbnEgg->setCursor(Qt::PointingHandCursor);

    pbnBack = new QPushButton("Back", this);
    pbnBack->setMinimumHeight(40);
    pbnBack->setMinimumWidth(100);
    pbnBack->setMaximumHeight(40);
    pbnBack->setMaximumWidth(100);
    pbnBack->move(10, 710);
    pbnBack->setCursor(Qt::PointingHandCursor);

    connect(pbnUpgrd, SIGNAL(clicked()), this, SLOT(upgrd()));
    connect(pbnFeed, SIGNAL(clicked()), this, SLOT(feed()));
    connect(pbnEgg, SIGNAL(clicked()), this, SLOT(egg()));
    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));

}

void Morghdari::upgrd()
{
    if(data->getMorq()->get_Time()<0){
        QMessageBox msgBox;
    //     msgBox.setText("are you sure you want to upgrade?");
        msgBox.setInformativeText("are you sure you want to upgrade?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Yes);
        msgBox.setStyleSheet("color : white; background-color : red");
        int ret = msgBox.exec();

        switch (ret) {
           case QMessageBox::Yes:

            if(data->isCanAddLevelMorqdari()){
                data->getAnbar()->ChangeMikh(-1);
                data->operator-=(10);
                data->addExp(5);
                data->getMorq()->set_Time(180);
                time_level->setText("Time to Level up: " + QString::number(data->getMorq()->get_Time()/60) + ":"
                 +QString::number(data->getMorq()->get_Time()%60));
                time_level->setHidden(false);
                QString str = "Aqol WILL BE UPGRADED IN 3 DAYS!";
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
                QString str = "MORGHDARI ALREADY IS UPGRADING!!";
                msg* temp = new msg(nullptr , &str);
                temp->show();
            }

}

void Morghdari::feed()
{
    if(data->getAqol()->isFood()){
        QString str = "The animals have eaten!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
    else{
        if(data->getsilo()->getCount()>=data->getMorq()->getCount()){
            data->getMorq()->setFood(true);
            QString str = "The animals ate successfully!!";
            data->getsilo()->operator-=(data->getMorq()->getCount());
            data->addExp(1);
            data->getMorq()->set_Time_food(120);
            time_food->setText("Time to Egg: " + QString::number(data->getMorq()->get_Time_food()/60) + ":"
             +QString::number(data->getMorq()->get_Time_food()%60));
            time_food->setHidden(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
        else{
            QString str = "NO ENOUGH GANDOM IN SILOO";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }
    }
}

void Morghdari::egg()
{
    if(data->getMorq()->isExist()){
            QString str = "The eggs were collected successfully!!";
            data->getAnbar()->ChangeEgg(data->getMorq()->getCount());
            data->addExp(2);
            data->getAqol()->setExist(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
    }
    else{
        if(data->getMorq()->get_Time_food()>=0){
            QString str = "It is not time to give egg!!";
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

void Morghdari::back()
{
    Animals_Place* animals = new Animals_Place;
    this->close();
    animals->showFullScreen();
}
