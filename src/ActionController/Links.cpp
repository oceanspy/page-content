#include "Links.h"

Links::Links(IOService& ioService, WebPageService& webPageService, WebPageEntity& webPageEntity)
    : ActionAbstract(ioService), ioService(ioService), webPageService(webPageService), webPageEntity(webPageEntity)
{
}

void Links::execute()
{
    // Parse the content of the page
    std::string links = parseContent();

    // Print the result
    printWebPageInfo(webPageEntity);

    ioService.print("All links found in the page:");
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.print(links);
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.br();
}

std::string Links::parseContent()
{
    std::string linksStr;
    std::vector<std::pair <std::string, std::string>> links = WebPageService::getLinks(webPageEntity.getBody());
    for (const auto& link : links)
    {
        linksStr += link.first + ": " + link.second + "\n";
    }
    return linksStr;
}
