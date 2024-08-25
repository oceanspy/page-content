#ifndef FILEDATASERVICEINTERFACE_H
#define FILEDATASERVICEINTERFACE_H

#include <filesystem>
#include <string>
#include <vector>
#include <optional>

class FileDataServiceInterface {
public:
    virtual void load(std::string fileName) = 0;
    virtual bool isFileWritable(std::string fileName) = 0;
    virtual std::vector <std::string> read(std::optional<int> limitOpt) = 0;
    virtual void write(std::vector <std::string> data) = 0;
    virtual void append(std::vector <std::string> data) = 0;
    virtual void empty() = 0;
    virtual ~FileDataServiceInterface() = default; // Virtual destructor to ensure proper cleanup
};

#endif //FILEDATASERVICEINTERFACE_H
