#ifndef ANIMALS_PLACE_H
#define ANIMALS_PLACE_H

#include <QWidget>
#include <QPushButton>

#include "widget.h"
#include "morghdari.h"
#include "gavdari.h"
#include "aghol.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Animals_Place; }
QT_END_NAMESPACE

class Animals_Place : public QWidget
{
    Q_OBJECT

public:
    Animals_Place(QWidget *parent = nullptr, Data* _data = nullptr);
    void check();
    void set(){}
    ~Animals_Place();

public slots:
    void showMorghdari();
    void showGavdari();
    void showAghol();
    void back();
private:
    Data* data;
    QThread* t;
    QLabel* build_Aqol;
    QLabel* build_gav;
    QLabel* build_morq;
    QPushButton* pbnMorgh;
    QPushButton* pbnGav;
    QPushButton* pbnGusfand;
    QPushButton* pbnBack;

};

#endif // ANIMALS_PLACE_H
