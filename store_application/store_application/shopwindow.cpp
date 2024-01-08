#include "shopwindow.h"
#include "QStringList"
#include "filewriter.h"
#include "shopfactory.h"
#include "shoplist.h"

#include <QStringList>
#include <QtWidgets>

ShopWindow::ShopWindow(QWidget *parent)
    : QMainWindow(parent),

      //    QActions initialization
      actAddProduct(new QAction("New Product")),
      actAddTransaction(new QAction("New Transaction")),
      actBroadcast(new QAction("Broadcast")), actAbout(new QAction("About")),
      actRestore(new QAction("Restore")),

      //    MVA
      standardModel(new QStandardItemModel(this)),
      treeView(new QTreeView(this)),

      //    Product pop up dialog initialization
      dialogProduct(new QDialog(this)), cmbProductType(new QComboBox),
      edtProductName(new QLineEdit), btnAddProduct(new QPushButton("Add item")),

      //    Transaction dialog pop initialization
      cmbCustomer(new QComboBox), cmbItem(new QComboBox),
      dialogTrans(new QDialog(this)), lblType(new QLabel),
      btnAddItem(new QPushButton("Add Item")), btnDone(new QPushButton("Done")),
      spnQuantity(new QSpinBox), txtConfirm(new QTextEdit) {

  //    setup Menus
  setupMenus();

  // Initialize window
  setCentralWidget(treeView);
  setWindowTitle("Shop");

  //  Headers
  QList<QStandardItem *> headers =
      prepareRow("Transaction", "Type", "Quantity");
  QStandardItem *item = standardModel->invisibleRootItem();
  item->appendRow(headers);

  //  Connecting Signals and Slots
  connect(actAddProduct, &QAction::triggered, this, &ShopWindow::addProduct);
  connect(actAddTransaction, &QAction::triggered, this,
          &ShopWindow::addTransaction);
  connect(actBroadcast, &QAction::triggered, this, &ShopWindow::broadcastUDP);
  connect(actRestore, &QAction::triggered, this, &ShopWindow::restoresTrans);
  connect(actAbout, &QAction::triggered, this, &ShopWindow::about);

  treeView->setModel(standardModel);
  treeView->show();
}

ShopWindow::~ShopWindow() {}

void ShopWindow::addProduct() { productDialog(); }

void ShopWindow::addTransaction() {
  transactionDialog();

  //  Connecting Signals and slots
  connect(btnAddItem, &QPushButton::clicked, this, &ShopWindow::processData);
  connect(btnDone, &QPushButton::clicked, this, &QWidget::close);
}

void ShopWindow::processData() {
  ShopFactory sf;
  if (cmbCustomer->isEnabled()) {
    Shop *b = sf.createShop("Book");
    txtConfirm->append(b->toString());

    //    Save to a Book list
    ShopList *listConfectionery = ShopList::getInstance();
    listConfectionery->addStock(b);
  }
  if (cmbItem->isEnabled()) {
    Shop *m = sf.createShop("Magazine");
    txtConfirm->append(m->toString());

    //    Save to a ReadingMaterial list
    ShopList *listRM = ShopList::getInstance();
    listRM->addStock(m);
  }
}

void ShopWindow::broadcastUDP() {
  //  geting an instance of StockList
  ShopList *stockList = ShopList::getInstance();

  QList<Shop *> listB = stockList->returnList("Book");
  QList<Shop *> listRM = stockList->returnList("Magasin");

  QString fileName =
      QFileDialog::getSaveFileName(this, "Open", ".", "xml(*.xml)");
  FileWriter fr(fileName);

  fr.write(listB);
  QMessageBox msg;
  msg.setText("Book List broadcasted using UDP in xml format");
  msg.exec();

  fr.write(listRM);
  QMessageBox msg2;
  msg2.setText("Magasin List broadcasted using UDP in xml format");
  msg2.exec();
}

void ShopWindow::about() {
  QMessageBox::information(this, tr("About"),
                           tr("This is a COS3711 Assignment 03 project"));
}

