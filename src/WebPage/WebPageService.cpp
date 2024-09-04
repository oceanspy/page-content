#include "WebPageService.h"

WebPageService::WebPageService(GumboService& gumboService)
    : gumboService(gumboService)
{

}

WebPageEntity WebPageService::loadFromUrl(std::string url, int port)
{
    // remove http:// or https://
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

WebPageEntity WebPageService::loadFromFile(const std::filesystem::path& filePath)
{
    std::ifstream ifs(filePath);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    WebPageEntity webPageEntity = WebPageEntity();
    webPageEntity.setBody(content);
    webPageEntity.setLocalStorageWebPagePath(filePath);

    return webPageEntity;
}

void WebPageService::parseTag(const std::string& content, const std::string& lookupTag, std::vector <WebPageTagEntity>& webPageTagEntities)
{
    gumboService.parseTag(content, lookupTag, webPageTagEntities);
}

std::string WebPageService::generateHighlightHTML(const std::string& html) {
    GumboOutput* output = gumbo_parse(html.c_str());
    std::string highlighted_html = gumboService.generateHighlightedHTML(output->root);
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    return highlighted_html;
}