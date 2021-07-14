#include "animals_place.h"

Animals_Place::Animals_Place(QWidget *parent, Data* _data)
    : QWidget(parent)
{
    setWindowTitle("Animals Place");
    data = _data;

    this->setMinimumHeight(768);
    this->setMinimumWidth(1366);
    this->setMaximumHeight(768);
    this->setMaximumWidth(1366);

   setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/aval.jpeg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    pbnMorgh = new QPushButton("Hen_osaurus Place", this);
    pbnMorgh->setMinimumHeight(50);
    pbnMorgh->setMinimumWidth(200);
    pbnMorgh->setMaximumHeight(50);
    pbnMorgh->setMaximumWidth(200);
    pbnMorgh->move(500, 200);
    pbnMorgh->setStyleSheet("QPushButton{background:#80c342;}");
    pbnMorgh->setCursor(Qt::PointingHandCursor);
    if (data->getMorq()->isBuild() == 1)
        pbnMorgh->setEnabled(true);
    else
        pbnMorgh->setEnabled(false);

    build1 = new QPushButton("Build", this);
    build1->setMinimumHeight(50);
    build1->setMinimumWidth(100);
    build1->setMaximumHeight(50);
    build1->setMaximumWidth(100);
    build1->move(710, 200);
    build1->setStyleSheet("QPushButton{background:#80c342;}");
    build1->setCursor(Qt::PointingHandCursor);
    if (data->isCanBuildMorqdari() == 1)
        build1->setEnabled(true);
    else
        build1->setEnabled(false);

    pbnGav = new QPushButton("Cow_osaurus Place", this);
    pbnGav->setMinimumHeight(50);
    pbnGav->setMinimumWidth(200);
    pbnGav->setMaximumHeight(50);
    pbnGav->setMaximumWidth(200);
    pbnGav->move(500, 260);
    pbnGav->setStyleSheet("QPushButton{background:#80c342;}");
    pbnGav->setCursor(Qt::PointingHandCursor);
    if (data->getGav()->isBuild() == 1)
        pbnGav->setEnabled(true);
    else
        pbnGav->setEnabled(false);

   build2 = new QPushButton("Build", this);
   build2->setMinimumHeight(50);
   build2->setMinimumWidth(100);
   build2->setMaximumHeight(50);
   build2->setMaximumWidth(100);
   build2->move(710, 260);
   build2->setStyleSheet("QPushButton{background:#80c342;}");
   build2->setCursor(Qt::PointingHandCursor);
   if (data->isCanBuildGavdari() == 1)
        build2->setEnabled(true);
    else
        build2->setEnabled(false);

    pbnGusfand = new QPushButton("Sheep_osaurus Place", this);
    pbnGusfand->setMinimumHeight(50);
    pbnGusfand->setMinimumWidth(200);
    pbnGusfand->setMaximumHeight(50);
    pbnGusfand->setMaximumWidth(200);
    pbnGusfand->move(500, 320);
    pbnGusfand->setStyleSheet("QPushButton{background:#80c342;}");
    pbnGusfand->setCursor(Qt::PointingHandCursor);
    if (data->getAqol()->isBuild() == 1)
        pbnGusfand->setEnabled(true);
    else
        pbnGusfand->setEnabled(false);

    build3 = new QPushButton("Build", this);
    build3->setMinimumHeight(50);
    build3->setMinimumWidth(100);
    build3->setMaximumHeight(50);
    build3->setMaximumWidth(100);
    build3->move(710, 320);
    build3->setStyleSheet("QPushButton{background:#80c342;}");
    build3->setCursor(Qt::PointingHandCursor);
    if (data->isCanBuildAqol())
        build3->setEnabled(true);
    else
        build3->setEnabled(false);

    pbnBack = new QPushButton("Back");
    pbnBack->setMinimumHeight(50);
    pbnBack->setMinimumWidth(100);
    pbnBack->setMaximumHeight(50);
    pbnBack->setMaximumWidth(100);
    pbnBack->move(10, 710);
    pbnBack->setCursor(Qt::PointingHandCursor);
    pbnBack->setStyleSheet("QPushButton{background:#868482;}");

    connect(pbnMorgh, SIGNAL(clicked()), this, SLOT(showMorghdari()));
    connect(pbnGav, SIGNAL(clicked()), this, SLOT(showGavdari()));
    connect(pbnGusfand, SIGNAL(clicked()), this, SLOT(showAghol()));

    connect(build1, SIGNAL(clicked()), this, SLOT(buildM()));
    connect(build2, SIGNAL(clicked()), this, SLOT(buildG()));
    connect(build3, SIGNAL(clicked()), this, SLOT(buildA()));

    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));
}

void Animals_Place::showMorghdari(){
    Morghdari* morgh = new Morghdari(nullptr, data);
    this->close();
    morgh->show();
}

void Animals_Place::showGavdari(){
    Gavdari* gav = new Gavdari(nullptr, data);
    this->close();
    gav->show();
}

void Animals_Place::showAghol(){
    Aghol* gusfand = new Aghol(nullptr, data);
    this->close();
    gusfand->show();
}

void Animals_Place::buildM(){
    data->BuildMorq();
    data->getMorq()->setBuild(true);
}

void Animals_Place::buildG(){
    data->BuildGav();
    data->getGav()->setBuild(true);
}

void Animals_Place::buildA(){
    data->BuildAqol();
    data->getAqol()->setBuild(true);
}

void Animals_Place::back()
{
    Widget* w = new Widget(nullptr, data);
    this->close();
    w->show();
}

Animals_Place::~Animals_Place()
{

}

