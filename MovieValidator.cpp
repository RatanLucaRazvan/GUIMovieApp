//
// Created by Ratan Luca on 5/5/2023.
//


#include "MovieValidator.h"

MovieException::MovieException(std::vector<std::string> _errors): errors{_errors}
{
}

std::vector<std::string> MovieException::getErrors() const {
    return this->errors;
}

void MovieValidator::validate(const Movie &movie) {
    std::vector<std::string> errors;
    if(movie.getTitle().size() < 2)
        errors.push_back("The title cannot have only one character!");
    if(movie.getYearOfRelease() < 1700 || movie.getYearOfRelease() > 2023)
        errors.push_back("Not a valid year!");
    if(movie.getNumberOfLikes() < 0)
        errors.push_back("Number cannot be negative!");
    if(movie.getGenre() != "SF" && movie.getGenre() != "horror" && movie.getGenre() != "animation" && movie.getGenre() != "comedy" && movie.getGenre() != "drama" && movie.getGenre() != "musical")
        errors.push_back("Genre not correct");
    size_t posWww = movie.getTrailer().find("www");
    size_t posHttp = movie.getTrailer().find("http");
    if(posWww != 0 && posHttp != 0)
        errors.push_back("Trailer not valid! It must start with \"www\" or \"http\"");
    if(errors.size() > 0)
        throw MovieException(errors);
}
