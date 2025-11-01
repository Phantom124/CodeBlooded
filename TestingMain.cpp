#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include "PlantComponent.h"
#include "PlantGroup.h"
#include "PlantDecorator.h"

#include "Plant.h"
#include "RedPot.h"
#include "Ribbon.h"
#include "Scent.h"

#include "Sunflower.h"
#include "Rose.h"

#include "PlantMonitor.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"

#include "RoseFactory.h"
#include "SunflowerFactory.h"
#include "CactusFactory.h"

#include "ProxyGreenHouseInventory.h"
#include "DeleteQueryBuilder.h"
#include "SelectQueryBuilder.h"
#include "InsertQueryBuilder.h"

#include "WaterHandler.h"
#include "DeadHandler.h"
#include "FertilizerHandler.h"
#include "StaffSystem.h"

using namespace std;

void systemTesting() {
    cout << "\n========================================" << endl;
    cout << "         GREENHOUSE SYSTEM TESTING      " << endl;
    cout << "========================================\n" << endl;

    cout << "[setup] Creating proxy for GreenHouse Inventory..." << endl;
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();

    cout << "[setup] Creating StaffSystem..." << endl;
    StaffSystem* staffSystem = new StaffSystem();

    cout << "[setup] Creating Plant monitors..." << endl;
    WaterMonitor* waterMonitor = new WaterMonitor();
    waterMonitor->setStaffSystem(staffSystem);
    FertilizerMonitor* fertilizerMonitor = new FertilizerMonitor();
    fertilizerMonitor->setStaffSystem(staffSystem);
    DeadMonitor* deadMonitor = new DeadMonitor();
    deadMonitor->setStaffSystem(staffSystem);

    cout << "[setup] Instantiating Factories..." << endl;  // 0 - Rose, 1 - Sunflower, 2 - Cactus
    PlantFactory** plantFactories = new PlantFactory*[3];
    plantFactories[0] = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
    plantFactories[1] = new SunflowerFactory(waterMonitor, fertilizerMonitor, deadMonitor);
    plantFactories[2] = new CactusFactory(waterMonitor, fertilizerMonitor, deadMonitor);

    cout << "[setup] Creating InsertQueryBuilder..." << endl;
    InsertQueryBuilder* insertQ = new InsertQueryBuilder();
    cout << "[setup] Creating Staff Handlers and adding to StaffSystem..." << endl;
    StaffSystem* ss = new StaffSystem();
    StaffHandler* gardener1 = new WaterHandler();
    StaffHandler* gardener2 = new FertilizerHandler();
    StaffHandler* gardener3 = new DeadHandler();
    ss->addHandler(gardener1);
    ss->addHandler(gardener2);
    ss->addHandler(gardener3);

    ss->printStaffHandlers();

    cout << "[setup] Adding plants to inventory via Proxy..." << endl;

    // print a neat table header
        cout << left << setw(6) << "ID" << setw(16) << "Type" << setw(18) << "Maturity" << setw(8) << "Water" << setw(12) << "Fertilizer" << setw(8) << "Health" << endl;
    cout << setfill('-') << setw(66) << "" << setfill(' ') << endl;

    for (int i = 0; i < 3; i++) {
        Plant* plant1 = plantFactories[i]->createPlant();
        proxy->addPlant(plant1);
            cout << left << setw(6) << plant1->getPlantId() << setw(16) << plant1->getName() << setw(18) << plant1->getMaturityStateName() << setw(8) << plant1->getWaterLevel() << setw(12) << plant1->getFertilizerLevel() << endl;

        Plant* plant2 = plantFactories[i]->createPlant();
        proxy->addPlant(plant2);
            cout << left << setw(6) << plant2->getPlantId() << setw(16) << plant2->getName() << setw(18) << plant2->getMaturityStateName() << setw(8) << plant2->getWaterLevel() << setw(12) << plant2->getFertilizerLevel() << endl;
    }

    proxy->showAllPlants();

    vector<Plant*> plants = proxy->getPlants();
    cout << "\nInventory summary: " << plants.size() << " plants present." << endl;

    cout << "\nStarting interactive simulation loop." << endl;
    cout << "Enter 1 to advance time by one hour for all plants, or 0 to exit." << endl;

    int choice = 0;
    cout << "Advance one hour? (1 = yes, 0 = no): ";
    if (!(cin >> choice)) choice = 0;
    int hour = 0;
    while(choice == 1 && plants.size() > 0){
        hour++;
        cout << "\n--- Hour " << hour << " ---" << endl;
        ss->printStaffHandlers();
        // header
        cout << left << setw(6) << "ID" << setw(16) << "Type" << setw(18) << "Maturity" << setw(8) << "Water" << setw(12) << "Fertilizer" << setw(8) << "Health" << endl;
        cout << setfill('-') << setw(76) << "" << setfill(' ') << endl;

        for (Plant* plant : plants) {
            plant->hoursHasPassed();
            // print compact table row using available getters
            cout << left << setw(6) << plant->getPlantId() << setw(16) << plant->getName() << setw(18) << plant->getMaturityStateName() << setw(8) << plant->getWaterLevel() << setw(12) << plant->getFertilizerLevel() << setw(8) << plant->getHealth() << endl;
        }

        cout << "\nAdvance another hour? (1 = yes, 0 = no): ";
        if (!(cin >> choice)) break;
    }
    
    delete ss;
    delete insertQ;
    for (int i = 0; i < 3; i++) {
        delete plantFactories[i];
    }
    delete [] plantFactories;
    delete deadMonitor;
    delete fertilizerMonitor;
    delete waterMonitor;
    delete staffSystem;
    delete proxy;

}

int main (){
    systemTesting();
    return 0;
}