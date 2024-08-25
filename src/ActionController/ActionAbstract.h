#ifndef ACTIONABSTRACT_H
#define ACTIONABSTRACT_H
#include "../IOService/IOService.h"
#include "../Helpers/StringHelpers.h"
#include "../Helpers/BashStyle.h"
#include "../WebPage/WebPageEntity.h"

class ActionAbstract {
public:
    ActionAbstract(IOService& ioService);
    void printWebPageInfo(WebPageEntity& webPageEntity);
private:
    IOService& ioService;
};

#endif //ACTIONABSTRACT_H
