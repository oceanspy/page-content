#include "Get.h"

Get::Get(IOService& ioService, std::string requestId, std::string url)
    : ioService(ioService), requestId(requestId), url(url)
{

}

void Get::run()
{
    // Print the result
    ioService.print("Request ID: " + requestId);
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
}