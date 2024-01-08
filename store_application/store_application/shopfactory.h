#ifndef SHOPFACTORY_H
#define SHOPFACTORY_H

#include "abstractshopfactory.h"
#include "book.h"
#include "magazine.h"

class ShopFactory : public AbstractShopFactory {
public:
  ShopFactory();
  ~ShopFactory();
  Shop *createShop(QString name);
};

#endif // SHOPFACTORY_H
