#ifndef FILEPARSER_STATISTICCREATOR_H
#define FILEPARSER_STATISTICCREATOR_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "TextParser.h"
#include "../DataReading/FilesSearcher.h"

class StatisticCreator
{
private:
    LinesCounter *linesCounter;

public:
    LinesCounter& createStatistic(FilesSearcher &files);
};

#endif //FILEPARSER_STATISTICCREATOR_H