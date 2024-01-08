#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "shop.h"

class Magazine : public Shop {
  Q_OBJECT
public:
  Magazine();
  ~Magazine();
  Magazine(QString n);
  QString getName() const;
  void setName(QString n);
  QString toString() const override;

private:
  QString name;
};

#endif // MAGAZINE_H
