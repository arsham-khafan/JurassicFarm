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
    int get_time(){ return data["time"].toInt();}
    void AddTime(int i) { data["time"] = data["time"].toInt() + i; }
    void UpLevel(int);
};

class silo {
    QJsonObject data;
public:
    silo(QJsonObject& obj) { data = obj; }
    QJsonObject getData(){return data;}
    int getLevel() { return data["level"].toInt(); }
    int getCount(){return data["count"].toInt(); }
    int getCapacity(){ return data["capacity"].toInt();}
    void setTime(int i) { data["time"] = i; }
    void AddTime(int i) { data["time"] = data["time"].toInt() + i; }
    int get_time(){ return data["time"].toInt();}
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
    int getArea() { return data["area"].toArray().count(); }
    int getLevel(){ return data["level"].toInt();}
    int get_time() { return data["level_time"].toInt(); }
    int get_time_work() { return data["time"].toInt(); }
    void Add_Time(int i){data["level_time"] = data["level_time"].toInt() + i;}
    void Add_Time_work(int i){data["time"] = data["time"].toInt() + i;}
    void setTime(int i){data["level_time"] = i;}
    void setTime_work(int i){data["time"] = i;}
    void setShokhm(bool i){ data["isshokhm"] = i;}
    void setKesht(bool i){ data["iskasht"] = i;}
    bool isKesht(){return data["iskasht"].toBool();}
    bool isShokhm(){return data["isshokhm"].toBool();}
    bool isBardasht(){return data["isbardasht"].toBool();}
    int at(int i){ return data["area"].toArray()[i].toInt();}
    void setAt(int i, int val){ QJsonArray arr = data["area"].toArray();
                                arr[i] = val;
                              data["area"] = arr;}
    void setBardasht(bool i){ data["isbardasht"] = i;}
    bool isBuild(){ return data["isbuild"].toBool(); }
    void setBuilds(bool i){data["isbuild"] = i;}
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
    bool isFood() { return data["isfooded"].toBool(); }
    bool isExist() { return data["isexist"].toBool(); }
    void set_Time_food(int i) { data["BeginAndLastFood"] = i; }
    void Add_Time_food(int i){data["BeginAndLastFood"] = data["BeginAndLastFood"].toInt() + i;}
    int get_Time_food() { return data["BeginAndLastFood"].toInt(); }
    void set_Time(int i) { data["level_time"] = i; }
    void Add_Time(int i){data["level_time"] = data["level_time"].toInt() + i;}
    int get_Time() { return data["level_time"].toInt(); }
    bool isBuild(){ return data["isbuild"].toBool(); }
    void setBuild(bool i){data["isbuild"]=i;}
    void UpLevel();
    int Taghzie();
    int JamAvari();
};

////////////////////////////////////////////////////////////////////////////////////////////////////        Main Data Structure    :)

class Data {
    int what;
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
    void setWhat(int i){what =i;}
    int getWhat(){return what;}
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
    int getTime_build_morq(){ return data["build_morq"].toInt();}
    int getTime_build_gav(){ return data["build_gav"].toInt();}
    int getTime_build_aqol(){ return data["build_aqol"].toInt();}
    int getTime_build_yonje(){ return data["build_yonje"].toInt();}
    void Add_build_morq(int i){data["build_morq"] = i;}
    void Add_build_gav(int i){data["build_gav"] = i;}
    void Add_build_aqol(int i){data["build_aqol"] = i;}
    void Add_build_yonje(int i){data["build_yonje"] = i;}
    void set_build_morq(int i){data["build_morq"] = i;}
    void set_build_gav(int i){data["build_gav"] = i;}
    void set_build_aqol(int i){data["build_aqol"] = i;}
    void set_build_yonje(int i){data["build_yonje"] = i;}
    int getTime(){ return data["time"].toInt(); }
    void AddTime(int i){data["time"] = data["time"].toInt()+i;}
    void setTime(int i){ data["time"] = i; }
    void AddMilk(){ getAnbar()->AddMilk(getDays());}
    void RemvoMilk(){ getAnbar()->RemoveMilk();}
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
    void nextDay(int);
    void addExp(int);
    void UpLevel();
};
