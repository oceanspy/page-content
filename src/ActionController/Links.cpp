#include "Links.h"

Links::Links(IOService& ioService, WebPageService& webPageService, WebPageEntity& webPageEntity)
    : ActionAbstract(ioService), ioService(ioService), webPageService(webPageService), webPageEntity(webPageEntity)
{
}

void Links::execute()
{
    // Parse the content of the page
    std::string linksRendered = parseContent();

    // Print the result
    printWebPageInfo(webPageEntity);

    ioService.print("All links found in the page:");
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.print(linksRendered);
    ioService.print(StringHelpers::colorize("────────────────────────────────────────────────────", GRAY));
    ioService.br();
}

std::string Links::parseContent()
{
    std::string linksStr;
    std::vector <WebPageTagEntity> webPageTagEntities;

    webPageService.parseTag(webPageEntity.getBody(), "a", webPageTagEntities);
    webPageService.parseTag(webPageEntity.getBody(), "button", webPageTagEntities);
    webPageService.parseTag(webPageEntity.getBody(), "form", webPageTagEntities);

    for (WebPageTagEntity& webPageTagEntity : webPageTagEntities) {
        linksStr += StringHelpers::colorize(webPageTagEntity.getTag(), YELLOW) + " > ";
        linksStr += StringHelpers::colorize(
                        StringHelpers::removeLineBreaks(
                            StringHelpers::removeExtraSpaces(webPageTagEntity.getTxtInnerValue())
                            ),
                        BLUE
                        );
        linksStr += ": ";
        if (webPageTagEntity.hasAttribute("href"))
        {
            linksStr += "[" + StringHelpers::colorize("href", RED) + "] ";
            linksStr += webPageTagEntity.getAttribute("href") + " ";
        }
        if (webPageTagEntity.hasAttribute("src"))
        {
            linksStr += "[" + StringHelpers::colorize("src", RED) + "] ";
            linksStr += webPageTagEntity.getAttribute("src") + " ";
        }
        if (webPageTagEntity.hasAttribute("action"))
        {
            linksStr += "[" + StringHelpers::colorize("action", RED) + "] ";
            linksStr += webPageTagEntity.getAttribute("action") + " ";
        }
        linksStr += "\n";
    }

    return linksStr;
}
