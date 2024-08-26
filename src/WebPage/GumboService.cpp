#include "GumboService.h"

void GumboService::parseTag(const std::string& content, const std::string& lookupTag, std::vector<WebPageTagEntity>& webPageTagEntities) {
    GumboOutput* output = gumbo_parse(content.c_str());
    parseNode(output->root, lookupTag, webPageTagEntities);
}

// Recursive function to parse the document and extract link information
void GumboService::parseNode(GumboNode* node, const std::string& lookupTag, std::vector <WebPageTagEntity>& webPageTagEntities) {
    if (node->type == GUMBO_NODE_ELEMENT)
    {
        GumboElement* element = &node->v.element;
        std::string tag = gumbo_normalized_tagname(element->tag);

        if (tag == lookupTag) {
            WebPageTagEntity webPageTagEntity;
            webPageTagEntity.setTag(tag);
            // get the text value of the element
            if (element->children.length > 0) {
                GumboNode* textNode = static_cast<GumboNode*>(element->children.data[0]);
                if (textNode->type == GUMBO_NODE_TEXT) {
                    webPageTagEntity.setTxtInnerValue(textNode->v.text.text);
                }
            }

            // Get the raw value inside the tag
            std::string innerHtml = getInnerHTML(node);
            webPageTagEntity.setRawInnerValue(innerHtml);

            // Iterate over all attributes of the element
            GumboVector* attributes = &element->attributes;
            for (unsigned int i = 0; i < attributes->length; ++i) {
                GumboAttribute* attribute = static_cast<GumboAttribute*>(attributes->data[i]);
                webPageTagEntity.addAttribute(attribute->name, attribute->value);
            }

            // Add the entity to the list
            webPageTagEntities.push_back(webPageTagEntity);
        }

        // Recursively parse child nodes
        GumboVector* children = &element->children;
        for (unsigned int i = 0; i < children->length; ++i) {
            parseNode(static_cast<GumboNode*>(children->data[i]), lookupTag, webPageTagEntities);
        }
        return;
    }

    if (node->type == GUMBO_NODE_DOCUMENT) {
        // Recursively parse child nodes
        GumboVector* children = &node->v.document.children;
        for (unsigned int i = 0; i < children->length; ++i) {
            parseNode(static_cast<GumboNode*>(children->data[i]), lookupTag, webPageTagEntities);
        }
        return;
    }
}

std::string GumboService::getInnerHTML(GumboNode* node) {
    if (!node || node->type != GUMBO_NODE_ELEMENT) {
        return "";
    }

    std::string innerHtml;
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        GumboNode* child = static_cast<GumboNode*>(children->data[i]);
        if (child->type == GUMBO_NODE_TEXT) {
            innerHtml += child->v.text.text;
        } else if (child->type == GUMBO_NODE_ELEMENT) {
            const char* tagName = gumbo_normalized_tagname(child->v.element.tag);
            innerHtml += "<" + std::string(tagName);

            // Append attributes
            GumboVector* attributes = &child->v.element.attributes;
            for (unsigned int j = 0; j < attributes->length; ++j) {
                GumboAttribute* attribute = static_cast<GumboAttribute*>(attributes->data[j]);
                innerHtml += " " + std::string(attribute->name) + "=\"" + attribute->value + "\"";
            }

            innerHtml += ">";

            // Recursively get the inner HTML of the child
            innerHtml += getInnerHTML(child);

            // Close the tag
            innerHtml += "</" + std::string(tagName) + ">";
        } else if (child->type == GUMBO_NODE_WHITESPACE) {
            innerHtml += child->v.text.text;
        }
    }

    return innerHtml;
}