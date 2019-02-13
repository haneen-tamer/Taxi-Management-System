#include "Trip.h"

Trip::Trip()
{
    Date = "";
    Destination = "";
    Begining = "";
    Client_ID = "";
    Driver_ID = "";
}

Trip::Trip(QString line){
    QStringList l = line.split(" ");
    Client_ID = l[0];
    Driver_ID = l[1];
    Destination = l[2];
    Begining = l[3];
    Date = l[4];
}

Trip::Trip(QString Date_,
           QString Destination_, QString Begining_){
    Date = Date_;
    Destination = Destination_;
    Begining = Begining_;
}


QString Trip::get_saveable_line(){
    return Client_ID+" "+
            Driver_ID+" "+
            Begining+" "+
            Destination+" "+
            Date;
}

QString Trip::get_printable_line(){
    QString l =  "Client: "+Client_ID+"\n"+
            "Driver: "+Driver_ID+"\n"+
            "Start: "+Begining+"\n"+
            "End: "+ Destination+"\n"+
            "Date: "+Date;
    return  l;
}
void Trip::set_client(QString C_ID)
{
    Client_ID = C_ID;
}
void Trip::set_driver(QString D_ID)
{
    Driver_ID = D_ID;
}

QString Trip::get_driverID()
{
    return Driver_ID;
}
QString Trip::get_clientID()
{
    return Client_ID;
}
