#ifndef FILEPARSER_STATISTICCREATOR_H
#define FILEPARSER_STATISTICCREATOR_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "TextParser.h"
#include "../DataReading/FilesSearcher.h"

class StatisticCreator
{
private:
    std::vector<std::string> filesPaths;
    LinesCounter linesCounter;

public:
    explicit StatisticCreator(FilesSearcher &files);
    LinesCounter& createStatistic();
};

#endif //FILEPARSER_STATISTICCREATOR_H