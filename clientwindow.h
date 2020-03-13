#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include"Client.h"
#include"Driver.h"
#include<iostream>
#include<map>
#include<QListWidget>
#include<QString>
#include<QMessageBox>
#include<QStringList>
#include<QStringListModel>
#include<QFile>
#include<QTextStream>
using namespace std;

namespace Ui{
class ClientWindow;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    void set_client_ds(vector<Trip*>& at, vector<Trip*>& nt,queue<Driver*> & av );
    ~ClientWindow();

private slots:
    void on_register_btn_clicked();

    void on_login_btn_clicked();

    void on_logout_btn_clicked();

    void on_request_btn_clicked();

    void on_home_btn_2_clicked();

    void on_home_btn_clicked();

    void on_view_client_history_btn_clicked();

    void on_register_btn_add_clicked();
    void load_from_file();
    void save_to_File();

private:
    Ui::ClientWindow *ui;
    Client * loggedIn;
    map<QString, Client*> clients;
    vector<Trip*>* AllTrips, *NewTrips;
    queue<Driver*>* avail_driver;
};

#endif // CLIENTWINDOW_H
