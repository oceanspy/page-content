#ifndef GET_H
#define GET_H

#include "ActionInterface.h"
#include "../IOService/IOService.h"

class Get : public ActionInterface {
public:
    Get(IOService& ioService, std::string requestId, std::string url);
    void run() override;
private:
    IOService ioService;
    std::string requestId;
    std::string url;
};



#endif //GET_H
