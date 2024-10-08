#ifndef WEBPAGESERVICE_H
#define WEBPAGESERVICE_H

#include "../IOService/IOService.h"
#include "WebPageRepository.h"
#include "WebPageEntity.h"
#include "../Helpers/StringHelpers.h"

#ifndef CPPHTTPLIB_OPENSSL_SUPPORT
#define CPPHTTPLIB_OPENSSL_SUPPORT
#endif
#include <httplib.h>

#include <string>

#include "GumboService.h"
#include "WebPageTagEntity.h"

class WebPageService {
public:
    explicit WebPageService(GumboService& gumboService);
    static WebPageEntity loadFromUrl(std::string url, int port = 443);
    static WebPageEntity loadFromFile(const std::filesystem::path& filePath);
    void parseTag(const std::string& content, const std::string& lookupTag, std::vector <WebPageTagEntity>& webPageTagEntities);
    std::string generateHighlightHTML(const std::string& html);
private:
    GumboService& gumboService;
};



#endif //WEBPAGESERVICE_H
