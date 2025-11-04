/**
 * @file CustomerWindows/ReceiptDialog.cpp
 * @brief ReceiptDialog.cpp — Header and declarations for the ReceiptDialog.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "ReceiptDialog.h"
#include "ui_ReceiptDialog.h"
#include <QDateTime>
#include <QMessageBox>

ReceiptDialog::ReceiptDialog(Order *order, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReceiptDialog)
    , order(order)
    , receipt(nullptr)
{
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 */

    ui->setupUi(this);
    setupConnections();
    displayOrderSummary();
    
/**
 * @brief Execute the function's primary operation.
 * @param Receipt" TODO - describe parameter
 */

    setWindowTitle("Order Receipt");
/**
 * @brief Execute the function's primary operation.
 * @param true The true parameter used by the function.
 */

    setModal(true);
}

ReceiptDialog::~ReceiptDialog()
{
    delete ui;
}

void ReceiptDialog::setupConnections()
{
/**
 * @brief Execute the function's primary operation.
 * @param ui->confirmButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &ReceiptDialog::onConfirmPurchaseClicked TODO - describe parameter
 */

    connect(ui->confirmButton, &QPushButton::clicked, this, &ReceiptDialog::onConfirmPurchaseClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->cancelButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &ReceiptDialog::onCancelClicked TODO - describe parameter
 */

    connect(ui->cancelButton, &QPushButton::clicked, this, &ReceiptDialog::onCancelClicked);
}

void ReceiptDialog::displayOrderSummary()
{
    if (!order) return;
    
    QString summary = "ORDER SUMMARY\n";
    summary += "=================================\n\n";
    double total = order->getPrice();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param R%1\n").arg(total TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

    summary += QString("\nTotal Amount: R%1\n").arg(total, 0, 'f', 2);
    summary += "\nPress CONFIRM to complete purchase\n";
    summary += "or CANCEL to return to shopping.\n";
    
/**
 * @brief Execute the function's primary operation.
 * @param summary The summary parameter used by the function.
 */

    ui->orderSummaryText->setPlainText(summary);
}

void ReceiptDialog::onConfirmPurchaseClicked()
{
    if (!order)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Error" TODO - describe parameter
 * @param process." TODO - describe parameter
 */

        QMessageBox::warning(this, "Error", "No order to process.");
        return;
    }
    
    // Generate receipt
    QString receiptID = generateReceiptID();
    double totalPrice = order->getPrice();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param order->generateInfo() TODO - describe parameter
 */

    QString orderInfo = QString::fromStdString(order->generateInfo());
    
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param receiptID.toStdString() TODO - describe parameter
 * @param totalPrice The totalPrice parameter used by the function.
 * @param orderInfo.toStdString() TODO - describe parameter
 */

    receipt = new Receipt(receiptID.toStdString(), totalPrice, orderInfo.toStdString());
    
    // Display confirmation
    QString confirmation = QString(
        "PURCHASE CONFIRMED!\n\n"
        "Receipt ID: %1\n"
        "Total: R%2\n\n"
        "Thank you for your purchase!\n"
        "Keep your receipt ID for returns."
/**
 * @brief Execute the function's primary operation.
 * @param receiptID).arg(totalPrice TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

    ).arg(receiptID).arg(totalPrice, 0, 'f', 2);
    
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Success" TODO - describe parameter
 * @param confirmation The confirmation parameter used by the function.
 */

    QMessageBox::information(this, "Success", confirmation);
    
    accept();
}

void ReceiptDialog::onCancelClicked()
{
    reject();
}

QString ReceiptDialog::generateReceiptID()
{
    // Generate unique receipt ID based on timestamp
    QDateTime now = QDateTime::currentDateTime();
    return QString("RCP-%1").arg(now.toString("yyyyMMddhhmmss"));
}
