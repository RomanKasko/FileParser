#ifndef FILEPARSER_TEXTPARSER_H
#define FILEPARSER_TEXTPARSER_H
#include <regex>
#include <fstream>
#include <iostream>
#include <vector>
#include <mutex>

#include "../LinesCounter.h"
class TextParser
{
private:
    LinesCounter counter;
    std::mutex mtx;

public:
    void parseFile(const std::string &path);
    LinesCounter& getResult();

    void commentCount(const std::string &line, LinesCounter &localCounter, bool &openComment);
    void codeCount(const std::string &line, LinesCounter &localCounter);
    void blankLineCount(const std::string &line, LinesCounter &localCounter, bool &openComment);

    void codeBeforeMultComment(const std::string &line, LinesCounter &localCounter );
    void codeAfterMultComment(const std::string &line, LinesCounter &localCounter);
    void codeBeforeLineComment(const std::string &line, LinesCounter &localCounter);
};

#endif