#include <bits/stdc++.h>
#include <exception>
using namespace std;
#include "Repository.h"
#include "RepoException.h"


std::vector<Movie> Repository::findAllMovies(){
    return this->database_of_movies;
}

void Repository::addMovieRepository(const Movie& new_movie) {
    auto iterator_for_movie = this->database_of_movies.end();
    std::string name_of_movie = new_movie.getTitle();
    for(auto iterator_of_vector = this->database_of_movies.begin();iterator_of_vector != this->database_of_movies.end();++iterator_of_vector)
    {
        std::string copy_of_title = (*iterator_of_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            iterator_for_movie = iterator_of_vector;
    }
    if(iterator_for_movie != this->database_of_movies.end())
        throw DuplicateMovieException();
    else {
        this->database_of_movies.push_back(new_movie);
    }
}

Movie Repository::deleteMovieRepository(const std::string name_of_movie) {
    auto iterator_for_movie = this->database_of_movies.end();
    Movie foundMovie;
    for(auto iterator_of_vector = this->database_of_movies.begin();iterator_of_vector != this->database_of_movies.end();++iterator_of_vector)
    {
        std::string copy_of_title = (*iterator_of_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            iterator_for_movie = iterator_of_vector, foundMovie = (*iterator_for_movie);
    }
    if(iterator_for_movie == this->database_of_movies.end())
        throw InexistentMovieException();
    else {
        this->database_of_movies.erase(iterator_for_movie);
        return foundMovie;
    }
}

Movie Repository::updateMovieByYearOfReleaseRepository(const std::string name_of_movie, const int new_year_of_release) {
    int position = -1;
    for(int index_in_vector = 0;index_in_vector < this->database_of_movies.size();index_in_vector++)
    {
        std::string copy_of_title = this->database_of_movies.at(index_in_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            position = index_in_vector;
    }
    if(position == -1)
        throw InexistentMovieException();
    else {
        Movie copy_of_movie = this->database_of_movies.at(position);
        this->database_of_movies.at(position).setYearOfRelease(new_year_of_release);
        return copy_of_movie;
    }
}

Movie Repository::updateMovieByGenreRepository(const std::string name_of_movie, const std::string new_genre) {
    int position = -1;
    for(int index_in_vector = 0;index_in_vector < this->database_of_movies.size();index_in_vector++)
    {
        std::string copy_of_title = this->database_of_movies.at(index_in_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            position = index_in_vector;
    }
    if(position == -1)
        throw InexistentMovieException();
    else {
        Movie copy_of_movie = this->database_of_movies.at(position);
        this->database_of_movies.at(position).setGenre(new_genre);
        return copy_of_movie;
    }
}

Movie Repository::updateMovieByNumberOfLikesRepository(const std::string name_of_movie,
                                                     int new_number_of_likes) {
    int position = -1;
    for(int index_in_vector = 0;index_in_vector < this->database_of_movies.size();index_in_vector++)
    {
        std::string copy_of_title = this->database_of_movies.at(index_in_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            position = index_in_vector;
    }
    if(position == -1)
        throw InexistentMovieException();
    else {
        Movie copy_of_movie = this->database_of_movies.at(position);
        this->database_of_movies.at(position).setNumberOfLikes(new_number_of_likes);
        return copy_of_movie;
    }
}

Movie Repository::updateMovieByTrailerRepository(const std::string name_of_movie, const std::string new_trailer) {
    int position = -1;
    for(int index_in_vector = 0;index_in_vector < this->database_of_movies.size();index_in_vector++)
    {
        std::string copy_of_title = this->database_of_movies.at(index_in_vector).getTitle();
        std::string copy_of_name_of_movie = name_of_movie;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            position = index_in_vector;
    }
    if(position == -1)
        throw InexistentMovieException();
    else {
        Movie copy_of_movie = this->database_of_movies.at(position);
        this->database_of_movies.at(position).setTrailer(new_trailer);
        return copy_of_movie;
    }
}

void Repository::giveLikeToMovieRepository(std::string movie_name) {
    int position = -1;
    for(int index_in_vector = 0;index_in_vector < this->database_of_movies.size();index_in_vector++)
    {
        std::string copy_of_title = this->database_of_movies.at(index_in_vector).getTitle();
        std::string copy_of_name_of_movie = movie_name;
        transform(copy_of_title.begin(), copy_of_title.end(), copy_of_title.begin(), ::tolower);
        transform(copy_of_name_of_movie.begin(), copy_of_name_of_movie.end(), copy_of_name_of_movie.begin(), ::tolower);
        if(copy_of_title == copy_of_name_of_movie)
            position = index_in_vector;
    }
    this->database_of_movies.at(position).setNumberOfLikes(this->database_of_movies.at(position).getNumberOfLikes() + 1);
}

void Repository::loadMoviesToFile() {
    ofstream file("movies.txt");
    if (!file.is_open())
        throw std::runtime_error{"File not open!"};
//    for(auto movie : this->database_of_movies)
//    {
//        file<<movie<<"\n";
//    }
    for(int i = 0; i < this->database_of_movies.size();i++)
    {
        file<<this->database_of_movies[i];
        if(i != this->database_of_movies.size() - 1)
            file<<"\n";
    }
    file.close();
}
