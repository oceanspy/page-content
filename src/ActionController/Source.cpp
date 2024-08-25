#include "Source.h"

Source::Source(IOService& ioService, TxtService& txtService, std::string requestId, std::string url)
    : ioService(ioService), txtService(txtService), requestId(requestId), url(url)
{

}

void Source::run()
{
    // get the page


    // save the page to a file
    std::filesystem::path fileName = requestId + "_source";

    std::vector <std::string> fileContent = { url, "This is the source of the page" };
    txtService.load(fileName);
    txtService.write(fileContent);


    // Print the result
    ioService.br();
    ioService.print("--------------------");
    ioService.print("Request ID: " + requestId);
    ioService.printWithoutLineBreak("URL: ");
    ioService.print(url);
    ioService.print("--------------------");
    ioService.br();

    // std::vector <std::string> pageContent = txtService.read(std::nullopt);
    // for (std::string line : pageContent)
    // {
    //     ioService.print(line);
    // }

}