//
// Created by Ratan Luca on 5/6/2023.
//
#include "HTMLWatchList.h"
#include <fstream>
#include <iostream>
//#include <winuser.h>
//#include <shellapi.h>
#include <windows.h>

void HTMLWatchList::writeToFile() {
    std::ofstream file(this->file_name);
    file<<"<!DOCTYPE html>\n";
    file<<"<html>\n";
    file<<"<head>\n";
    file<<"\t\t<title>WatchList</title>\n";
    file<<"</head>\n";
    file<<"<body>\n";
    file<<"<table border=\"1\">\n";
    file<<"\t\t<tr>\n";
    file<<"\t\t\t\t<td>Title</td>\n";
    file<<"\t\t\t\t<td>Genre</td>\n";
    file<<"\t\t\t\t<td>Year of Release</td>\n";
    file<<"\t\t\t\t<td>Likes</td>\n";
    file<<"\t\t\t\t<td>Trailer link</td>\n";
    file<<"\t\t</tr>\n";
    for(auto movie : this->list_of_movies)
    {
        file<<"\t\t<tr>\n";
        file<<"\t\t\t\t<td>"<<movie.getTitle()<<"</td>\n";
        file<<"\t\t\t\t<td>"<<movie.getGenre()<<"</td>\n";
        file<<"\t\t\t\t<td>"<<movie.getYearOfRelease()<<"</td>\n";
        file<<"\t\t\t\t<td>"<<movie.getNumberOfLikes()<<"</td>\n";
        file<<"\t\t\t\t<td><a href=\""<<movie.getTrailer()<<"\">Link</a></td>\n";
        file<<"\t\t</tr>\n";
    }
    file<<"</table>\n";
    file<<"</body>\n";
    file<<"</html>\n";
    file.close();
}

void HTMLWatchList::displayWatchList() {
//    std::cout<<"Ceau";
//    ShellExecuteA(0, "open", this->file_name.c_str(), "chrome.exe", 0, SW_SHOWMAXIMIZED);
    ShellExecuteA(0, "open", this->file_name.c_str(),R"("C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Microsoft Edge.lnk")", 0, SW_SHOWMAXIMIZED);
}

