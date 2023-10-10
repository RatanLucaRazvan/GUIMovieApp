//
// Created by Ratan Luca on 3/25/2023.
//
#include <iostream>
#include "Movie.h"
#include <cstring>
#include <vector>

using namespace std;


Movie::Movie(): title(""), genre(""), year_of_release(0), number_of_likes(0), trailer("") {}

Movie::Movie(const std::string &title, const std::string &genre, int year_of_release, int number_of_likes,
             const std::string &trailer) {
    this->title = title;
    this->genre = genre;
    this->year_of_release = year_of_release;
    this->number_of_likes = number_of_likes;
    this->trailer = trailer;
}

void Movie::setYearOfRelease(const int new_year_of_release) {
    this->year_of_release = new_year_of_release;
}

void Movie::setGenre(const std::string new_genre) {
    this->genre = new_genre;
}

void Movie::setNumberOfLikes(int new_number_of_likes) {
    this->number_of_likes = new_number_of_likes;
}

void Movie::setTrailer(const std::string new_trailer) {
    this->trailer = new_trailer;
}

std::string Movie::convertObjectInStringFormat() {
    return this->getTitle() + ": " + this->getGenre() + ", year of release: " + std::to_string(this->getYearOfRelease()) + ", number of likes: " + std::to_string(this->getNumberOfLikes()) + ", trailer: " + this->trailer;
}

std::ostream &operator<<(ostream &output, const Movie &movie) {
    output<<movie.getTitle()<<","<<movie.getGenre()<<","<<movie.getYearOfRelease()<<","<<movie.getNumberOfLikes()<<","<<movie.getTrailer();
    return output;
}

std::istream &operator>>(istream &input, Movie &movie) {
    string line;
    getline(input, line);
    std::vector<string> fields;
    string field = "";
    for (char c: line) {
        if (c == ',') {
            fields.push_back(field);
            field = "";
        } else
            field += c;
    }
    fields.push_back(field);
//    cout<<field;
    movie.title = fields[0];
    movie.genre = fields[1];
    movie.year_of_release = stoi(fields[2]);
    movie.number_of_likes = stoi(fields[3]);
    movie.setTrailer(fields[4]);
    return input;
//    input>>movie.title>>movie.genre>>movie.year_of_release>>movie.number_of_likes>>movie.trailer;
//    return input;
}




//Movie::Movie(const Movie& movie){
//    this->number_of_likes = movie.number_of_likes;
//    this->year_of_release = movie.year_of_release;
//    this->title = new char[strlen(movie.title) + 1];
//    strcpy(this->title, movie.title);
//    this->genre = new char[strlen(movie.genre) + 1];
//    strcpy(this->genre, movie.genre);
//    this->trailer = new char[strlen(movie.trailer) + 1];
//    strcpy(this->trailer, movie.trailer);
//}
