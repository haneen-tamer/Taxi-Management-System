#ifndef DRIVER_H
#define DRIVER_H

#include<QString>
#include"Car.h"
#include"Trip.h"
//#include<iostream>
//using namespace std;
class Driver
{
    QString name;
    QString Id;
    QString salary;
    bool status;
    bool in_trip;
    car *driver_car;
public:
    Driver();
    Driver(QString name_ui,QString id_ui,QString salary_ui,car car_ui);
    QString get_savable_line();
    Driver(QString line);
    bool check_ID(QString id1);
    void change_status(bool state);
    void recieve_R();
    bool check_in_trip();
    void change_in_trip(bool in);
    QString get_driver_ID();
    bool get_status();
    void end_trip();
    ~Driver();
};

#endif // DRIVER_H
