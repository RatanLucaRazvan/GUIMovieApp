////
//// Created by Ratan Luca on 4/5/2023.
////
//
//#include <crtdbg.h>
//#include "test_dynamic_vector.h"
//#include "DynamicVector.h"
//#include "Movie.h"
//
//void testDynamicArrayAddMovie()
//{
//    DynamicVector<Movie> array_for_test{};
//
//    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    array_for_test.dynamicArrayAddMovie(movie1);
//
//    assert(array_for_test.getLength() == 1);
//    assert(array_for_test.getArrayOfMovies()[0].getTitle() == "League of Justice");
//    assert(array_for_test.getArrayOfMovies()[0].getGenre() == "SF");
//    assert(array_for_test.getArrayOfMovies()[0].getYearOfRelease() == 2016);
//    assert(array_for_test.getArrayOfMovies()[0].getNumberOfLikes() == 20000);
//    assert(array_for_test.getArrayOfMovies()[0].getTrailer() == "https://www.youtube.com/watch?v=3cxixDgHUYw");
//
//    _CrtDumpMemoryLeaks();
//}
//
//void testResizeDynamicArray()
//{
//    DynamicVector<Movie> array_for_test{};
//    array_for_test.reziseDynamicVector();
//    assert(array_for_test.getCapacity() == 10);
//}
//
//void testDynamicArrayDeleteMovie()
//{
//    DynamicVector<Movie> array_for_test{};
//
//    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    array_for_test.dynamicArrayAddMovie(movie1);
//    array_for_test.dynamicArrayDeleteMovie("League of Justice");
//
//    assert(array_for_test.getLength() == 0);
//
//    _CrtDumpMemoryLeaks();
//}
//
//void testDynamicArrayUpdate()
//{
//    DynamicVector<Movie> array_for_test{};
//
//    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    array_for_test.dynamicArrayAddMovie(movie1);
//
//    array_for_test.updateMovieByGenreDynamicArray("League of justice", "horror");
//    assert(array_for_test.getArrayOfMovies()[0].getGenre() != "SF");
//    assert(array_for_test.getArrayOfMovies()[0].getGenre() == "horror");
//
//    array_for_test.updateMovieByNumberOfLikesDynamicArray("League of justice", 1);
//    assert(array_for_test.getArrayOfMovies()[0].getNumberOfLikes() != 20000);
//    assert(array_for_test.getArrayOfMovies()[0].getNumberOfLikes() == 1);
//
//    array_for_test.updateMovieByYearOfReleaseDynamicArray("League of justice", 1900);
//    assert(array_for_test.getArrayOfMovies()[0].getYearOfRelease() != 2016);
//    assert(array_for_test.getArrayOfMovies()[0].getYearOfRelease() == 1900);
//
//    array_for_test.updateMovieByTrailerDynamicArray("League of justice", "other trailer");
//    assert(array_for_test.getArrayOfMovies()[0].getTrailer() != "https://www.youtube.com/watch?v=3cxixDgHUYw");
//    assert(array_for_test.getArrayOfMovies()[0].getTrailer() == "other trailer");
//
//    _CrtDumpMemoryLeaks();
//}
//
//void testFindMovie()
//{
//    DynamicVector<Movie> array_for_test{};
//
//    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    array_for_test.dynamicArrayAddMovie(movie1);
//
//    assert(array_for_test.findMovie("League of Justice") == 0);
//    assert(array_for_test.findMovie("league of Justice") == 0);
//    assert(array_for_test.findMovie("Star Wars") == -1);
//
//    _CrtDumpMemoryLeaks();
//}
//
//void testGiveLikeToMovieDynamicArray()
//{
//    DynamicVector<Movie> array_for_test{};
//
//    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    array_for_test.dynamicArrayAddMovie(movie1);
//
//    array_for_test.giveLikeToMovieDynamicArray("League of Justice");
//
//    assert(array_for_test.getArrayOfMovies()[0].getNumberOfLikes() == 20001);
//
//    _CrtDumpMemoryLeaks();
//}