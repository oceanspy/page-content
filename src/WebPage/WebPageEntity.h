#ifndef WEBPAGEENTITY_H
#define WEBPAGEENTITY_H

#include <string>
#include <vector>

class WebPageEntity {
public:
    explicit WebPageEntity();
    void setFromHttplib(const std::string& url,
                        const int status,
                        const std::string& content,
                        const std::vector<std::pair<std::string, std::string>>& headers,
                        const std::string& reason,
                        const std::string& errorMessage
                        );
    void setUrl(const std::string& url);
    void setStatus(const int& status);
    void setBody(const std::string& body);
    void setHeaders(const std::vector<std::pair<std::string, std::string>>& headers);
    void setReason(const std::string& reason);
    void setErrorMessage(const std::string& errorMessage);

    const std::string getUrl();
    const int getStatus();
    const std::string getBody();
    const std::vector<std::pair<std::string, std::string>> getHeaders();
    const std::string getReason();
    const std::string getErrorMessage();
private:
    std::string url;
    std::string body;
    std::vector<std::pair<std::string, std::string>> headers;
    int status;
    std::string reason;
    std::string errorMessage;
};



#endif //WEBPAGEENTITY_H
