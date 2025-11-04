/**
 * @file CustomerWindows/ReceiptDialog.h
 * @brief ReceiptDialog.h — Header and declarations for the ReceiptDialog.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param *order TODO - describe parameter
 */

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
