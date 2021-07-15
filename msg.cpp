#include "msg.h"
#include <QLabel>
msg::msg(QWidget *parent,QString* _message) : QWidget(parent)
{
    this->setWindowTitle("Message");
    this->setMinimumHeight(300);
    this->setMinimumWidth(400);
    this->setMaximumHeight(300);
    this->setMaximumWidth(400);

    setAutoFillBackground(true);
    this->setStyleSheet("background-color : rgb(152,233,165)");

    QHBoxLayout* main_lay = new QHBoxLayout;
    QVBoxLayout* left_lay = new QVBoxLayout;
    QPushButton* ok_butt = new QPushButton("OK");
    ok_butt->setStyleSheet("background-color : rgb(51,186,51)");
    QLabel* lbl = new QLabel("message:  ");

    message = new QTextEdit(*_message);
    QPalette pal1 = palette();
    pal1.setColor(QPalette::Text, Qt::black);
    message->setAutoFillBackground(true);
    message->setPalette(pal1);
    message->setFont(QFont("Comic Sans MS",13,-1,true));
    message->setAlignment(Qt::AlignHCenter);
    left_lay->addWidget(lbl);
    left_lay->addWidget(message);
    left_lay->addWidget(ok_butt);
    message->setReadOnly(true);

    main_lay->addLayout(left_lay);
    QMovie* movie = new QMovie(":gifs/d3.gif");
    QLabel* label = new QLabel;
    main_lay->addWidget(label);
    if (!movie->isValid())
    {
        label->setText("mammad");
    }
    else{
        label->setMovie(movie);
        movie->start();
    }

    this->setLayout(main_lay);
    connect(ok_butt, SIGNAL(clicked()), this, SLOT(closer()));
}

void msg::closer(){
    this->destroy();
}


void msg::settext(QString str){
    message->setText(str);

}
