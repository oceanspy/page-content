#include "WebPageService.h"

WebPageService::WebPageService(IOService& ioService, TxtService& txtService)
    : ioService(ioService), txtService(txtService)
{

}

void WebPageService::load(std::string url)
{
    // remove http:// or https://
    int port;
    if (url.find("http://") == 0) {
        url = url.substr(7);
        port = 80;
    } else if (url.find("https://") == 0) {
        url = url.substr(8);
        port = 443;
    }

    // split url into host and path
    std::string host;
    std::string path;
    size_t pos = url.find("/");
    if (pos != std::string::npos) {
        host = url.substr(0, pos);
        path = url.substr(pos);
    } else {
        host = url;
        path = "/";
    }

    httplib::SSLClient cli(host, port);

    if (auto res = cli.Get(path)) {
        if (res->status == 200) {
            ioService.print(res->body);
        } else {
            ioService.error("HTTP error - Web Page status: " + std::to_string(res->status));
        }
    } else {
        auto err = res.error();
        ioService.error("HTTP error: " + httplib::to_string(err));
    }
}
