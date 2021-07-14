#include "khata.h"
#include "ui_khata.h"

khata::khata(QWidget *parent,QString tozihkhata) :
    QWidget(parent),
    ui(new Ui::khata)
{
    this->setFixedSize(400,600);
    ui->setupUi(this);
    this->setMinimumHeight(760);
        this->setMinimumWidth(600);
        this->setMaximumHeight(760);
        this->setMaximumWidth(600);
    setAutoFillBackground(true);
    QPixmap pixmap=QPixmap(":backgrounds/warningg.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(this->backgroundRole(),QBrush(pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

    lb1=new QLineEdit;
//   lb2=new  QLabel("type of warning:");
   lb1->setText(tozihkhata);
   lb1->setAlignment(Qt::AlignCenter);
   lb1->setEnabled(false);
    lb1->setStyleSheet("color:black;" "background-color: #FFE164;" "font-size:32px;");
//    lb2->setStyleSheet("color:black;" "font-size:20px;");
    lb1->setFixedSize(550,130);
    lb1->move(24,593);
//    lb2->move(40,280);
    lb1->setParent(this);
//    lb2->setParent(this);

}

khata::~khata()
{
    delete ui;
}
