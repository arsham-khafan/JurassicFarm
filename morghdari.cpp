#include "morghdari.h"

Morghdari::Morghdari(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Hen_osaurus Place");
    data = _data;

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
    if(data->isCanAddLevelMorqdari() == 1)
        data->getMorq()->UpLevel();
    //else

}

void Morghdari::feed()
{

}

void Morghdari::egg()
{

}

void Morghdari::back()
{
    Animals_Place* animals = new Animals_Place;
    this->close();
    animals->show();
}
