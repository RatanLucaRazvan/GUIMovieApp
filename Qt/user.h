//
// Created by Ratan Luca on 5/26/2023.
//

#ifndef A89_RATANLUCARAZVAN_USER_H
#define A89_RATANLUCARAZVAN_USER_H

#include <QWidget>
#include <QAbstractItemModel>
#include "../Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class User; }
QT_END_NAMESPACE

class User : public QWidget {
Q_OBJECT

public:
    explicit User(QAbstractItemModel* model, Service& service, QWidget *parent = nullptr);

    ~User() override;
    void populateWatchList();
    int getSelectedIndex();

private:
    Ui::User *ui;
    Service& service;
    QAbstractItemModel* model;
    int count;
    Movie current_movie;
public slots:
    void showDatabase();
    void resetCount();
    void addToWatchList();
    void showMovie();
    void deleteFromWatchList();
    void openWatchList();
};


#endif //A89_RATANLUCARAZVAN_USER_H
