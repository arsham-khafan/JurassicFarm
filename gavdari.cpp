#include "gavdari.h"

Gavdari::Gavdari(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Cow_osaurus Place");
    data = _data;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

   setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":icons/cow.jpg").scaled(this->size());
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
    if(data->isCanAddLevelGavdari() == 1)
        data->getGav()->UpLevel();
    //else

}

void Gavdari::feed()
{

}

void Gavdari::milk()
{

}

void Gavdari::back()
{
    Animals_Place* animals = new Animals_Place(nullptr, data);
    this->close();
    animals->show();
}
