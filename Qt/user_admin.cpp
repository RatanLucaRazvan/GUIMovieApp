//
// Created by Ratan Luca on 5/26/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_user_admin.h" resolved

#include "user_admin.h"
#include "ui_user_admin.h"


user_admin::user_admin(Service& service, QWidget *parent) :
       model{model}, service(service), QWidget(parent), ui(new Ui::user_admin) {
    ui->setupUi(this);
    this->initializeWindow();
}

user_admin::~user_admin() {
    delete ui;
}

void user_admin::showAdmin() {
    this->admin->show();
    this->admin->populateList();
}

void user_admin::showUser() {
    this->user->show();
//    this->user->populateWatchList();
}

void user_admin::initializeWindow() {
    this->ui->pushButton->hide();
    this->ui->pushButton_2->hide();
    this->ui->label->setText("Where do you want to store your watchlist?");
}

void user_admin::initializeHTMLWatchList() {
    this->service.initializeHTMLWatchList();
    this->admin = new AppGUI(this->service);
    this->user = new User(model, this->service);
    this->ui->pushButton_2->show();
    this->ui->pushButton->show();
    this->ui->CSVButton->hide();
    this->ui->HTMLButton->hide();
    this->ui->label->setText("Choose a mode");
}

void user_admin::initializeCSVWatchList() {
    this->service.initializeCSVWatchList();
    this->admin = new AppGUI(this->service);
    this->user = new User(model, this->service);
    this->ui->pushButton_2->show();
    this->ui->pushButton->show();
    this->ui->CSVButton->hide();
    this->ui->HTMLButton->hide();
    this->ui->label->setText("Choose a mode");
}

