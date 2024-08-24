#include <stdexcept>
#include "CommandOption.h"

CommandOption::CommandOption() {
    populateOptions();
}

void CommandOption::populateOptions()
{
    options["l"] = "links";
}

bool CommandOption::isValidOption(const std::string &arg)
{
    // Check if myString is a key
    if (options.find(arg) != options.end()) {
        return true;
    }
    // Check if myString is a value
    for (const auto& pair : options) {
        if (pair.second == arg) {
            return true;
        }
    }

    return false;
}

bool CommandOption::isOptionWithValue(const std::string &arg)
{
    return false;
}

std::string CommandOption::shortToLongOption(const std::string &shortOption)
{
    for (const auto& pair : options) {
        if (pair.first == shortOption) {
            return pair.second;
        }
    }

    return shortOption;
}

std::string CommandOption::getLongOptionName(const std::string &arg) {
    if (isValidOption(arg))
    {
        if (isShortOption(arg))
        {
            return shortToLongOption(arg);
        }
        return arg;
    }

    throw std::invalid_argument("Option " + arg + " is not valid");
}

bool CommandOption::isShortOption(const std::string &arg) {
    if (options.find(arg) != options.end()) {
        return true;
    }

    return false;
}
