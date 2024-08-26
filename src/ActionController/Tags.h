#ifndef TAGS_H
#define TAGS_H

#include "ActionInterface.h"
#include "ActionAbstract.h"
#include "../IOService/IOService.h"
#include "../WebPage/WebPageEntity.h"
#include "../Helpers/StringHelpers.h"
#include "../Helpers/BashStyle.h"
#include "../WebPage/WebPageService.h"

class Tags : public ActionInterface, public ActionAbstract {
public:
    Tags(IOService& ioService, WebPageService& webPageService, WebPageEntity& webPageEntity, std::vector <std::string> tagsToParse);
    void execute() override;
private:
    IOService& ioService;
    WebPageService& webPageService;
    WebPageEntity& webPageEntity;
    std::vector <std::string> tagsToParse;
    std::string parseContent();
};

#endif //TAGS_H
