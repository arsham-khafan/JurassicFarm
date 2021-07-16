#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include <QTimer>
#include <QWidget>
#include <QFormLayout>
#include <QProgressBar>
#include <QLabel>
#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include "widget.h"

namespace Ui {
class store;
}

class store : public QWidget
{
    Q_OBJECT

public:
    explicit store(QWidget *parent = nullptr, Data* _data=nullptr);
    ~store();
public slots:
    void check_buy();
    void check_sell();
    void show2();
    void show3();
    void milk_();
    void cow_();
    void pashm_();
    void hen_();
    void egg_();
    void sheep_();
    void bill_();
    void mikh_();
    void yonje_();
    void gandom_();
    void map_menu();
private:
    QThread* t;
    Data* data;
    int i,counter;
    QMovie* movie;
    QLabel* label;
    QLabel* coins;
    QPushButton* milk;
    QPushButton* cow;
    QPushButton* hen;
    QPushButton* sheep;
    QPushButton* egg;
    QPushButton* pashm;
    QPushButton* gandom;
    QPushButton* yonje;
    QPushButton* bil;
    QPushButton* mikh;

    QPushButton* go_back;
    QTimer* tm,*tm1;
    Ui::store *ui;
};

#endif // STORE_H
