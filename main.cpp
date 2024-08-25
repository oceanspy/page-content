#include "src/IOService/IOService.h"
#include "src/Help/Help.h"
#include "src/Helpers/StringHelpers.h"
#include "src/Command/Command.h"
#include "src/Command/CommandOption.h"
#include "src/Command/CommandValidation.h"
#include "src/ActionController/Source.h"
#include "src/ActionController/Links.h"
#include "src/FileStorage/TxtService.h"
#include "src/WebPage/WebPageService.h"

#include <string>
#include <filesystem>

int main(int argc, const char *argv[])
{
    IOService ioService = IOService();
    Help help = Help(ioService);
    std::filesystem::path systemTempPathDirectory = std::filesystem::temp_directory_path();
    TxtService txtService = TxtService(ioService, systemTempPathDirectory);

    // Get command: URL & parameters
    CommandOption commandOption = CommandOption();
    CommandValidation commandValidation(commandOption, argc, argv);
    try {
        commandValidation.make();
    } catch (const std::exception& e) {
        ioService.br();
        ioService.error(e.what());
        ioService.br();
        help.commandNotFound();
        return 1;
    }
    Command command(commandValidation.getCommandName(),
                    commandValidation.getCommandArguments(),
                    commandValidation.getCommandOptions(),
                    commandValidation.getRawCommand());

    std::string requestId = StringHelpers::randomAlNumString(12);

    if (command.getName() == "help")
    {
        help.show();
        return 0;
    }

    // Loading web page
    GumboService gumboService = GumboService();
    WebPageService webPageService = WebPageService(gumboService);
    std::string url = !command.getArguments().empty()
                    ? command.getArguments().at(0)
                    : "";

    WebPageEntity webPageEntity;
    try
    {
        webPageEntity = WebPageService::load(url);
    }
    catch (const std::exception& e)
    {
        ioService.br();
        ioService.error(e.what());
        return 1;
    }

    txtService.load(requestId + "_source");
    txtService.write({webPageEntity.getBody()});

    // Parse web page and show result
    if (command.getName() == "source")
    {
        Source source = Source(ioService, webPageService, webPageEntity);
        source.execute();

        return 0;
    } else if (command.getName() == "links")
    {
        Links links = Links(ioService, webPageService, webPageEntity);
        links.execute();

        return 0;
    }

    help.commandNotFound();
    return 1;
}
