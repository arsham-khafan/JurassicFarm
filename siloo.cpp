#include "siloo.h"
#include <QMovie>
#include <QLabel>
#include "widget.h"

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
    main_bar->move(400,140);
    main_bar->setMinimumHeight(514);
    main_bar->setMinimumWidth(599);
    main_bar->setMaximumHeight(514);
    main_bar->setMaximumWidth(599);
    main_bar->setStyleSheet("QProgressBar { border-image: url(:icons/silomask2.png); }"
                            "QProgressBar::chunk { background-image: url(:backgrounds/weat.jpg); }");
    main_bar->setTextVisible(false);
    main_bar->setValue(40);
    main_bar->setToolTip("silo level: " + QString::number(data->getsilo()->getLevel()));

    QMovie* movie = new QMovie(":gifs/tenor.gif");
    QLabel* label = new QLabel(this);
    label->move(0,676);
    // Make sure the GIF was loaded correctly
    if (!movie->isValid())
    {
        label->setText("mammad");
    }
    else{
        label->setMovie(movie);
        movie->start();
    }

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
}

void siloo::back_to_map(){
    Widget* temp = new Widget(nullptr, data);
    temp->showFullScreen();
    this->destroy();
}
