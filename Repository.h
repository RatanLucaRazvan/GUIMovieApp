//
// Created by Ratan Luca on 3/25/2023.
//

#ifndef A45_RATANLUCARAZVAN_REPOSITORY_H
#define A45_RATANLUCARAZVAN_REPOSITORY_H
#include <vector>

#endif //A45_RATANLUCARAZVAN_REPOSITORY_H

#pragma once


#include "Movie.h"

class Repository{
private:
    std::vector<Movie> database_of_movies;

public:
    Repository() {}
    std::vector<Movie> findAllMovies();
    void addMovieRepository(const Movie& new_movie);
    void loadMoviesToFile();
    Movie deleteMovieRepository(const std::string name_of_movie);
    Movie updateMovieByYearOfReleaseRepository(const std::string name_of_movie, int new_year_of_release);
    Movie updateMovieByGenreRepository(const std::string name_of_movie, const std::string new_genre);
    Movie updateMovieByNumberOfLikesRepository(const std::string name_of_movie, int new_number_of_likes);
    Movie updateMovieByTrailerRepository(const std::string name_of_movie, const std::string new_trailer);
    void giveLikeToMovieRepository(std::string movie_name);
};
