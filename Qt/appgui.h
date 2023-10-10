//
// Created by Ratan Luca on 5/21/2023.
//

#ifndef A89_RATANLUCARAZVAN_APPGUI_H
#define A89_RATANLUCARAZVAN_APPGUI_H

#include <QWidget>
#include "../Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AppGUI; }
QT_END_NAMESPACE

class AppGUI : public QWidget {
Q_OBJECT

public:
    AppGUI(Service& service, QWidget *parent = nullptr);

    ~AppGUI() override;
    void connectSignalsAndSlots();
    void populateList();
    void deleteMovie();
    int getSelectedIndex();

private:
    Service& service;
    Ui::AppGUI *ui;


public slots:
    void updateMovie();
    void addMovie();
    void elementClick();
    void makeUndo();
};


#endif //A89_RATANLUCARAZVAN_APPGUI_H
