#ifndef BOOK_H
#define BOOK_H

#include "shop.h"
#include <QString>

class Book : public Shop {
  Q_OBJECT
public:
  Book();
  ~Book();
  Book(QString n);

  QString getName() const;
  void setName(QString n);

  QString toString() const override;

private:
  QString name;
};

#endif // BOOK_H
