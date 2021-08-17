#ifndef FILEPARSER_TEXTPARSER_H
#define FILEPARSER_TEXTPARSER_H
#include <regex>
#include <fstream>
#include <iostream>
#include <vector>

#include "../LinesCounter.h"
class TextParser
{
private:
    LinesCounter counter;

public:
    void parseFile(const std::string &path);
    LinesCounter getResult();
};

#endif
