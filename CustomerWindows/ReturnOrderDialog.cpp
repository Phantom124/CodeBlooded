#include "ReturnOrderDialog.h"
#include "ui_ReturnOrderDialog.h"
#include <QMessageBox>
#include "../Common/SharedInstances.h"
#include "../CustomerFacade.h"
#include "../OrderMemento.h"
#include "../PlantSnapshot.h"
#include "../Plant.h"
#include <memory>
#include <QStringList>

ReturnOrderDialog::ReturnOrderDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReturnOrderDialog)
    , facade(g_customerFacade)
    , currentMemento(nullptr)
{
    ui->setupUi(this);
    setupConnections();
    ui->confirmReturnButton->setEnabled(false);
    
    setWindowTitle("Return Order");
    setModal(true);
}

ReturnOrderDialog::~ReturnOrderDialog()
{
    delete ui;
}

void ReturnOrderDialog::setupConnections()
{
    connect(ui->searchButton, &QPushButton::clicked, this, &ReturnOrderDialog::onSearchReceiptClicked);
    connect(ui->confirmReturnButton, &QPushButton::clicked, this, &ReturnOrderDialog::onConfirmReturnClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &ReturnOrderDialog::onCancelClicked);
}

void ReturnOrderDialog::onSearchReceiptClicked()
{
    QString receiptID = ui->receiptIDEdit->text().trimmed();
    
    if (receiptID.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please enter a receipt ID.");
        return;
    }

    if (!facade)
    {
        QMessageBox::critical(this, "System Error", "Customer system is unavailable.");
        return;
    }

    OrderMemento* memento = facade->searchOrder(receiptID.toStdString());

    if (!memento)
    {
        QMessageBox::warning(this, "Not Found", "Receipt ID not found in system.");
        ui->receiptInfoLabel->setText("Receipt not found");
        ui->confirmReturnButton->setEnabled(false);
        currentMemento = nullptr;
        activeReceiptId.clear();
        return;
    }

    currentMemento = memento;
    activeReceiptId = receiptID;

    displayReceiptInfo(buildReceiptSummary(currentMemento));
    ui->confirmReturnButton->setEnabled(true);
}

void ReturnOrderDialog::onConfirmReturnClicked()
{
    if (!facade)
    {
        QMessageBox::critical(this, "System Error", "Customer system is unavailable.");
        return;
    }

    if (activeReceiptId.isEmpty() || !currentMemento)
    {
        QMessageBox::warning(this, "Error", "No receipt selected.");
        return;
    }

    if (QMessageBox::question(this, "Confirm Return",
        QString("Confirm return for receipt: %1?").arg(activeReceiptId)) == QMessageBox::Yes)
    {
        facade->returnOrder(activeReceiptId.toStdString());
        QMessageBox::information(this, "Success", "Order returned successfully!");
        currentMemento = nullptr;
        activeReceiptId.clear();
        accept();
    }
}

void ReturnOrderDialog::onCancelClicked()
{
    reject();
}

void ReturnOrderDialog::displayReceiptInfo(const QString& infoText)
{
    ui->receiptInfoLabel->setText(infoText);
}

QString ReturnOrderDialog::buildReceiptSummary(const OrderMemento* memento) const
{
    if (!memento)
    {
        return QStringLiteral("Receipt not found");
    }

    QStringList lines;
    const QString receiptIdText = activeReceiptId.isEmpty() ? QStringLiteral("N/A") : activeReceiptId;
    lines << QStringLiteral("Receipt ID: %1").arg(receiptIdText);
    lines << QStringLiteral("Order Price: R%1").arg(memento->getOrderPrice(), 0, 'f', 2);

    const auto snapshots = memento->getPlants();
    if (!snapshots.empty())
    {
        lines << QString();
        lines << QStringLiteral("Items:");
        int index = 1;
        for (PlantSnapshot* snapshot : snapshots)
        {
            if (!snapshot)
            {
                continue;
            }

            std::unique_ptr<Plant> plant(snapshot->convertToPlant());
            if (!plant)
            {
                continue;
            }

            lines << QString("  %1. %2 (State: %3)")
                        .arg(index++)
                        .arg(QString::fromStdString(plant->getName()))
                        .arg(QString::fromStdString(plant->getMaturityStateName()));
        }
    }

    lines << QString();
    lines << QStringLiteral("Status: Valid");

    return lines.join('\n');
}
