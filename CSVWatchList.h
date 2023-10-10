//
// Created by Ratan Luca on 5/5/2023.
//
#pragma once
#ifndef A7_RATANLUCARAZVAN_1_CSVWATCHLIST_H
#define A7_RATANLUCARAZVAN_1_CSVWATCHLIST_H

#endif //A7_RATANLUCARAZVAN_1_CSVWATCHLIST_H
#include <iostream>
#include "FileWatchList.h"

class CSVWatchList : public FileWatchList
{
public:
    CSVWatchList(const std::string& file_name) : FileWatchList(file_name) {};
    ~CSVWatchList() {};
    void writeToFile() override;
    void displayWatchList() override;
};