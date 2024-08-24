#include "src/IOService/IOService.h"
#include "src/Help/Help.h"
#include "src/Helpers/StringHelpers.h"
#include "src/Command/Command.h"
#include "src/Command/CommandOption.h"
#include "src/Command/CommandValidation.h"
#include "src/Actions/Get.h"
#include "src/Actions/Links.h"

#include <string>

int main(int argc, const char *argv[])
{
    IOService ioService = IOService();
    Help help = Help(ioService);

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
        return 1;
    } else if (command.getName() == "get")
    {
        std::string url = !command.getArguments().empty()
                        ? command.getArguments().at(0)
                        : "";
        if (!StringHelpers::isUrlValid(url))
        {
            ioService.error("Invalid URL");
            return 1;
        }

        Get get = Get(ioService, requestId, url);
        get.run();

        return 1;
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

        Links links = Links(ioService, requestId, url);
        links.run();

        return 1;
    }

    help.commandNotFound();
    return 1;
}
