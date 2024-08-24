#include "Help.h"

Help::Help(IOService& ioService)
    : ioService(ioService)
{

}


void Help::show()
{
    ioService.message("Help Center");
    ioService.message("----");
    for (std::string help : helpListForCli())
    {
        ioService.message(help);
    }
}

void Help::commandNotFound()
{
    ioService.error("Command not found");
    ioService.info("Type '-h/--help' for help");
}

void Help::commandOptionNotSupported()
{
    ioService.error("The arguments of the command do not match. Aborting.");
    ioService.info("Type '-h/--help' for help");
}

std::vector<std::string> Help::helpListForCli()
{
    return {
        "\033[96m-h/--help\033[0m                                                       Show the help center",
    };
}

std::string Help::getVersion()
{
    return "development";
}
