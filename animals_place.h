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
    ~Animals_Place();

public slots:
    void showMorghdari();
    void showGavdari();
    void showAghol();
    void buildM();
    void buildG();
    void buildA();
    void back();

private:
    Data* data;

    QPushButton* pbnMorgh;
    QPushButton* pbnGav;
    QPushButton* pbnGusfand;
    QPushButton* build1;
    QPushButton* build2;
    QPushButton* build3;
    QPushButton* pbnBack;

};

#endif // ANIMALS_PLACE_H
