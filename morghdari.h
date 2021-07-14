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

public slots:
    void upgrd();
    void feed();
    void egg();
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
    QPushButton* pbnEgg;
    QPushButton* pbnBack;

};

#endif // MORGHDARI_H
