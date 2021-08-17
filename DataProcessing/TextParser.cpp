#include "TextParser.h"

LinesCounter TextParser::getResult()
{
    return counter;
}

void TextParser::parseFile(const std::string &path)
{
    const std::regex lineBlank(R"(\t*\s*)");
    const std::regex lineComment(R"(\/\/)");
    const std::regex multCommentStart(R"(\/\*)");
    const std::regex multCommentEnd(R"(\*\/)");
    const std::regex codeBeforeMultComment(R"((\\w|\\s|[;,.=()])+(\\/\\*)(\\w|\\s|[;,.=()])+)");// code /*
    const std::regex codeAfterMultComment(R"((\\w|\\s|[;,.=()])+(\\*\\/)(\\w|\\s|[;,.=()])+)"); // */ code
    const std::regex codeBeforeLineComment("(\\w|\\s|[(),;.])+\\/\\/(\\w|\\s|[(),;.])*");       // code //

    std::string line;
    bool isOpenComment = false;

    std::fstream file(path);
    if(!file)
    {
        std::cerr<<"Can't create file stream";
        return;
    }

    while(getline(file,line))
    {
        ++counter.allLines;

        if(std::regex_match(line,lineBlank))
        {
            if(isOpenComment)
            {
                ++counter.commentsCounter;
                continue;
            }
            ++counter.blankLinesCounter;
            continue;
        }

        if(isOpenComment)
        {
            if(std::regex_search(line,multCommentEnd))
            {
                if(std::regex_match(line,codeAfterMultComment))
                {
                    ++counter.codeLinesCounter;
                }
                ++counter.commentsCounter;
                isOpenComment = false;
            }
        }
        else
        {
            if(std::regex_match(line,multCommentStart) )
            {
                if(std::regex_match(line,codeBeforeMultComment))
                {
                    ++counter.codeLinesCounter;
                }

                ++counter.commentsCounter;
                isOpenComment = true;

                if(std::regex_search(line,multCommentEnd))
                {
                    if(std::regex_match(line,codeAfterMultComment))
                    {
                        ++counter.codeLinesCounter;
                    }
                    isOpenComment = false;
                }
            }
            else if(std::regex_search(line,lineComment))
            {
                ++counter.commentsCounter;
                if(std::regex_match(line,codeBeforeLineComment))
                {
                    ++counter.codeLinesCounter;
                }
                continue;
            }
            else
            {
                ++counter.codeLinesCounter;
            }
        }
    }
}