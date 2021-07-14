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

public slots:
    void upgrd();
    void feed();
    void milk();
    void back();

private:
    Data* data;

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
