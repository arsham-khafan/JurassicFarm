#ifndef MSG_H
#define MSG_H

#include <QWidget>
#include <QMovie>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>


class msg : public QWidget
{
    Q_OBJECT
public:
    explicit msg(QWidget *parent = nullptr, QString* _message = nullptr);
private:

public slots:
    void closer();

};

#endif // MSG_H
