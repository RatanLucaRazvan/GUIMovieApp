//
// Created by Ratan Luca on 5/6/2023.
//
#pragma once

#include "FileWatchList.h"

#ifndef A7_RATANLUCARAZVAN_1_HTMLWATCHLIST_H
#define A7_RATANLUCARAZVAN_1_HTMLWATCHLIST_H

#endif //A7_RATANLUCARAZVAN_1_HTMLWATCHLIST_H

class HTMLWatchList : public FileWatchList
{
public:
    HTMLWatchList(const std::string& file_name) : FileWatchList(file_name) {};
    ~HTMLWatchList() {};
    void writeToFile() override;
    void displayWatchList() override;
};
