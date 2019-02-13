#ifndef DRIVERWINDOW_H
#define DRIVERWINDOW_H

#include <QMainWindow>
#include<map>
#include<QListWidget>
#include<QString>
#include<QMessageBox>
#include"Driver.h"
#include"Trip.h"
#include<queue>
#include<QStringListModel>
#include<QFile>
#include<QTextStream>
namespace Ui {
class DriverWindow;
}

class DriverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DriverWindow(QWidget *parent = nullptr);
    void set_DataStructures(vector<Trip> &NewTrips,
    vector<Trip> &AllTrips,
    map<QString, Driver> &AllDrivers,
    queue<Driver> &AvailableDrivers);
    ~DriverWindow();

private slots:
    void load_Drivers();
    void save_Drivers();
    void on_pushButton_2_clicked();

    void on_change_status_btn_clicked();

    void on_status_btn_clicked();

    void on_request_btn_clicked();

    void on_view_btn_clicked();

    void on_home_from_status_btn_clicked();

    void on_pushButton_clicked();

    void on_logout_btn_clicked();

    void set_status();

    void on_home_from_trip_btn_clicked();

    void on_end_trip_btn_clicked();

private:
    Ui::DriverWindow *ui;
    Driver *d1 = new Driver();
    vector<Trip> *NewTrips;
    vector<Trip> *AllTrips;
    queue<Driver>*AvailableDrivers;
    map<QString, Driver> *AllDrivers;
};

#endif // DRIVERWINDOW_H
