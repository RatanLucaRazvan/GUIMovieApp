//
// Created by Ratan Luca on 6/24/2023.
//
#include "Undo.h"
#include <iostream>
void UndoAdd::executeUndo() {
    this->repo.deleteMovieRepository(this->addedMovie.getTitle());
    this->repo.loadMoviesToFile();
}

void UndoRemove::executeUndo() {
    this->repo.addMovieRepository(this->deletedMovie);
    this->repo.loadMoviesToFile();
}

void UndoUpdate::executeUndo() {
    this->repo.deleteMovieRepository(this->updatedMovie.getTitle());
    this->repo.addMovieRepository(updatedMovie);
    this->repo.loadMoviesToFile();
}
