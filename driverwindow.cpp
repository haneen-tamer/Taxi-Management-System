#include "driverwindow.h"
#include "ui_driverwindow.h"

DriverWindow::DriverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DriverWindow)
{
    ui->setupUi(this);
    ui->DriverStack->setCurrentIndex(0);
    load_Drivers();
}

void DriverWindow::set_DataStructures(vector<Trip> &nt, vector<Trip> &at,
    map<QString, Driver> &ad, queue<Driver> &av){
    NewTrips = &nt;
    AllTrips = &at;
    AllDrivers = &ad;
    AvailableDrivers = &av;
}

DriverWindow::~DriverWindow()
{
    save_Drivers();
    delete ui;
}

void DriverWindow::on_pushButton_2_clicked()
{
    ui->DriverStack->setCurrentIndex(1);
}

void DriverWindow::on_change_status_btn_clicked()
{
    //og code
    d1->change_status(!d1->get_status());
    if (d1->get_status())
    {   //pop driver from queue
        Driver *temp_d = new Driver();
        int size = AvailableDrivers->size();
        for (int i = 0; i < size; i++)
        {
            *temp_d = AvailableDrivers->front();
            AvailableDrivers->pop();
            if (d1 != temp_d)
            {
                AvailableDrivers->push(*temp_d);
            }
            delete temp_d;
        }
    }
    else {
        AvailableDrivers->push(*d1);
    }
    set_status();
}

void DriverWindow::on_status_btn_clicked()
{
     ui->DriverStack->setCurrentIndex(2);
     set_status();
}

void DriverWindow::on_request_btn_clicked()
{
    if (NewTrips->empty())
      {
          QMessageBox* m = new QMessageBox;
          m->setText("there is no new trips.");
          m->show();
      }
      else
      {
          for (int i = 0; i < NewTrips->size(); i++)
          {
              if (d1->check_ID((*NewTrips)[i].get_driverID()))
              {
                  if (!d1->check_in_trip())//recive request
                  {
                      d1->recieve_R();
                      //QString ct = ;

                  }
                  ui->view_current_trip->setText((*NewTrips)[i].get_printable_line());
                  ui->DriverStack->setCurrentIndex(3);
                  break;
              }
              else if (i == NewTrips->size()-1)
              {
                  QMessageBox* m = new QMessageBox;
                  m->setText("you have no requests.");
                  m->show();
                  return;
              }
          }
          //ui->DriverStack->setCurrentIndex(3);
      }

}

void DriverWindow::on_view_btn_clicked()
{
    QStringListModel* m=new QStringListModel(this);
    QStringList list;
    vector<Trip>::iterator it;
    for(it=AllTrips->begin();it!=AllTrips->end();it++)
    {
       list.append(it->get_printable_line());
    }
    m->setStringList(list);
    ui->trip_history->setModel(m);
    ui->DriverStack->setCurrentIndex(4);
}

void DriverWindow::on_home_from_status_btn_clicked()
{
     ui->DriverStack->setCurrentIndex(1);
}

void DriverWindow::on_pushButton_clicked()//login
{
    if(ui->id_txt_box->text()!="")
    {
       map<QString, Driver>::iterator it;
       it = AllDrivers->find(ui->id_txt_box->text());
       if (it == AllDrivers->end())
       {
           QMessageBox* m = new QMessageBox;
           m->setText("This ID doesnot exist! Re-enter id .");
           m->show();
           ui->id_txt_box->clear();
           return;
       }
       d1 = &it->second;
       ui->DriverStack->setCurrentIndex(1);
    }
    else
    {
        QMessageBox* m = new QMessageBox;
        m->setText("please enter an ID.");
        m->show();
    }
}

void DriverWindow::on_logout_btn_clicked()
{
    ui->DriverStack->setCurrentIndex(0);
}

void DriverWindow::set_status()
{
    bool current_status = d1->get_status();
    if (current_status == true)
        ui->status_lbl->setText("Available");
    else
        ui->status_lbl->setText("Not_Available");
}
void DriverWindow::on_home_from_trip_btn_clicked()
{
     ui->DriverStack->setCurrentIndex(1);
}

void DriverWindow::on_end_trip_btn_clicked()
{
    d1->end_trip();
    AvailableDrivers->push(*d1);
    for(int j=0;j < NewTrips->size();j++)
    {
        if(d1->check_ID((*NewTrips)[j].get_driverID()))
        {
            AllTrips->push_back((*NewTrips)[j]);
            NewTrips->erase(NewTrips->begin() + j);//delete trip from new trips
        }
    }
    ui->DriverStack->setCurrentIndex(1);
}


void DriverWindow::load_Drivers(){
    QString fileName = "AllDrivers.txt";
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }else{
       QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            Driver d(line);
            (*AllDrivers)[d.get_driver_ID()]= d; //.insert(make_pair<QString, Driver>(d.get_driver_ID(),d));
        }
        file.close();
    }
}

void DriverWindow::save_Drivers(){
    QString fileName = "AllDrivers.txt";
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }else{
       QTextStream out(&file);
       map<QString, Driver>::iterator it;
        for(it = AllDrivers->begin(); it!=AllDrivers->end(); it++){
            if(it!=AllDrivers->begin())
                out<<endl;
            out<< it->second.get_savable_line();

        }
        file.flush();
        file.close();
    }
}
