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
    bool isAllowedExtensions(const std::string &extension);

public:
    explicit FilesSearcher(const std::filesystem::path &path);
    std::vector<std::string> getFilesPaths();
    unsigned int getFilesCount();
    void printFoundData();
    void collectData();
};

#endif