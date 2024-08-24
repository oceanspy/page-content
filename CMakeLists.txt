cmake_minimum_required(VERSION 3.29)
project(page_content)

set(CMAKE_CXX_STANDARD 23)

add_executable(page_content main.cpp
        src/IOService/IOCliService/IOCliService.cpp
        src/IOService/IOCliService/IOCliService.h
        src/IOService/IOService.h
        src/IOService/IOService.cpp
        src/Help/Help.h
        src/Help/Help.cpp
        src/Helpers/StringHelpers.h
        src/Helpers/StringHelpers.cpp
        src/Helpers/DateHelpers.h
        src/Helpers/DateHelpers.cpp
        src/Helpers/BashStyle.h
        src/Helpers/BashStyle.cpp
        src/Command/CommandValidation.cpp
        src/Command/CommandValidation.h
        src/Command/Command.cpp
        src/Command/Command.h
        src/Command/CommandOption.cpp
        src/Command/CommandOption.h

)
