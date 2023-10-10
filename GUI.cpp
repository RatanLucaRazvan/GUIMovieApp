//
// Created by Ratan Luca on 5/20/2023.
//
#include "GUI.h"
#include "RepoException.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>

GUI::GUI(Service &service): service(service)
{
    this->initGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {
    movieListWidget = new QListWidget{};
    titleLineEdit = new QLineEdit{};
    genreLineEdit = new QLineEdit{};
    yearOfReleaseLineEdit = new QLineEdit{};
    numberOfLikesLineEdit = new QLineEdit{};
    trailerLineEdit = new QLineEdit{};
    addButton = new QPushButton{"Add Movie"};
    deleteButton = new QPushButton{"Delete Movie"};
    updateButton = new QPushButton{"Update Movie"};
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(movieListWidget);
    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("Title", titleLineEdit);
    formLayout->addRow("Genre", genreLineEdit);
    formLayout->addRow("Year of Release", yearOfReleaseLineEdit);
    formLayout->addRow("Number of Likes", numberOfLikesLineEdit);
    formLayout->addRow("Trailer", trailerLineEdit);
    mainLayout->addLayout(formLayout);
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(updateButton);
    mainLayout->addLayout(buttonsLayout);

}

void GUI::populateList() {
    movieListWidget->clear();
    for(auto movie: service.getAllMovies())
    {
        movieListWidget->addItem(QString::fromStdString(movie.convertObjectInStringFormat()));
    }
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(movieListWidget, &QListWidget::clicked, [this]() {
        int selectedIndex = getSelectedIndex();
        Movie movie = service.getAllMovies()[selectedIndex];
        titleLineEdit->setText(QString::fromStdString(movie.getTitle()));
        genreLineEdit->setText(QString::fromStdString(movie.getGenre()));
        yearOfReleaseLineEdit->setText(QString::fromStdString(std::to_string(movie.getYearOfRelease())));
        numberOfLikesLineEdit->setText(QString::fromStdString(std::to_string(movie.getNumberOfLikes())));
        trailerLineEdit->setText(QString::fromStdString(movie.getTrailer()));
    });
    QObject::connect(addButton, &QPushButton::clicked, this, &GUI::addMovie);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &GUI::deleteMovie);
    QObject::connect(updateButton, &QPushButton::clicked, this, &GUI::updateMovie);
}

void GUI::addMovie()
{
    std::string title = titleLineEdit->text().toStdString();
    std::string genre = genreLineEdit->text().toStdString();
    int yearOfRelease = yearOfReleaseLineEdit->text().toInt();
    int numberOfLikes = numberOfLikesLineEdit->text().toInt();
    std::string trailer = trailerLineEdit->text().toStdString();

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

    this->genreLineEdit->clear();
    this->titleLineEdit->clear();
    this->yearOfReleaseLineEdit->clear();
    this->numberOfLikesLineEdit->clear();
    this->trailerLineEdit->clear();
    this->populateList();
}

void GUI::deleteMovie()
{
    int index = getSelectedIndex();
    if(index == -1)
    {
        QMessageBox::critical(this, "Error", "No movie selected");
        return;
    }
    Movie movie = this->service.getAllMovies()[index];
    this->service.deleteMovieService(movie.getTitle());
    this->populateList();
}

void GUI::updateMovie()
{
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

    std::string newTitle = titleLineEdit->text().toStdString();
    std::string newGenre = genreLineEdit->text().toStdString();
    int newYearOfRelease = yearOfReleaseLineEdit->text().toInt();
    int newNumberOfLikes = numberOfLikesLineEdit->text().toInt();
    std::string newTrailer = trailerLineEdit->text().toStdString();

    if(oldTitle != newTitle)
    {
        QMessageBox::critical(this, "Error", "Title is unique!");
        this->genreLineEdit->clear();
        this->titleLineEdit->clear();
        this->yearOfReleaseLineEdit->clear();
        this->numberOfLikesLineEdit->clear();
        this->trailerLineEdit->clear();
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

    this->genreLineEdit->clear();
    this->titleLineEdit->clear();
    this->yearOfReleaseLineEdit->clear();
    this->numberOfLikesLineEdit->clear();
    this->trailerLineEdit->clear();

    this->populateList();
}

int GUI::getSelectedIndex()
{
    QModelIndexList indexList = this->movieListWidget->selectionModel()->selectedIndexes();
    if(indexList.size() == 0)
        return -1;
    return indexList.at(0).row();
}