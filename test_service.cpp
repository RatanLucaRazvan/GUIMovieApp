////
//// Created by Ratan Luca on 4/5/2023.
////
//
//
//#include <crtdbg.h>
//#include <cassert>
//#include "test_service.h"
//#include "Service.h"
//#include "CSVWatchList.h"
//
//void testServiceAddMovie()
//{
//    Repository repository;
//    FileWatchList* watch_list = new CSVWatchList{"movie_watchlist.csv"};
//    Service service{repository, watch_list};
//
//    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    service.addMovieService("League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw");
//    service.addMovieToWatchListService(movie1);
//
//    std::vector<Movie> array_for_test = service.getAllMovies();
//    std::vector<Movie> watch_list_for_test = service.getWatchList();
//
//    assert(array_for_test.at(0).getTitle() == "League of Justice");
//    assert(array_for_test.at(0).getGenre() == "SF");
//    assert(array_for_test.at(0).getYearOfRelease() == 2016);
//    assert(array_for_test.at(0).getNumberOfLikes() == 20000);
//    assert(array_for_test.at(0).getTrailer() == "https://www.youtube.com/watch?v=3cxixDgHUYw");
//    assert(array_for_test.size() == 1);
//
//    assert(watch_list_for_test.at(0).getTitle() == "League of Justice");
//    assert(watch_list_for_test.at(0).getGenre() == "SF");
//    assert(watch_list_for_test.at(0).getYearOfRelease() == 2016);
//    assert(watch_list_for_test.at(0).getNumberOfLikes() == 20000);
//    assert(watch_list_for_test.at(0).getTrailer() == "https://www.youtube.com/watch?v=3cxixDgHUYw");
//    assert(watch_list_for_test.size() == 1);
//
//    _CrtDumpMemoryLeaks();
//
//}
//
//void testServiceDeleteMovie()
//{
//    Repository repository;
//    FileWatchList* watch_list = new CSVWatchList{"movie_watchlist.csv"};
//    Service service{repository, watch_list};
////
//    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    service.addMovieService("League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw");
//    service.addMovieToWatchListService(movie1);
//
//
//
//    service.deleteMovieService("league of justice");
//    service.deleteMovieFromWatchListService("League of justice");
//
//    std::vector<Movie> array_for_test = service.getAllMovies();
//    std::vector<Movie> watch_list_for_test = service.getWatchList();
//
//    assert(array_for_test.empty() == true);
//    assert(watch_list_for_test.empty() == true);
//
//    _CrtDumpMemoryLeaks();
//}
//
//void testServiceUpdateMovie()
//{
//    Repository repository;
//    FileWatchList* watch_list = new CSVWatchList{"movie_watchlist.csv"};
//    Service service{repository, watch_list};
//
////    Movie movie1{"League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw"};
//
//    service.addMovieService("League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw");
//
//    service.updateMovieByNumberOfLikesService("League of Justice", 1);
//    std::vector<Movie> all_movies = service.getAllMovies();
//    assert(all_movies.at(0).getNumberOfLikes() != 20000);
//    assert(all_movies.at(0).getNumberOfLikes() == 1);
//
//    service.updateMovieByGenreService("League of Justice", "horror");
//    std::vector<Movie> all_movies1 = service.getAllMovies();
//    assert(all_movies1.at(0).getGenre() != "SF");
//    assert(all_movies1.at(0).getGenre() == "horror");
//
//
//    service.updateMovieByYearOfReleaseService("League of Justice", 2000);
//    std::vector<Movie> all_movies2 = service.getAllMovies();
//    assert(all_movies2.at(0).getYearOfRelease() != 2016);
//    assert(all_movies2.at(0).getYearOfRelease() == 2000);
//
//    service.updateMovieByTrailerService("League of Justice", "other trailer");
//    std::vector<Movie> all_movies3 = service.getAllMovies();
//    assert(all_movies3.at(0).getTrailer() != "https://www.youtube.com/watch?v=3cxixDgHUYw");
//    assert(all_movies3.at(0).getTrailer() == "other trailer");
//
//    _CrtDumpMemoryLeaks();
//}
//
//void testServiceGiveLikeToMovie()
//{
//    Repository repository;
//    FileWatchList* watch_list = new CSVWatchList{"movie_watchlist.csv"};
//    Service service{repository, watch_list};
//
//    service.addMovieService("League of Justice", "SF", 2016, 20000, "https://www.youtube.com/watch?v=3cxixDgHUYw");
//    service.giveLikeToMovieService("League of Justice");
//    std::vector<Movie> all_movies =  service.getAllMovies();
//    assert(all_movies.at(0).getNumberOfLikes() == 20001);
//
//    _CrtDumpMemoryLeaks();
//}
//
