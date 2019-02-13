#include "mainwindow.h"
#include <QApplication>
#include<QDialog>
#include<QMessageBox>
#include <unordered_map>
#include <queue>
#include<map>
#include<vector>
#include"Admin.h"
//#include"Trip.h"
//#include"Client.h"
//#include"Driver.h"
#include"adminwindow.h"
#include"clientwindow.h"
#include"driverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<Trip> NewTrips;
    vector<Trip> AllTrips;
    map<QString, Driver> AllDrivers;
    queue<Driver>AvailableDrivers;
    //client path
    ClientWindow c;
    c.set_client_ds(AllTrips, NewTrips, AvailableDrivers);
    c.setWindowTitle("Client");
    c.show();
    //admin path
    AdminWindow ad;
    ad.setTrips(AllTrips);
    ad.setDrivers(AllDrivers);
    ad.setWindowTitle("Admin");
    ad.show();

    //Driver Path
    DriverWindow d;
    d.set_DataStructures(NewTrips, AllTrips, AllDrivers, AvailableDrivers);
    d.setWindowTitle("Driver");
    d.show();
    return a.exec();
}
