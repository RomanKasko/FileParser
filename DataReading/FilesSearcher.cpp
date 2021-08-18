#include "FilesSearcher.h"

FilesSearcher::FilesSearcher(const std::filesystem::path &path)
{
    rootFolderPath = path;
}

std::vector<std::string> FilesSearcher::getFilesPaths()
{
    return filesPaths;
}

unsigned int FilesSearcher::getFilesCount()
{
    return fileCounter;
}

void FilesSearcher::collectData()
{
    if(!fs::exists(rootFolderPath) ||
       !fs::is_directory(rootFolderPath))
    {
        throw "Root directory doesn't exists or it's not a directory";
    }

    for(auto& curPath : fs::recursive_directory_iterator(rootFolderPath))
    {
        if(fs::is_regular_file(curPath) && isAllowedExtensions(curPath.path().extension().string()))
        {
            filesPaths.push_back(curPath.path().string());
        }
    }
    fileCounter = filesPaths.size();
}

bool FilesSearcher::isAllowedExtensions(const std::string &ext)
{
    std::vector<std::string> extensions = {".c",".cpp",".h",".hpp"};
    for(auto &it : extensions)
    {
        if(it == ext)
        {
            return true;
        }
    }
    return false;
}

void FilesSearcher::printFoundData()
{
    for(auto i : filesPaths)
    {
        std::cout << i << std::endl;
    }
}