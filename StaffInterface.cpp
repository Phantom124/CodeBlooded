/**
 * @file StaffInterface.cpp
 * @brief StaffInterface.cpp — Header and declarations for the StaffInterface.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "StaffInterface.h"
#include <iostream>
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
/**
 * @brief Execute the function's primary operation.
 * @param inventory The inventory parameter used by the function.
 * @param GreenHouse(inventory) TODO - describe parameter
 * @param staffSystem(staffSystem TODO - describe parameter
 */

StaffInterface::StaffInterface(ProxyGreenHouseInventory * inventory, StaffSystem* staffSystem): GreenHouse(inventory), staffSystem(staffSystem){
    WaterMonitor* waterMonitor = new WaterMonitor();
    FertilizerMonitor* fertilizerMonitor = new FertilizerMonitor();
    DeadMonitor* deadMonitor = new DeadMonitor();

/**
 * @brief Execute the function's primary operation.
 * @param staffSystem The staffSystem parameter used by the function.
 */

    waterMonitor->setStaffSystem(staffSystem);


    fertilizerMonitor->setStaffSystem(staffSystem);


    deadMonitor->setStaffSystem(staffSystem);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param waterMonitor The waterMonitor parameter used by the function.
 * @param fertilizerMonitor The fertilizerMonitor parameter used by the function.
 * @param deadMonitor The deadMonitor parameter used by the function.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param newPlant The newPlant parameter used by the function.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param DeleteQueryBuilder() TODO - describe parameter
 */

        deadHandler->setQueryBuilder(new DeleteQueryBuilder());
/**
 * @brief Execute the function's primary operation.
 * @param deadHandler The deadHandler parameter used by the function.
 */

        staffSystem->addHandler(deadHandler);
        std::cout << "DeadHandler added to Staff System.\n";


    } else if(choice == "2"){
        StaffHandler* waterHandler = new WaterHandler();
/**
 * @brief Execute the function's primary operation.
 * @param waterHandler The waterHandler parameter used by the function.
 */

        staffSystem->addHandler(waterHandler);
        std::cout << "WaterHandler added to Staff System.\n";


    } else if(choice == "3"){
        StaffHandler* fertilizerHandler = new FertilizerHandler();
/**
 * @brief Execute the function's primary operation.
 * @param fertilizerHandler The fertilizerHandler parameter used by the function.
 */

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
