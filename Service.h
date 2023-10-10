//
// Created by Ratan Luca on 3/25/2023.
//

#ifndef A45_RATANLUCARAZVAN_SERVICE_H
#define A45_RATANLUCARAZVAN_SERVICE_H

#endif //A45_RATANLUCARAZVAN_SERVICE_H

#pragma once

#include "Repository.h"
#include "Watchlist.h"
#include "MovieValidator.h"
#include "FileWatchList.h"
#include "Undo.h"

#include <memory>

class Service{
private:
    Repository& repository;
    MovieValidator validator_for_movie;
    FileWatchList* watch_list;

    std::vector<std::unique_ptr<UndoAction>> undoActions;

public:
    Service(Repository& repository) : repository{repository}, watch_list(nullptr) {}
    Service(const Service& service) = delete;
    void operator=(const Service& service) = delete;
    void addMovieService(const std::string movie_name, const std::string movie_genre, int year_of_release_of_movie, int number_of_likes_of_movie, const std::string trailer_of_movie);
    void addMovieToWatchListService(const Movie& new_movie);
    void deleteMovieService(const std::string name_of_movie);
    void deleteMovieFromWatchListService(const std::string given_title);
    void updateMovieByYearOfReleaseService(const std::string name_of_movie, int new_year_of_release);
    void updateMovieByGenreService(const std::string name_of_movie, const std::string new_genre);
    void updateMovieByNumberOfLikesService(const std::string name_of_movie, int new_number_of_likes);
    void updateMovieByTrailerService(const std::string name_of_movie, const std::string new_trailer);
    void performUndo();
    void giveLikeToMovieService(std::string movie_name);
    void openWatchList();
    void initializeHTMLWatchList();
    void initializeCSVWatchList();
    std::vector<Movie> getAllMoviesContainingAGivenGenre(std::string& given_genre);
    std::vector<Movie> getAllMovies();
    std::vector<Movie> getWatchList();
};
