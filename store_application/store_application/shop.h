#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QString>

class Shop : public QObject {
  Q_OBJECT
public:
  Shop();
  virtual ~Shop();
  Shop(QString n);

  QString getName() const;
  void setName(QString n);

  virtual QString toString() const = 0;

protected:
  QString name;
};

#endif // SHOP_H
