#ifndef FILEPARSER_STATISTICLOGGER_H
#define FILEPARSER_STATISTICLOGGER_H

#include <fstream>
#include <iostream>
#include "../Statistic.h"

class StatisticLogger
{
public:
    virtual void writeStatistic(const Statistic &stat) = 0;
    virtual void printStatistic(const Statistic &stat) = 0;
};

class TextFileStatisticLogger : StatisticLogger
{
public:
    void writeStatistic(const Statistic &stat) override;
    void printStatistic(const Statistic &stat) override;
};

#endif //FILEPARSER_STATISTICLOGGER_H
