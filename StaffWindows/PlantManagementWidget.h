/**
 * @file StaffWindows/PlantManagementWidget.h
 * @brief PlantManagementWidget.h — Header and declarations for the PlantManagementWidget.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef PLANTMANAGEMENTWIDGET_H
#define PLANTMANAGEMENTWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include "../GreenHouseFacade.h"
#include "../Plant.h"

namespace Ui {
class PlantManagementWidget;
}

class PlantManagementWidget : public QWidget
{
    Q_OBJECT

public:
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    explicit PlantManagementWidget(QWidget *parent = nullptr);
    ~PlantManagementWidget();

private slots:
    void onAddPlantClicked();
    void onRemovePlantClicked();
    void onRefreshPlantsClicked();
    
    // Plant selection
/**
 * @brief Execute the function's primary operation.
 * @param *item TODO - describe parameter
 */

    void onPlantTableItemSelected(QTableWidgetItem *item);
    
    // Time simulation (triggers monitors, queues commands)
    void onTimeElapsedClicked();
    
    // Command queue processing (executes commands via staffhandler chain of command)
    void onProcessQueueClicked();

private:
    Ui::PlantManagementWidget *ui;
    GreenHouseFacade *facade;
    Plant *selectedPlant;
    
    // Helper functions
    void setupConnections();
    void loadPlants();
/**
 * @brief Execute the function's primary operation.
 * @param *plant TODO - describe parameter
 */

    void updatePlantDetails(Plant *plant);
    void loadCommandQueue();
    Plant* getSelectedPlant();
};

#endif
