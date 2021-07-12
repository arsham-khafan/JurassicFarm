#ifndef SILOO_H
#define SILOO_H
#include "Data.h"
#include <QWidget>
#include <QProgressBar>

class siloo : public QWidget
{
    Q_OBJECT
public:
    explicit siloo(QWidget *parent = nullptr, Data* _data = nullptr);
private:
    Data* data;
    QProgressBar* main_bar;
    QPushButton* go_back;
    QPushButton* upgrade;
public slots:
    void back_to_map();
};

#endif // SILOO_H
