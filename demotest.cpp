/**
 * @file demotest.cpp
 * @brief demotest.cpp — Header and declarations for the demotest.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param proxyGreenHouseInventory The proxyGreenHouseInventory parameter used by the function.
 * @param staffSystem The staffSystem parameter used by the function.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param deleteQueryBuilder The deleteQueryBuilder parameter used by the function.
 */

    // deadHandler->setQueryBuilder(deleteQueryBuilder);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param proxyGreenHouseInventory The proxyGreenHouseInventory parameter used by the function.
 */

    // QueryProduct* product = new QueryProduct(proxyGreenHouseInventory);

    

    //Create Staff System and add handlers
    
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param waterHandler The waterHandler parameter used by the function.
 */

    // staffSystem->addHandler(waterHandler);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param fertilizerHandler The fertilizerHandler parameter used by the function.
 */

    // staffSystem->addHandler(fertilizerHandler);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param deadHandler The deadHandler parameter used by the function.
 */

    // staffSystem->addHandler(deadHandler);

    //Create Monitors and link to Staff System
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

    //Create Inventory and add some plants



    while (true) {
        std::cout << "\n===== Welcome to the Greenhouse Management System =====\n"
                  << "1. Customer\n"
                  << "2. Staff\n"
                  << "q. Quit\n"
                  << "Enter your choice (1, 2, or q): ";

        std::string choice;
/**
 * @brief Execute the function's primary operation.
 * @param std::cin TODO - describe parameter
 * @param choice The choice parameter used by the function.
 */

        std::getline(std::cin, choice);

        if (choice == "1") {
            std::cout << "\nYou selected Customer.\n";
            // TODO: Call customerMenu() or whatever logic goes here.

        } 
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

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
