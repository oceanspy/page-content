#include "Links.h"

Links::Links(IOService& ioService, std::string requestId, std::string url)
    : ioService(ioService), requestId(requestId), url(url)
{

}

void Links::run()
{
    // Print the result
    ioService.print("Request ID: " + requestId);
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
}
