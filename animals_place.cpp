#include "animals_place.h"
#include "msg.h"

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
    QPixmap pixmap=QPixmap(":backgrounds/animals_place.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    pbnGav = new QPushButton( this);
    pbnGav->setMinimumHeight(485);
    pbnGav->setMinimumWidth(600);
    pbnGav->setMaximumHeight(485);
    pbnGav->setMaximumWidth(600);
    pbnGav->move(130, 100);
    pbnGav->setStyleSheet("QPushButton{background:transparent;}");
    pbnGav->setCursor(Qt::PointingHandCursor);
//    if (data->getGav()->isBuild() == 1)
        pbnGav->setEnabled(true);
//    else
//        pbnGav->setEnabled(false);

//    build1 = new QPushButton("Build", this);
//    build1->setMinimumHeight(50);
//    build1->setMinimumWidth(100);
//    build1->setMaximumHeight(50);
//    build1->setMaximumWidth(100);
//    build1->move(710, 200);
//    build1->setStyleSheet("QPushButton{background:#80c342;}");
//    build1->setCursor(Qt::PointingHandCursor);
//    if (data->isCanBuildMorqdari() == 1)
//        build1->setEnabled(true);
//    else
//        build1->setEnabled(false);

    pbnMorgh = new QPushButton(this);
    pbnMorgh->setMinimumHeight(183);
    pbnMorgh->setMinimumWidth(860);
    pbnMorgh->setMaximumHeight(183);
    pbnMorgh->setMaximumWidth(860);
    pbnMorgh->move(470, 605);
    pbnMorgh->setStyleSheet("QPushButton{background: transparent;}");
    pbnMorgh->setCursor(Qt::PointingHandCursor);
//    if (data->getMorq()->isBuild() == 1)
        pbnMorgh->setEnabled(true);
//    else
//        pbnMorgh->setEnabled(false);

//   build2 = new QPushButton("Build", this);
//   build2->setMinimumHeight(50);
//   build2->setMinimumWidth(100);
//   build2->setMaximumHeight(50);
//   build2->setMaximumWidth(100);
//   build2->move(710, 260);
//   build2->setStyleSheet("QPushButton{background:#80c342;}");
//   build2->setCursor(Qt::PointingHandCursor);
//   if (data->isCanBuildGavdari() == 1)
//        build2->setEnabled(true);
//    else
//        build2->setEnabled(false);

    pbnGusfand = new QPushButton(this);
    pbnGusfand->setMinimumHeight(200);
    pbnGusfand->setMinimumWidth(270);
    pbnGusfand->setMaximumHeight(200);
    pbnGusfand->setMaximumWidth(270);
    pbnGusfand->move(1000, 270);
    pbnGusfand->setStyleSheet("QPushButton{background:transparent;}");
    pbnGusfand->setCursor(Qt::PointingHandCursor);
//    if (data->getAqol()->isBuild() == 1)
        pbnGusfand->setEnabled(true);
//    else
//        pbnGusfand->setEnabled(false);

//    build3 = new QPushButton("Build", this);
//    build3->setMinimumHeight(50);
//    build3->setMinimumWidth(100);
//    build3->setMaximumHeight(50);
//    build3->setMaximumWidth(100);
//    build3->move(710, 320);
//    build3->setStyleSheet("QPushButton{background:#80c342;}");
//    build3->setCursor(Qt::PointingHandCursor);
//    if (data->isCanBuildAqol())
//        build3->setEnabled(true);
//    else
//        build3->setEnabled(false);

    pbnBack = new QPushButton(this);
    pbnBack->setMinimumHeight(90);
    pbnBack->setMinimumWidth(90);
    pbnBack->setMaximumHeight(90);
    pbnBack->setMaximumWidth(90);
    pbnBack->move(20, 30);
    pbnBack->setCursor(Qt::PointingHandCursor);
    pbnBack->setStyleSheet("QPushButton {border-image:url(:icons/back2.png);}"
"                           QPushButton::hover{border-image:url(:icons/back22.png);} ");

    connect(pbnMorgh, SIGNAL(clicked()), this, SLOT(showMorghdari()));
    connect(pbnGav, SIGNAL(clicked()), this, SLOT(showGavdari()));
    connect(pbnGusfand, SIGNAL(clicked()), this, SLOT(showAghol()));
    connect(pbnBack, SIGNAL(clicked()), this, SLOT(back()));
}

