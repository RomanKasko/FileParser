#include "LinesCounter.h"

void LinesCounter::operator+=(const LinesCounter &counter)
{
    this->codeLinesCounter += counter.codeLinesCounter;
    this->commentsCounter += counter.commentsCounter;
    this->blankLinesCounter += counter.blankLinesCounter;
    this->allLines += counter.allLines;
}