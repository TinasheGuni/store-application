#include "shoplist.h"

ShopList *ShopList::getInstance() {
  if (uniqueInstance == NULL) {
    uniqueInstance = new ShopList();
  }

  return uniqueInstance;
}

void ShopList::deleteInstance() { delete uniqueInstance; }

void ShopList::addStock(Shop *s) {
  const QMetaObject *meta = s->metaObject();
  if (QString(meta->className()) == "Book")
    listB.append(s);
  else if (QString(meta->className()) == "Magazine")
    listM.append(s);
}

QList<Shop *> ShopList::returnList(QString type) const {
  if (type == "Confectionery") {
    return listB;
  }
  if (type == "ReadingMaterial") {
    return listM;
  }
  return QList<Shop *>();
}

ShopList::ShopList() {}

ShopList::~ShopList() {
  qDeleteAll(listB.begin(), listB.end());
  listB.clear();
  qDeleteAll(listM.begin(), listM.end());
  listM.clear();
}

ShopList *ShopList::uniqueInstance = NULL;
