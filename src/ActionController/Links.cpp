#include "Links.h"

Links::Links(IOService& ioService, TxtService& txtService, WebPageService& webPageService, std::string requestId, std::string url)
    : ioService(ioService), txtService(txtService), webPageService(webPageService), requestId(requestId), url(url)
{

}

void Links::execute()
{
    // Print the result
    ioService.print("Request ID: " + requestId);
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
}
