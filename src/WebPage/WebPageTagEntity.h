#ifndef WEBPAGETAGENTITY_H
#define WEBPAGETAGENTITY_H

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ranges>


class WebPageTagEntity {

struct Attribute {
    std::string name;
    std::string value;
};

public:
    WebPageTagEntity();
    void setTag(const std::string& tag);
    void setTxtInnerValue(const std::string& value);
    void setRawInnerValue(const std::string& value);
    void addAttribute(const std::string& name, const std::string& value);
    const std::string * getTag();
    const std::string * getTxtInnerValue();
    const std::string * getRawInnerValue();
    bool hasAttribute(const std::string& name);
    const std::string * getAttribute(const std::string& name);
    const std::vector<Attribute> * getAttributes();
private:
    std::string tag;
    std::string txtInnerValue;
    std::string rawInnerValue;
    std::vector <Attribute> attributes;
};



#endif //WEBPAGETAGENTITY_H
