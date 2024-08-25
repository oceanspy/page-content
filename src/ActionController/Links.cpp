#include "Links.h"

Links::Links(IOService& ioService, WebPageEntity& webPageEntity)
    : ActionAbstract(ioService), ioService(ioService), webPageEntity(webPageEntity)
{
}

void Links::execute()
{
    // Parse the content of the page


    // Print the result
    printWebPageInfo(webPageEntity);

    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));

    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.br();
}
