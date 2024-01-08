#ifndef SHOPMEMENTO_H
#define SHOPMEMENTO_H

#include <QString>

class ShopMemento {
private:
  ShopMemento();
  void setState(int s);
  int getState() const;

  int transaction;
};

#endif // SHOPMEMENTO_H
