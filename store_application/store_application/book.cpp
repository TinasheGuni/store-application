#include "book.h"

Book::Book() {}

Book::~Book() {}

Book::Book(QString n) : Shop(n), name(n) {}

QString Book::getName() const { return name; }

void Book::setName(QString n) { name = n; }

QString Book::toString() const {

  //    Returns the string representation of the Confectionary Object
  return "Name: " + name;
}
