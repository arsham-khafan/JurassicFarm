#ifndef RANKING_H
#define RANKING_H

#include <QWidget>
#include <QFormLayout>
#include <QProgressBar>
#include <QLabel>
#include <QFormLayout>
#include <QScrollArea>
#include <QHBoxLayout>
#include <map>
#include "widget.h"



namespace Ui {
class Ranking;
}

class Row : public QWidget
{
    Q_OBJECT

public:
    explicit Row();
    void add(int, int, int, QString, QString);

private:
    QFormLayout* main;
    QLabel* rank;
    QLabel* name;
    QLabel* picture;
    QProgressBar* exp;
    QLabel* level;
    QHBoxLayout* h;
};

class Ranking : public QWidget
{
    Q_OBJECT

public:
    Ranking(QWidget *parent = nullptr, Data* _data = nullptr);
    //, Data* _data = nullptr
    ~Ranking();
public slots:
    void map_menu();
private:
    Data* data;
    map<pair<int,int>,QString> sort;
    Ui::Ranking *ui;
    QLabel* picture;
    QScrollArea* area;
    QPushButton* go_back;
};

#endif // RANKING_H
