#include "WebPageTagEntity.h"


WebPageTagEntity::WebPageTagEntity()
{
}

void WebPageTagEntity::setTag(const std::string& tag)
{
    this->tag = tag;
}

void WebPageTagEntity::setValue(const std::string& value)
{
    this->value = value;
}

void WebPageTagEntity::addAttribute(const std::string& name, const std::string& value)
{
    attributes.push_back({name, value});
}

const std::string& WebPageTagEntity::getTag()
{
    return tag;
}

const std::string& WebPageTagEntity::getValue()
{
    return value;
}

bool WebPageTagEntity::hasAttribute(const std::string& name)
{
    return std::ranges::any_of(attributes, [&name](const auto& attribute) {
        return attribute.name == name;
    });
}

const std::string WebPageTagEntity::getAttribute(const std::string& name)
{
    for (const auto& attribute : attributes)
    {
        if (attribute.name == name)
        {
            return attribute.value;
        }
    }
    return "";
}

const std::vector<WebPageTagEntity::Attribute> WebPageTagEntity::getAttributes()
{
    return attributes;
}