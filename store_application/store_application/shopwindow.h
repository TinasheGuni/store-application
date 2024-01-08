#ifndef STOCKGUI_H
#define STOCKGUI_H

#include <QMainWindow>

class QAction;
class QMenu;
class QMenuBar;
class QTextEdit;
class QToolBar;
class QDialog;
class QPushButton;
class QLineEdit;
class QSpinBox;
class QTreeView;
class QComboBox;
class QSpinBox;
class QLabel;
class QStandardItem;
class QStandardItemModel;

class ShopWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit ShopWindow(QWidget *parent = nullptr);
  ~ShopWindow();

private slots:
  void addProduct();
  void addTransaction();

  void restoresTrans();
  void processData();
  void broadcastUDP();
  void about();

private:
  void setupMenus();

  // Pop up Dialog
  void transactionDialog();
  void productDialog();

  //  Actions
  QAction *actAddProduct;
  QAction *actAddTransaction;
  QAction *actBroadcast;
  QAction *actAbout;
  QAction *actRestore;

  // Menus
  QMenu *menuStock;
  QMenu *menuList;
  QMenu *menuBroadcastUDP;
  QMenu *menuAbout;

  //  Model/View
  QList<QStandardItem *> prepareRow(const QString &first, const QString &second,
                                    const QString &third);
  QStandardItemModel *standardModel;
  QTreeView *treeView;

  //  Product Pop up dialog
  QDialog *dialogProduct;
  QComboBox *cmbProductType;
  QLineEdit *edtProductName;
  QPushButton *btnAddProduct;

  // Transaction Pop up dialog
  QDialog *dialogTrans;
  QComboBox *cmbCustomer;
  QComboBox *cmbItem;
  QLabel *lblType;
  QPushButton *btnAddItem;
  QPushButton *btnDone;
  QSpinBox *spnQuantity;
  QTextEdit *txtConfirm;
};

#endif // STOCKGUI_H
