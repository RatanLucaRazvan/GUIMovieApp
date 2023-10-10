//
// Created by Ratan Luca on 5/5/2023.
//
#pragma once

#include "Watchlist.h"

#ifndef A7_RATANLUCARAZVAN_1_FILEWATCHLIST_H
#define A7_RATANLUCARAZVAN_1_FILEWATCHLIST_H

#endif //A7_RATANLUCARAZVAN_1_FILEWATCHLIST_H

class FileWatchList : public WatchList
{
protected:
    std::string file_name;
public:
    FileWatchList(const std::string& file_name)
    {
        this->file_name = file_name;
    }
    virtual ~FileWatchList() {}
    virtual void writeToFile() = 0;
    virtual void displayWatchList() = 0;
};