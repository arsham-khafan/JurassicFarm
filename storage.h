#ifndef STORAGE_H
#define STORAGE_H
#include <QProgressBar>
#include <QWidget>
#include <Data.h>

class storage : public QWidget
{
    Q_OBJECT
public:
    explicit storage(QWidget *parent = nullptr, Data* _data = nullptr);

private:
    Data* data;
    QLabel* nail;
    QLabel* shovel;
    QLabel* yonje;
    QLabel* egg;
    QLabel* milk;
    QLabel* whool;
    QLabel* nail_txt;
    QLabel* shovel_txt;
    QLabel* yonje_txt;
    QLabel* egg_txt;
    QLabel* milk_txt;
    QLabel* whool_txt;
    QPushButton* go_back;
    QPushButton* up_level;
    QProgressBar* cpc_bar;
    QProgressBar* time_bar;
public slots:
    void map_menu();
    void upgrade_slot();
};



#endif // STORAGE_H
