#include "Source.h"

Source::Source(IOService& ioService, WebPageEntity& webPageEntity)
    : ActionAbstract(ioService), ioService(ioService), webPageEntity(webPageEntity)
{
}

void Source::execute()
{
    // Parse the content of the page


    // Print the result
    printWebPageInfo(webPageEntity);

    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.print(webPageEntity.getBody());
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.br();
}
