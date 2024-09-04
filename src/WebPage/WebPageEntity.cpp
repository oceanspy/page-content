#include "WebPageEntity.h"

WebPageEntity::WebPageEntity()
{
}

void WebPageEntity::setFromHttplib(const std::string& url,
                                   const std::string& host,
                                   const int& port,
                                   const std::string& path,
                                   const int& status,
                                   const std::string& content,
                                   const std::vector<std::pair<std::string, std::string>>& headers,
                                   const std::string& reason,
                                   const std::string& errorMessage
) {
    this->url = url;
    this->host = host;
    this->port = port;
    this->path = path;
    this->status = status;
    this->body = content;
    this->headers = headers;
    this->reason = reason;
    this->errorMessage = errorMessage;
}

void WebPageEntity::setUrl(const std::string& url)
{
    this->url = url;
}

void WebPageEntity::setHost(const std::string& host)
{
    this->host = host;
}

void WebPageEntity::setPort(const int& port)
{
    this->port = port;
}

void WebPageEntity::setPath(const std::string& path)
{
    this->path = path;
}

void WebPageEntity::setLocalStorageWebPagePath(const std::filesystem::path& localStorageWebPagePath)
{
    this->localStorageWebPagePath = localStorageWebPagePath;
}

void WebPageEntity::setStatus(const int& status)
{
    this->status = status;
}

void WebPageEntity::setBody(const std::string& body)
{
    this->body = body;
}

void WebPageEntity::setHeaders(const std::vector<std::pair<std::string, std::string>>& headers)
{
    this->headers = headers;
}

void WebPageEntity::setReason(const std::string& reason)
{
    this->reason = reason;
}

void WebPageEntity::setErrorMessage(const std::string& errorMessage)
{
    this->errorMessage = errorMessage;
}

const std::string * WebPageEntity::getUrl()
{
    return &url;
}

const std::string * WebPageEntity::getHost()
{
    return &host;
}

const int * WebPageEntity::getPort()
{
    return &port;
}

const std::string * WebPageEntity::getPath()
{
    return &path;
}

const std::filesystem::path * WebPageEntity::getLocalStorageWebPagePath()
{
    return &localStorageWebPagePath;
}

const int * WebPageEntity::getStatus()
{
    return &status;
}

const std::string * WebPageEntity::getBody()
{
    return &body;
}

const std::vector<std::pair<std::string, std::string>> * WebPageEntity::getHeaders()
{
    return &headers;
}

const std::string * WebPageEntity::getReason()
{
    return &reason;
}

const std::string * WebPageEntity::getErrorMessage()
{
    return &errorMessage;
}




