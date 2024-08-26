#ifndef GUMBOSERVICE_H
#define GUMBOSERVICE_H

#include <string>
#include <stdexcept>
#include <vector>
#include <gumbo.h>
#include "../WebPage/WebPageTagEntity.h"

class GumboService {
public:
  void parseTag(const std::string& content, const std::string& lookupTag, std::vector<WebPageTagEntity>& webPageTagEntities);

  void parseNode(GumboNode* node, const std::string& lookupTag, std::vector<WebPageTagEntity>& webPageTagEntities);
  std::string getInnerHTML(GumboNode* node);
};



#endif //GUMBOSERVICE_H
