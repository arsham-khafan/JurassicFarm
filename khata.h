#ifndef KHATA_H
#define KHATA_H

#include <QWidget>
#include<QString>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
namespace Ui {
class khata;
}

class khata : public QWidget
{
    Q_OBJECT

public:
    explicit khata(QWidget *parent = nullptr,QString tozihkhata=NULL);
    ~khata();

private:
    QLineEdit*lb1;
    QLabel*lb2;
    Ui::khata *ui;
};

#endif // KHATA_H
