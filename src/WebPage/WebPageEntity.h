#ifndef WEBPAGEENTITY_H
#define WEBPAGEENTITY_H

#include <string>
#include <vector>
#include <filesystem>

class WebPageEntity {
public:
    explicit WebPageEntity();
    void setFromHttplib(const std::string& url,
                        const std::string& host,
                        const int& port,
                        const std::string& path,
                        const int& status,
                        const std::string& content,
                        const std::vector<std::pair<std::string, std::string>>& headers,
                        const std::string& reason,
                        const std::string& errorMessage
                        );
    void setUrl(const std::string& url);
    void setLocalStorageWebPagePath(const std::filesystem::path& localStorageWebPagePath);
    void setHost(const std::string& host);
    void setPort(const int& port);
    void setPath(const std::string& path);
    void setStatus(const int& status);
    void setBody(const std::string& body);
    void setHeaders(const std::vector<std::pair<std::string, std::string>>& headers);
    void setReason(const std::string& reason);
    void setErrorMessage(const std::string& errorMessage);

    const std::string getUrl();
    const std::filesystem::path getLocalStorageWebPagePath();
    const std::string getHost();
    const int getPort();
    const std::string getPath();
    const int getStatus();
    const std::string getBody();
    const std::vector<std::pair<std::string, std::string>> getHeaders();
    const std::string getReason();
    const std::string getErrorMessage();
private:
    std::string url;
    std::filesystem::path localStorageWebPagePath;
    std::string host;
    int port = 0;
    std::string path;
    std::string body;
    std::vector<std::pair<std::string, std::string>> headers;
    int status = 0;
    std::string reason;
    std::string errorMessage;
};



#endif //WEBPAGEENTITY_H
