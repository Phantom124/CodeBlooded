/**
 * @file StaffWindows/StaffManagementWidget.cpp
 * @brief StaffManagementWidget.cpp — Header and declarations for the StaffManagementWidget.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "StaffManagementWidget.h"
#include "ui_StaffManagementWidget.h"
#include "../Common/SharedInstances.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QStringList>
#include <QColor>

StaffManagementWidget::StaffManagementWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StaffManagementWidget)
    , facade(g_greenHouseFacade)
{
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 */

    ui->setupUi(this);

    // Prepare handler table presentation
/**
 * @brief Execute the function's primary operation.
 * @param 2 The 2 parameter used by the function.
 */

    ui->handlerTable->setColumnCount(2);
/**
 * @brief Execute the function's primary operation.
 * @param Type" TODO - describe parameter
 * @param "Status"} TODO - describe parameter
 */

    ui->handlerTable->setHorizontalHeaderLabels({"Handler Type", "Status"});
/**
 * @brief Execute the function's primary operation.
 * @param )->setSectionResizeMode(QHeaderView::Stretch TODO - describe parameter
 */

    ui->handlerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
/**
 * @brief Execute the function's primary operation.
 * @param )->setVisible(false TODO - describe parameter
 */

    ui->handlerTable->verticalHeader()->setVisible(false);
/**
 * @brief Execute the function's primary operation.
 * @param false The false parameter used by the function.
 */

    ui->handlerTable->setAlternatingRowColors(false);

    setupConnections();
    updateHandlerDisplay();
    updateQueueDisplay();
    updateSystemInfo();
}

StaffManagementWidget::~StaffManagementWidget()
{
    delete ui;
}

