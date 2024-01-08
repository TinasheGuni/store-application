#include "shop.h"

Shop::Shop() {}

Shop::~Shop() {}

Shop::Shop(QString n) : name(n) {}

QString Shop::getName() const { return name; }

void Shop::setName(QString n) { name = n; }
