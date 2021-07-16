#ifndef GAVDARI_H
#define GAVDARI_H

#include <QObject>
#include <QWidget>
#include "widget.h"
#include "animals_place.h"
#include <QLabel>
#include <QPushButton>

class Gavdari : public QWidget
{
    Q_OBJECT

public:
    Gavdari(QWidget *parent = nullptr, Data* _data = nullptr);
    void check(){if(data->getGav()->get_Time()<0) time_level->setHidden(true);
                     if(data->getGav()->get_Time_food()<0) time_food->setHidden(true);}
        void set(){time_food->setText("Time to Upgrade: " + QString::number(data->getGav()->get_Time_food()/60) +
                                      ":" + QString::number(data->getGav()->get_Time_food()%60));
                   time_level->setText("Time to Upgrade: " + QString::number(data->getGav()->get_Time()/60) +
                                                               ":" + QString::number(data->getGav()->get_Time()%60));}
public slots:
    void upgrd();
    void feed();
    void milk();
    void back();

private:
    QThread* t;
    Data* data;
    QLabel* time_food,* time_level;
    QLabel* lblLvl;
    QLabel* lblLvl2;
    QLabel* lblCpc;
    QLabel* lblCpc2;
    QLabel* lblNum;
    QLabel* lblNum2;
    QPushButton* pbnUpgrd;
    QPushButton* pbnFeed;
    QPushButton* pbnMilk;
    QPushButton* pbnBack;

};

#endif // GAVDARI_H
