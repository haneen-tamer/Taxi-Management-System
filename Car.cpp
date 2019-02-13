#include "Car.h"

#include<iostream>
#include<string>


using namespace std;
car::car()
{
    plate_num = "";
    color = "";
    model = "";
    year = "";
}

car::car(QString line)
{
    QStringList list = line.split(",");
   list[0]=plate_num;
   list[1]=color ;
   list[2]=model ;
   list[3]=year ;
}
car::car(QString p, QString c, QString m, QString y){
    plate_num=p;
    color=c;
    model=m;
    year=y;
}
QString car::get_saveable_line()
{
    QString delimeter=",";
    QString s1;
    s1.append(plate_num);
    s1.append(delimeter);
    s1.append(color);
    s1.append(delimeter);
    s1.append(model);
    s1.append(delimeter);
    s1.append(year);
    return s1;
}
void car::set_id(QString d){
    driver_id=d;
}
QString car::get_printable_line()
{
 QString p="Plate Number: "+plate_num+"    Color: "+color+"   Model: "+model+"   Year: "+year+"\n";
 return p;
}
