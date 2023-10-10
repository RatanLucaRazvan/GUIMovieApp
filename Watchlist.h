//
// Created by Ratan Luca on 4/4/2023.
//

#ifndef A45_RATANLUCARAZVAN_WATCHLIST_H
#define A45_RATANLUCARAZVAN_WATCHLIST_H
#include <vector>

#endif //A45_RATANLUCARAZVAN_WATCHLIST_H

#pragma once


#include "Movie.h"




class WatchList{
protected:
    std::vector<Movie> list_of_movies;


public:
    WatchList() = default;
    virtual ~WatchList() = default;
    std::vector<Movie> getAllMovies();
    void addMovieWatchList(const Movie& new_movie);
    void deleteMovieWatchList(const std::string name_of_movie);

};



