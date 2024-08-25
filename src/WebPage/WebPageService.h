#ifndef WEBPAGESERVICE_H
#define WEBPAGESERVICE_H

#include "../IOService/IOService.h"
#include "../FileStorage/TxtService.h"
#include "WebPageEntity.h"
#include "../Helpers/StringHelpers.h"

#ifndef CPPHTTPLIB_OPENSSL_SUPPORT
#define CPPHTTPLIB_OPENSSL_SUPPORT
#endif
#include <httplib.h>

#include <string>

class WebPageService {
public:
    WebPageService();
    static WebPageEntity load(std::string url);
    static std::vector <std::pair<std::string, std::string>> getLinks(std::string content);
};



#endif //WEBPAGESERVICE_H
