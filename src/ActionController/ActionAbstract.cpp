#include "ActionAbstract.h"

ActionAbstract::ActionAbstract(IOService& ioService)
    : ioService(ioService)
{
}

void ActionAbstract::printWebPageInfo(WebPageEntity& webPageEntity)
{
    ioService.br();
    ioService.print(StringHelpers::colorize("════════════════════════════════════════════════════", YELLOW));
    ioService.print("Page stored at: " + webPageEntity.getLocalStorageWebPagePath().string());
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(webPageEntity.getUrl());
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
}