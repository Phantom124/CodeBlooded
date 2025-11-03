#include <iostream>
#include <string>
#include "GreenHouseInventory.h"
#include "ProxyGreenHouseInventory.h"
#include "RealGreenHouseInventory.h"
#include "Plant.h"
#include <vector>

#include "StaffHandler.h"
#include "DeadHandler.h"
#include "FertilizerHandler.h"
#include "WaterHandler.h"

#include "StaffSystem.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"

#include "QueryBuilder.h"
#include "QueryProduct.h"

#include "DeleteQueryBuilder.h"
#include "InsertQueryBuilder.h"
#include "SelectQueryBuilder.h"

#include "StaffInterface.h"


int main() {
    //Create Inventory
    ProxyGreenHouseInventory* proxyGreenHouseInventory = new ProxyGreenHouseInventory();
    StaffSystem* staffSystem = new StaffSystem();
    StaffInterface* staffInterface = new StaffInterface(proxyGreenHouseInventory, staffSystem);//sets up monitors and factories


    // //Create Handlers
    // StaffHandler *waterHandler = new WaterHandler();
    // StaffHandler *fertilizerHandler = new FertilizerHandler();
    // StaffHandler *deadHandler = new DeadHandler();

    // //Creating Query Builders
    // QueryBuilder* selectQueryBuilder = new SelectQueryBuilder();
    // QueryBuilder* insertQueryBuilder = new InsertQueryBuilder();
    // QueryBuilder* deleteQueryBuilder = new DeleteQueryBuilder();

    // //Assign DeadHandler to use DeleteQueryBuilder
    // deadHandler->setQueryBuilder(deleteQueryBuilder);
    // QueryProduct* product = new QueryProduct(proxyGreenHouseInventory);

    

    //Create Staff System and add handlers
    
    // staffSystem->addHandler(waterHandler);
    // staffSystem->addHandler(fertilizerHandler);
    // staffSystem->addHandler(deadHandler);

    //Create Monitors and link to Staff System
    WaterMonitor* waterMonitor = new WaterMonitor();
    FertilizerMonitor* fertilizerMonitor = new FertilizerMonitor();
    DeadMonitor* deadMonitor = new DeadMonitor();
    waterMonitor->setStaffSystem(staffSystem);
    fertilizerMonitor->setStaffSystem(staffSystem);
    deadMonitor->setStaffSystem(staffSystem);

    //Create Inventory and add some plants



    while (true) {
        std::cout << "\n===== Welcome to the Greenhouse Management System =====\n"
                  << "1. Customer\n"
                  << "2. Staff\n"
                  << "q. Quit\n"
                  << "Enter your choice (1, 2, or q): ";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            std::cout << "\nYou selected Customer.\n";
            // TODO: Call customerMenu() or whatever logic goes here.

        } 
        else if (choice == "2") {
            std::cout << "\nYou selected Staff.\n";
            // TODO: Call staffMenu() or related function.
        } 
        else if (choice == "q" || choice == "Q") {
            std::cout << "\nExiting program...\n";
            break;
        } 
        else {
            std::cout << "\nInvalid option. Please try again.\n";
        }
    }

    return 0;
}
