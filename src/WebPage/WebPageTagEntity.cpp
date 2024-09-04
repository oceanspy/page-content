#include "WebPageTagEntity.h"


WebPageTagEntity::WebPageTagEntity()
{
}

void WebPageTagEntity::setTag(const std::string& tag)
{
    this->tag = tag;
}

void WebPageTagEntity::setTxtInnerValue(const std::string& value)
{
    this->txtInnerValue = value;
}

void WebPageTagEntity::setRawInnerValue(const std::string& value)
{
    this->rawInnerValue = value;
}

void WebPageTagEntity::addAttribute(const std::string& name, const std::string& value)
{
    attributes.push_back({name, value});
}

const std::string * WebPageTagEntity::getTag()
{
    return &tag;
}

const std::string * WebPageTagEntity::getTxtInnerValue()
{
    return &txtInnerValue;
}

const std::string * WebPageTagEntity::getRawInnerValue()
{
    return &rawInnerValue;
}

bool WebPageTagEntity::hasAttribute(const std::string& name)
{
    return std::ranges::any_of(attributes, [&name](const auto& attribute) {
        return attribute.name == name;
    });
}

const std::string * WebPageTagEntity::getAttribute(const std::string& name)
{
    for (const auto& attribute : attributes)
    {
        if (attribute.name == name)
        {
            return &attribute.value;
        }
    }
    return nullptr;
}

const std::vector<WebPageTagEntity::Attribute> * WebPageTagEntity::getAttributes()
{
    return &attributes;
}