#include "Admin.h"
#include <QString>
#include<QStringList>
using namespace std;

Admin::Admin()
{
    admin_name = "";
    admin_password = "";
}

Admin::Admin(QString name, QString password)
{
    admin_name = name;
    admin_password = password;
}

bool Admin::check_password(QString password) {
    if (password == admin_password) {
        return true;
    }
    else { return false; }
}

QString Admin::get_name() {
    return admin_name;
}



Admin::Admin(QString line){
    QStringList l= line.split(" ");
    admin_name=l[0];
    admin_password=l[1];
}
