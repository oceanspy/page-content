#include "Tags.h"

Tags::Tags(IOService& ioService, WebPageService& webPageService, WebPageEntity& webPageEntity, std::vector <std::string>& tagsToParse)
    : ActionAbstract(ioService), ioService(ioService), webPageService(webPageService), webPageEntity(webPageEntity), tagsToParse(tagsToParse)
{
}

void Tags::execute()
{
    // Parse the content of the page
    std::string tagsRendered = parseContent();

    // Print the result
    printWebPageInfo(webPageEntity);

    ioService.print("All links found in the page:");
    ioService.printFullLineOfString("─", BashStyle::getBashCode("GRAY"));
    ioService.print(tagsRendered);
    ioService.printFullLineOfString("─", BashStyle::getBashCode("GRAY"));
    ioService.br();
}

std::string Tags::parseContent()
{
    std::string tagsStr;
    std::vector <WebPageTagEntity> webPageTagEntities;

    for (const std::string& tag : tagsToParse)
    {
        webPageService.parseTag(*webPageEntity.getBody(), tag, webPageTagEntities);
    }

    for (WebPageTagEntity& webPageTagEntity : webPageTagEntities) {
        tagsStr += StringHelpers::colorize(*webPageTagEntity.getTag(), YELLOW) + " > ";
        if (!(*webPageTagEntity.getTxtInnerValue()).empty())
        {
            tagsStr += StringHelpers::colorize(
                                    StringHelpers::removeLineBreaks(
                                        StringHelpers::removeExtraSpaces(*webPageTagEntity.getTxtInnerValue())
                                        ),
                                    BLUE
                                    );
            tagsStr += ": ";
        } else {
            tagsStr += StringHelpers::removeExtraSpaces(*webPageTagEntity.getRawInnerValue());
            tagsStr += ": ";
        }

        for (auto& [key, value] : *webPageTagEntity.getAttributes())
        {
            tagsStr += "[" + StringHelpers::colorize(key, RED) + "] ";
            tagsStr += value;
        }
        tagsStr += "\n";
    }

    return tagsStr;
}