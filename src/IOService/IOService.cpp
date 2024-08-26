#include "IOService.h"

IOService::IOService(std::string channel)
    : channel(std::move(channel))
{

}

void IOService::print(const std::string& message)
{
    if (channel == "cli")
    {
        IOCliService::print(message);
    }
}

void IOService::message(const std::string& message)
{
    if (channel == "cli")
    {
        IOCliService::print(" " + message);
    }
}

void IOService::printWithoutLineBreak(const std::string& message)
{
    if (channel == "cli")
    {
        IOCliService::printWithoutLineBreak(message);
    }
}

void IOService::success(std::string message)
{
    message = " ✅ " + message;
    if (channel == "cli")
    {
        IOCliService::error(message);
    }
}

void IOService::error(std::string message)
{
    message = " ❌ " + message;
    if (channel == "cli")
    {
        IOCliService::error(message);
    }
}

void IOService::info(std::string message)
{
    message = " ℹ️  " + message;
    if (channel == "cli")
    {
        IOCliService::error(message);
    }
}

void IOService::br()
{
    if (channel == "cli")
    {
        IOCliService::br();
    }
}

void IOService::show(const std::vector <std::string>& messages)
{
    if (channel == "cli")
    {
        for (const std::string& message : messages)
        {
            IOCliService::print(message);
        }
    }
}

std::string IOService::ask(const std::string& message)
{
    if (channel == "cli")
    {
        return IOCliService::ask(" " + message);
    }

    return "";
}

int IOService::getConsoleDisplayWidth() {
    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void IOService::printFullLineOfString(const std::string& str, const std::string& color)
{
    if (channel == "cli")
    {
        std::string renderedStr;
        int width = getConsoleDisplayWidth();
        // convert to wstring
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wStr = converter.from_bytes(str);
        // get the length of the string
        int length = wStr.length();
        // calculate how many times the string should be printed
        int times = width / length;

        for (int i = 0; i < times; i++)
        {
            renderedStr += str;
        }

        if (color.empty())
        {
            IOCliService::print(renderedStr);
            return;
        }

        renderedStr = color + renderedStr + "\033[0m";
        IOCliService::print(renderedStr);
    }
}