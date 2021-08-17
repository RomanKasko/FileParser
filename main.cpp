#include "DataProcessing/StatisticCreator.h"
#include "DataWriting/StatisticLogger.h"
#include <chrono>

#include <iostream>

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::string root = "D:\\SoftServe\\FileParser";

    FilesSearcher filesSearcher(root);
    filesSearcher.collectData();
    filesSearcher.printFoundData();

    StatisticCreator creator(filesSearcher);

    start = std::chrono::system_clock::now();

    LinesCounter linesCounter = creator.analyzeData();

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;

    Statistic stat(linesCounter, filesSearcher.getFilesCount(),root, time);

    TextFileStatisticLogger logger;
    logger.writeStatistic(stat);
    logger.printStatistic(stat);

    return 0;
}