#ifndef GET_H
#define GET_H

#include "ActionAbstract.h"
#include "ActionInterface.h"
#include "../IOService/IOService.h"
#include "../WebPage/WebPageEntity.h"
#include "../Helpers/StringHelpers.h"
#include "../Helpers/BashStyle.h"

class Source : public ActionInterface, public ActionAbstract {
public:
    Source(IOService& ioService, WebPageEntity& webPageEntity);
    void execute() override;
private:
    IOService& ioService;
    WebPageEntity& webPageEntity;
};



#endif //GET_H
