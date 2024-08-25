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

    WebPageService webPageService(ioService, txtService);

    if (command.getName() == "source")
    {
        std::string url = !command.getArguments().empty()
                        ? command.getArguments().at(0)
                        : "";
        if (!StringHelpers::isUrlValid(url))
        {
            ioService.error("Invalid URL");
            return 1;
        }

        webPageService.load(url);

        Source get = Source(ioService, txtService, requestId, url);
        get.run();

        return 0;
    } else if (command.getName() == "links")
    {
        std::string url = !command.getArguments().empty()
                        ? command.getArguments().at(0)
                        : "";
        if (!StringHelpers::isUrlValid(url))
        {
            ioService.error("Invalid URL");
            return 1;
        }

        Links links = Links(ioService, txtService, requestId, url);
        links.run();

        return 0;
    }

    help.commandNotFound();
    return 1;
}
