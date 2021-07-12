#ifndef AVAL_H
#define AVAL_H

#include <QWidget>
#include<QPushButton>
#include<QPalette>
#include<QLabel>
#include<QLineEdit>
#include<QFileDialog>
#include"khata.h"
#include "signupp.h"
#include "widget.h"
namespace Ui {
class aval;
}

class aval : public QWidget
{
    Q_OBJECT

public:
    explicit aval(QWidget *parent = nullptr);
    ~aval();
public slots:
     void loginn();
      void vorood();
     void signn();
     void back();
private:
     QLabel* lb1;
     QPushButton* go_back;
     QLabel* lb2;
     QLineEdit* lv1;
      QLineEdit* lv2;
    QPushButton*lg1;
     QPushButton*lg2;
      QPushButton*lg3;
      QPushButton*lg4;
    Ui::aval *ui;
};

#endif // AVAL_H
