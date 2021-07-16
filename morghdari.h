#ifndef MORGHDARI_H
#define MORGHDARI_H

#include <QObject>
#include <QWidget>
#include "widget.h"
#include "animals_place.h"
#include <QLabel>
#include <QPushButton>

class Morghdari : public QWidget
{
    Q_OBJECT

public:
    Morghdari(QWidget *parent = nullptr ,Data* _data = nullptr);
    void check(){if(data->getMorq()->get_Time()<0) time_level->setHidden(true);
                 if(data->getMorq()->get_Time_food()<0) time_food->setHidden(true);}
    void set(){time_food->setText("Time to Upgrade: " + QString::number(data->getMorq()->get_Time_food()/60) +
                                  ":" + QString::number(data->getMorq()->get_Time_food()%60));
               time_level->setText("Time to Upgrade: " + QString::number(data->getMorq()->get_Time()/60) +
                                                           ":" + QString::number(data->getMorq()->get_Time()%60));}
public slots:
    void upgrd();
    void feed();
    void egg();
    void back();

private:
    QThread* t;
    Data* data;
    QLabel* time_level, *time_food;
    QLabel* lblLvl;
    QLabel* lblLvl2;
    QLabel* lblCpc;
    QLabel* lblCpc2;
    QLabel* lblNum;
    QLabel* lblNum2;
    QPushButton* pbnUpgrd;
    QPushButton* pbnFeed;
    QPushButton* pbnEgg;
    QPushButton* pbnBack;

};

#endif // MORGHDARI_H
