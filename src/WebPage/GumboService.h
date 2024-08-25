#ifndef GUMBOSERVICE_H
#define GUMBOSERVICE_H

#include <string>
#include <stdexcept>
#include <vector>
#include <gumbo.h>
#include "../WebPage/WebPageTagEntity.h"

class GumboService {
public:
  void parseNode(GumboNode* node, const std::string& lookupTag, std::vector<WebPageTagEntity>& webPageTagEntities);
};



#endif //GUMBOSERVICE_H
