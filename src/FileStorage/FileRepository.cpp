#include "FileRepository.h"

FileRepository::FileRepository(IOService& ioService, std::filesystem::path& directoryPath)
    : ioService(ioService), directoryPath(directoryPath)
{
}

void FileRepository::load(const std::string& fileName)
{
    filePath = directoryPath / fileName;

    if (!isFileWritable(filePath))
    {
        throw std::invalid_argument("Error: Unable to load the file: " + filePath.string());
    }
}

bool FileRepository::isFileWritable(const std::string& fileName)
{
    bool fileWritable = false;
    filePath = directoryPath / fileName;
    std::ofstream file(filePath, std::ofstream::out | std::ofstream::app);
    fileWritable = file.is_open();
    file.close();
    return fileWritable;
}


std::vector <std::string> FileRepository::read(const std::string& fileName, std::optional<int> limitOpt)
{
    load(fileName);

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

void FileRepository::create(const std::string& fileName, std::vector <std::string>& data)
{
    load(fileName);

    std::ofstream file(filePath, std::ofstream::out);

    for (const auto& line : data) {
        file << line;
        file << std::endl; // End of row
    }

    file.close();
}

void FileRepository::append(const std::string& fileName, std::vector <std::string> data)
{
    load(fileName);

    std::ofstream file(filePath, std::ios::app);

    for (const auto& line : data) {
        file << line;
        file << std::endl; // End of row
    }

    file.close();
}

void FileRepository::empty(const std::string& fileName)
{
    load(fileName);

    std::ofstream file(filePath, std::ofstream::out);
    file.close();
}

std::filesystem::path FileRepository::getFilePath(const std::string& fileName)
{
    load(fileName);

    return filePath;
}
