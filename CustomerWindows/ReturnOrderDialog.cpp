/**
 * @file CustomerWindows/ReturnOrderDialog.cpp
 * @brief ReturnOrderDialog.cpp — Header and declarations for the ReturnOrderDialog.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "ReturnOrderDialog.h"
#include "ui_ReturnOrderDialog.h"
#include <QMessageBox>
#include "../Common/SharedInstances.h"
#include "../CustomerFacade.h"
#include "../OrderMemento.h"
#include "../PlantSnapshot.h"
#include "../Plant.h"
#include <QStringList>

ReturnOrderDialog::ReturnOrderDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReturnOrderDialog)
    , facade(g_customerFacade)
    , currentMemento(nullptr)
{
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 */

    ui->setupUi(this);
    setupConnections();
/**
 * @brief Execute the function's primary operation.
 * @param false The false parameter used by the function.
 */

    ui->confirmReturnButton->setEnabled(false);
    
/**
 * @brief Execute the function's primary operation.
 * @param Order" TODO - describe parameter
 */

    setWindowTitle("Return Order");
/**
 * @brief Execute the function's primary operation.
 * @param true The true parameter used by the function.
 */

    setModal(true);
}

ReturnOrderDialog::~ReturnOrderDialog()
{
    delete ui;
}

void ReturnOrderDialog::setupConnections()
{
/**
 * @brief Execute the function's primary operation.
 * @param ui->searchButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &ReturnOrderDialog::onSearchReceiptClicked TODO - describe parameter
 */

    connect(ui->searchButton, &QPushButton::clicked, this, &ReturnOrderDialog::onSearchReceiptClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->confirmReturnButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &ReturnOrderDialog::onConfirmReturnClicked TODO - describe parameter
 */

    connect(ui->confirmReturnButton, &QPushButton::clicked, this, &ReturnOrderDialog::onConfirmReturnClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->cancelButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &ReturnOrderDialog::onCancelClicked TODO - describe parameter
 */

    connect(ui->cancelButton, &QPushButton::clicked, this, &ReturnOrderDialog::onCancelClicked);
}

void ReturnOrderDialog::onSearchReceiptClicked()
{
    QString receiptID = ui->receiptIDEdit->text().trimmed();
    
    if (receiptID.isEmpty())
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Error" TODO - describe parameter
 * @param ID." TODO - describe parameter
 */

        QMessageBox::warning(this, "Input Error", "Please enter a receipt ID.");
        return;
    }

    if (!facade)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Error" TODO - describe parameter
 * @param unavailable." TODO - describe parameter
 */

        QMessageBox::critical(this, "System Error", "Customer system is unavailable.");
        return;
    }

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param receiptID.toStdString() TODO - describe parameter
 */

    OrderMemento* memento = facade->searchOrder(receiptID.toStdString());

    if (!memento)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Found" TODO - describe parameter
 * @param system." TODO - describe parameter
 */

        QMessageBox::warning(this, "Not Found", "Receipt ID not found in system.");
/**
 * @brief Execute the function's primary operation.
 * @param found" TODO - describe parameter
 */

        ui->receiptInfoLabel->setText("Receipt not found");


        ui->confirmReturnButton->setEnabled(false);
        currentMemento = nullptr;
        activeReceiptId.clear();
        return;
    }

    currentMemento = memento;
    activeReceiptId = receiptID;

/**
 * @brief Execute the function's primary operation.
 * @param buildReceiptSummary(currentMemento) TODO - describe parameter
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Error" TODO - describe parameter
 * @param selected." TODO - describe parameter
 */

        QMessageBox::warning(this, "Error", "No receipt selected.");
        return;
    }

    if (QMessageBox::question(this, "Confirm Return",
        QString("Confirm return for receipt: %1?").arg(activeReceiptId)) == QMessageBox::Yes)
    {
/**
 * @brief Execute the function's primary operation.
 * @param activeReceiptId.toStdString() TODO - describe parameter
 */

        facade->returnOrder(activeReceiptId.toStdString());
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Success" TODO - describe parameter
 * @param successfully!" TODO - describe parameter
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param infoText The infoText parameter used by the function.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param %1").arg(receiptIdText TODO - describe parameter
 */

    lines << QStringLiteral("Receipt ID: %1").arg(receiptIdText);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param R%1").arg(memento->getOrderPrice() TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

    lines << QStringLiteral("Order Price: R%1").arg(memento->getOrderPrice(), 0, 'f', 2);

    const auto snapshots = memento->getPlants();
    if (!snapshots.empty())
    {
        lines << QString();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param "Items:" TODO - describe parameter
 */

        lines << QStringLiteral("Items:");
        int index = 1;
        for (PlantSnapshot* snapshot : snapshots)
        {
            if (!snapshot)
            {
                continue;
            }

            Plant* plant = snapshot->convertToPlant();
            if (!plant)
            {
                continue;
            }

            lines << QString("  %1. %2 (State: %3)")
                        .arg(index++)
                        .arg(QString::fromStdString(plant->getName()))
/**
 * @brief Execute the function's primary operation.
 * @param QString::fromStdString(plant->getMaturityStateName()) TODO - describe parameter
 */

                        .arg(QString::fromStdString(plant->getMaturityStateName()));

            delete plant;  // avoid leaking the temporary plant clone
            plant = nullptr;
        }
    }

    lines << QString();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Valid" TODO - describe parameter
 */

    lines << QStringLiteral("Status: Valid");

    return lines.join('\n');
}
