#ifndef TRIP_H
#define TRIP_H

#include<QString>
#include<QStringList>
class Trip
{
    QString Client_ID, Date, Destination, Begining, Driver_ID;

public:
    Trip();
    Trip(QString line);
    Trip(QString Date, QString Destination, QString Begining);
    QString get_saveable_line();
    QString get_printable_line();
    void set_client(QString C_ID);
    void set_driver(QString D_ID);
    QString get_driverID();
    QString get_clientID();
};

#endif
