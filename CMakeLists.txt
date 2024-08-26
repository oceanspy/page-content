cmake_minimum_required(VERSION 3.29)
project(page_content)

include(FetchContent)
FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.16.3  # Use the appropriate version tag or branch
)
FetchContent_MakeAvailable(httplib)

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
        src/ActionController/ActionAbstract.h
        src/ActionController/ActionAbstract.cpp
        src/ActionController/Source.h
        src/ActionController/Source.cpp
        src/ActionController/Links.h
        src/ActionController/Links.cpp
        src/ActionController/Links.h
        src/FileStorage/TxtService.h
        src/FileStorage/TxtService.cpp
        src/WebPage/GumboService.h
        src/WebPage/GumboService.cpp
        src/WebPage/WebPageService.h
        src/WebPage/WebPageService.cpp
        src/WebPage/WebPageEntity.h
        src/WebPage/WebPageEntity.cpp
        src/WebPage/WebPageTagEntity.h
        src/WebPage/WebPageTagEntity.cpp
        src/ActionController/Tags.h
        src/ActionController/Tags.cpp
)

# Link the cpp-httplib library
target_link_libraries(page_content httplib::httplib)

find_package(OpenSSL REQUIRED)
target_link_libraries(page_content OpenSSL::SSL OpenSSL::Crypto)

# Link the Gumbo library
target_link_libraries(page_content gumbo)


