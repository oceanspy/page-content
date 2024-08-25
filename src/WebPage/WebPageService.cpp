#include "WebPageService.h"

WebPageService::WebPageService(IOService& ioService, TxtService& txtService)
    : ioService(ioService), txtService(txtService)
{

}

WebPageEntity WebPageService::load(std::string url)
{
    // remove http:// or https://
    int port = 80;
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
    size_t pos = url.find('/');
    if (pos != std::string::npos) {
        host = url.substr(0, pos);
        path = url.substr(pos);
    } else {
        host = url;
        path = "/";
    }

    httplib::SSLClient cli(host, port);

    httplib::Result res = cli.Get(path);

    std::vector<std::pair<std::string, std::string>> headers;
    for (auto& header : res->headers) {
        headers.emplace_back(header.first, header.second);
    }

    WebPageEntity webPageEntity = WebPageEntity();
    webPageEntity.setFromHttplib(url, host, port, path, res->status, res->body, headers, res->reason, httplib::to_string(res.error()));

    return webPageEntity;
}
