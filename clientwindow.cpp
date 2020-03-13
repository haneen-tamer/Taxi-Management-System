#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui->ClientStack->setCurrentIndex(0);

}

void ClientWindow::set_client_ds(vector<Trip*>& at, vector<Trip*>& nt,queue<Driver*> & av ){
    AllTrips = &at;
    NewTrips = &nt;
    avail_driver = &av;
    load_from_file();
}

ClientWindow::~ClientWindow()
{
    save_to_File();
    delete ui;
}

void ClientWindow::on_register_btn_clicked()
{
    ui->ClientStack->setCurrentIndex(4);
}

void ClientWindow::on_login_btn_clicked()
{
    map<QString, Client*>::iterator it;
    it = clients.find(ui->id_txt_box->text());
    if(it== clients.end()){
        QMessageBox* m = new QMessageBox;
        m->setText("ID not found!");
        m->show();
    }else{
        if(it->second->check_pass(ui->pass_txt_box->text())){
            loggedIn = (it->second);
            ui->ClientStack->setCurrentIndex(1);
            ui->id_txt_box->clear();
            ui->pass_txt_box->clear();
        }else{
            QMessageBox* m = new QMessageBox;
            m->setText("Wrong password!");
            m->show();
        }
    }
}

void ClientWindow::on_logout_btn_clicked()
{
    loggedIn = nullptr;
    ui->ClientStack->setCurrentIndex(0);
}

void ClientWindow::on_request_btn_clicked()
{
    //handle on trip
    vector<Trip*>::iterator it;
    for(it = NewTrips->begin(); it!=NewTrips->end(); it++){
        if((*it)->get_clientID() == loggedIn->get_client_id()){
            QMessageBox* m = new QMessageBox;
            m->setText("You are currently on trip. Please wait untill trip ends before requesting another...");
            m->show();
            return;
        }
    }
    //handle no avail drivers
    if(avail_driver->empty()){
        QMessageBox* m = new QMessageBox;
        m->setText("There seems to be no available drivers at the moment. Please try again later...");
        m->show();
    }else{
        //handle request
        Driver* d = avail_driver->front();
        avail_driver->pop();
        Trip *request= new Trip(ui->Date_txt_box->text(), ui->end_txt_box->text(), ui->beg_txt_box->text());
        request->set_client(loggedIn->get_client_id());
        request->set_driver(d->get_driver_ID());
        NewTrips->push_back(request);
        //display reguest
        ui->current_trip_display->setText(request->get_printable_line());
        ui->ClientStack->setCurrentIndex(3);
        //clear text  boxes
        ui->Date_txt_box->clear();
        ui->end_txt_box->clear();
        ui->beg_txt_box->clear();
    }

}

void ClientWindow::on_home_btn_2_clicked()
{
    ui->ClientStack->setCurrentIndex(1);
}

void ClientWindow::on_home_btn_clicked()
{
    ui->ClientStack->setCurrentIndex(1);
}

void ClientWindow::on_view_client_history_btn_clicked()
{
    //past trips
    QStringListModel * model = new QStringListModel(this);
    QStringList list;
    vector<Trip*>::iterator it;
    for(it = AllTrips->begin(); it!=AllTrips->end(); it++){
        if((*it)->get_clientID() == loggedIn->get_client_id()){
            list.append((*it)->get_printable_line());
        }
    }
    //check empty
    if(list.empty()){
        QMessageBox* m = new QMessageBox;
        m->setText("No past trips!");
        m->show();
        return;
    }
    model->setStringList(list);
    ui->past_trips->setModel(model);

    //current trip
    for(it = NewTrips->begin(); it!=NewTrips->end(); it++){
        if((*it)->get_clientID() == loggedIn->get_client_id()){
            ui->current_trip->setText((*it)->get_printable_line());
            break;
        }
    }
    //go to view
    ui->ClientStack->setCurrentIndex(2);
}

void ClientWindow::on_register_btn_add_clicked()
{
    map<QString, Client*>::iterator it;
    it = clients.find(ui->id_txt_box_2->text());
    if(it != clients.end()){
        QMessageBox* m = new QMessageBox;
        m->setText("ID taken!");
        m->show();
        return;
    }
    if(ui->pass_txt_box_2->text() == ui->pas_rentry_txt_box->text()){
        Client *c= new Client(ui->name_txt_box->text(),
                 ui->id_txt_box_2->text(),
                 ui->pass_txt_box->text());
        clients[c->get_client_id()] = c;
        this->loggedIn = c;
        ui->ClientStack->setCurrentIndex(1);
        ui->name_txt_box->clear();
        ui->id_txt_box_2->clear();
        ui->pass_txt_box->clear();
    }else{
        QMessageBox* m = new QMessageBox;
        m->setText("Passwords don't match!");
        m->show();
    }
}


void ClientWindow::load_from_file(){
    QString fileName = "Client.txt";
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }else{
       QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            Client *c= new Client(line);
            clients[c->get_client_id()] = c;
        }
        file.close();
    }
}

void ClientWindow::save_to_File(){
    QString fileName = "Client.txt";
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }else{
       QTextStream out(&file);
       map<QString, Client*>::iterator it;
        for(it = clients.begin(); it!=clients.end(); it++){
            if(it!=clients.begin())
                out<<endl;
            out<<it->second->get_saveable_line();
            delete (it->second);
           // cout<<it->second.get_saveable_line().toStdString();
        }
        file.flush();
        file.close();
    }
}
