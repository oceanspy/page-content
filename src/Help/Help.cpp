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
        "\033[94m-u/--url {url}\033[0m                                             Provide the url to be used",
        "\033[94m-f/--file {path}\033[0m                                           Provide the file to be used",
        "\033[94m-p/--port {int}\033[0m                                            Provide the port to be used to connect",
        "",
        "\033[0msource \033[93m[-u/-f]\033[0m                                             Show the source content of the page",
        "\033[0mlinks \033[93m[-u/-f]\033[0m                                              Show all the links found in page content",
        "\033[0mtags \033[93m{tags} [-u/-f]\033[0m                                        Show all the links found in page content"
    };
}

std::string Help::getVersion()
{
    return "development";
}
