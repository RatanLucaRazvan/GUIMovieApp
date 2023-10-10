//
// Created by Ratan Luca on 5/5/2023.
//
#include "CSVWatchList.h"
#include <fstream>
//#include <winuser.h>
#include <windows.h>
//#include <shellapi.h>

void CSVWatchList::writeToFile() {
    std::ofstream file(this->file_name);
    for(auto movie : this->list_of_movies)
    {
        file << movie<<"\n";
    }
    file.close();
}

void CSVWatchList::displayWatchList() {
//    ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", this->file_name.c_str(), NULL, SW_SHOWMAXIMIZED);
    ShellExecuteA(nullptr, nullptr,"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", this->file_name.c_str(), nullptr, SW_SHOWNORMAL);
}
