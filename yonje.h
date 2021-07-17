#ifndef YONJE_H
#define YONJE_H

#include <QWidget>
#include"widget.h"
#include"QPushButton"

namespace Ui {
class Yonje;
}

class Yonje : public QWidget
{
    Q_OBJECT

public:
    explicit Yonje(QWidget *parent = nullptr, Data*_data=nullptr);
    void set();
    void check();
    ~Yonje();

private:
    int w;
    QPushButton* pb1;
    QPushButton* pb2;
    QPushButton* pb3;
    QPushButton* pb4;
    QPushButton* pb5;
    QPushButton* up_level;
    QPushButton* kol;
    QGridLayout* main;
    QPushButton* bardasht;
    Data* data;
    Ui::Yonje *ui;

public slots:
   void sabt();
   void kesht();
   void bardasht_();
   void uplevel();
   void buttons();
   void shokhm();
   void back_to_map();
   void go_to_gandom_widget();
};

#endif // YONJE_H
