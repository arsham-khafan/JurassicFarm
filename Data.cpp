#include "Data.h"
#include "msg.h"

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
    if(kind == 2){
        Exp_Day();
    }
    if(kind == 1){

        QString str;
        addExp(1);
        if(getTime_build_aqol()>0)
            set_build_aqol(-60);
        if(getTime_build_aqol()<=0){
            getAqol()->setBuild(true);
            set_build_aqol(-1);
            str = "Aqol build Successfully\n";
            Add_message(str,1);
        }

        if(getTime_build_gav()>0)
            set_build_gav(-60);
        if(getTime_build_gav()<=0){
            set_build_gav(-1);
            getGav()->setBuild(true);
            str = "Gavdari build Successfully\n";
            Add_message(str,1);
        }

        if(getTime_build_morq()>0)
            set_build_morq(-60);
        if(getTime_build_morq()<=0){
            getMorq()->setBuild(true);
            set_build_morq(-1);
            str = "Morqdari build Successfully\n";
            Add_message(str,1);
        }

        if(getTime_build_yonje()>0)
            set_build_yonje(-60);
        if(getTime_build_yonje()<=0){
            set_build_yonje(-1);
            getYonjeLand()->setBuilds(true);
            str = "Yonje land build Successfully\n";
            Add_message(str,1);
        }

        if(getAnbar()->get_time()>0)
            getAnbar()->AddTime(-60);
        if(getAnbar()->get_time()<=0){
            getAnbar()->UpLevel(2);
            getAnbar()->setTime(-1);
            str = "STORAGE SUCCESSFULLY UPGRADED!\n Level: " + QString::fromLatin1(to_string(getAnbar()->getLevel()))
                    + "\n New Capacity: " + QString::fromLatin1(to_string(getAnbar()->getCapacity())) + "\n";
            Add_message(str,5);
        }

        if(getsilo()->get_time()>0)
            getsilo()->AddTime(-60);
        if(getsilo()->get_time()<=0){
            getsilo()->UpLevel();
            getsilo()->setTime(-1);
            str = "SILOO SUCCESSFULLY UPGRADED!\n Level: " + QString::fromLatin1(to_string(getsilo()->getLevel()))
                    + "\n New Capacity: " + QString::fromLatin1(to_string(getsilo()->getCapacity())) + "\n";
            Add_message(str,6);
        }

        if(getAqol()->get_Time()>0)
            getAqol()->Add_Time(-60);
        if(getAqol()->get_Time()<=0){
            getAqol()->UpLevel();
            getAqol()->set_Time(-1);
            str = "Aqol SUCCESSFULLY UPGRADED!\n Level: " + QString::number(getAqol()->getLevel())
                    + "\n New Area: " + QString::number(getAqol()->getCapacity()) + "\n";
            Add_message(str,2);
        }

        if(getAqol()->get_Time_food()>0)
            getAqol()->Add_Time_food(-60);
        if(getAqol()->get_Time_food()<=0){
            getAqol()->setExist(true);
            getAqol()->setFood(false);
            getAqol()->set_Time_food(-1);
            str = "The sheep_osarus are ready to be bred\n";
            Add_message(str,2);
        }

        if(getGav()->get_Time()>0)
            getGav()->Add_Time(-60);
        if(getGav()->get_Time()<=0){
            getGav()->UpLevel();
            getGav()->set_Time(-1);
            str = "Gavdari SUCCESSFULLY UPGRADED!\n Level: " + QString::number(getGav()->getLevel())
                    + "\n New Area: " + QString::number(getGav()->getCapacity()) + "\n";
            Add_message(str,3);
        }

        if(getGav()->get_Time_food()>0)
            getGav()->Add_Time_food(-60);
        if(getGav()->get_Time_food()<=0){
            getGav()->setExist(true);
            getGav()->setFood(false);
            getGav()->set_Time_food(-1);
            str = "The cow_osarus are ready to be bred\n";
            Add_message(str,3);
        }

        if(getMorq()->get_Time()>0)
            getMorq()->Add_Time(-60);
        if(getMorq()->get_Time()<=0){
            getMorq()->UpLevel();
            getMorq()->set_Time(-1);
            str = "Morqdari SUCCESSFULLY UPGRADED!\n Level: " + QString::number(getMorq()->getLevel())
                    + "\n New Area: " + QString::number(getMorq()->getCapacity()) + "\n";
            Add_message(str,4);
        }

        if(getMorq()->get_Time_food()>0)
            getMorq()->Add_Time_food(-60);
        if(getMorq()->get_Time_food()<=0){
            getMorq()->setExist(true);
            getMorq()->setFood(false);
            getMorq()->set_Time_food(-1);
            str = "The hen_osarus are ready to be bred\n";
            Add_message(str,4);
        }

        if(getGandomLand()->get_time()>0)
            getGandomLand()->Add_Time(-60);
        if(getGandomLand()->get_time()<=0){
            getGandomLand()->UpLevel();
            getGandomLand()->setTime(-1);
            str = "Gandom land Level up Successfully\n";
            Add_message(str,7);
        }

        if(getGandomLand()->get_time_work()>0)
            getGandomLand()->Add_Time_work(-60);
        if(getGandomLand()->get_time_work()<=0){
            getGandomLand()->setKesht(false);
            getGandomLand()->setTime_work(-1);
            str = "Gandom Land is Ready to Bardasht!!!!\n";
            Add_message(str,7);
        }

        if(getYonjeLand()->get_time()>0)
            getYonjeLand()->Add_Time(-60);
        if(getYonjeLand()->get_time()<=0){
            getYonjeLand()->UpLevel();
            getYonjeLand()->setTime(-1);
            str = "Yonje Land SUCCESSFULLY UPGRADED!\n Level: " + QString::number(getYonjeLand()->getLevel())
                    + "\n New Area: " + QString::number(getYonjeLand()->getArea()) + "\n";
            Add_message(str,8);
        }

        if(getYonjeLand()->get_time_work()>0)
            getYonjeLand()->Add_Time_work(-60);
        if(getYonjeLand()->get_time_work()<=0){
            getYonjeLand()->setTime_work(-1);
            if(getYonjeLand()->isShokhm()){
                str = "Yonje land was successfully plowed\n";
                getYonjeLand()->setShokhm(false);
                Add_message(str,8);
            }
            else{
                getYonjeLand()->setKesht(false);
                getYonjeLand()->setBardasht(false);
                str = "Yonje was successfully cultivated\n";
                Add_message(str,8);
            }
        }


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

    QString str = "congratulations! Your level has been upgraded";
    msg* payam = new msg(nullptr,&str);
    payam->show();
}

