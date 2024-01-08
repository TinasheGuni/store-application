#include "shopmemento.h"

ShopMemento::ShopMemento() {}

void ShopMemento::setState(int s) { transaction = s; }

int ShopMemento::getState() const { return transaction; }
