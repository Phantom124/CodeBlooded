/**
 * @file StaffWindows/PlantManagementWidget.cpp
 * @brief PlantManagementWidget.cpp — Header and declarations for the PlantManagementWidget.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "PlantManagementWidget.h"
#include "ui_PlantManagementWidget.h"
#include "../Common/SharedInstances.h"
#include <QMessageBox>
#include <QComboBox>
#include <QHeaderView>

PlantManagementWidget::PlantManagementWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlantManagementWidget)
    , facade(g_greenHouseFacade)
    , selectedPlant(nullptr)
{
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 */

    ui->setupUi(this);
/**
 * @brief Execute the function's primary operation.
 * @param QComboBox::AdjustToContents TODO - describe parameter
 */

    ui->plantTypeCombo->setSizeAdjustPolicy(QComboBox::AdjustToContents); // ensure dropdown fits longest entry
/**
 * @brief Execute the function's primary operation.
 * @param 12 The 12 parameter used by the function.
 */

    ui->plantTypeCombo->setMinimumContentsLength(12);
/**
 * @brief Execute the function's primary operation.
 * @param )->setSectionResizeMode(QHeaderView::Stretch TODO - describe parameter
 */

    ui->plantTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // spread columns across available width
/**
 * @brief Execute the function's primary operation.
 * @param )->setMinimumSectionSize(110 TODO - describe parameter
 */

    ui->plantTable->horizontalHeader()->setMinimumSectionSize(110);
    setupConnections();
    loadPlants();
    loadCommandQueue();
}

PlantManagementWidget::~PlantManagementWidget()
{
    delete ui;
}

void PlantManagementWidget::setupConnections()
{
    // Plant operations
/**
 * @brief Execute the function's primary operation.
 * @param ui->addPlantButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &PlantManagementWidget::onAddPlantClicked TODO - describe parameter
 */

    connect(ui->addPlantButton, &QPushButton::clicked, this, &PlantManagementWidget::onAddPlantClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->removePlantButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &PlantManagementWidget::onRemovePlantClicked TODO - describe parameter
 */

    connect(ui->removePlantButton, &QPushButton::clicked, this, &PlantManagementWidget::onRemovePlantClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->refreshButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &PlantManagementWidget::onRefreshPlantsClicked TODO - describe parameter
 */

    connect(ui->refreshButton, &QPushButton::clicked, this, &PlantManagementWidget::onRefreshPlantsClicked);
    
    // Table selection
/**
 * @brief Execute the function's primary operation.
 * @param ui->plantTable TODO - describe parameter
 * @param &QTableWidget::itemClicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &PlantManagementWidget::onPlantTableItemSelected TODO - describe parameter
 */

    connect(ui->plantTable, &QTableWidget::itemClicked, this, &PlantManagementWidget::onPlantTableItemSelected);
    
    // Time simulation and queue processing
/**
 * @brief Execute the function's primary operation.
 * @param ui->timeElapsedButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &PlantManagementWidget::onTimeElapsedClicked TODO - describe parameter
 */

    connect(ui->timeElapsedButton, &QPushButton::clicked, this, &PlantManagementWidget::onTimeElapsedClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->processQueueButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &PlantManagementWidget::onProcessQueueClicked TODO - describe parameter
 */

    connect(ui->processQueueButton, &QPushButton::clicked, this, &PlantManagementWidget::onProcessQueueClicked);
}

void PlantManagementWidget::loadPlants()
{
/**
 * @brief Execute the function's primary operation.
 * @param 0 The 0 parameter used by the function.
 */

    ui->plantTable->setRowCount(0);
    
    if (!facade) return;
    
    std::vector<Plant*> plants = facade->getAllPlants();
    
/**
 * @brief Execute the function's primary operation.
 * @param static_cast<int>(plants.size()) TODO - describe parameter
 */

    ui->plantTable->setRowCount(static_cast<int>(plants.size()));
    
    for (size_t i = 0; i < plants.size(); ++i)
    {
        Plant *plant = plants[i];
        
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 0 The 0 parameter used by the function.
 * @param QTableWidgetItem(QString::number(plant->getPlantId())) TODO - describe parameter
 */

        ui->plantTable->setItem(i, 0, new QTableWidgetItem(QString::number(plant->getPlantId())));
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 1 The 1 parameter used by the function.
 * @param QTableWidgetItem(QString::fromStdString(plant->getBaseName())) TODO - describe parameter
 */

        ui->plantTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(plant->getBaseName())));  // show concise plant name regardless of decorations
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 2 The 2 parameter used by the function.
 * @param QTableWidgetItem(QString::fromStdString(plant->getMaturityStateName())) TODO - describe parameter
 */

        ui->plantTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(plant->getMaturityStateName())));
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 3 The 3 parameter used by the function.
 * @param QTableWidgetItem(QString::number(plant->getHealth())) TODO - describe parameter
 */

        ui->plantTable->setItem(i, 3, new QTableWidgetItem(QString::number(plant->getHealth())));
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 4 The 4 parameter used by the function.
 * @param QTableWidgetItem(QString::number(plant->getWaterLevel())) TODO - describe parameter
 */

        ui->plantTable->setItem(i, 4, new QTableWidgetItem(QString::number(plant->getWaterLevel())));
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 5 The 5 parameter used by the function.
 * @param QTableWidgetItem(QString::number(plant->getFertilizerLevel())) TODO - describe parameter
 */

        ui->plantTable->setItem(i, 5, new QTableWidgetItem(QString::number(plant->getFertilizerLevel())));
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 6 The 6 parameter used by the function.
 * @param QTableWidgetItem(QString::number(plant->getPrice() TODO - describe parameter
 * @param 'f' TODO - describe parameter
 * @param 2)) TODO - describe parameter
 */

        ui->plantTable->setItem(i, 6, new QTableWidgetItem(QString::number(plant->getPrice(), 'f', 2)));

        // Store plant pointer in first column using an integer payload for stability
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param reinterpret_cast<quintptr>(plant) TODO - describe parameter
 */

        const qulonglong rawPtr = static_cast<qulonglong>(reinterpret_cast<quintptr>(plant));
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 * @param 0)->setData(Qt::UserRole TODO - describe parameter
 * @param QVariant::fromValue(rawPtr) TODO - describe parameter
 */

        ui->plantTable->item(i, 0)->setData(Qt::UserRole, QVariant::fromValue(rawPtr));
    }
    
