#include "WebPageService.h"

WebPageService::WebPageService()
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

    // cli.set_follow_location(true);
    httplib::Result res = cli.Get(path);

    std::vector<std::pair<std::string, std::string>> headers;
    for (auto& header : res->headers) {
        headers.emplace_back(header.first, header.second);
    }

    WebPageEntity webPageEntity = WebPageEntity();
    webPageEntity.setFromHttplib(url, host, port, path, res->status, res->body, headers, res->reason, httplib::to_string(res.error()));

    return webPageEntity;
}

std::vector <std::pair<std::string, std::string>> WebPageService::getLinks(std::string content)
{
    std::vector <std::pair<std::string, std::string>> links;
    std::string::size_type pos = 0;
    while ((pos = content.find("href=\"", pos)) != std::string::npos) {
        pos += 6;
        std::string::size_type end = content.find("\"", pos);
        if (end != std::string::npos) {
            std::string link = content.substr(pos, end - pos);
            links.emplace_back(link, "");
            pos = end;
        }
    }
    return links;
}
