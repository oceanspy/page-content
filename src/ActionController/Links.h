#ifndef LINKS_H
#define LINKS_H

#include "ActionInterface.h"
#include "../IOService/IOService.h"
#include "../FileStorage/TxtService.h"
#include "../WebPage/WebPageService.h"

class Links : public ActionInterface {
public:
    Links(IOService& ioService, TxtService& txtService, WebPageService& webPageService, std::string requestId, std::string url);
    void execute() override;
private:
    IOService& ioService;
    TxtService& txtService;
    WebPageService& webPageService;
    std::string requestId;
    std::string url;
};



#endif //LINKS_H
