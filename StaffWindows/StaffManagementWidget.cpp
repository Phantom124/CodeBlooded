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
    ui->setupUi(this);

    // Prepare handler table presentation
    ui->handlerTable->setColumnCount(2);
    ui->handlerTable->setHorizontalHeaderLabels({"Handler Type", "Status"});
    ui->handlerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->handlerTable->verticalHeader()->setVisible(false);
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
    connect(ui->refreshQueueButton, &QPushButton::clicked, this, &StaffManagementWidget::onRefreshQueueClicked);
    connect(ui->processQueueButton, &QPushButton::clicked, this, &StaffManagementWidget::onProcessQueueClicked);
    connect(ui->clearQueueButton, &QPushButton::clicked, this, &StaffManagementWidget::onClearQueueClicked);
    connect(ui->addWaterHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddWaterHandlerClicked);
    connect(ui->addFertilizerHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddFertilizerHandlerClicked);
    connect(ui->addDeadHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddDeadHandlerClicked);
    connect(ui->addSalesHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onAddSalesHandlerClicked);
    connect(ui->removeHandlerButton, &QPushButton::clicked, this, &StaffManagementWidget::onRemoveHandlerClicked);
    connect(ui->refreshHandlersButton, &QPushButton::clicked, this, &StaffManagementWidget::onRefreshHandlersClicked);
    connect(ui->handlerTable, &QTableWidget::itemSelectionChanged, this, &StaffManagementWidget::onHandlerSelectionChanged);
}

void StaffManagementWidget::onRefreshQueueClicked()
{
    updateQueueDisplay();
    updateHandlerDisplay();
    updateSystemInfo();
    QMessageBox::information(this, "Refreshed", "Queue display refreshed.");
}

void StaffManagementWidget::onProcessQueueClicked()
{
    if (!facade)
    {
        QMessageBox::warning(this, "Error", "System not initialized.");
        return;
    }
    
    int queueSize = facade->getQueueSize();
    
    if (queueSize == 0)
    {
        QMessageBox::information(this, "Empty Queue", "No commands to process.");
        return;
    }
    
    facade->processCommandQueue();
    updateQueueDisplay();
    updateHandlerDisplay();
    updateSystemInfo();
    
    QMessageBox::information(this, "Queue Processed", 
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
        QMessageBox::information(this, "Queue Cleared", QString("%1 command(s) removed.").arg(cleared));
    }
}

void StaffManagementWidget::updateQueueDisplay()
{
    ui->queueList->clear();
    
    if (!facade)
    {
        ui->queueCountLabel->setText("Queue Size: 0");
        return;
    }
    
    std::vector<Command*> commands = facade->getQueuedCommands();
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
        
        ui->queueList->addItem(QString("%1. %2").arg(++count).arg(cmdType));
    }
}

void StaffManagementWidget::updateHandlerDisplay()
{
    loadHandlerTable();

    if (!facade)
    {
        ui->handlerSummaryLabel->setText("System not initialized.");
        return;
    }

    const auto snapshot = facade->getHandlerSnapshot();
    if (snapshot.empty())
    {
        ui->handlerSummaryLabel->setText("No handlers registered.");
        return;
    }

    QStringList parts;
    for (const auto& entry : snapshot)
    {
        const QString name = QString::fromStdString(entry.first);
        const QString status = entry.second ? "Busy" : "Available";
        parts << QString("%1 (%2)").arg(name, status);
    }

    ui->handlerSummaryLabel->setText(parts.join("  ->  "));
}

void StaffManagementWidget::updateSystemInfo()
{
    if (!facade)
    {
        ui->handlerSummaryLabel->setToolTip(QString());
        return;
    }

    const int handlerCount = static_cast<int>(facade->getHandlerSnapshot().size());
    const int queueSize = facade->getQueueSize();
    ui->handlerSummaryLabel->setToolTip(QString("Handlers: %1 | Queue: %2 commands").arg(handlerCount).arg(queueSize));
}

void StaffManagementWidget::loadHandlerTable()
{
    ui->handlerTable->setRowCount(0);

    if (!facade)
    {
        ui->removeHandlerButton->setEnabled(false);
        return;
    }

    const auto snapshot = facade->getHandlerSnapshot();
    ui->handlerTable->setRowCount(static_cast<int>(snapshot.size()));

    for (int row = 0; row < static_cast<int>(snapshot.size()); ++row)
    {
        const auto& entry = snapshot[static_cast<std::size_t>(row)];

        auto *typeItem = new QTableWidgetItem(QString::fromStdString(entry.first));
        auto *statusItem = new QTableWidgetItem(entry.second ? "Busy" : "Available");
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setForeground(entry.second ? QColor("#b71c1c") : QColor("#0f380f"));

        ui->handlerTable->setItem(row, 0, typeItem);
        ui->handlerTable->setItem(row, 1, statusItem);
    }

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
        QMessageBox::information(this, "Handler Added", "Water Handler added to the chain.");
    }
    else
    {
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
        QMessageBox::information(this, "Remove Handler", "Please select a handler to remove.");
        return;
    }

    if (!facade->removeHandlerAtIndex(row))
    {
        QMessageBox::warning(this, "Remove Handler", "Unable to remove the selected handler.");
        return;
    }

    updateHandlerDisplay();
    updateQueueDisplay();
    updateSystemInfo();
    QMessageBox::information(this, "Handler Removed", "Handler removed from the chain.");
}

void StaffManagementWidget::onRefreshHandlersClicked()
{
    if (!facade) return;
    facade->refreshHandlerAvailability();
    updateHandlerDisplay();
    updateQueueDisplay();
    updateSystemInfo();
    QMessageBox::information(this, "Handler Status", "Handler availability refreshed.");
}

void StaffManagementWidget::onHandlerSelectionChanged()
{
    ui->removeHandlerButton->setEnabled(ui->handlerTable->currentRow() >= 0);
}
