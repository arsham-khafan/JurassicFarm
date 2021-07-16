#ifndef AGHOL_H
#define AGHOL_H

#include <QObject>
#include <QWidget>
#include "widget.h"
#include "animals_place.h"
#include <QLabel>
#include <QPushButton>

class Aghol : public QWidget
{
    Q_OBJECT

public:
    Aghol(QWidget *parent = nullptr, Data* _data = nullptr);
    void check(){if(data->getAqol()->get_Time()<0) time_level->setHidden(true);
                 if(data->getAqol()->get_Time_food()<0) time_food->setHidden(true);}
    void set(){time_food->setText("Time to Upgrade: " + QString::number(data->getAqol()->get_Time_food()/60) +
                                  ":" + QString::number(data->getAqol()->get_Time_food()%60));
               time_level->setText("Time to Upgrade: " + QString::number(data->getAqol()->get_Time()/60) +
                                                           ":" + QString::number(data->getAqol()->get_Time()%60));}
public slots:
    void upgrd();
    void feed();
    void shr();
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
    QPushButton* pbnShr;
    QPushButton* pbnBack;
};

#endif // AGHOL_H
