#include "magazine.h"

Magazine::Magazine() {}

Magazine::~Magazine() {}

Magazine::Magazine(QString n) : Shop(n), name(n) {}

QString Magazine::getName() const { return name; }

void Magazine::setName(QString n) { name = n; }

QString Magazine::toString() const { return "Item: " + name; }
