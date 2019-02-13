#ifndef ADMIN_H
#define ADMIN_H


#include"Trip.h"
#include"Driver.h"
#include <iostream>
#include<unordered_map>
#include<QString>
#include<vector>
using namespace std;
class Admin
{
    QString admin_password;
    QString admin_name;

public:
    Admin();
    bool check_password(QString password);
    QString get_name();
    Admin(QString name, QString password);
    Admin(QString line);

};

#endif // ADMIN_H
