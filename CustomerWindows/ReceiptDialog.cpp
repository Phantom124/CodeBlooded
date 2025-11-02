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
    ui->setupUi(this);
    setupConnections();
    displayOrderSummary();
    
    setWindowTitle("Order Receipt");
    setModal(true);
}

ReceiptDialog::~ReceiptDialog()
{
    delete ui;
}

void ReceiptDialog::setupConnections()
{
    connect(ui->confirmButton, &QPushButton::clicked, this, &ReceiptDialog::onConfirmPurchaseClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &ReceiptDialog::onCancelClicked);
}

void ReceiptDialog::displayOrderSummary()
{
    if (!order) return;
    
    QString summary = "ORDER SUMMARY\n";
    summary += "=================================\n\n";
    double total = order->getPrice();
    summary += QString("\nTotal Amount: R%1\n").arg(total, 0, 'f', 2);
    summary += "\nPress CONFIRM to complete purchase\n";
    summary += "or CANCEL to return to shopping.\n";
    
    ui->orderSummaryText->setPlainText(summary);
}

void ReceiptDialog::onConfirmPurchaseClicked()
{
    if (!order)
    {
        QMessageBox::warning(this, "Error", "No order to process.");
        return;
    }
    
    // Generate receipt
    QString receiptID = generateReceiptID();
    double totalPrice = order->getPrice();
    QString orderInfo = QString::fromStdString(order->generateInfo());
    
    receipt = new Receipt(receiptID.toStdString(), totalPrice, orderInfo.toStdString());
    
    // Display confirmation
    QString confirmation = QString(
        "PURCHASE CONFIRMED!\n\n"
        "Receipt ID: %1\n"
        "Total: R%2\n\n"
        "Thank you for your purchase!\n"
        "Keep your receipt ID for returns."
    ).arg(receiptID).arg(totalPrice, 0, 'f', 2);
    
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
