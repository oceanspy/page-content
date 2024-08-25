#ifndef WEBPAGESERVICE_H
#define WEBPAGESERVICE_H

#include "../IOService/IOService.h"
#include "../FileStorage/TxtService.h"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#include <iostream>

#include <string>

class WebPageService {
public:
    WebPageService(IOService& ioService, TxtService& txtService);
    void load(std::string url);
private:
    IOService& ioService;
    TxtService& txtService;
};



#endif //WEBPAGESERVICE_H
