#ifndef FILEPARSER_STATISTIC_H
#define FILEPARSER_STATISTIC_H

#include "LinesCounter.h"
#include <iostream>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;

struct Statistic
{
    LinesCounter counter;
    unsigned int filesCount = 0;
    fs::path rootDirectory;
    std::chrono::duration<double> analysisTime;

    Statistic(LinesCounter &lines, unsigned int files, fs::path &root, std::chrono::duration<double> time)
                            :counter(lines),filesCount(files),rootDirectory(root),analysisTime(time) {}
};

#endif //FILEPARSER_STATISTIC_H