void ShopWindow::restoresTrans() {
  //  Displaying Book List
  ShopList *stockList = ShopList::getInstance();

  qDebug() << "\n***List of Books***";
  QList<Shop *> listB = stockList->returnList("Book");
  for (int i = 0; i < listB.size(); i++) {
    qDebug() << i << ":" << listB.at(i)->toString();
  }

  //  Displaying Magazine List
  qDebug() << "\n***List Of Magazines***";
  QList<Shop *> listM = stockList->returnList("Magazine");
  for (int i = 0; i < listM.size(); i++) {
    qDebug() << i << ":" << listM.at(i)->toString();
  }
}

void ShopWindow::setupMenus() {
  //  Stock Menu
  menuStock = menuBar()->addMenu("File");
  menuStock->addAction(actBroadcast);

  //  New Menu
  menuList = menuBar()->addMenu("Add");
  menuList->addAction(actAddProduct);
  menuList->addSeparator();
  menuList->addAction(actAddTransaction);

  //  Broadcast
  menuBroadcastUDP = menuBar()->addMenu("Restore");
  menuBroadcastUDP->addAction(actRestore);

  //  about
  menuAbout = menuBar()->addMenu("About");
  menuAbout->addAction(actAbout);
}

void ShopWindow::productDialog() {
  dialogProduct->show();
  dialogProduct->setWindowTitle("Enter Product Name:");

  QVBoxLayout *mainLayout(new QVBoxLayout(dialogProduct));
  QFormLayout *entryLayout(new QFormLayout);

  //  Form title
  QLabel *lblTitle(new QLabel("<b>Complete the required data</b>"));
  mainLayout->addWidget(lblTitle);

  //  mainLayout->addLayout(entryLayout);

  //  product type
  QStringList type = QStringList() << "Book"
                                   << "Magazine";
  cmbProductType->addItems(type);

  QLabel *lblProductType(new QLabel("Item type"));
  entryLayout->addRow(lblProductType, cmbProductType);
  //  mainLayout->addLayout(entryLayout);

  //  Product name
  QLabel *lblProductName(new QLabel("Name of item:"));
  entryLayout->addRow(lblProductName, edtProductName);
  mainLayout->addLayout(entryLayout);
  mainLayout->addWidget(btnAddProduct);
}

QList<QStandardItem *> ShopWindow::prepareRow(const QString &first,
                                              const QString &second,
                                              const QString &third) {
  return {new QStandardItem(first), new QStandardItem(second),
          new QStandardItem(third)};
}

void ShopWindow::transactionDialog() {
  dialogTrans->show();
  dialogTrans->setWindowTitle("Shop");

  QVBoxLayout *mainLayout(new QVBoxLayout(dialogTrans));

  QFormLayout *formLayout(new QFormLayout);

  //  Form title
  QLabel *lblTitle(new QLabel("<b>Complete the required data</b>"));
  formLayout->addRow(lblTitle);

  //  Customer name
  QStringList customerName = QStringList() << "Customer1"
                                           << "Customer2"
                                           << "Customer3";
  cmbCustomer->addItems(customerName);
  QLabel *lblName(new QLabel("Select the customer:"));
  formLayout->addRow(lblName, cmbCustomer);

  //  product name
  QStringList productName = QStringList() << "Book"
                                          << "Magasin";
  cmbItem->addItems(productName);
  QLabel *lblItem(new QLabel("Select the item:"));
  formLayout->addRow(lblItem, cmbItem);

  // product type
  QLabel *lblType1(new QLabel("Item type:"));
  formLayout->addRow(lblType1, lblType);

  mainLayout->addLayout(formLayout);

  //  Quantity
  QHBoxLayout *layoutQuantity(new QHBoxLayout);
  QLabel *lblQuantity(new QLabel("Item quantity:"));
  layoutQuantity->addWidget(spnQuantity);
  layoutQuantity->addWidget(btnAddItem);

  //  mainLayout->addLayout(layoutQuantity);
  formLayout->addRow(lblQuantity, layoutQuantity);

  //  Text Edit
  mainLayout->addWidget(txtConfirm);
  mainLayout->addWidget(btnDone);
}
