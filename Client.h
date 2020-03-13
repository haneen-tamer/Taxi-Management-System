#ifndef CLIENT_H
#define CLIENT_H

#include<iostream>
#include<vector>
#include<queue>
#include<QString>
#include<QStringList>
using namespace std;
class Client
{
    QString name, id, pass;
public:
    Client();
    Client(QString line);
    Client(QString name_, QString id_, QString pass_);
    QString get_saveable_line();
    bool check_pass(QString password);
    QString get_client_id();
    QString get_client_name();
    void display_client();
    void save_client(ofstream &f);
    void load_client(ifstream &f);
};

#endif
