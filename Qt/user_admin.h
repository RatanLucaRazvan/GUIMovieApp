//
// Created by Ratan Luca on 5/26/2023.
//

#ifndef A89_RATANLUCARAZVAN_USER_ADMIN_H
#define A89_RATANLUCARAZVAN_USER_ADMIN_H

#include <QWidget>
#include <ui_AppGUI.h>
#include "appgui.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class user_admin; }
QT_END_NAMESPACE

class user_admin : public QWidget {
Q_OBJECT

public:
    explicit user_admin(Service& service, QWidget *parent = nullptr);

    ~user_admin() override;
    void initializeWindow();

private:
    Ui::user_admin *ui;
    AppGUI* admin;
    QAbstractItemModel* model;
    User* user;
    Service& service;
public slots:
    void showAdmin();
    void showUser();
    void initializeHTMLWatchList();
    void initializeCSVWatchList();
};


#endif //A89_RATANLUCARAZVAN_USER_ADMIN_H
