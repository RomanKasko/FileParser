#include "StatisticCreator.h"

StatisticCreator::StatisticCreator(FilesSearcher &files)
{
    filesPaths = files.getFilesPaths();
    fileCounter = files.getFilesCount();
}

void StatisticCreator::setFileCounts(FilesSearcher &filesSearcher)
{
    fileCounter = filesSearcher.getFilesCount();
}

LinesCounter& StatisticCreator::analyzeData()
{
    auto numOfConcurrency = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    unsigned int oneThreadWork,extraWorks;
    int count = 0;
    bool extraWork = 0;

    if(fileCounter < numOfConcurrency)
    {
        numOfConcurrency = fileCounter;
    }

    oneThreadWork = fileCounter / numOfConcurrency;
    extraWorks = fileCounter % numOfConcurrency;
    unsigned int beginIndex = 0;

    for(int i = 0; i < numOfConcurrency; ++i)
    {
        if(count < extraWorks)
        {
            extraWork = 1;
        }
        else
        {
            extraWork = 0;
        }
        threads.emplace_back(&StatisticCreator::countLines, std::ref(*this), beginIndex, beginIndex + oneThreadWork + extraWork);
        beginIndex += oneThreadWork + extraWork;
        ++count;
    }

    for(auto &th : threads)
    {
        if(th.joinable())
        {
            th.join();
        }
    }

    return counter;
}

void StatisticCreator::countLines(int begin, int end)
{
    TextParser parser;
    LinesCounter lines;
    for(; begin < end && begin < fileCounter; ++begin)
    {
        std::lock_guard<std::mutex> lock(dataMutex);
        parser.parseFile(filesPaths[begin]);
        lines = parser.getResult();
        counter += lines;
    }
}
