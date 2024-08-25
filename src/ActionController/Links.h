#ifndef LINKS_H
#define LINKS_H

#include "ActionInterface.h"
#include "ActionAbstract.h"
#include "../IOService/IOService.h"
#include "../WebPage/WebPageEntity.h"
#include "../Helpers/StringHelpers.h"
#include "../Helpers/BashStyle.h"
#include "../WebPage/WebPageService.h"

class Links : public ActionInterface, public ActionAbstract {
public:
    Links(IOService& ioService, WebPageService& webPageService, WebPageEntity& webPageEntity);
    void execute() override;
private:
    IOService& ioService;
    WebPageService& webPageService;
    WebPageEntity& webPageEntity;
    std::string parseContent();
};



#endif //LINKS_H
