#pragma once

#include <QtWidgets/QWidget>
#include <qcheckbox.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFormLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <qmessagebox.h>
#include <QComboBox>
#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <QFile>
#include <qdebug.h>
#include <qmath.h>
#include <time.h>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////       Buildings   :)

class Anbar {
    QJsonObject data;
public:
    Anbar(QJsonObject& obj) { data = obj; }
    QJsonObject getData(){return data;}
    int getLevel() { return data["level"].toInt(); }
    int getBil() { return data["bil"].toInt(); }
    int getMikh() { return data["mikh"].toInt(); }
    int getYonje() { return data["yonje"].toInt(); }
    int getCount() { return data["count"].toInt(); }
    int getCapacity() { return data["capacity"].toInt(); }
    int getEgg() { return data["egg"].toInt(); }
    int getMilk() { return data["milk"].toArray().count(); }
    int getFirstMilk(){return data["milk"].toArray()[0].toInt();}
    int getPashm() { return data["pashm"].toInt(); }
    void ChangeBil(int i) { data["bil"] = data["bil"].toInt() + i; data["count"] = data["count"].toInt() + i; }
    void AddMilk(int i) { data["milk"].toArray().append(i); }
    void RemoveMilk() { QJsonArray arr = data["milk"].toArray();
                       arr.pop_front();
                       data["milk"] = arr;}
    void ChangeMikh(int i) { data["mikh"] = data["mikh"].toInt() + i; data["count"] = data["count"].toInt() + i; }
    void ChangeYonje(int i) { data["yonje"] = data["yonje"].toInt() + i; data["count"] = data["count"].toInt() + i; }
    void ChangeEgg(int i) { data["egg"] = data["egg"].toInt() + i; data["count"] = data["count"].toInt() + i; }
    void ChangePashm(int i) { data["pashm"] = data["pashm"].toInt() + i; data["count"] = data["count"].toInt() + i; }
    int getSpace() { return data["capacity"].toInt() - data["count"].toInt();  }
    bool isCanUp() { if (data["mikh"].toInt() >= data["level"].toInt() && data["bil"].toInt() >= data["level"].toInt() - 1) return true; return false; }
    void setTime(int i) { data["time"] = i; }
    void unsetTime(){data["time"] = -1;}
    void AddTime(int i) { data["time"] = data["time"].toInt() + i; }
    void UpLevel();
};

class silo {
    QJsonObject data;
public:
    silo(QJsonObject& obj) { data = obj; }
    QJsonObject getData(){return data;}
    int getLevel() { return data["level"].toInt(); }
    int getCount(){return data["count"].toInt(); }
    void setTime(int i) { data["time"] = i; }
    void unsetTime(){data["time"] = -1;}
    void AddTime(int i) { data["time"] = data["time"].toInt() + i; }
    void operator-=(int i) { data["count"] = data["count"].toInt() - i; }
    void operator+=(int i) { data["count"] = data["count"].toInt() + i; }
    int getSpace() { return data["capacity"].toInt() - data["count"].toInt(); }
    void UpLevel();
};

////////////////////////////////////////////////////////////////////////////////////////////////////       Lands  of  Farm      :)

class lands {
protected:
    QJsonObject data;
public:
    lands(QJsonObject& obj) { data = obj; }
    QJsonObject getData(){return data;}
    int getCount() { return data["count"].toInt(); }
    int getArea() { return data["area"].toArray().count(); }
    long long int get_kesht_time() { return data["kesht_time"].toString().toLongLong(); }
    long long int get_shokhm_time() { return data["shokhm_time"].toString().toLongLong(); }
    void setCount(int i) { data["count"] = i; }
    void set_kesht_time(long long int i) { data["kesht_time"] = QString::fromStdString(to_string(i)); }
    void set_shokhm_time(long long int i) { data["shokhm_time"] = QString::fromStdString(to_string(i)); }
    void setShokhm(bool i){ data["isshokhm"] = i;}
    void setKesht(bool i){ data["iskasht"] = i;}
    int at(int i){ return data["area"].toArray()[i].toInt();}
    void setAt(int i, int val){ QJsonArray arr = data["area"].toArray();
                                arr[i] = val;
                              data["area"] = arr;}
    void setBardasht(bool i){ data["isbardasht"] = i;}
    void operator++() { data["count"] = data["count"].toInt() + 1; }
    bool isBuild(){ return data["isbuild"].toBool(); }
    void UpLevel();
};

