//
// Created by Ratan Luca on 4/12/2023.
//

#include <cassert>
#include "Movie.h"
#include "test_movie.h"


void testGetters()
{
    Movie movie1{};
    Movie movie{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};

    assert(movie1.getNumberOfLikes() == 0);
    assert(movie1.getYearOfRelease() == 0);
    assert(movie1.getTrailer().empty() == true);
    assert(movie1.getTitle().empty() == true);
    assert(movie1.getGenre().empty() == true);

    assert(movie.getNumberOfLikes() == 20000);
    assert(movie.getYearOfRelease() == 2016);
    assert(movie.getTrailer() == "https://www.youtube.com/watch?v=3cxixDgHUYw");
    assert(movie.getTitle() == "League of Justice");
    assert(movie.getGenre() == "SF");
}


void testSetters()
{
    Movie movie{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};

    movie.setNumberOfLikes(1);
    assert(movie.getNumberOfLikes() != 20000);
    assert(movie.getNumberOfLikes() == 1);

    movie.setYearOfRelease(2);
    assert(movie.getYearOfRelease() != 2016);
    assert(movie.getYearOfRelease() == 2);

    movie.setTrailer("abcd");
    assert(movie.getTrailer() != "https://www.youtube.com/watch?v=3cxixDgHUYw");
    assert(movie.getTrailer() == "abcd");

    movie.setGenre("horror");
    assert(movie.getGenre() != "SF");
    assert(movie.getGenre() == "horror");
}


//void testConvertToString()
//{
//    Movie movie{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    assert(movie.convertObjectInStringFormat() == "League of Justice: SF, year of release: 2016, number of likes: 20000, trailer: https://www.youtube.com/watch?v=3cxixDgHUYw");
//}