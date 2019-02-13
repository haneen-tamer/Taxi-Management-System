#include "adminwindow.h"
#include "ui_adminwindow.h"



AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    load();
    load_trips();
    ui->stack->setCurrentIndex(0);
}

void AdminWindow::setDrivers(map<QString,Driver>&d){
    drivermap = &d;
}

AdminWindow::~AdminWindow()
{
    save_trips();
    delete ui;
}

void AdminWindow::on_pushButton_clicked()
{
    if(ui->lineEdit_4->text()==""
            ||ui->lineEdit_5->text()==""
            ||ui->lineEdit_6->text()==""
            ||ui->lineEdit_7->text()==""
            ||ui->lineEdit->text()==""
            ||ui->lineEdit_3->text()==""
            ||ui->lineEdit_2->text()==""
            ||ui->lineEdit_4->text()==""){
        QMessageBox * msgBox= new QMessageBox();
                     msgBox->setText("Can not leave field empty!");
                     msgBox->show();
                     return;
    }

    car c(ui->lineEdit_4->text(),ui->lineEdit_5->text(),
          ui->lineEdit_6->text(),ui->lineEdit_7->text());

    Driver d(ui->lineEdit->text(),ui->lineEdit_2->text(),
             ui->lineEdit_3->text(),c);
    (*drivermap)[d.get_driver_ID()]=d;
    ui->stack->setCurrentIndex(1);
    //clear text boxes
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_4->clear();
}

void AdminWindow::on_pushButton_2_clicked()
{
    ui->stack->setCurrentIndex(2);
}

void AdminWindow::on_pushButton_3_clicked()
{
    ui->stack->setCurrentIndex(1);
}

void AdminWindow::on_pushButton_4_clicked()
{
    ui->stack->setCurrentIndex(1);
}

void AdminWindow::on_loginButton_clicked()
{
   map<QString, Admin>::iterator it;
    it = admins.find(ui->id_txt_box->text());
    if(it==admins.end()){
        QMessageBox * msgBox= new QMessageBox();
                     msgBox->setText("Wrong name!");
                     msgBox->show();
    }
   else{
        if(it->second.check_password(ui->pass_txt_box->text())){
            ui->stack->setCurrentIndex(1);
            ui->pass_txt_box->clear();
            ui->id_txt_box->clear();
         }
        else{
            QMessageBox * msgBox= new QMessageBox();
                         msgBox->setText("Wrong password!");
                         msgBox->show();
                     }
}
}

void AdminWindow::on_addButton_clicked()
{
     ui->stack->setCurrentIndex(3);
}



void AdminWindow::on_viewAllButton_clicked()
{
     ui->stack->setCurrentIndex(2);
     QStringListModel * model = new QStringListModel(this);
     QStringList list;
     vector<Trip>::iterator it;
     for(it=t->begin();it<t->end();it++){
       list.append( it->get_printable_line());
     }

     model->setStringList(list);
     ui->listView->setModel(model);
}

void AdminWindow::setTrips(vector<Trip>&trip){
   t=&trip;
}

void AdminWindow::load(){
    QString fileName = "AdminsFile.txt";
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }else{
       QTextStream in(&file);
       //out.setVersion(QDataStream::Qt_4_5);

        while(!in.atEnd()){
            QString line = in.readLine();
            Admin a(line);
            admins[a.get_name()]=a;
        }
        file.close();
    }
}


void AdminWindow::load_trips(){
    QString fileName = "Trips.txt";
    QFile file(fileName);
            if (!file.open(QFile::ReadOnly | QFile::Text)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }else{
               QTextStream in(&file);
                while(!in.atEnd()){
                    QString line = in.readLine();
                    Trip trip(line);
                    t->push_back(trip);
                }
                file.close();
            }
}

void AdminWindow::save_trips(){
    QString fileName = "Trips.txt";
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }else{
       QTextStream out(&file);
       vector<Trip>::iterator it;
        for(it = t->begin(); it!=t->end(); it++){
            if(it!=t->begin())
                out<<endl;
            out<<it->get_saveable_line();
        }
        file.flush();
        file.close();
    }
}

void AdminWindow::on_logout_btn_clicked()
{
    ui->id_txt_box->clear();
    ui->pass_txt_box->clear();
    ui->stack->setCurrentIndex(0);
}
