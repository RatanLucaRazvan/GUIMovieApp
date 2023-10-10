//
// Created by Ratan Luca on 5/5/2023.
//

#ifndef A7_RATANLUCARAZVAN_1_REPOEXCEPTION_H
#define A7_RATANLUCARAZVAN_1_REPOEXCEPTION_H

#endif //A7_RATANLUCARAZVAN_1_REPOEXCEPTION_H
#include <iostream>

class RepoException : public std::exception
{
protected:
    std::string message;
public:
    RepoException();
    RepoException(const std::string& message);
    virtual ~RepoException() {}
    virtual const char* what();
};

class DuplicateMovieException : public RepoException
{
public:
    const char* what();
};

class InexistentMovieException : public RepoException
{
public:
    const char* what();
};