#include "Data.h"
Data::Data(QJsonObject& obj){
    data=obj;
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
    if (getLevel() > getAnbar()->getLevel() && An->isCanUp() && getCoin() >= qPow(getLevel(),3)*10)
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
    if(addExp(5))
        UpLevel();}

void Data::BuildGav(){
    this->operator-=(20);
    getAnbar()->ChangeMikh(-3);
    getAnbar()->ChangeBil(-1);
    if(addExp(10))
        UpLevel();}

void Data::BuildAqol(){
    this->operator-=(50);
    getAnbar()->ChangeMikh(-4);
    getAnbar()->ChangeBil(-2);
    if(addExp(20))
        UpLevel();}

void Data::BuildYonje(){
    this->operator-=(15);
    getAnbar()->ChangeMikh(-1);
    getAnbar()->ChangeBil(-1);
    if(addExp(6))
        UpLevel();
}

void Data::check(){

}

void Data::nextDay(){

}

void Data::quit() {
    QFile f("Ap project.Json");
    f.open(QIODevice::ReadWrite);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject total = d.object();
    total[data["username"].toString()] = data;
    f.close();
    f.open(QIODevice::WriteOnly);
    b = f.readAll();
    d = QJsonDocument::fromJson(b);
    qDebug() << total;
    d.setObject(total);
    f.write(d.toJson());
}

bool Data::addExp(int i) {
    data["experience"] = data["experience"].toInt() + i;
    if (data["experience"].toInt() >= data["capacity"].toInt())
        return true;
    return false;
}

void Data::UpLevel() {
    data["level"] = data["level"].toInt() + 1;
    data["experience"] = data["experience"].toInt() - data["capacity"].toInt();
    data["capacity"] = data["capacity"].toInt() * 2 + 10;
}

void Anbar::UpLevel() {
    data["capacity"] = data["capacity"].toInt() * 3;
    if (data["capacity"].toInt() % 2)
        data["capacity"] = data["capacity"].toInt() / 2 + 1;
    else
        data["capacity"] = data["capacity"].toInt() / 2;
    data["mikh"] = data["mikh"].toInt() - data["level"].toInt();
    data["bil"] = data["bil"].toInt() - data["level"].toInt() + 1;
    data["level"] = data["level"].toInt() + 1;
}

void silo::UpLevel() {
    data["level"] = data["level"].toInt() + 1;
    data["capacity"] = data["capacity"].toInt() * 2;
}

void lands::UpLevel(){
    data["area"] = data["area"].toInt()*2;
    data["level"] = data["level"].toInt()+1;
}

void AnimalsPlace::UpLevel() {
    data["level"] = data["level"].toInt() + 1;
    data["capacity"] = data["capacity"].toInt() * 2;
}

int AnimalsPlace::JamAvari() {
    setExist(false);
    setFood(false);
    return getCount();
}

int AnimalsPlace::Taghzie() {
    if (!getExist()) {
        setFood(true);
        setTime();
        return 1;
    }
    return 0;
}

