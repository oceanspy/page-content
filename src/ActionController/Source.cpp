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
    ioService.print(StringHelpers::colorize("════════════════════════════════════════════════════", YELLOW));
    ioService.print("Page stored at: " + txtService.getFilePath().string());
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
    ioService.printWithoutLineBreak("Host: ");
    ioService.print(webPageEntity.getHost());
    ioService.printWithoutLineBreak("Port: ");
    ioService.print(std::to_string(webPageEntity.getPort()));
    ioService.printWithoutLineBreak("Path: ");
    ioService.print(webPageEntity.getPath());
    ioService.printWithoutLineBreak("Status: ");
    ioService.print(std::to_string(webPageEntity.getStatus()));
    ioService.printWithoutLineBreak("Reason: ");
    ioService.print(webPageEntity.getReason());
    ioService.printWithoutLineBreak("Error: ");
    ioService.print(webPageEntity.getErrorMessage());
    ioService.print(StringHelpers::colorize("════════════════════════════════════════════════════", YELLOW));
    ioService.br();
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.print(webPageEntity.getBody());
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.br();
}