#ifndef TXTSERVICE_H
#define TXTSERVICE_H

#include "FileDataServiceInterface.h"
#include "../IOService/IOService.h"

#include <string>
#include <vector>
#include <filesystem>
#include <optional>
#include <deque>
#include <fstream>

class TxtService : public FileDataServiceInterface {
public:
    explicit TxtService(IOService& ioService, std::filesystem::path& directoryPath);
    void load(std::filesystem::path fileName) override;
    bool isFileWritable(std::filesystem::path fileName) override;
    std::vector <std::string> read(std::optional<int> limitOpt) override;
    void write(std::vector <std::string> data) override;
    void append(std::vector <std::string> data) override;
    void empty() override;
private:
    IOService& ioService;
    std::filesystem::path directoryPath;
    std::filesystem::path filePath;
    std::filesystem::path fileName;
    bool fileWritable = false;
};



#endif //TXTSERVICE_H
