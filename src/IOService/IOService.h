#ifndef IOSERVICE_H
#define IOSERVICE_H

#include <string>
#include <vector>
#include <unistd.h>
#include <sys/ioctl.h>
#include <codecvt>
#include <locale>
#include <utility>

#include "IOCliService/IOCliService.h"

class IOService {
public:
    explicit IOService(std::string channel = "cli");
    void print (const std::string& message);
    void message (const std::string& message);
    void printWithoutLineBreak (const std::string& message);
    void success(std::string message);
    void error(std::string message);
    void info(std::string message);
    void br();
    void show(const std::vector <std::string>& messages);
    std::string ask(const std::string& message);
    static int getConsoleDisplayWidth();
    void printFullLineOfString(const std::string& str, const std::string& color = "");
protected:
    std::string channel;
};



#endif //IOSERVICE_H
