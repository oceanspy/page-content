#include "WebPageService.h"

WebPageService::WebPageService(GumboService& gumboService)
    : gumboService(gumboService)
{

}

WebPageEntity WebPageService::load(std::string url)
{
    // remove http:// or https://
    int port = 443;
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

    if (!res) {
        throw std::runtime_error("Error: " + httplib::to_string(res.error()));
    }

    std::vector<std::pair<std::string, std::string>> headers;
    for (auto& header : res->headers) {
        headers.emplace_back(header.first, header.second);
    }

    WebPageEntity webPageEntity = WebPageEntity();
    webPageEntity.setFromHttplib(url, host, port, path, res->status, res->body, headers, res->reason, httplib::to_string(res.error()));

    return webPageEntity;
}

void WebPageService::parseTag(const std::string& content, const std::string& lookupTag, std::vector <WebPageTagEntity>& webPageTagEntities)
{
    GumboOutput* output = gumbo_parse(content.c_str());
    gumboService.parseNode(output->root, lookupTag, webPageTagEntities);
}