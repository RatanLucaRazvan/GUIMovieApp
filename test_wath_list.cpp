//
// Created by Ratan Luca on 4/5/2023.
//

#include <crtdbg.h>
#include <cassert>
#include "test_wath_list.h"
#include "Watchlist.h"

void testWatchListAddMovie(){
    WatchList watch_list;

    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
    Movie movie2{"The Shape of Water", "SF", 2015, 40000, "https://www.youtube.com/watch?v=XFYWazblaUA&t=4s"};

    watch_list.addMovieWatchList(movie1);
    watch_list.addMovieWatchList(movie2);
    std::vector<Movie> all_movies = watch_list.getAllMovies();

    assert(all_movies.at(0).getTitle() == "League of Justice");
    assert(all_movies.at(0).getGenre() == "SF");
    assert(all_movies.at(0).getYearOfRelease() == 2016);
    assert(all_movies.at(0).getNumberOfLikes() == 20000);
    assert(all_movies.at(0).getTrailer() == "https://www.youtube.com/watch?v=3cxixDgHUYw");
    assert(all_movies.size() == 2);

    try{
        watch_list.addMovieWatchList(movie1);
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }
    _CrtDumpMemoryLeaks();
}

void testWatchListDeleteMovie()
{
    WatchList watch_list;

    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};

    watch_list.addMovieWatchList(movie1);
    watch_list.deleteMovieWatchList("league of Justice");
    std::vector<Movie> all_movies = watch_list.getAllMovies();

    assert(all_movies.empty() == true);

    try{
        watch_list.deleteMovieWatchList("league of Justice");
    }
    catch(std::exception& e)
    {
        assert(e.what() == e.what());
    }

    _CrtDumpMemoryLeaks();
}