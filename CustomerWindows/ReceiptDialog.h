#ifndef RECEIPTDIALOG_H
#define RECEIPTDIALOG_H

#include <QDialog>
#include "../Order.h"
#include "../Receipt.h"

namespace Ui {
class ReceiptDialog;
}

class ReceiptDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiptDialog(Order *order, QWidget *parent = nullptr);
    ~ReceiptDialog();

    Receipt* getReceipt() const { return receipt; }

private slots:
    void onConfirmPurchaseClicked();
    void onCancelClicked();

private:
    Ui::ReceiptDialog *ui;
    Order *order;
    Receipt *receipt;
    
    void setupConnections();
    void displayOrderSummary();
    QString generateReceiptID();
};

#endif
