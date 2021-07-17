#ifndef GANDOM_H
#define GANDOM_H

#include <QWidget>
#include "widget.h"

namespace Ui {
class Gandom;
}

class Gandom : public QWidget
{
    Q_OBJECT

public:
    explicit Gandom(QWidget *parent = nullptr, Data* _data = nullptr);
    void set();
    void check();
    ~Gandom();

private:
    int w;
    QThread* t;
    QPushButton* pb1;
    QPushButton* up_level;
    QLabel* time_build;
    QPushButton* pb2;
    QPushButton* pb3;
    QPushButton* pb4;
    QPushButton* kol;
    QPushButton* build;
    QGridLayout* main;
    QPushButton* bar;
    QPushButton* ref;
    Data* data;
    Ui::Gandom *ui;
public slots:
   void uplevel();
   void build_();
   void check2();
   void sabt();
   void kesht();
   void bardasht();
   void buttons();
   void back_to_map();
   void go_to_yonjeh_widget();
};

#endif // GANDOM_H
