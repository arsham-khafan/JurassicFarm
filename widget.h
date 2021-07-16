#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QThread>
#include "Data.h"
#include "msg.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr, Data* _data = nullptr);
    void set(){ time_lbl->setText("Days: " + QString::number(data->getDays()) + " Time: " +
                                  QString::number(data->getTime()/60) +
                                  ":" + QString::number(data->getTime()%60));
                lvl_txt->setText(QString::number(data->getLevel()));
                        exp->setText("Experiencr: " + QString::number(data->getExperience()) + " / " +
                                          QString::number(data->getCapacity()));
              }
    ~Widget();
private:
    QThread* t;
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
    QLabel* exp;
    QLabel* time_lbl;
public slots:
    void lands_slot();
    void storage_slot();
    void siloo_slot();
    void back_slot();
    void store_slot();
    void rank_slot();
    void forward_slot();
    void animals_slot();
};
#endif // WIDGET_H
