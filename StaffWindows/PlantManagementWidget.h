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
    explicit PlantManagementWidget(QWidget *parent = nullptr);
    ~PlantManagementWidget();

private slots:
    void onAddPlantClicked();
    void onRemovePlantClicked();
    void onRefreshPlantsClicked();
    
    // Plant selection
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
    void updatePlantDetails(Plant *plant);
    void loadCommandQueue();
    Plant* getSelectedPlant();
};

#endif
