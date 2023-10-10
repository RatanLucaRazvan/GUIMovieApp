//
// Created by Ratan Luca on 5/21/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppGUI.h" resolved

#include <QMessageBox>
#include "appgui.h"
#include "ui_AppGUI.h"
#include "../RepoException.h"


AppGUI::AppGUI(Service& service, QWidget *parent) :
        QWidget(parent), ui(new Ui::AppGUI), service(service) {
    ui->setupUi(this);
    this->populateList();
    this->connectSignalsAndSlots();
}

AppGUI::~AppGUI() {
    delete ui;
}

void AppGUI::populateList() {
    this->ui->movielistwidget->clear();

    for(auto movie : this->service.getAllMovies())
    {
        this->ui->movielistwidget->addItem(QString::fromStdString(movie.convertObjectInStringFormat()));
    }
}

void AppGUI::connectSignalsAndSlots() {
    QObject::connect(this->ui->deleteButton, &QPushButton::clicked, this, &AppGUI::deleteMovie);
}

int AppGUI::getSelectedIndex()
{
    QModelIndexList indexList = this->ui->movielistwidget->selectionModel()->selectedIndexes();
    if(indexList.size() == 0)
        return -1;
    return indexList.at(0).row();
}

void AppGUI::deleteMovie() {
    int index = getSelectedIndex();
    if(index == -1)
    {
        QMessageBox::critical(this, "Error", "No movie selected");
        return;
    }
    Movie movie = this->service.getAllMovies()[index];
    this->service.deleteMovieService(movie.getTitle());
    this->populateList();
    this->ui->trailerLineEdit->clear();
    this->ui->genreLineEdit->clear();
    this->ui->titleLineEdit->clear();
    this->ui->yearOfReleaseLineEdit->clear();
    this->ui->numberOfLikesLineEdit->clear();
}

void AppGUI::addMovie() {
    std::string title = this->ui->titleLineEdit->text().toStdString();
    std::string genre = this->ui->genreLineEdit->text().toStdString();
    int yearOfRelease = this->ui->yearOfReleaseLineEdit->text().toInt();
    int numberOfLikes = this->ui->numberOfLikesLineEdit->text().toInt();
    std::string trailer = this->ui->trailerLineEdit->text().toStdString();

    try {
        service.addMovieService(title, genre, yearOfRelease, numberOfLikes, trailer);
    }
    catch(DuplicateMovieException& e)
    {
        QMessageBox::critical(this, "Error", e.what());
        return;
    }
    catch(MovieException& e)
    {
        std::string all_error;
        for(auto error : e.getErrors())
            all_error += error + "\n";
        QMessageBox::critical(this, "Error", QString::fromStdString(all_error));
        return;
    }

    this->ui->genreLineEdit->clear();
    this->ui->titleLineEdit->clear();
    this->ui->yearOfReleaseLineEdit->clear();
    this->ui->numberOfLikesLineEdit->clear();
    this->ui->trailerLineEdit->clear();
    this->populateList();
}

void AppGUI::updateMovie() {
    int index = getSelectedIndex();
    if(index == -1)
    {
        QMessageBox::critical(this, "Error", "No movie selected");
        return;
    }
    Movie movie = this->service.getAllMovies()[index];
    std::string oldTitle = movie.getTitle();
    std::string oldGenre = movie.getGenre();
    int oldYearOfRelease = movie.getYearOfRelease();
    int oldNumberOfLikes = movie.getNumberOfLikes();
    std::string oldTrailer = movie.getTrailer();

    std::string newTitle = this->ui->titleLineEdit->text().toStdString();
    std::string newGenre = this->ui->genreLineEdit->text().toStdString();
    int newYearOfRelease = this->ui->yearOfReleaseLineEdit->text().toInt();
    int newNumberOfLikes = this->ui->numberOfLikesLineEdit->text().toInt();
    std::string newTrailer = this->ui->trailerLineEdit->text().toStdString();

    if(oldTitle != newTitle)
    {
        QMessageBox::critical(this, "Error", "Title is unique!");
        this->ui->genreLineEdit->clear();
        this->ui->titleLineEdit->clear();
        this->ui->yearOfReleaseLineEdit->clear();
        this->ui->numberOfLikesLineEdit->clear();
        this->ui->trailerLineEdit->clear();
        return;
    }
    if(oldGenre != newGenre)
        this->service.updateMovieByGenreService(movie.getTitle(), newGenre);
    if(oldNumberOfLikes != newNumberOfLikes)
        this->service.updateMovieByNumberOfLikesService(movie.getTitle(), newNumberOfLikes);
    if(oldYearOfRelease != newYearOfRelease)
        this->service.updateMovieByYearOfReleaseService(movie.getTitle(), newYearOfRelease);
    if(oldTrailer != newTrailer)
        this->service.updateMovieByTrailerService(movie.getTitle(), newTrailer);
    this->ui->genreLineEdit->clear();
    this->ui->titleLineEdit->clear();
    this->ui->yearOfReleaseLineEdit->clear();
    this->ui->numberOfLikesLineEdit->clear();
    this->ui->trailerLineEdit->clear();
    this->populateList();
}

void AppGUI::elementClick() {
    int selectedIndex = getSelectedIndex();
    Movie movie = service.getAllMovies()[selectedIndex];
    this->ui->titleLineEdit->setText(QString::fromStdString(movie.getTitle()));
    this->ui->genreLineEdit->setText(QString::fromStdString(movie.getGenre()));
    this->ui->yearOfReleaseLineEdit->setText(QString::fromStdString(std::to_string(movie.getYearOfRelease())));
    this->ui->numberOfLikesLineEdit->setText(QString::fromStdString(std::to_string(movie.getNumberOfLikes())));
    this->ui->trailerLineEdit->setText(QString::fromStdString(movie.getTrailer()));
}

void AppGUI::makeUndo() {
    this->service.performUndo();
    this->populateList();
}


