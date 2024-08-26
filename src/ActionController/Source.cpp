#include "Source.h"

Source::Source(IOService& ioService, WebPageService& webPageService, WebPageEntity& webPageEntity)
    : ActionAbstract(ioService), ioService(ioService), webPageService(webPageService), webPageEntity(webPageEntity)
{
}

void Source::execute()
{
    // Parse the content of the page


    // Print the result
    printWebPageInfo(webPageEntity);

    ioService.print("Source code:");
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.print(webPageService.generateHighlightHTML(webPageEntity.getBody()));
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.br();
}
