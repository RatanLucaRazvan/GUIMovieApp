//
// Created by Ratan Luca on 5/5/2023.
//
#pragma once
#ifndef A7_RATANLUCARAZVAN_1_MOVIEVALIDATOR_H
#define A7_RATANLUCARAZVAN_1_MOVIEVALIDATOR_H

#endif //A7_RATANLUCARAZVAN_1_MOVIEVALIDATOR_H

#include <iostream>
#include <vector>
#include "Movie.h"

class MovieException : public std::exception
{
private:
    std::vector<std::string> errors;
public:
    MovieException(std::vector<std::string> _errors);
    std::vector<std::string> getErrors() const;
};


class MovieValidator
{
public:
    MovieValidator() = default;
    static void validate(const Movie& movie);
};