void Data::Exp_Day(){
    data["experience"] = data["experience"].toInt() + 1;
    if (data["experience"].toInt() >= data["capacity"].toInt())
        level_Day();
}

void Data::level_Day(){
    data["level"] = data["level"].toInt() + 1;
    data["experience"] = data["experience"].toInt() - data["capacity"].toInt();
    data["capacity"] = data["capacity"].toInt() * 2 + 10;

}

void Data::done(int h){
    if(h==1){
        int num = getGandomLand()->getArea();
        for(int i=0; i < num;i++){
            if(getGandomLand()->at(i) == 1)
                getGandomLand()->setAt(i,3);
        }
    }
    else{
        int num = getYonjeLand()->getArea();
        for(int i=0; i < num;i++){
            if(getYonjeLand()->at(i) == 1)
                getYonjeLand()->setAt(i,3);
        }
    }
}

void Data::shokhm(){
    int num = getYonjeLand()->getArea();
    for(int i=0;i<num;i++){
        if(getYonjeLand()->at(i) == 2){
            getYonjeLand()->setAt(i,4);
        }
    }
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

QString Data::get_Message(int i){
    QString str;
    pair<QString,int> v;
    multimap<QString,int>::iterator p = payam.begin();
    for(;p!=payam.end();p++){
        v=*p;
        if(v.second==i){
            str+=v.first;
            //payam.erase(p);
        }
    }
    return str;
}
