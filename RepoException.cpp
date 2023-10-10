//
// Created by Ratan Luca on 5/5/2023.
//
#include "RepoException.h"

RepoException::RepoException() : exception{}, message{""}
{
}

RepoException::RepoException(const std::string &message) : message{message}
{
}

const char* RepoException::what()
{
    return this->message.c_str();
}

const char* DuplicateMovieException::what()
{
    return "Movie already exists!";
}

const char* InexistentMovieException::what()
{
    return "Movie doesn't exist!";
}
