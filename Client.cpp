#include "Client.h"

using namespace std;



Client::Client()
{
    id = "";
    name = "";
    pass = "";
}

Client::Client(QString name_, QString id_, QString pass_) {
    name = name_;
    id = id_;
    pass = pass_;
}

Client::Client(QString line){
    QStringList l = line.split(" ");
    name = l[0];
    id = l[1];
    pass = l[2];
}

QString Client::get_saveable_line(){
    return  name+" "+id+" "+pass;
}

bool Client::check_pass(QString password) {
    return (pass.compare(password) == 0);
}


QString Client::get_client_id() {
    return id;
}
QString Client::get_client_name() {
    return name;
}



