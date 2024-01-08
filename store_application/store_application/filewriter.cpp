#include "filewriter.h"
#include "book.h"
#include "magazine.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamWriter>

FileWriter::FileWriter(QString fName) : fileName(fName) {}

void FileWriter::write(QList<Shop *> stockList) {
  QFile outFile(fileName);

  if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qCritical() << outFile.errorString();
  }

  if (!outFile.exists()) {
    qCritical() << outFile.errorString();
  }
}
