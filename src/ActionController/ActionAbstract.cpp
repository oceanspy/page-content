#include "ActionAbstract.h"

ActionAbstract::ActionAbstract(IOService& ioService)
    : ioService(ioService)
{
}

void ActionAbstract::printWebPageInfo(WebPageEntity& webPageEntity)
{
    ioService.br();
    ioService.printFullLineOfString("═", BashStyle::getBashCode("YELLOW"));
    ioService.print(" Page stored at: " + (*webPageEntity.getLocalStorageWebPagePath()).string());
    ioService.printFullLineOfString("─", BashStyle::getBashCode("YELLOW"));
    if (!(*webPageEntity.getUrl()).empty())
    {
        ioService.printWithoutLineBreak(" URL: ");
        ioService.print(*webPageEntity.getUrl());
    }
    if (!(*webPageEntity.getUrl()).empty())
    {
        ioService.printWithoutLineBreak(" Host: ");
        ioService.print(*webPageEntity.getHost());
    }
    if (*webPageEntity.getPort() != 0)
    {
        ioService.printWithoutLineBreak(" Port: ");
        ioService.print(std::to_string(*webPageEntity.getPort()));
    }
    if (!(*webPageEntity.getPath()).empty())
    {
        ioService.printWithoutLineBreak(" Path: ");
        ioService.print(*webPageEntity.getPath());
    }
    if (*webPageEntity.getStatus() != 0)
    {
        ioService.printWithoutLineBreak(" Status: ");
        ioService.print(std::to_string(*webPageEntity.getStatus()));
    }
    if (!(*webPageEntity.getReason()).empty())
    {
        ioService.printWithoutLineBreak(" Reason: ");
        ioService.print(*webPageEntity.getReason());
    }
    if (!(*webPageEntity.getErrorMessage()).empty())
    {
        ioService.printWithoutLineBreak(" Error: ");
        ioService.print((*webPageEntity.getErrorMessage()));
    }

    ioService.printFullLineOfString("═", BashStyle::getBashCode("YELLOW"));
    ioService.br();
}