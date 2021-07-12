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
    ~Gandom();

private:
    Data* data;
    QPushButton* kasht;
    QPushButton* buttons;
    QPushButton* jam;
    QPushButton* go_back;
    QProgressBar* time;
    QLabel* leve_p;
    QLabel* area_p;
    Ui::Gandom *ui;
};

#endif // GANDOM_H
