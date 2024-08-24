#include "CommandValidation.h"

#include <cstring>
#include <string>
#include <vector>
#include <stdexcept>

CommandValidation::CommandValidation(CommandOption& commandOption, const int argc, const char* argv[])
    : commandOption(commandOption), argc(argc), argv(argv)
{

}

bool CommandValidation::make()
{
    std::vector <std::string> tmpCommandArguments;
    for (int i = 1; i < argc; ++i) {
        // Removing the line breaks
        std::string arg = argv[i];
        arg.erase(std::remove(arg.begin(), arg.end(), '\n'), arg.end());
        argv[i] = strdup(arg.c_str());

        // Keeping the raw commands
        rawCommand += argv[i];
        if(i != argc - 1) {
            rawCommand += " ";
        }

        tmpCommandArguments.push_back(arg);
    }

    // looping tmpCommandArguments to separate options and arguments
    for (int i = 0; i < tmpCommandArguments.size(); i++)
    {
        std::string tmpArgument = tmpCommandArguments.at(i);

        // if start with dash = option
        if (tmpArgument[0] == '-')
        {
            // if argument contains a space, we treat it as an argument
            if (tmpArgument.find(' ') != std::string::npos)
            {
                this->arguments.push_back(tmpArgument);
                continue;
            }

            std::string option = removeLeadingDash(tmpArgument);

            if (!commandOption.isValidOption(option))
            {
                throw std::invalid_argument("Invalid option: " + option);
            }

            if (!commandOption.isOptionWithValue(option))
            {
                options[commandOption.getLongOptionName(option)] = "";
                continue;
            }

            if (i + 1 >= tmpCommandArguments.size())
            {
                options[commandOption.getLongOptionName(option)] = "";
                break;
            }
            options[commandOption.getLongOptionName(option)] = tmpCommandArguments.at(i + 1);
            i++;
            continue;
        }

        this->arguments.push_back(tmpArgument);
    }

    return true;
}

std::vector <std::string> CommandValidation::getCommandArguments()
{
    return arguments;
}

std::map <std::string, std::string> CommandValidation::getCommandOptions()
{
    return options;
}

std::string CommandValidation::getRawCommand() {
    return rawCommand;
}

std::string CommandValidation::removeLeadingDash(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[0] != '-')
        {
            return str;
        }
        str.erase(0, 1);
    }

    return str;
}
