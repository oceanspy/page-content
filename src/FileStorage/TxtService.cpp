#include "TxtService.h"

TxtService::TxtService(IOService& ioService, std::filesystem::path& directoryPath)
    : ioService(ioService), directoryPath(directoryPath)
{
}

void TxtService::load(std::string fileName)
{
    this->fileName = fileName;
    filePath = directoryPath / fileName;

    if (!isFileWritable(filePath))
    {
        throw std::invalid_argument("Error: Unable to load the file: " + filePath.string());
    }
}

bool TxtService::isFileWritable(std::string fileName)
{
    if (!fileWritable)
    {
        filePath = directoryPath / fileName;
        std::ofstream file(filePath, std::ofstream::out | std::ofstream::app);
        fileWritable = file.is_open();
        file.close();
    }
    return fileWritable;
}


std::vector <std::string> TxtService::read(std::optional<int> limitOpt)
{
    int limit = limitOpt.value_or(10000); // Use 10000 as default value
    std::vector<std::string> data;
    // data.reserve(limit); // Reserve space for n elements
    std::ifstream file(filePath);
    std::string line;
    int i = 0;
    while (std::getline(file, line) && i < limit) {
        data.push_back( line );
        i++;
    }
    file.close();
    return data;
}

void TxtService::write(std::vector <std::string> data)
{
    std::ofstream file(filePath, std::ofstream::out);

    for (const auto& line : data) {
        file << line;
        file << std::endl; // End of row
    }

    file.close();
}

void TxtService::append(std::vector <std::string> data)
{
    std::ofstream file(filePath, std::ios::app);

    for (const auto& line : data) {
        file << line;
        file << std::endl; // End of row
    }

    file.close();
}

void TxtService::empty()
{
    std::ofstream file(filePath, std::ofstream::out);
    file.close();
}

std::string TxtService::getFileName() const
{
    return fileName;
}

std::filesystem::path TxtService::getFilePath() const
{
    return filePath;
}
