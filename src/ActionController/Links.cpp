#include "Links.h"

Links::Links(IOService& ioService, TxtService& txtService, std::string requestId, std::string url)
    : ioService(ioService), txtService(txtService), requestId(requestId), url(url)
{

}

void Links::run()
{
    // Print the result
    ioService.print("Request ID: " + requestId);
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
}
