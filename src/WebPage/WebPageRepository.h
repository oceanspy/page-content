#ifndef TXTSERVICE_H
#define TXTSERVICE_H

#include "../IOService/IOService.h"

#include <string>
#include <vector>
#include <filesystem>
#include <optional>
#include <deque>
#include <fstream>

class WebPageRepository {
public:
    explicit WebPageRepository(IOService& ioService, std::filesystem::path& directoryPath);
    void load(const std::string& fileName);
    bool isFileWritable(const std::string& fileName);
    std::vector <std::string> read(const std::string& fileName, std::optional<int> limitOpt);
    void create(const std::string& fileName, std::vector <std::string>& data); 
    void append(const std::string& fileName, std::vector <std::string> data);
    void empty(const std::string& fileName);
    [[nodiscard]] std::filesystem::path getFilePath(const std::string& fileName);
private:
    IOService& ioService;
    std::filesystem::path directoryPath;
    std::filesystem::path filePath;
};



#endif //TXTSERVICE_H