void Animals_Place::showMorghdari(){
    if (data->getMorq()->isBuild() == 1)
    {
        if(data->getTime_build_morq()<0){
            Morghdari* morgh = new Morghdari(nullptr, data);
            this->close();
            morgh->show();
        }
        else{
            QString str = "Wait until the construction time is complete!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }
    else{
        if (data->isCanBuildMorqdari() == 1 && data->getMorq()->getLevel()>=2)
        {
            QMessageBox msgBox;
            msgBox.setInformativeText("Hen-saurus holding is not built yet do you want to build it? ");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setStyleSheet("color : white; background-color : green");
            int ret = msgBox.exec();

            switch (ret) {
               case QMessageBox::Yes:
                    data->BuildMorq();
                    data->getMorq()->setBuild(true);
                    data->set_build_morq(3*60);
                   break;
               case QMessageBox::Cancel:
                   return;
                   break;
               default:
                   break;
             }
        }
        else{
            QString str = "Hen-saurus holding is not built yet and you don't have the ability to build it yet!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }
}

void Animals_Place::showGavdari(){
    if (data->getGav()->isBuild() == 1)
    {
        if(data->getTime_build_gav()<0){
            Gavdari* gav = new Gavdari(nullptr, data);
            this->close();
            gav->show();
        }
        else{
                    QString str = "Wait until the construction time is complete!";
                    msg* message = new msg(nullptr, &str);
                    message->show();
            }
    }
    else{
        if (data->isCanBuildGavdari() == 1 && data->getGav()->getLevel()>=4)
        {
            QMessageBox msgBox;
            msgBox.setInformativeText("Cow-saurus holding is not built yet do you want to build it? ");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setStyleSheet("color : white; background-color : green");
            int ret = msgBox.exec();

            switch (ret) {
               case QMessageBox::Yes:
                    data->BuildGav();
                    data->getGav()->setBuild(true);
                    data->set_build_gav(5*60);
                   break;
               case QMessageBox::Cancel:
                   return;
                   break;
               default:
                   break;
             }
        }
        else{
            QString str = "Cow-saurus holding is not built yet and you don't have the ability to build it yet!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }
}

void Animals_Place::showAghol(){
    if (data->getAqol()->isBuild() == 1)
    {
        if(data->getTime_build_aqol()<0){
            Aghol* gusfand = new Aghol(nullptr, data);
            this->close();
            gusfand->show();
        }
        else{
                    QString str = "Wait until the construction time is complete!";
                    msg* message = new msg(nullptr, &str);
                    message->show();
            }
    }
    else{
        if (data->isCanBuildAqol() == 1 && data->getAqol()->getLevel()>=6)
        {
            QMessageBox msgBox;
            msgBox.setInformativeText("Sheep-saurus(Aqol) holding is not built yet do you want to build it? ");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setStyleSheet("color : white; background-color : green");
            int ret = msgBox.exec();

            switch (ret) {
               case QMessageBox::Yes:
                    data->BuildAqol();
                    data->getAqol()->setBuild(true);
                    data->set_build_aqol(600);
                   break;
               case QMessageBox::Cancel:
                   return;
                   break;
               default:
                   break;
             }
        }
        else{
            QString str = "Sheep-saurus holding(Aqol) is not built yet and you don't have the ability to build it yet!";
            msg* message = new msg(nullptr, &str);
            message->show();
        }
    }


}

void Animals_Place::back()
{
    Widget* w = new Widget(nullptr, data);
    this->close();
    w->showFullScreen();
}

Animals_Place::~Animals_Place()
{

}
