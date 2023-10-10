//
// Created by Ratan Luca on 4/4/2023.
//
#include <bits/stdc++.h>

#include "Watchlist.h"


void WatchList::addMovieWatchList(const Movie& new_movie) {
    auto iterator_for_movie = this->list_of_movies.end();
    std::string name_of_movie = new_movie.getTitle();
    for(auto iterator_of_vector = this->list_of_movies.begin();iterator_of_vector != this->list_of_movies.end();++iterator_of_vector)
    {
        std::string copy_of_title = (*iterator_of_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            iterator_for_movie = iterator_of_vector;
    }
    if(iterator_for_movie != this->list_of_movies.end())
        throw std::exception();
    else
        this->list_of_movies.push_back(new_movie);
}

void WatchList::deleteMovieWatchList(const std::string name_of_movie) {
    auto iterator_for_movie = this->list_of_movies.end();
    for(auto iterator_of_vector = this->list_of_movies.begin();iterator_of_vector != this->list_of_movies.end();++iterator_of_vector)
    {
        std::string copy_of_title = (*iterator_of_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            iterator_for_movie = iterator_of_vector;
    }
    if(iterator_for_movie == this->list_of_movies.end())
        throw std::exception();
    else
        this->list_of_movies.erase(iterator_for_movie);
}

std::vector<Movie> WatchList::getAllMovies() {
    return this->list_of_movies;
}

