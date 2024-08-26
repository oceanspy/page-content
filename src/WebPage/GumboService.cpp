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
            std::string innerHtml = "";
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