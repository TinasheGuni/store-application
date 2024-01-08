#include "shopfactory.h"

ShopFactory::ShopFactory() {}

ShopFactory::~ShopFactory() {}

Shop *ShopFactory::createShop(QString name) {
  if (name == "Book")
    return new Book();
  else if (name == "Magazine")
    return new Magazine();
  return NULL;
}
