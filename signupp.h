#ifndef SIGNUPP_H
#define SIGNUPP_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QTimer>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<aval.h>
#include"khata.h"
#include"msg2.h"
namespace Ui {
class signupp;
}

class signupp : public QWidget
{
    Q_OBJECT

public:
    explicit signupp(QWidget *parent = nullptr);
    ~signupp();

private:
    int i;
    QLineEdit* li1;
    QLineEdit* li2;
    QLineEdit* li3;
    QLineEdit* li4;
    QLineEdit* li5;
    QLabel* lb1;
     QLabel* lb2;
      QLabel* lb3;
       QLabel* lb4;
        QLabel* lb5;
        QPushButton*pb1;
        QPushButton*pb2;
        QTimer* tm;
    Ui::signupp *ui;
public slots:
    void opdatee();
     void backk();
     void sett();
};

#endif // SIGNUPP_H
