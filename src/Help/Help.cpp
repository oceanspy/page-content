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
    ioService.br();
    ioService.error("Command not found");
    ioService.info("Type 'page-content help' for help");
}

void Help::commandOptionNotSupported()
{
    ioService.br();
    ioService.error("The arguments of the command do not match. Aborting.");
    ioService.info("Type 'page-content help' for help");
}

std::vector<std::string> Help::helpListForCli()
{
    return {
        "\033[96mhelp\033[0m                                                       Show the help center",
        "",
        "\033[0mget \033[93m{url}\033[0m                                                      Show the content of the url",
        "\033[0mlinks \033[93m{url}\033[0m                                                      Show all the links found in the content of the url"
    };
}

std::string Help::getVersion()
{
    return "development";
}
