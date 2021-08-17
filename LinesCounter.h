#ifndef FILEPARSER_LINESCOUNTER_H
#define FILEPARSER_LINESCOUNTER_H

struct LinesCounter
{
    unsigned long commentsCounter = 0;
    unsigned long blankLinesCounter = 0;
    unsigned long codeLinesCounter = 0;
    unsigned long allLines = 0;

    void operator+= (const LinesCounter &counter);
};

#endif //FILEPARSER_LINESCOUNTER_H