void StaffManagementWidget::setupConnections()
{
/**
 * @brief Execute the function's primary operation.
 * @param ui->refreshQueueButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onRefreshQueueClicked TODO - describe parameter
 */

    connect(ui->refreshQueueButton, &QPushButton::clicked, this, &StaffManagementWidget::onRefreshQueueClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->processQueueButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onProcessQueueClicked TODO - describe parameter
 */

    connect(ui->processQueueButton, &QPushButton::clicked, this, &StaffManagementWidget::onProcessQueueClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->clearQueueButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onClearQueueClicked TODO - describe parameter
 */

    connect(ui->clearQueueButton, &QPushButton::clicked, this, &StaffManagementWidget::onClearQueueClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->addWaterHandlerButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onAddWaterHandlerClicked TODO - describe parameter
 */

    connect(ui->addWaterHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddWaterHandlerClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->addFertilizerHandlerButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onAddFertilizerHandlerClicked TODO - describe parameter
 */

    connect(ui->addFertilizerHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddFertilizerHandlerClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->addDeadHandlerButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onAddDeadHandlerClicked TODO - describe parameter
 */

    connect(ui->addDeadHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddDeadHandlerClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->addSalesHandlerButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onAddSalesHandlerClicked TODO - describe parameter
 */

    connect(ui->addSalesHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddSalesHandlerClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->removeHandlerButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onRemoveHandlerClicked TODO - describe parameter
 */

    connect(ui->removeHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onRemoveHandlerClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->refreshHandlersButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onRefreshHandlersClicked TODO - describe parameter
 */

    connect(ui->refreshHandlersButton, &QPushButton::clicked, this, &StaffManagementWidget::onRefreshHandlersClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->handlerTable TODO - describe parameter
 * @param &QTableWidget::itemSelectionChanged TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffManagementWidget::onHandlerSelectionChanged TODO - describe parameter
 */

    connect(ui->handlerTable, &QTableWidget::itemSelectionChanged, this, &StaffManagementWidget::onHandlerSelectionChanged);
}

void StaffManagementWidget::onRefreshQueueClicked()
{
    updateQueueDisplay();
    updateHandlerDisplay();
    updateSystemInfo();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Refreshed" TODO - describe parameter
 * @param refreshed." TODO - describe parameter
 */

    QMessageBox::information(this, "Refreshed", "Queue display refreshed.");
}

void StaffManagementWidget::onProcessQueueClicked()
{
    if (!facade)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Error" TODO - describe parameter
 * @param initialized." TODO - describe parameter
 */

        QMessageBox::warning(this, "Error", "System not initialized.");
        return;
    }
    
    int queueSize = facade->getQueueSize();
    
    if (queueSize == 0)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Queue" TODO - describe parameter
 * @param process." TODO - describe parameter
 */

        QMessageBox::information(this, "Empty Queue", "No commands to process.");
        return;
    }
    
    facade->processCommandQueue();
    updateQueueDisplay();
    updateHandlerDisplay();
    updateSystemInfo();
    
    QMessageBox::information(this, "Queue Processed", 
/**
 * @brief Execute the function's primary operation.
 * @param chain.").arg(queueSize) TODO - describe parameter
 */

        QString("%1 command(s) processed through handler chain.").arg(queueSize));
}

void StaffManagementWidget::onClearQueueClicked()
{
    if (QMessageBox::question(this, "Clear Queue", "Are you sure you want to clear all pending commands?") 
        != QMessageBox::Yes)
    {
        return;
    }
    
    if (!facade)
    {


        QMessageBox::warning(this, "Error", "System not initialized.");
        return;
    }
    
    StaffSystem* staffSystem = facade->getStaffSystem();
    if (staffSystem)
    {
        // Clear queue using iterator
        QueueIterator iterator = staffSystem->createIterator();
        int cleared = 0;
        while (!iterator.isEmpty())
        {
            Command *cmd = iterator.dequeue();
            delete cmd;
            cleared++;
        }
        
        updateQueueDisplay();
        updateHandlerDisplay();
        updateSystemInfo();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Cleared" TODO - describe parameter
 * @param removed.").arg(cleared) TODO - describe parameter
 */

        QMessageBox::information(this, "Queue Cleared", QString("%1 command(s) removed.").arg(cleared));
    }
}

void StaffManagementWidget::updateQueueDisplay()
{
    ui->queueList->clear();
    
    if (!facade)
    {
/**
 * @brief Execute the function's primary operation.
 * @param 0" TODO - describe parameter
 */

        ui->queueCountLabel->setText("Queue Size: 0");
        return;
    }
    
    std::vector<Command*> commands = facade->getQueuedCommands();
/**
 * @brief Execute the function's primary operation.
 * @param %1").arg(commands.size()) TODO - describe parameter
 */

    ui->queueCountLabel->setText(QString("Queue Size: %1").arg(commands.size()));
    
    int count = 0;
    for (Command* cmd : commands)
    {
        QString cmdType;
        switch(cmd->getType())
        {
            case WATER:
                cmdType = "WATER Command";
                break;
            case FERTILIZER:
                cmdType = "FERTILIZER Command";
                break;
            case DEAD:
                cmdType = "DEAD Command";
                break;
            case GET_PLANT:
                cmdType = "GET_PLANT Command";
                break;
            default:
                cmdType = "Unknown Command";
        }
        
/**
 * @brief Execute the function's primary operation.
 * @param %2").arg(++count).arg(cmdType) TODO - describe parameter
 */

        ui->queueList->addItem(QString("%1. %2").arg(++count).arg(cmdType));
    }
}

void StaffManagementWidget::updateHandlerDisplay()
{
    loadHandlerTable();

    if (!facade)
    {
/**
 * @brief Execute the function's primary operation.
 * @param initialized." TODO - describe parameter
 */

        ui->handlerSummaryLabel->setText("System not initialized.");
        return;
    }

    const auto snapshot = facade->getHandlerSnapshot();
    if (snapshot.empty())
    {
/**
 * @brief Execute the function's primary operation.
 * @param registered." TODO - describe parameter
 */

        ui->handlerSummaryLabel->setText("No handlers registered.");
        return;
    }

    QStringList parts;
    for (const auto& entry : snapshot)
    {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param entry.first TODO - describe parameter
 */

        const QString name = QString::fromStdString(entry.first);
        const QString status = entry.second ? "Busy" : "Available";
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param (%2)").arg(name TODO - describe parameter
 * @param status The status parameter used by the function.
 */

        parts << QString("%1 (%2)").arg(name, status);
    }

/**
 * @brief Execute the function's primary operation.
 * @param ") TODO - describe parameter
 */

    ui->handlerSummaryLabel->setText(parts.join("  ->  "));
}

void StaffManagementWidget::updateSystemInfo()
{
    if (!facade)
    {
/**
 * @brief Execute the function's primary operation.
 * @param QString() TODO - describe parameter
 */

        ui->handlerSummaryLabel->setToolTip(QString());
        return;
    }

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param facade->getHandlerSnapshot().size() TODO - describe parameter
 */

    const int handlerCount = static_cast<int>(facade->getHandlerSnapshot().size());
    const int queueSize = facade->getQueueSize();
/**
 * @brief Execute the function's primary operation.
 * @param commands").arg(handlerCount).arg(queueSize) TODO - describe parameter
 */

    ui->handlerSummaryLabel->setToolTip(QString("Handlers: %1 | Queue: %2 commands").arg(handlerCount).arg(queueSize));
}

void StaffManagementWidget::loadHandlerTable()
{
/**
 * @brief Execute the function's primary operation.
 * @param 0 The 0 parameter used by the function.
 */

    ui->handlerTable->setRowCount(0);

    if (!facade)
    {


        ui->removeHandlerButton->setEnabled(false);
        return;
    }

    const auto snapshot = facade->getHandlerSnapshot();
/**
 * @brief Execute the function's primary operation.
 * @param static_cast<int>(snapshot.size()) TODO - describe parameter
 */

    ui->handlerTable->setRowCount(static_cast<int>(snapshot.size()));

    for (int row = 0; row < static_cast<int>(snapshot.size()); ++row)
    {
        const auto& entry = snapshot[static_cast<std::size_t>(row)];

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param QString::fromStdString(entry.first) TODO - describe parameter
 */

        auto *typeItem = new QTableWidgetItem(QString::fromStdString(entry.first));
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param "Available" TODO - describe parameter
 */

        auto *statusItem = new QTableWidgetItem(entry.second ? "Busy" : "Available");
/**
 * @brief Execute the function's primary operation.
 * @param Qt::AlignCenter TODO - describe parameter
 */

        statusItem->setTextAlignment(Qt::AlignCenter);
/**
 * @brief Execute the function's primary operation.
 * @param QColor("#0f380f") TODO - describe parameter
 */

        statusItem->setForeground(entry.second ? QColor("#b71c1c") : QColor("#0f380f"));

/**
 * @brief Execute the function's primary operation.
 * @param row The row parameter used by the function.
 * @param 0 The 0 parameter used by the function.
 * @param typeItem The typeItem parameter used by the function.
 */

        ui->handlerTable->setItem(row, 0, typeItem);
/**
 * @brief Execute the function's primary operation.
 * @param row The row parameter used by the function.
 * @param 1 The 1 parameter used by the function.
 * @param statusItem The statusItem parameter used by the function.
 */

        ui->handlerTable->setItem(row, 1, statusItem);
    }

/**
 * @brief Execute the function's primary operation.
 * @param > TODO - describe parameter
 */

    ui->removeHandlerButton->setEnabled(ui->handlerTable->currentRow() >= 0);
}

void StaffManagementWidget::onAddWaterHandlerClicked()
{
    if (!facade) return;
    if (facade->addHandlerOfType("Water"))
    {
        updateHandlerDisplay();
        updateQueueDisplay();
        updateSystemInfo();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Added" TODO - describe parameter
 * @param chain." TODO - describe parameter
 */

        QMessageBox::information(this, "Handler Added", "Water Handler added to the chain.");
    }
    else
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Handler" TODO - describe parameter
 * @param Handler." TODO - describe parameter
 */

        QMessageBox::warning(this, "Add Handler", "Unable to add Water Handler.");
    }
}

void StaffManagementWidget::onAddFertilizerHandlerClicked()
{
    if (!facade) return;
    if (facade->addHandlerOfType("Fertilizer"))
    {
        updateHandlerDisplay();
        updateQueueDisplay();
        updateSystemInfo();


        QMessageBox::information(this, "Handler Added", "Fertilizer Handler added to the chain.");
    }
    else
    {


        QMessageBox::warning(this, "Add Handler", "Unable to add Fertilizer Handler.");
    }
}

void StaffManagementWidget::onAddDeadHandlerClicked()
{
    if (!facade) return;
    if (facade->addHandlerOfType("Dead"))
    {
        updateHandlerDisplay();
        updateQueueDisplay();
        updateSystemInfo();


        QMessageBox::information(this, "Handler Added", "Dead Handler added to the chain.");
    }
    else
    {


        QMessageBox::warning(this, "Add Handler", "Unable to add Dead Handler.");
    }
}

void StaffManagementWidget::onAddSalesHandlerClicked()
{
    if (!facade) return;
    if (facade->addHandlerOfType("Sales"))
    {
        updateHandlerDisplay();
        updateQueueDisplay();
        updateSystemInfo();


        QMessageBox::information(this, "Handler Added", "Sales Handler added to the chain.");
    }
    else
    {


        QMessageBox::warning(this, "Add Handler", "Unable to add Sales Handler.");
    }
}

void StaffManagementWidget::onRemoveHandlerClicked()
{
    if (!facade) return;

    const int row = ui->handlerTable->currentRow();
    if (row < 0)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Handler" TODO - describe parameter
 * @param remove." TODO - describe parameter
 */

        QMessageBox::information(this, "Remove Handler", "Please select a handler to remove.");
        return;
    }

    if (!facade->removeHandlerAtIndex(row))
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Handler" TODO - describe parameter
 * @param handler." TODO - describe parameter
 */

        QMessageBox::warning(this, "Remove Handler", "Unable to remove the selected handler.");
        return;
    }

    updateHandlerDisplay();
    updateQueueDisplay();
    updateSystemInfo();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Removed" TODO - describe parameter
 * @param chain." TODO - describe parameter
 */

    QMessageBox::information(this, "Handler Removed", "Handler removed from the chain.");
}

void StaffManagementWidget::onRefreshHandlersClicked()
{
    if (!facade) return;
    facade->refreshHandlerAvailability();
    updateHandlerDisplay();
    updateQueueDisplay();
    updateSystemInfo();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Status" TODO - describe parameter
 * @param refreshed." TODO - describe parameter
 */

    QMessageBox::information(this, "Handler Status", "Handler availability refreshed.");
}

void StaffManagementWidget::onHandlerSelectionChanged()
{


    ui->removeHandlerButton->setEnabled(ui->handlerTable->currentRow() >= 0);
}
