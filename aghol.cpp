#include "aghol.h"

Aghol::Aghol(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle(("Sheep_osaurus Place"));
    data = _data;

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
    if(data->isCanAddLevelAqol() == 1)
        data->getAqol()->UpLevel();
    //else

}

void Aghol::feed()
{

}

void Aghol::shr()
{

}

void Aghol::back()
{
    Animals_Place* animals = new Animals_Place(nullptr, data);
    animals->show();
    this->close();
}
