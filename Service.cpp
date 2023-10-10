//
// Created by Ratan Luca on 3/25/2023.
//
#include <iostream>
#include <algorithm>
#include "Service.h"
#include "HTMLWatchList.h"
#include "CSVWatchList.h"

using namespace std;




void Service::addMovieService(std::string movie_name, std::string movie_genre, int year_of_release_of_movie,
                             int number_of_likes_of_movie, std::string trailer_of_movie) {
    Movie new_movie{movie_name, movie_genre, year_of_release_of_movie, number_of_likes_of_movie, trailer_of_movie};
    this->validator_for_movie.validate(new_movie);
    this->repository.addMovieRepository(new_movie);
    this->repository.loadMoviesToFile();
    this->undoActions.push_back(std::make_unique<UndoAdd>(this->repository, new_movie));
}

std::vector<Movie> Service::getAllMovies() {
    return this->repository.findAllMovies();
}

void Service::deleteMovieService(const std::string name_of_movie) {
    Movie deletedMovie = this->repository.deleteMovieRepository(name_of_movie);
    std::cout<<deletedMovie.convertObjectInStringFormat()<<"\n";
    this->repository.loadMoviesToFile();
    this->undoActions.push_back(std::make_unique<UndoRemove>(this->repository, deletedMovie));

}

void Service::updateMovieByYearOfReleaseService(const std::string name_of_movie, const int new_year_of_release) {
    Movie updatedMovie = this->repository.updateMovieByYearOfReleaseRepository(name_of_movie, new_year_of_release);
    this->repository.loadMoviesToFile();
    this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repository, updatedMovie));
}

void Service::updateMovieByGenreService(const std::string name_of_movie, const std::string new_genre) {
    Movie updatedMovie = this->repository.updateMovieByGenreRepository(name_of_movie,new_genre);
    this->repository.loadMoviesToFile();
    this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repository, updatedMovie));
}

void Service::updateMovieByNumberOfLikesService(const std::string name_of_movie, int new_number_of_likes) {
    Movie updatedMovie = this->repository.updateMovieByNumberOfLikesRepository(name_of_movie, new_number_of_likes);
    this->repository.loadMoviesToFile();
    this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repository, updatedMovie));
}

void Service::updateMovieByTrailerService(const std::string name_of_movie, const std::string new_trailer) {
    Movie updatedMovie  = this->repository.updateMovieByTrailerRepository(name_of_movie, new_trailer);
    this->repository.loadMoviesToFile();
    this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repository, updatedMovie));
}

void Service::addMovieToWatchListService(const Movie& new_movie) {
    this->watch_list->addMovieWatchList(new_movie);
    this->watch_list->writeToFile();
}

void Service::deleteMovieFromWatchListService(const std::string given_title) {
    this->watch_list->deleteMovieWatchList(given_title);
}

std::vector<Movie> Service::getWatchList() {
    return this->watch_list->getAllMovies();
}

void Service::giveLikeToMovieService(std::string movie_name) {
    this->repository.giveLikeToMovieRepository(movie_name);
}

void Service::openWatchList() {
    this->watch_list->displayWatchList();
}

std::vector<Movie> Service::getAllMoviesContainingAGivenGenre(std::string& given_genre) {
    std::vector<Movie> all_movies = this->repository.findAllMovies();
    int number = std::count_if(all_movies.begin(), all_movies.end(), [&given_genre](const Movie& movie){return movie.getGenre() == given_genre || given_genre.empty();});
    std::vector<Movie> filtered_movies(number);
    std::copy_if(all_movies.begin(), all_movies.end(), filtered_movies.begin(), [&given_genre](const Movie& movie){return movie.getGenre() == given_genre || given_genre.empty();});

    return filtered_movies;
}

void Service::initializeHTMLWatchList() {
    this->watch_list = new HTMLWatchList{"movie_watchlist.html"};
}

void Service::initializeCSVWatchList() {
    this->watch_list = new CSVWatchList("move_watchlist.csv");
}

void Service::performUndo() {
    if(undoActions.empty())
    {
        throw exception();
    }

    std::unique_ptr<UndoAction> last = std::move(undoActions.back());
    last->executeUndo();
    undoActions.pop_back();
}

//void Service::performRedo() {
//    if(this->redoActions.empty())
//    {
//        throw exception();
//    }
//
//    std::unique_ptr<RedoAction> last = std::move(redoActions.back());
//    last->executeRedo();
//    redoActions.pop_back();
//}


