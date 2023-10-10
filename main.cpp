//
// Created by Ratan Luca on 3/30/2023.
//


#include <iostream>
#include <fstream>
#include <cstring>
#include <crtdbg.h>
#include <QApplication>
#include "test_repository.h"
#include "test_dynamic_vector.h"
#include "test_service.h"
#include "test_wath_list.h"
#include "test_movie.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include "GUI.h"
#include "Qt/appgui.h"
#include "Qt/user_admin.h"


int main(int argc, char* argv[])
{
    /// Tests
//    testRepositoryAdd();
//    testRepositoryDelete();
//    testRepositoryUpdate();
//    testRepositoryGiveLikeToMovie();
//    testServiceAddMovie();
//    testServiceDeleteMovie();
//    testServiceUpdateMovie();
//    testServiceGiveLikeToMovie();
//    testWatchListAddMovie();
//    testWatchListDeleteMovie();
//    testGetters();
//    testSetters();


    Repository repository;
    Movie movie;
    std::ifstream data("movies.txt");
    while(!data.eof())
    {
        data>>movie;
        repository.addMovieRepository(movie);
    }
    data.close();
    Service service{repository};

    QApplication a(argc, argv);

    user_admin user_admin{service};
    user_admin.show();
    return QApplication::exec();
    _CrtDumpMemoryLeaks();

}