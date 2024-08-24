#ifndef LINKS_H
#define LINKS_H

#include "ActionInterface.h"
#include "../IOService/IOService.h"

class Links : public ActionInterface {
public:
    Links(IOService& ioService, std::string requestId, std::string url);
    void run() override;
private:
    IOService ioService;
    std::string requestId;
    std::string url;
};



#endif //LINKS_H
