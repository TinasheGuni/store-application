#include "shopwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QPixmap pixmap(":/icons/icons/box_icon.ico");
  QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
  splash.showNormal();
  QTimer::singleShot(5000, &splash, &QWidget::close);

  app.processEvents();

  ShopWindow window;
  window.showMaximized();
  window.show();

  return app.exec();
}