////////////////////////////////////////////////////////////////////////////////////////////////////        Animals AnimalsPlace     :)

class AnimalsPlace {
protected:
    QJsonObject data;
public:
    AnimalsPlace(QJsonObject& arr_) { data = arr_;}
    QJsonObject getData(){return data;}
    void operator+=(int i) { data["count"] = data["count"].toInt() + i; }
    void operator-=(int i) { data["count"] = data["count"].toInt() - i; }
    int getCount() { return data["count"].toInt(); }
    int getCapacity() { return data["capacity"].toInt(); }
    int getLevel() { return data["level"].toInt(); }
    int getSpace() { return data["capacity"].toInt() - data["count"].toInt(); }
    void setFood(bool i) { data["isfooded"] = i; }
    void setExist(bool i) { data["isexist"] = i; }
    bool getFood() { return data["isfooded"].toBool(); }
    bool getExist() { return data["isexist"].toBool(); }
    void setTime() { data["BeginAndLastFood"] = 0; }
    void AddTime(int i){data["BeginAndLastFood"] = data["BeginAndLastFood"].toInt() + i;}
    void unsetTime(){data["BeginAndLastFood"] = -1;}
    int getTime() { return data["BeginAndLastFood"].toInt(); }
    bool isBuild(){ return data["isbuild"].toBool(); }
    bool setBuild(bool i){data["isbuild"]=i;}
    void UpLevel();
    int Taghzie();
    int JamAvari();
};

////////////////////////////////////////////////////////////////////////////////////////////////////        Main Data Structure    :)

class Data {
    QJsonObject data;
    AnimalsPlace* aq;
    AnimalsPlace* gav;
    AnimalsPlace* morq;
    lands* gandom;
    lands* yonje;
    silo* s;
    Anbar* An;
public:
    Data(QJsonObject&);
    void quit();
    AnimalsPlace* getAqol() { return aq; }
    AnimalsPlace* getGav() { return gav; }
    AnimalsPlace* getMorq() { return morq; }
    lands* getGandomLand() { return gandom; }
    lands* getYonjeLand() { return yonje; }
    silo* getsilo() { return s; }
    Anbar* getAnbar() { return An; }
    QString getName() { return data["name"].toString(); }
    void setCoin(int i) { data["coins"] = i; }
    void operator+=(int i) { data["coins"] = data["coins"].toInt() + i; }
    void operator-=(int i) { data["coins"] = data["coins"].toInt() - i; }
    int getCoin() { return data["coins"].toInt(); }
    int getCapacity(){ return data["capacity"].toInt(); }
    int getExperience() { return data["experience"].toInt(); }
    int getLevel() { return data["level"].toInt(); }
    int getDays(){return data["days"].toInt();}
    bool isCanAddLevelSilo();
    bool isCanAddLevelAnbar();
    bool isCanAddLevelAqol();
    bool isCanAddLevelGavdari();
    bool isCanAddLevelMorqdari();
    bool isCanAddLevelgandom();
    bool isCanAddLevelYonje();
    bool isCanBuildAqol();
    bool isCanBuildGavdari();
    bool isCanBuildMorqdari();
    bool isCanBuildYonje();
    void BuildMorq();
    void BuildGav();
    void BuildAqol();
    void BuildYonje();
    int getTime(){ return data["time"].toInt(); }
    void AddTime(int i){data["time"] = data["time"].toInt()+i;}
    void setTime(int i){ data["time"] = i; }
    void AddMilk(){ getAnbar()->AddMilk(getDays());}
    void RemvoMilk(){ getAnbar()->RemoveMilk();}
    void nextDay();
    bool addExp(int);
    void UpLevel();
};
