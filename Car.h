#pragma once

#include <iostream>
#include <QString>
#include<QStringList>
using namespace std;
class car
{
    QString plate_num, color, model, year,driver_id;
public:

    car();
    car(QString line);
    car(QString p,QString c,QString m,QString y);

    void set_id(QString driver_id);
    QString get_saveable_line();

    QString get_printable_line();
};

