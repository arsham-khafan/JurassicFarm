#include "Data.h"

Data::Data(QJsonObject& obj){
    data=obj;
    what =1;
 QJsonObject a = data["aqol"].toObject();
    aq = new AnimalsPlace(a);
    a = data["gavdari"].toObject();
    gav = new AnimalsPlace(a);
    a = data["morqdari"].toObject();
    morq = new AnimalsPlace(a);
        a = data["gandomland"].toObject();
    gandom = new lands(a);
    a = data["yonjeland"].toObject();
    yonje = new lands(a);
    a = data["anbar"].toObject();
    An = new Anbar(a);
    a = data["silo"].toObject();
    s = new silo(a);
}

bool Data::isCanAddLevelAnbar() {
    if (getLevel() > getAnbar()->getLevel() && An->isCanUp() && getCoin() >= qPow(getAnbar()->getLevel(),3)*10)
        return true;
    return false;
}

bool Data::isCanAddLevelSilo() {
    int i = getAnbar()->getLevel();
    if (getLevel() - 1 > getsilo()->getLevel() && An->getBil() >= i - 2  && An->getMikh() >= i * 2 && getCoin() >= 100 * qPow((2 * i),2))
        return true;
    return false;
}

bool Data::isCanAddLevelAqol() {
    if (An->getBil() >= 1 && An->getMikh() >= 3 && getCoin() >= 50)
        return true;
    return false;
}

bool Data::isCanAddLevelGavdari() {
    if (An->getMikh() >= 2 && getCoin() >= 15)
        return true;
    return false;
}

bool Data::isCanAddLevelMorqdari() {
    if (An->getMikh() >= 1 && getCoin() >= 10)
        return true;
    return false;
}

bool Data::isCanAddLevelgandom(){
    if(getAnbar()->getBil()>=getGandomLand()->getArea() && getCoin()>=getGandomLand()->getArea()*5)
        return true;
    return false;
}

bool Data::isCanAddLevelYonje(){
    if(getAnbar()->getBil()>=getGandomLand()->getArea()*2 && getCoin()>=getGandomLand()->getArea()*5)
        return true;
    return false;
}

bool Data::isCanBuildAqol(){
    if(getAnbar()->getMikh()>=4 && getAnbar()->getBil()>=2 && getCoin()>=50)
        return true;
    return false;
}

bool Data::isCanBuildGavdari(){
    if(getAnbar()->getMikh()>=3 && getAnbar()->getBil()>=1 && getCoin()>=20)
        return true;
    return false;
}

bool Data::isCanBuildMorqdari(){
    if(getAnbar()->getMikh()>=2 && getCoin()>=10)
        return true;
    return false;
}

bool Data::isCanBuildYonje(){
    if(getAnbar()->getMikh()>=1 && getAnbar()->getBil()>=1 && getCoin()>=15)
        return true;
    return false;
}

void Data::BuildMorq(){
    this->operator-=(10);
    getAnbar()->ChangeMikh(-1);
    addExp(5);
}

void Data::BuildGav(){
    this->operator-=(20);
    getAnbar()->ChangeMikh(-3);
    getAnbar()->ChangeBil(-1);
    addExp(10);
}

void Data::BuildAqol(){
    this->operator-=(50);
    getAnbar()->ChangeMikh(-4);
    getAnbar()->ChangeBil(-2);
    addExp(20);
}

void Data::BuildYonje(){
    this->operator-=(15);
    getAnbar()->ChangeMikh(-1);
    getAnbar()->ChangeBil(-1);
    addExp(6);
}

void Data::nextDay(int kind){
    data["days"]=data["days"].toInt()+1;
    for(;getAnbar()->getMilk()>0;){
        if(getDays() - getAnbar()->getFirstMilk()>10)
            getAnbar()->RemoveMilk();
        else
            break;
    }
}

void Data::quit() {
    QFile f("Ap project.Json");
    f.open(QIODevice::ReadWrite);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject total = d.object();
    data["aqol"] = getAqol()->getData();
    data["gavdari"] = getGav()->getData();
    data["morqdari"] = getMorq()->getData();
    data["anbar"] = getAnbar()->getData();
    data["silo"] = getsilo()->getData();
    data["gandomland"] = getGandomLand()->getData();
    data["yonjeland"] = getYonjeLand()->getData();
    total[data["username"].toString()] = data;
    f.close();
    f.open(QIODevice::WriteOnly);
    b = f.readAll();
    d = QJsonDocument::fromJson(b);
    qDebug() << total;
    d.setObject(total);
    f.write(d.toJson());
}

void Data::addExp(int i) {
    data["experience"] = data["experience"].toInt() + i;
    if (data["experience"].toInt() >= data["capacity"].toInt())
        UpLevel();
}

void Data::UpLevel() {
    data["level"] = data["level"].toInt() + 1;
    data["experience"] = data["experience"].toInt() - data["capacity"].toInt();
    data["capacity"] = data["capacity"].toInt() * 2 + 10;
}

void Anbar::UpLevel(int i) {
    if(i == 2){
        data["capacity"] = data["capacity"].toInt() * 3;
        if (data["capacity"].toInt() % 2)
            data["capacity"] = data["capacity"].toInt() / 2 + 1;
        else
            data["capacity"] = data["capacity"].toInt() / 2;
    }
    else if(i == 1){
        data["mikh"] = data["mikh"].toInt() - data["level"].toInt();
        data["bil"] = data["bil"].toInt() - data["level"].toInt() + 1;
        data["level"] = data["level"].toInt() + 1;
    }
}

void silo::UpLevel() {
    data["level"] = data["level"].toInt() + 1;
    data["capacity"] = data["capacity"].toInt() * 2;
}

void lands::UpLevel(){
    int i = data["area"].toArray().count();
    QJsonArray arr = data["area"].toArray();
    for(int j=0;j<i;j++)
        arr.append(0);
    data["area"] = arr;
    data["level"] = data["level"].toInt()+1;
}

void AnimalsPlace::UpLevel() {
    data["level"] = data["level"].toInt() + 1;
    data["capacity"] = data["capacity"].toInt() * 2;
}