/**
 * @brief Execute the function's primary operation.
 * @param %1").arg(plants.size()) TODO - describe parameter
 */

    ui->plantCountLabel->setText(QString("Total Plants: %1").arg(plants.size()));
}

void PlantManagementWidget::loadCommandQueue()
{
    ui->commandQueueList->clear();
    
    if (!facade) return;
    
    std::vector<Command*> commands = facade->getQueuedCommands();
/**
 * @brief Execute the function's primary operation.
 * @param %1").arg(commands.size()) TODO - describe parameter
 */

    ui->queueSizeLabel->setText(QString("Queue Size: %1").arg(commands.size()));
    
    for (Command* cmd : commands)
    {
        QString cmdText;
        switch (cmd->getType())
        {
            case WATER:
                cmdText = "WATER Command";
                break;
            case FERTILIZER:
                cmdText = "FERTILIZER Command";
                break;
            case DEAD:
                cmdText = "DEAD Command";
                break;
            case GET_PLANT:
                cmdText = "GET_PLANT Command";
                break;
            default:
                cmdText = "Unknown Command";
                break;
        }
/**
 * @brief Execute the function's primary operation.
 * @param cmdText The cmdText parameter used by the function.
 */

        ui->commandQueueList->addItem(cmdText);
    }
}

void PlantManagementWidget::onAddPlantClicked()
{
    if (!facade) return;
    
    QString plantType = ui->plantTypeCombo->currentText();
    
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType.toStdString() TODO - describe parameter
 */

    Plant *newPlant = facade->createPlant(plantType.toStdString());
    
    if (newPlant)
    {
/**
 * @brief Execute the function's primary operation.
 * @param newPlant The newPlant parameter used by the function.
 */

        facade->addPlantToInventory(newPlant);
        loadPlants(); // Refresh the plant table to show the new plant
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Success" TODO - describe parameter
 * @param successfully!").arg(plantType) TODO - describe parameter
 */

        QMessageBox::information(this, "Success", QString("%1 added successfully!").arg(plantType));
    }
    else
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Error" TODO - describe parameter
 * @param plant." TODO - describe parameter
 */

        QMessageBox::warning(this, "Error", "Failed to create plant.");
    }
}

