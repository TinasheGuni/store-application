#include "broadcastlistener.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QUdpSocket>
#include <QVBoxLayout>

BroadcastListener::BroadcastListener(QWidget *parent)
    : btnStart(new QPushButton(tr("Start"))),
      btnStop(new QPushButton(tr("Stop"))), statusLabel(new QTextEdit),
      socket(new QUdpSocket(this)) {

  // window title
  setWindowTitle(tr("UDP Broadcast Listener"));

  //  signals and slots
  connect(btnStart, &QPushButton::clicked, this,
          &BroadcastListener::startListening);
  connect(btnStop, &QPushButton::clicked, this,
          &BroadcastListener::stopListening);

  setupGui();
}

BroadcastListener::~BroadcastListener() { delete socket; }

void BroadcastListener::startListening() {
  statusLabel->append(tr("Listening for broadcasted messages..."));
  socket->bind(12332);
  connect(socket, &QUdpSocket::readyRead, this,
          &BroadcastListener::processPendingDatagrams);
}

void BroadcastListener::stopListening() {
  statusLabel->append(tr("Stopped Listening..."));
  socket->close();
}

void BroadcastListener::processPendingDatagrams() {
  QByteArray datagram;
  while (socket->hasPendingDatagrams()) {
    datagram.resize(int(socket->pendingDatagramSize()));
    socket->readDatagram(datagram.data(), datagram.size());
    statusLabel->setText(
        tr("Received datagram: \"%1\"").arg(datagram.constData()));
  }
}

void BroadcastListener::setupGui() {
  QVBoxLayout *mainLayout(new QVBoxLayout(this));
  mainLayout->addWidget(statusLabel);

  // buttons
  QHBoxLayout *btnLayout(new QHBoxLayout);
  btnLayout->addWidget(btnStart);
  btnStart->setDefault(true);
  btnLayout->addWidget(btnStop);

  // complete layout
  mainLayout->addLayout(btnLayout);
}
