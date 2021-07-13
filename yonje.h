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
    ~Yonje();

private:
    QPushButton* pb1;
    QPushButton* pb2;
    QPushButton* pb3;
    QPushButton* pb4;
    QPushButton* pb5;
    QPushButton* up_level;
    QProgressBar* time_bar;
    Data* data;
    Ui::Yonje *ui;

public slots:
   void back_to_map();
   void go_to_gandom_widget();
};

#endif // YONJE_H
