#include "Source.h"

Source::Source(IOService& ioService, TxtService& txtService, WebPageService& webPageService, std::string requestId, std::string url)
    : ioService(ioService), txtService(txtService), webPageService(webPageService), requestId(requestId), url(url)
{

}

void Source::execute()
{
    // get the page
    WebPageEntity webPageEntity = webPageService.load(url);
    txtService.load(requestId + "_source");
    txtService.write({webPageEntity.getBody()});


    // Print the result
    ioService.br();
    ioService.print("════════════════════════════════════════════════════");
    ioService.print("Page stored in : " + txtService.getFilePath().string());
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
    ioService.print("════════════════════════════════════════════════════");
    ioService.br();

    ioService.print(webPageEntity.getBody());

}