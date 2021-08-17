#ifndef FILEPARSER_FILESSEARCHER_H
#define FILEPARSER_FILESSEARCHER_H

#include <filesystem>
#include <iostream>
#include <vector>
#include <regex>

namespace fs = std::filesystem;

class FilesSearcher
{
private:
    fs::path rootFolderPath;
    std::vector<std::string> filesPaths;
    unsigned int fileCounter = 0;
    std::regex extensions {".*\\.[hc](pp)?"}; // .h .c .cpp .hpp

public:
    explicit FilesSearcher(const std::filesystem::path &path);
    std::vector<std::string> getFilesPaths();
    unsigned int getFilesCount();
    void printFoundData();
    void collectData();
};

#endif