#ifndef SHOPLIST_H
#define SHOPLIST_H

#include <QList>

#include "book.h"
#include "magazine.h"

class ShopList {
public:
  static ShopList *getInstance();
  static void deleteInstance();

  void addStock(Shop *s);

  QList<Shop *> returnList(QString type) const;

private:
  ShopList();
  ~ShopList();

  static ShopList *uniqueInstance;

  QList<Shop *> listB;
  QList<Shop *> listM;
};

#endif // SHOPLIST_H
