#include "src/IOService/IOService.h"
#include "src/Help/Help.h"
#include "src/Helpers/StringHelpers.h"
#include "src/Command/Command.h"
#include "src/Command/CommandOption.h"
#include "src/Command/CommandValidation.h"

#include <string>

int main(int argc, const char *argv[])
{
    IOService ioService = IOService();
    Help help = Help(ioService);

    CommandOption commandOption = CommandOption();
    CommandValidation commandValidation(commandOption, argc, argv);
    try {
        commandValidation.make();
    } catch (const std::exception& e) {
        help.commandNotFound();
        return 1;
    }

    // Get command: URL & parameters

    // Create ID for the request
    std::string requestId = StringHelpers::randomAlNumString(12);

    // Fetch the web page

    // Parse the web page

    // Print the result
    ioService.print("Request ID: " + requestId);
    ioService.printWithoutLineBreak("URL: ");
    ioService.print("https://www.oceanspy.com");
}
