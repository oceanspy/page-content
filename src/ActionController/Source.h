#ifndef GET_H
#define GET_H

#include "ActionInterface.h"
#include "../IOService/IOService.h"
#include "../FileStorage/TxtService.h"
#include "../WebPage/WebPageService.h"

class Source : public ActionInterface {
public:
    Source(IOService& ioService, TxtService& txtService, WebPageService& webPageService, std::string requestId, std::string url);
    void execute() override;
private:
    IOService& ioService;
    TxtService& txtService;
    WebPageService& webPageService;
    std::string requestId;
    std::string url;
};



#endif //GET_H
