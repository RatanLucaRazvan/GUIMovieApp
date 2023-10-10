//
// Created by Ratan Luca on 5/20/2023.
//
#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include "Service.h"
#include <qlineedit.h>

#ifndef A89_RATANLUCARAZVAN_GUI_H
#define A89_RATANLUCARAZVAN_GUI_H

#endif //A89_RATANLUCARAZVAN_GUI_H


class GUI : public QWidget
{
private:
    Service& service;
    QListWidget* movieListWidget;
    QLineEdit* titleLineEdit;
    QLineEdit* genreLineEdit;
    QLineEdit* numberOfLikesLineEdit;
    QLineEdit* yearOfReleaseLineEdit;
    QLineEdit* trailerLineEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
public:
    GUI(Service& service);
private:
    void initGUI();
    void populateList();
    void connectSignalsAndSlots();
    void addMovie();
    void deleteMovie();
    void updateMovie();
    int getSelectedIndex();

};