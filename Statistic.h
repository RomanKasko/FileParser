#ifndef FILEPARSER_STATISTIC_H
#define FILEPARSER_STATISTIC_H

#include "LinesCounter.h"
#include <iostream>
#include <chrono>

struct Statistic
{
    LinesCounter counter;
    unsigned int filesCount;
    std::string rootDirectory;
    std::chrono::duration<double> analysisTime;

    Statistic() = default;
    Statistic(LinesCounter &lines, unsigned int files, std::string &root, std::chrono::duration<double> time)
                            :counter(lines),filesCount(files),rootDirectory(root),analysisTime(time) {}
};

#endif //FILEPARSER_STATISTIC_H