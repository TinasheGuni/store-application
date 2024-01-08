#include <QApplication>

#include "broadcastlistener.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  BroadcastListener listener;
  listener.show();

  return a.exec();
}
