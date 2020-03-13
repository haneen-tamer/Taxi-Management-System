#include "Driver.h"
using namespace std;
Driver::Driver()
{
    name = "";
    salary = "";
    status = false;
    Id = "";
    in_trip = false;
    driver_car = new car();
}
Driver::Driver(QString name_ui,QString id_ui,QString salary_ui,car car_ui)//adding new driver
{
    name=name_ui;
    Id=id_ui;
    salary=salary_ui;
    driver_car=&car_ui;
    driver_car->set_id(Id);
}
Driver::Driver(QString line)//reading file
{
    QStringList l = line.split(" ");
    Id=l[0];
    name=l[1];
    salary=l[2];
    if(l[3]=="in_trip")
    {
        in_trip=true;
    }
    else
        in_trip=false;
    if(l[4]=="available")
    {
        status=true;
    }
    else
        status=false;
    //driver_car = new car(l[5]);
}
bool Driver::check_ID(QString id1)
{
    if (Id == id1)
    {
        return true;
    }
    else
        return false;
}
void Driver::change_status(bool state)
{
    status = state;
}
void Driver::recieve_R()
{
    change_status(false);
    change_in_trip(true);
}
QString Driver::get_driver_ID()
{
    return Id;
}
bool Driver::check_in_trip()
{
    return in_trip;
}
void Driver::change_in_trip(bool in)
{
    in_trip = in;
}
void Driver::end_trip()
{
    change_status(true);
    change_in_trip(false);
}
bool Driver::get_status()
{
    return status;
}
QString Driver::get_savable_line()
{
    QString t,s;
    if(in_trip==true)
    {
        t="in_trip";
    }
    else {
        t="not_in_trip";
    }
    if(status==true)
    {
        s="available";
    }
    else {
        s="unavailable";
    }
    return Id+" "+name+" "+salary+" "+t+" "+s+" ";//+ driver_car->get_saveable_line();
}

