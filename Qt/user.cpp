//
// Created by Ratan Luca on 5/26/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_User.h" resolved

#include <QMessageBox>
#include "user.h"
#include "ui_User.h"
#include "windows.h"


User::User(QAbstractItemModel* model, Service& service, QWidget *parent) :
        model{model}, service(service), QWidget(parent), ui(new Ui::User) {
    ui->setupUi(this);
    this->count = -1;
    this->current_movie = Movie();
}

User::~User() {
    delete ui;
}

void User::showDatabase() {
    std::string given_genre = this->ui->genreLineEdit->text().toStdString();
    std::vector<Movie> filtered_movies = this->service.getAllMoviesContainingAGivenGenre(given_genre);
    this->count++;
    if(this->count == filtered_movies.size())
        this->count = 0;
    if(this->count == 0)
    {
        this->current_movie = filtered_movies.at(this->count);
        this->ui->currentMovieLineEdit->setText(QString::fromStdString(filtered_movies.at(0).convertObjectInStringFormat()));
        this->ui->nextButton->setText("Next");
        ShellExecuteA(nullptr, nullptr, "chrome.exe", filtered_movies.at(this->count).getTrailer().c_str(), nullptr, SW_SHOWNORMAL);

    }
    else
    {
        this->current_movie = filtered_movies.at(this->count);
        this->ui->currentMovieLineEdit->setText(QString::fromStdString(filtered_movies.at(this->count).convertObjectInStringFormat()));
        ShellExecuteA(nullptr, nullptr, "chrome.exe", filtered_movies.at(this->count).getTrailer().c_str(), nullptr, SW_SHOWNORMAL);
    }
}

void User::resetCount() {
    this->count = -1;
    this->ui->nextButton->setText("See Movies");
    this->ui->currentMovieLineEdit->clear();
}

void User::addToWatchList() {
    if(this->ui->currentMovieLineEdit->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "No current movie");
        return;
    }
    try {
        this->service.addMovieToWatchListService(this->current_movie);
    }
    catch(...){
        QMessageBox::critical(this, "Error", "Already exists!");
        return;
    }
    std::string given_genre = this->ui->genreLineEdit->text().toStdString();
    std::vector<Movie> filtered_movies = this->service.getAllMoviesContainingAGivenGenre(given_genre);
    this->count++;
    if(this->count == filtered_movies.size())
        this->count = 0;
    if(this->count == 0)
    {
        this->current_movie = filtered_movies.at(this->count);
        this->ui->currentMovieLineEdit->setText(QString::fromStdString(filtered_movies.at(0).convertObjectInStringFormat()));
        this->ui->nextButton->setText("Next");
        ShellExecuteA(nullptr, nullptr, "chrome.exe", filtered_movies.at(this->count).getTrailer().c_str(), nullptr, SW_SHOWNORMAL);

    }
    else
    {
        this->current_movie = filtered_movies.at(this->count);
        this->ui->currentMovieLineEdit->setText(QString::fromStdString(filtered_movies.at(this->count).convertObjectInStringFormat()));
        ShellExecuteA(nullptr, nullptr, "chrome.exe", filtered_movies.at(this->count).getTrailer().c_str(), nullptr, SW_SHOWNORMAL);
    }
    this->populateWatchList();
}

void User::populateWatchList() {
    this->ui->movieWatchList->clear();
    std::vector<Movie> watchList = this->service.getWatchList();
    for(auto movie : watchList)
    {
        this->ui->movieWatchList->addItem(QString::fromStdString(movie.convertObjectInStringFormat()));
    }
}

void User::showMovie() {
    int index = getSelectedIndex();
    std::vector<Movie> watchList = this->service.getWatchList();
    this->ui->lineEdit->setText(QString::fromStdString(watchList[index].getTitle()));
    this->ui->lineEdit_2->setText(QString::fromStdString(std::to_string(watchList[index].getNumberOfLikes())));
    this->ui->lineEdit_3->setText(QString::fromStdString(std::to_string(watchList[index].getYearOfRelease())));
    this->ui->lineEdit_4->setText(QString::fromStdString(watchList[index].getGenre()));
    this->ui->lineEdit_5->setText(QString::fromStdString(watchList[index].getTrailer()));
}

int User::getSelectedIndex() {
    QModelIndexList index = this->ui->movieWatchList->selectionModel()->selectedIndexes();

    if(index.size() == 0)
    {
        return -1;
    }

    return index.at(0).row();
}

void User::deleteFromWatchList() {
    int index = this->getSelectedIndex();
    if(index == -1)
    {
        QMessageBox::critical(this, "Error", "No movie selected!");
        return;
    }
    {
        QMessageBox giveLike;
        giveLike.setText("Movie deleted.");
        giveLike.setInformativeText("Did you like the movie?");
        giveLike.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = giveLike.exec();
        switch(ret)
        {
            case QMessageBox::Yes: {
                this->service.giveLikeToMovieService(this->ui->lineEdit->text().toStdString());
                break;
            }
            case QMessageBox::No:
            {
                break;
            }
        }
    }
    this->service.deleteMovieFromWatchListService(this->ui->lineEdit->text().toStdString());
    this->populateWatchList();
    this->ui->lineEdit->clear();
    this->ui->lineEdit_2->clear();
    this->ui->lineEdit_3->clear();
    this->ui->lineEdit_4->clear();
    this->ui->lineEdit_5->clear();
}

void User::openWatchList() {
    this->service.openWatchList();
}
