#ifndef ABSTRACTSHOPFACTORY_H
#define ABSTRACTSHOPFACTORY_H

#include "shop.h"

class AbstractShopFactory {
public:
  AbstractShopFactory();
  virtual ~AbstractShopFactory();
  virtual Shop *createShop(QString name);
};

#endif // ABSTRACTSHOPFACTORY_H
