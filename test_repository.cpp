//
// Created by Ratan Luca on 4/5/2023.
//

#include <iostream>
#include "test_repository.h"
#include "Repository.h"
#include <crtdbg.h>
#include <cassert>


void testRepositoryAdd()
{
    Repository repository;

    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};

    repository.addMovieRepository(movie1);
    std::vector<Movie> all_movies = repository.findAllMovies();

    assert(all_movies.at(0).getTitle() == "League of Justice");
    assert(all_movies.at(0).getGenre() == "SF");
    assert(all_movies.at(0).getYearOfRelease() == 2016);
    assert(all_movies.at(0).getNumberOfLikes() == 20000);
    assert(all_movies.at(0).getTrailer() == "https://www.youtube.com/watch?v=3cxixDgHUYw");
    assert(all_movies.size() == 1);

    try{
    repository.addMovieRepository(movie1);
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }

    _CrtDumpMemoryLeaks();

}


void testRepositoryDelete()
{
    Repository repository;

    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};

    repository.addMovieRepository(movie1);
    repository.deleteMovieRepository("league of Justice");
    std::vector<Movie> all_movies = repository.findAllMovies();

    assert(all_movies.empty() == true);

    try{
        repository.deleteMovieRepository("league of Justice");
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }


    _CrtDumpMemoryLeaks();
}

void testRepositoryUpdate()
{
    Repository repository;

    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};

    repository.addMovieRepository(movie1);

    repository.updateMovieByNumberOfLikesRepository("League of Justice", 1);
    std::vector<Movie> all_movies = repository.findAllMovies();
    assert(all_movies.at(0).getNumberOfLikes() != 20000);
    assert(all_movies.at(0).getNumberOfLikes() == 1);

    try{
        repository.updateMovieByNumberOfLikesRepository("mama", 1);
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }

    repository.updateMovieByGenreRepository("League of Justice", "horror");
    std::vector<Movie> all_movies1 = repository.findAllMovies();
    assert(all_movies1.at(0).getGenre() != "SF");
    assert(all_movies1.at(0).getGenre() == "horror");

    try{
        repository.updateMovieByGenreRepository("mama", "horror");
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }


    repository.updateMovieByYearOfReleaseRepository("League of Justice", 2000);
    std::vector<Movie> all_movies2 = repository.findAllMovies();
    assert(all_movies2.at(0).getYearOfRelease() != 2016);
    assert(all_movies2.at(0).getYearOfRelease() == 2000);

    try{
        repository.updateMovieByYearOfReleaseRepository("mama", 1);
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }

    repository.updateMovieByTrailerRepository("League of Justice", "other trailer");
    std::vector<Movie> all_movies3 = repository.findAllMovies();
    assert(all_movies3.at(0).getTrailer() != "https://www.youtube.com/watch?v=3cxixDgHUYw");
    assert(all_movies3.at(0).getTrailer() == "other trailer");

    try{
        repository.updateMovieByTrailerRepository("mama", "ppp");
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }

    _CrtDumpMemoryLeaks();
}

void testRepositoryGiveLikeToMovie()
{
    Repository repository;

    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};

    repository.addMovieRepository(movie1);

    repository.giveLikeToMovieRepository("League of Justice");
    std::vector<Movie> all_movies = repository.findAllMovies();
    assert(all_movies.at(0).getNumberOfLikes() == 20001);

    _CrtDumpMemoryLeaks();

}