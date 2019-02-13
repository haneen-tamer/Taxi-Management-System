#pragma once

#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<QFile>
#include<QTextStream>
#include "Admin.h"
//#include"Driver.h"
using namespace std;

void load_admins(map<string, Admin>& adminmap)
{
    QFile admin("AdminsFile.txt");
    if (!admin.open(QIODevice::ReadOnly)){
        QString errMsg = admin.errorString();
        //QFileDevice::FileError err = admin.error();
        return;
    }
    QTextStream in(&admin);
    while(!in.atEnd()){
        QString Line =in.readLine();
        QStringList list = Line.split(' ');
        Admin A(list[0].toStdString(), list[1].toStdString());
        adminmap[list[1].toStdString()] = A;
    }
    admin.close();
}


Driver AddNewDriver()
{
    Driver d;
    d.add_info();
    return d;

}

void VeiwAllTrips(vector<Trip>&trip) {
        vector<Trip>::iterator it;
        for (it = trip.begin(); it != trip.end(); it++) {
            (*it).Display();
        }
    }


