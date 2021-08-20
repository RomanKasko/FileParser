#include "DataProcessing/StatisticCreator.h"
#include "DataWriting/StatisticLogger.h"
#include <chrono>

int main(int argc, char* argv[])
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    fs::path root{argc >= 2 ? argv[1] : fs::current_path()};

    start = std::chrono::system_clock::now();

    FilesSearcher filesSearcher(root);
    filesSearcher.collectData();

    StatisticCreator creator;
    LinesCounter linesCounter = creator.createStatistic(filesSearcher);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;

    Statistic stat(linesCounter, filesSearcher.getFilesCount(),root, time);

    TextFileStatisticLogger logger;
    logger.writeStatistic(stat);
    logger.printStatistic(stat);

    return 0;
}