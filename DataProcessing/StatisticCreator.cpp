#include "StatisticCreator.h"

LinesCounter& StatisticCreator::createStatistic(FilesSearcher &files)
{
    TextParser parser;
    std::vector<std::string> filesPaths = files.getFilesPaths();

    boost::asio::thread_pool pool(std::thread::hardware_concurrency()); // pool with supported threads by implementation
    for(auto& path : filesPaths)
    {
        boost::asio::post(pool,[ObjectPtr = &parser, &path]{ ObjectPtr->parseFile(path); });
    }
    pool.join();

    linesCounter = &parser.getResult();
    return *linesCounter;
}