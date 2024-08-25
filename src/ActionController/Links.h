#ifndef LINKS_H
#define LINKS_H

#include "ActionInterface.h"
#include "ActionAbstract.h"
#include "../IOService/IOService.h"
#include "../WebPage/WebPageEntity.h"
#include "../Helpers/StringHelpers.h"
#include "../Helpers/BashStyle.h"

class Links : public ActionInterface, public ActionAbstract {
public:
    Links(IOService& ioService, WebPageEntity& webPageEntity);
    void execute() override;
private:
    IOService& ioService;
    WebPageEntity& webPageEntity;
};



#endif //LINKS_H
