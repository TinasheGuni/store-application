#ifndef BROADCASTLISTENER_H
#define BROADCASTLISTENER_H

// Concepts using in this application have been heavily borrowed from the Qt
// Documentation examples

#include <QWidget>

class QLineEdit;
class QTextEdit;
class QPushButton;
class QUdpSocket;

class BroadcastListener : public QWidget {
  Q_OBJECT
public:
  explicit BroadcastListener(QWidget *parent = nullptr);
  ~BroadcastListener();

public slots:
  void startListening();
  void stopListening();
  void processPendingDatagrams();

private:
  void setupGui();

  QPushButton *btnStart = nullptr;
  QPushButton *btnStop = nullptr;
  QTextEdit *statusLabel = nullptr;
  QUdpSocket *socket = nullptr;
  QString line;
};

#endif // BROADCASTLISTENER_H
