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
    ui->setupUi(this);
    ui->plantTypeCombo->setSizeAdjustPolicy(QComboBox::AdjustToContents); // ensure dropdown fits longest entry
    ui->plantTypeCombo->setMinimumContentsLength(12);
    ui->plantTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // spread columns across available width
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
    connect(ui->addPlantButton, &QPushButton::clicked, this, &PlantManagementWidget::onAddPlantClicked);
    connect(ui->removePlantButton, &QPushButton::clicked, this, &PlantManagementWidget::onRemovePlantClicked);
    connect(ui->refreshButton, &QPushButton::clicked, this, &PlantManagementWidget::onRefreshPlantsClicked);
    
    // Table selection
    connect(ui->plantTable, &QTableWidget::itemClicked, this, &PlantManagementWidget::onPlantTableItemSelected);
    
    // Time simulation and queue processing
    connect(ui->timeElapsedButton, &QPushButton::clicked, this, &PlantManagementWidget::onTimeElapsedClicked);
    connect(ui->processQueueButton, &QPushButton::clicked, this, &PlantManagementWidget::onProcessQueueClicked);
}

void PlantManagementWidget::loadPlants()
{
    ui->plantTable->setRowCount(0);
    
    if (!facade) return;
    
    std::vector<Plant*> plants = facade->getAllPlants();
    
    ui->plantTable->setRowCount(static_cast<int>(plants.size()));
    
    for (size_t i = 0; i < plants.size(); ++i)
    {
        Plant *plant = plants[i];
        
        ui->plantTable->setItem(i, 0, new QTableWidgetItem(QString::number(plant->getPlantId())));
        ui->plantTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(plant->getBaseName())));  // show concise plant name regardless of decorations
        ui->plantTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(plant->getMaturityStateName())));
        ui->plantTable->setItem(i, 3, new QTableWidgetItem(QString::number(plant->getHealth())));
        ui->plantTable->setItem(i, 4, new QTableWidgetItem(QString::number(plant->getWaterLevel())));
        ui->plantTable->setItem(i, 5, new QTableWidgetItem(QString::number(plant->getFertilizerLevel())));
        ui->plantTable->setItem(i, 6, new QTableWidgetItem(QString::number(plant->getPrice(), 'f', 2)));

        // Store plant pointer in first column using an integer payload for stability
        const qulonglong rawPtr = static_cast<qulonglong>(reinterpret_cast<quintptr>(plant));
        ui->plantTable->item(i, 0)->setData(Qt::UserRole, QVariant::fromValue(rawPtr));
    }
    
    ui->plantCountLabel->setText(QString("Total Plants: %1").arg(plants.size()));
}

void PlantManagementWidget::loadCommandQueue()
{
    ui->commandQueueList->clear();
    
    if (!facade) return;
    
    std::vector<Command*> commands = facade->getQueuedCommands();
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
        ui->commandQueueList->addItem(cmdText);
    }
}

void PlantManagementWidget::onAddPlantClicked()
{
    if (!facade) return;
    
    QString plantType = ui->plantTypeCombo->currentText();
    
    Plant *newPlant = facade->createPlant(plantType.toStdString());
    
    if (newPlant)
    {
        facade->addPlantToInventory(newPlant);
        loadPlants(); // Refresh the plant table to show the new plant
        QMessageBox::information(this, "Success", QString("%1 added successfully!").arg(plantType));
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to create plant.");
    }
}

void PlantManagementWidget::onRemovePlantClicked()
{
    Plant *plant = getSelectedPlant();
    
    if (!plant)
    {
        QMessageBox::warning(this, "No Selection", "Please select a plant to remove.");
        return;
    }
    
    if (QMessageBox::question(this, "Confirm", "Remove this plant?") == QMessageBox::Yes)
    {
        if (facade)
        {
            facade->removePlantFromInventory(std::to_string(plant->getPlantId()));
            selectedPlant = nullptr;
            loadPlants();
            ui->plantDetailsText->clear();
            QMessageBox::information(this, "Removed", "Plant removed successfully.");
        }
    }
}

void PlantManagementWidget::onRefreshPlantsClicked()
{
    loadPlants();
    loadCommandQueue();
    QMessageBox::information(this, "Refreshed", "Plant inventory and command queue refreshed.");
}

void PlantManagementWidget::onPlantTableItemSelected(QTableWidgetItem *item)
{
    if (!item) return;
    
    int row = item->row();
    QTableWidgetItem *firstItem = ui->plantTable->item(row, 0);
    
    if (firstItem)
    {
        const qulonglong rawPtr = firstItem->data(Qt::UserRole).toULongLong();
        Plant *plant = reinterpret_cast<Plant*>(static_cast<quintptr>(rawPtr));
        selectedPlant = plant;
        updatePlantDetails(plant);
    }
}

void PlantManagementWidget::onTimeElapsedClicked()
{
    if (!facade)
    {
        QMessageBox::warning(this, "Error", "System not initialized.");
        return;
    }
    
    facade->simulateHourPassed();
    
    loadPlants();
    loadCommandQueue();
    
    int queueSize = facade->getQueueSize();
    QMessageBox::information(this, "Time Simulated", 
        QString("Hour has passed.\nPlant states updated.\n%1 command(s) queued for processing.")
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
        QMessageBox::information(this, "Empty Queue", "No commands to process.");
        return;
    }
    
    facade->processCommandQueue();
    
    loadPlants();
    loadCommandQueue();
    
    QMessageBox::information(this, "Queue Processed", 
        QString("%1 command(s) executed.\nPlant states have been updated.")
        .arg(queueSizeBefore));
}

void PlantManagementWidget::updatePlantDetails(Plant *plant)
{
    if (!plant)
    {
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
     .arg(plant->getPrice(), 0, 'f', 2);
    
    ui->plantDetailsText->setPlainText(details);
}

Plant* PlantManagementWidget::getSelectedPlant()
{
    return selectedPlant;
}
