#ifndef FILEPARSER_STATISTICCREATOR_H
#define FILEPARSER_STATISTICCREATOR_H
#include <mutex>

//#include <boost/asio.hpp>
//#include <boost/thread.hpp>

#include "TextParser.h"
#include "../DataReading/FilesSearcher.h"
#include <mutex>

class StatisticCreator
{
private:
    std::vector<std::string> filesPaths;
    unsigned int fileCounter = 0;
    LinesCounter counter;
    std::mutex dataMutex;

public:
    StatisticCreator(FilesSearcher &files);
    void setFileCounts(FilesSearcher &fileSearcher);
    void countLines(int begin, int end);
    LinesCounter& analyzeData();
};


#endif //FILEPARSER_STATISTICCREATOR_H
