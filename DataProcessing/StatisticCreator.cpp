#include "StatisticCreator.h"

StatisticCreator::StatisticCreator(FilesSearcher &files)
{
    filesPaths = files.getFilesPaths();
}

LinesCounter& StatisticCreator::createStatistic()
{
    TextParser parser;

    boost::asio::thread_pool pool(std::thread::hardware_concurrency());
    for(auto& path : filesPaths)
    {
        boost::asio::post(pool,[ObjectPtr = &parser, &path]{ ObjectPtr->parseFile(path); });
    }
    pool.wait();

    linesCounter = parser.getResult();
    return linesCounter;
}