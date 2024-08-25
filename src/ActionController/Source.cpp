#include "Source.h"

Source::Source(IOService& ioService, TxtService& txtService, WebPageService& webPageService, std::string requestId, std::string url)
    : ioService(ioService), txtService(txtService), webPageService(webPageService), requestId(requestId), url(url)
{

}

void Source::execute()
{
    // get the page
    WebPageEntity webPageEntity = webPageService.load(url);

    // save the page to a file
    std::filesystem::path fileName = requestId + "_source";

    std::vector <std::string> fileContent = { webPageEntity.getBody() };
    txtService.load(fileName);
    txtService.write(fileContent);


    // Print the result
    ioService.br();
    ioService.print("════════════════════════════════════════════════════");
    ioService.print("Page stored in : " + txtService.getFilePath().string());
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
    ioService.print("════════════════════════════════════════════════════");
    ioService.br();

    ioService.print(webPageEntity.getBody());

    // std::vector <std::string> pageContent = txtService.read(std::nullopt);
    // for (std::string line : pageContent)
    // {
    //     ioService.print(line);
    // }

}