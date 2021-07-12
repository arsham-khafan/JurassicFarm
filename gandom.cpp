#include "gandom.h"
#include "ui_gandom.h"

Gandom::Gandom(QWidget *parent, Data* _data) :
    QWidget(parent),
    ui(new Ui::Gandom)
{

    data = _data;
    kasht = new QPushButton(this);
    buttons = new QPushButton(this);
    jam = new QPushButton(this);
    go_back = new QPushButton(this);
    time = new QProgressBar(this);
    leve_p = new QLabel(this);
    area_p = new QLabel(this);
    ui->setupUi(this);

}

Gandom::~Gandom()
{
    delete ui;
}
