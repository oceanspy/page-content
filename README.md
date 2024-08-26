# WIP

/!\ This project is a work in progress/POC.

# Application

This project is a simple CLI web scraper that uses the `httplib`/`libcurl` and `gumbo` libraries to get the content of a web page.

It helps to get the source code of a page, debug and see the links and the tags quickly.

*NB: The application doesn't support (for now) JavaScript and dynamic content, but can analyze directly from a local file.*

The project is written in C++ and uses the `CMake` build system.

## Installation
```
// Linux
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install libssl-dev
sudo apt-get install libgumbo-dev

git clone https://github.com/oceanspy/page-content.git
```

## Usage:
```
./page-content help
./page-content source -u <url>
./page-content source -f <file>
./page-content links -u <url>
./page-content links -f <file>
./page-content tags {tag1} {tag2} ... -u <url>
```
