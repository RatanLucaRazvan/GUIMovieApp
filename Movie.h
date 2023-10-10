//
// Created by Ratan Luca on 3/25/2023.
//

#ifndef A45_RATANLUCARAZVAN_MOVIE_H
#define A45_RATANLUCARAZVAN_MOVIE_H

#endif //A45_RATANLUCARAZVAN_MOVIE_H
#include <string>

#pragma once



class Movie{
private:
    std::string title;
    std::string genre;
    int year_of_release;
    int number_of_likes;
    std::string trailer;
public:
    Movie(); /// default constructor
    Movie(const std::string& title, const std::string& genre, int year_of_release, int number_of_likes, const std::string& trailer);
//    Movie(const Movie& movie);
    std::string getTitle() const {return this->title;}
    std::string getGenre() const {return this->genre;}
    int getYearOfRelease() const {return this->year_of_release;}
    int getNumberOfLikes() const {return this->number_of_likes;}
    void setYearOfRelease(int new_year_of_release);
    void setGenre(const std::string new_genre);
    void setNumberOfLikes(int new_number_of_likes);
    void setTrailer(const std::string new_trailer);
    std::string convertObjectInStringFormat();
    std::string getTrailer() const {return this->trailer;};
    friend std::ostream &operator<<(std::ostream &output, const Movie &movie);
    friend std::istream &operator>>(std::istream &input, Movie &movie);
};