#include "StatisticLogger.h"

void TextFileStatisticLogger::writeStatistic(const Statistic &stat)
{
    std::ofstream outData;
    outData.open("result.txt", std::ios::app);

    if(!outData)
    {
        std::cerr << "Error: result.txt could not be opened" << std::endl;
        return;
    }

    outData << "------------Root directory: " << stat.rootDirectory << " statistic-----------" << std::endl;
    outData << " Files analyzed:  " << stat.filesCount << std::endl
            << " Spent time(sec): " << stat.analysisTime.count() << std::endl
            << " Blank lines:     " << stat.counter.blankLinesCounter << std::endl
            << " Code lines:      " << stat.counter.codeLinesCounter << std::endl
            << " Comment lines:   " << stat.counter.commentsCounter << std::endl
            << " All lines:       " << stat.counter.allLines << std::endl;

    outData.close();
}

void TextFileStatisticLogger::printStatistic(const Statistic &stat)
{
    std::cout << "------------Root directory: " << stat.rootDirectory << " statistic-----------" << std::endl;
    std::cout << " Files analyzed:  " << stat.filesCount << std::endl
              << " Spent time(sec): " << stat.analysisTime.count() << std::endl
              << " Blank lines:     " << stat.counter.blankLinesCounter << std::endl
              << " Code lines:      " << stat.counter.codeLinesCounter << std::endl
              << " Comment lines:   " << stat.counter.commentsCounter << std::endl
              << " All lines:       " << stat.counter.allLines << std::endl;
}