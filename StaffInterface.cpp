#include "StaffInterface.h"
#include <iostream>
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
StaffInterface::StaffInterface(ProxyGreenHouseInventory * inventory, StaffSystem* staffSystem): GreenHouse(inventory), staffSystem(staffSystem){
    WaterMonitor* waterMonitor = new WaterMonitor();
    FertilizerMonitor* fertilizerMonitor = new FertilizerMonitor();
    DeadMonitor* deadMonitor = new DeadMonitor();

    waterMonitor->setStaffSystem(staffSystem);
    fertilizerMonitor->setStaffSystem(staffSystem);
    deadMonitor->setStaffSystem(staffSystem);

    this->roseFactory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
    this->sunflowerFactory = new SunflowerFactory(waterMonitor, fertilizerMonitor, deadMonitor);
    this->cactusFactory = new CactusFactory(waterMonitor, fertilizerMonitor, deadMonitor);
}

void StaffInterface::startInterface(){
    std::cout << "Staff Interface.\n";
    while(true){
        std::cout << "\nChoose an option:\n1. Add Plant\n2. Add Handler\n3. Elapse Time\n4. Exit\n";
        std::string choice;
        std::cin >> choice;
        if(choice == "1"){
            addPlant();
        } else if(choice == "2"){
            addHandler();
        } else if(choice == "3"){
            elapseTime();
        } else if(choice == "4"){
            std::cout << "Exiting Staff Interface.\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

}

StaffInterface::~StaffInterface(){}

void StaffInterface::addPlant(){
    std::cout << "Choose Plant to Add:\n1. Rose\n2. Sunflower\n3. Cactus\n";
    std::string choice;
    std::cin >> choice;
    Plant* newPlant = nullptr;

    if(choice == "1"){
        newPlant = this->roseFactory->createPlant();
    } else if(choice == "2"){
        newPlant = this->sunflowerFactory->createPlant();
    } else if(choice == "3"){
        newPlant = this->cactusFactory->createPlant();
    } else {
        std::cout << "Invalid choice. No plant added.\n";
        return;
    }

    if(newPlant != nullptr){
        this->GreenHouse->addPlant(newPlant);
        std::cout << "Plant added to inventory.\n";
    } else {
        std::cout << "Failed to create plant.\n";
    }
}

void StaffInterface::addHandler()
{
    std::cout << "Choose Handler to Add:\n1. DeadHandler\n2. WaterHandler\n3. FertilizerHandler\n";
    std::string choice;
    std::cin >> choice;
    if(staffSystem == nullptr){
        std::cout << "Staff System is not initialized. Cannot add handler.\n";
        return;
    }
    if(choice == "1"){
        StaffHandler* deadHandler = new DeadHandler();
        deadHandler->setQueryBuilder(new DeleteQueryBuilder());
        staffSystem->addHandler(deadHandler);
        std::cout << "DeadHandler added to Staff System.\n";
    } else if(choice == "2"){
        StaffHandler* waterHandler = new WaterHandler();
        staffSystem->addHandler(waterHandler);
        std::cout << "WaterHandler added to Staff System.\n";
    } else if(choice == "3"){
        StaffHandler* fertilizerHandler = new FertilizerHandler();
        staffSystem->addHandler(fertilizerHandler);
        std::cout << "FertilizerHandler added to Staff System.\n";
    } else {
        std::cout << "Invalid choice. No handler added.\n";
    }
}

void StaffInterface::elapseTime(){
    std::cout << "An hour has passed in the greenhouse.\n";
    if(GreenHouse != nullptr){
        GreenHouse->hourHasPassed();
    }
    if(staffSystem != nullptr){
        staffSystem->timeElapsed();
    }
}
