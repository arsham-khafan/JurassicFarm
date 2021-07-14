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

public slots:
    void upgrd();
    void feed();
    void shr();
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
    QPushButton* pbnShr;
    QPushButton* pbnBack;
};

#endif // AGHOL_H
