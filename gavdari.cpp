#include "gavdari.h"
#include "msg.h"

Gavdari::Gavdari(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Cow_osaurus Place");
    data = _data;
    time_food = new QLabel;
    time_level = new QLabel;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

   setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/cow.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    lblLvl = new QLabel("Level: ", this);
    lblLvl2 = new QLabel(this);
    lblLvl2->setNum(data->getGav()->getLevel());
    lblLvl->move(620, 10);
    lblLvl2->move(680, 10);

    lblCpc = new QLabel("Capacity: ", this);
    lblCpc2 = new QLabel(this);
    lblCpc2->setNum(data->getGav()->getCapacity());
    lblCpc->move(620, 40);
    lblCpc2->move(680, 40);

    lblNum = new QLabel("Number: ", this);
    lblNum2 = new QLabel(this);
    lblNum2->setNum(data->getGav()->getCount());
    lblNum->move(620, 70);
    lblNum2->move(680, 70);

    pbnUpgrd = new QPushButton("Upgrade", this);
    pbnUpgrd->setMinimumHeight(40);
    pbnUpgrd->setMinimumWidth(100);
    pbnUpgrd->setMaximumHeight(40);
    pbnUpgrd->setMaximumWidth(100);
    pbnUpgrd->move(650, 500);
    pbnUpgrd->setCursor(Qt::PointingHandCursor);

    pbnFeed = new QPushButton("Feeding", this);
    pbnFeed->setMinimumHeight(40);
    pbnFeed->setMinimumWidth(100);
    pbnFeed->setMaximumHeight(40);
    pbnFeed->setMaximumWidth(100);
    pbnFeed->move(650, 550);
    pbnFeed->setCursor(Qt::PointingHandCursor);

    pbnMilk = new QPushButton("Collecting Milk", this);
    pbnMilk->setMinimumHeight(40);
    pbnMilk->setMinimumWidth(100);
    pbnMilk->setMaximumHeight(40);
    pbnMilk->setMaximumWidth(100);
    pbnMilk->move(650, 600);
    pbnMilk->setCursor(Qt::PointingHandCursor);

    pbnBack = new QPushButton("Back", this);
    pbnBack->setMinimumHeight(40);
    pbnBack->setMinimumWidth(100);
    pbnBack->setMaximumHeight(40);
    pbnBack->setMaximumWidth(100);
    pbnBack->move(10, 710);
    pbnBack->setCursor(Qt::PointingHandCursor);

    connect(pbnUpgrd, SIGNAL(clicked()), this, SLOT(upgrd()));
    connect(pbnFeed, SIGNAL(clicked()), this, SLOT(feed()));
    connect(pbnMilk, SIGNAL(clicked()), this, SLOT(milk()));
    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));

}

void Gavdari::upgrd()
{
    if(data->getGav()->get_Time()<0){
    QMessageBox msgBox;
//     msgBox.setText("are you sure you want to upgrade?");
    msgBox.setInformativeText("are you sure you want to upgrade?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setStyleSheet("color : white; background-color : red");
    int ret = msgBox.exec();

    switch (ret) {
       case QMessageBox::Yes:

        if(data->isCanAddLevelGavdari()){
            data->getAnbar()->ChangeMikh(-2);
            data->operator-=(15);
            data->addExp(6);
            data->getGav()->set_Time(300);
            time_level->setText("Time to Level up: " + QString::number(data->getMorq()->get_Time()/60) + ":"
            +QString::number(data->getMorq()->get_Time()%60));
            time_level->setHidden(false);
            QString str = "Aqol WILL BE UPGRADED IN 5 DAYS!";
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
            QString str = "GAVDARI ALREADY IS UPGRADING!!";
            msg* temp = new msg(nullptr , &str);
            temp->show();
        }

}

void Gavdari::feed()
{
    if(data->getGav()->isFood()){
        QString str = "The animals have eaten!!";
        msg* temp = new msg(nullptr , &str);
        temp->show();
    }
    else{
        if(data->getAnbar()->getYonje()>=data->getGav()->getCount()*2){
            data->getMorq()->setFood(true);
            QString str = "The animals ate successfully!!";
            data->getAnbar()->ChangeYonje(data->getGav()->getCount()*-2);
            data->addExp(3);
            data->getGav()->set_Time_food(120);
            time_food->setText("Time to Egg: " + QString::number(data->getGav()->get_Time_food()/60) + ":"
            +QString::number(data->getGav()->get_Time_food()%60));
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

void Gavdari::milk()
{
    if(data->getGav()->isExist()){
            QString str = "The milks were collected successfully!!";
            int num = data->getGav()->getCount();
            for(int i = 0;i<num;data->AddMilk(),i++);
            data->addExp(5);
            data->getGav()->setExist(false);
            msg* temp = new msg(nullptr , &str);
            temp->show();
    }
    else{
        if(data->getGav()->get_Time_food()>=0){
            QString str = "It is not time to give MILK!!";
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

void Gavdari::back()
{
    Animals_Place* animals = new Animals_Place(nullptr, data);
    this->close();
    animals->showFullScreen();
}
