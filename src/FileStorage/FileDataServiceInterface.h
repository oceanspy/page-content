#ifndef FILEDATASERVICEINTERFACE_H
#define FILEDATASERVICEINTERFACE_H

#include <filesystem>
#include <string>
#include <vector>
#include <optional>

class FileDataServiceInterface {
public:
    virtual void load(const std::string& fileName) = 0;
    virtual bool isFileWritable(const std::string& fileName) = 0;
    virtual std::vector <std::string> read(const std::string& fileName, std::optional<int> limitOpt) = 0;
    virtual void create(const std::string& fileName, std::vector <std::string>& data) = 0;
    virtual void append(const std::string& fileName, std::vector <std::string> data) = 0;
    virtual void empty(const std::string& fileName) = 0;
    virtual ~FileDataServiceInterface() = default; // Virtual destructor to ensure proper cleanup
};

#endif //FILEDATASERVICEINTERFACE_H
