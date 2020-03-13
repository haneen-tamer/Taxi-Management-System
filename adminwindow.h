#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include<map>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QString>
#include<QStringList>
#include<QStringListModel>
#include"Car.h"
#include"Driver.h"
#include"Admin.h"
#include"Trip.h"
using namespace std;

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    void setTrips(vector<Trip*>&trip);
    void setDrivers(map<QString,Driver*>&d);
    void load_trips();
    void save_trips();
    ~AdminWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_loginButton_clicked();



    void on_addButton_clicked();

    void on_viewAllButton_clicked();
    void load();

    void on_logout_btn_clicked();

private:
    Ui::AdminWindow *ui;
    map<QString, Admin*> admins;
    vector<Trip*> *t ;
    map<QString,Driver*> *drivermap;
};

#endif // ADMINWINDOW_H
