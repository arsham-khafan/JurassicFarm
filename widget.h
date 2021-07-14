#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <thread>
#include "Data.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr, Data* _data = nullptr);
    void Time(Data* _data, Widget* w);
    void set(){ exp_bar->setValue((data->getTime() * 100)/3600);}
    ~Widget();
private:
    //std::thread t;
    Data* data;
    QPushButton* siloo_butt;
    QPushButton* store_butt;
    QPushButton* places_butt;
    QPushButton* lands_butt;
    QPushButton* storage_butt;
    QGridLayout* main_lay;
    QLabel* coins_pic;
    QLabel* coins_txt;
    QLabel* time_pic;
    QLabel* time_txt;
    QLabel* xp_;
    QLabel* xp_txt;
    QLabel* lvl_;
    QLabel* lvl_txt;
    QPushButton* back_to_main_menu;
    QPushButton* one_day_forward;
    QPushButton* rankings;
    QProgressBar* exp_bar;
    QProgressBar* time_bar;
public slots:
    void lands_slot();
    void storage_slot();
    void siloo_slot();
    void back_slot();
    void store_slot();
    void rank_slot();
};
#endif // WIDGET_H
