//
// Created by Ratan Luca on 6/24/2023.
//

#include "Movie.h"
#include "Repository.h"

#ifndef A89_RATANLUCARAZVAN_UNDO_H
#define A89_RATANLUCARAZVAN_UNDO_H

#endif //A89_RATANLUCARAZVAN_UNDO_H


class UndoAction
{
public:
    virtual void executeUndo() = 0;
    // virtual destructor!
    virtual ~UndoAction() {};
};


class UndoAdd : public UndoAction
{
private:
    Movie addedMovie;
    Repository& repo;
public:
    UndoAdd(Repository& _repo, const Movie& movie): repo{_repo}, addedMovie{movie} {}

    void executeUndo() override;
};


class UndoRemove : public UndoAction
{
private:
    Movie deletedMovie;
    Repository& repo;
public:
    UndoRemove(Repository& repo, const Movie& movie): repo{repo}, deletedMovie{movie} {}

    void executeUndo() override;
};


class UndoUpdate : public UndoAction
{
private:
    Movie updatedMovie;
    Repository& repo;
public:
    UndoUpdate(Repository& repo, const Movie& movie): repo{repo}, updatedMovie{movie} {}

    void executeUndo() override;
};