void PlantManagementWidget::onRemovePlantClicked()
{
    Plant *plant = getSelectedPlant();
    
    if (!plant)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Selection" TODO - describe parameter
 * @param remove." TODO - describe parameter
 */

        QMessageBox::warning(this, "No Selection", "Please select a plant to remove.");
        return;
    }
    
    if (QMessageBox::question(this, "Confirm", "Remove this plant?") == QMessageBox::Yes)
    {
        if (facade)
        {
/**
 * @brief Execute the function's primary operation.
 * @param std::to_string(plant->getPlantId()) TODO - describe parameter
 */

            facade->removePlantFromInventory(std::to_string(plant->getPlantId()));
            selectedPlant = nullptr;
            loadPlants();
            ui->plantDetailsText->clear();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Removed" TODO - describe parameter
 * @param successfully." TODO - describe parameter
 */

            QMessageBox::information(this, "Removed", "Plant removed successfully.");
        }
    }
}

void PlantManagementWidget::onRefreshPlantsClicked()
{
    loadPlants();
    loadCommandQueue();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Refreshed" TODO - describe parameter
 * @param refreshed." TODO - describe parameter
 */

    QMessageBox::information(this, "Refreshed", "Plant inventory and command queue refreshed.");
}

void PlantManagementWidget::onPlantTableItemSelected(QTableWidgetItem *item)
{
    if (!item) return;
    
    int row = item->row();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param row The row parameter used by the function.
 * @param 0 The 0 parameter used by the function.
 */

    QTableWidgetItem *firstItem = ui->plantTable->item(row, 0);
    
    if (firstItem)
    {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Qt::UserRole).toULongLong( TODO - describe parameter
 */

        const qulonglong rawPtr = firstItem->data(Qt::UserRole).toULongLong();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param static_cast<quintptr>(rawPtr) TODO - describe parameter
 */

        Plant *plant = reinterpret_cast<Plant*>(static_cast<quintptr>(rawPtr));
        selectedPlant = plant;
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

        updatePlantDetails(plant);
    }
}

void PlantManagementWidget::onTimeElapsedClicked()
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
    
    facade->simulateHourPassed();
    
    loadPlants();
    loadCommandQueue();
    
    int queueSize = facade->getQueueSize();
    QMessageBox::information(this, "Time Simulated", 
        QString("Hour has passed.\nPlant states updated.\n%1 command(s) queued for processing.")
/**
 * @brief Execute the function's primary operation.
 * @param queueSize) TODO - describe parameter
 */

        .arg(queueSize));
}

void PlantManagementWidget::onProcessQueueClicked()
{
    if (!facade)
    {


        QMessageBox::warning(this, "Error", "System not initialized.");
        return;
    }
    
    int queueSizeBefore = facade->getQueueSize();
    
    if (queueSizeBefore == 0)
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
    
    loadPlants();
    loadCommandQueue();
    
    QMessageBox::information(this, "Queue Processed", 
        QString("%1 command(s) executed.\nPlant states have been updated.")
/**
 * @brief Execute the function's primary operation.
 * @param queueSizeBefore) TODO - describe parameter
 */

        .arg(queueSizeBefore));
}

void PlantManagementWidget::updatePlantDetails(Plant *plant)
{
    if (!plant)
    {
/**
 * @brief Execute the function's primary operation.
 * @param selected" TODO - describe parameter
 */

        ui->plantDetailsText->setPlainText("No plant selected");
        return;
    }
    
    QString details = QString(
        "Plant Type: %1\n"
        "ID: %2\n"
        "Growth State: %3\n"
        "Health: %4\n"
        "Water Level: %5 (%6)\n"
        "Fertilizer Level: %7 (%8)\n"
        "Price: R%9"
    ).arg(QString::fromStdString(plant->getName()))
     .arg(QString::number(plant->getPlantId()))
     .arg(QString::fromStdString(plant->getMaturityStateName()))
     .arg(plant->getHealth())
     .arg(plant->getWaterLevel())
     .arg(QString::fromStdString(plant->getWaterStateName()))
     .arg(plant->getFertilizerLevel())
     .arg(QString::fromStdString(plant->getFertilizerStateName()))
/**
 * @brief Execute the function's primary operation.
 * @param plant->getPrice() TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

     .arg(plant->getPrice(), 0, 'f', 2);
    
/**
 * @brief Execute the function's primary operation.
 * @param details The details parameter used by the function.
 */

    ui->plantDetailsText->setPlainText(details);
}

Plant* PlantManagementWidget::getSelectedPlant()
{
    return selectedPlant;
}
