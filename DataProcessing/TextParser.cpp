#include "TextParser.h"

LinesCounter& TextParser::getResult()
{
    return counter;
}

void TextParser::parseFile(const std::string &path)
{
    LinesCounter localCounter;
    std::string line;
    bool isOpenComment = false;

    std::ifstream file(path);
    if(!file)
    {
        std::cerr<<"Can't create file stream";
        return;
    }

    while(getline(file,line))
    {
        blankLineCount(line,localCounter,isOpenComment);
        commentCount(line,localCounter,isOpenComment);
        codeCount(line,localCounter);
        ++localCounter.allLines;
    }

    file.close();
    std::lock_guard<std::mutex> lock(mtx);
    counter += localCounter;
}

void TextParser::commentCount(const std::string &line, LinesCounter &localCounter, bool &openComment)
{
    if(openComment)
    {
        if(line.find("*/") != std::string::npos)
        {
            codeAfterMultComment(line,localCounter);
            openComment = false;
        }
        ++localCounter.commentsCounter;
    }
    else
    {
        if(line.find("//") != std::string::npos)
        {
            codeBeforeLineComment(line,localCounter);
            ++localCounter.commentsCounter;
        }
        else if(line.find("/*") != std::string::npos)
        {
            codeBeforeMultComment(line,localCounter);
            openComment = true;
            ++localCounter.commentsCounter;
        }
    }
}

void TextParser::codeCount(const std::string &line, LinesCounter &localCounter)
{
    if(line.find("//") == std::string::npos &&
       line.find("/*") == std::string::npos &&
       line.find("*/") == std::string::npos &&
       !line.empty())
    {
        ++localCounter.codeLinesCounter;
    }
}

void TextParser::blankLineCount(const std::string &line, LinesCounter &localCounter, bool &openComment)
{
    if(!openComment && (line.empty() || line.find_first_not_of(' ') == std::string::npos))
    {
        ++localCounter.blankLinesCounter;
    }
}

void TextParser::codeBeforeMultComment(const std::string &line,LinesCounter &localCounter)
{
    const std::regex codeBeforeMultComment(R"(((\w|\s|[;,.=()<>]|\]|\[)+(\/\*)(\w|\s|[;,.=()<>]|\]|\[)*))"); /// code /*
    if(std::regex_match(line,codeBeforeMultComment))
    {
        ++localCounter.codeLinesCounter;
    }
}

void TextParser::codeAfterMultComment(const std::string &line,LinesCounter &localCounter)
{
    const std::regex codeAfterMultComment(R"(((\w|\s|[;,.=()<>]|\]|\[)*(\*\/)(\w|\s|[;,.=()<>]|\]|\[)+))"); /// */ code
    if(std::regex_match(line,codeAfterMultComment))
    {
        ++localCounter.codeLinesCounter;
    }
}

void TextParser::codeBeforeLineComment(const std::string &line,LinesCounter &localCounter)
{
    const std::regex codeBeforeLineComment(R"((\w|\s|[(),;.])+\/\/(\w|\s|[(),;.])*)"); /// code //
    if(std::regex_match(line,codeBeforeLineComment))
    {
        ++localCounter.codeLinesCounter;
    }
}