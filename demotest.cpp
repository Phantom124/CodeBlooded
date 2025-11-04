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
#include "SharedInventory.h"

#include "StaffSystem.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"

#include "QueryBuilder.h"
#include "QueryProduct.h"

#include "DeleteQueryBuilder.h"
#include "InsertQueryBuilder.h"
#include "SelectQueryBuilder.h"

#include "CustomerInterface.h"
#include "Customer.h"

#include "StaffInterface.h"

int main()
{
    // Create Inventory
    GreenHouseInventory *GH = new ProxyGreenHouseInventory();
    g_inventory = new ProxyGreenHouseInventory();

    StaffSystem *staffSystem = new StaffSystem(g_inventory, new DeleteQueryBuilder());

    StaffInterface *staffInterface = new StaffInterface(static_cast<ProxyGreenHouseInventory *>(g_inventory), staffSystem);

    // Create Builders
    QueryBuilder *InsertBuilder = new InsertQueryBuilder();
    SelectQueryBuilder *SelectBuilder = new SelectQueryBuilder();
    // DeleteQueryBuilder* DeleteBuilder = new DeleteQueryBuilder();

    // StaffSystem* staffSystem = new StaffSystem();
    WaterMonitor *waterMon = new WaterMonitor();
    FertilizerMonitor *fertMon = new FertilizerMonitor();
    DeadMonitor *deadMon = new DeadMonitor();

    RoseFactory *roseFact = new RoseFactory(waterMon, fertMon, deadMon, InsertBuilder, g_inventory);
    SunflowerFactory *sunflowerFact = new SunflowerFactory(waterMon, fertMon, deadMon, InsertBuilder, g_inventory);
    CactusFactory *cactusFact = new CactusFactory(waterMon, fertMon, deadMon, InsertBuilder, g_inventory);
    roseFact->createPlant();
    sunflowerFact->createPlant();
    cactusFact->createPlant();

    // GH->displayPlants();

    Caretaker *caretaker = new Caretaker();
    Customer *customer = new Customer(g_inventory, SelectBuilder);
    CustomerInterface *customerInterface = new CustomerInterface(g_inventory, caretaker, customer);
    // customerInterface->DisplayPlants();
    while (true)
    {
        std::cout << "\n===== Welcome to the Greenhouse Management System =====\n"
                  << "1. Customer\n"
                  << "2. Staff\n"
                  << "q. Quit\n"
                  << "Enter your choice (1, 2, or q): ";
        std::string choice1;
        std::cin >> choice1;
        if (choice1 == "1")
        {
            std::cout << "\nCustomer selected.\n";
            customerInterface->customerMenu();
        }
        else if (choice1 == "2")
        {
            std::cout << "\nStaff Selected.\n";
            staffInterface->startInterface();
        }
        else if (choice1 == "q" || choice1 == "Q")
        {
            std::cout << "\nLeaving program...\n";
            break;
        }
        else
        {
            std::cout << "\nInvalid option. Please try again.\n";
        }
    }
    bool doIt = true;
    while (doIt)
    {
        GH->hourHasPassed();
        GH->displayPlants();
        std::string userInput;
        std::cout << "Continue to next hour? (y/n): ";
        std::cin >> userInput;
        if (userInput != "y" && userInput != "Y")
        {
            doIt = false;
        }
    }

    // StaffSystem* staffSystem = new StaffSystem(GH, DeleteBuilder);
    // staffSystem->sendDeadQuery(toRemove);
    // GH->displayPlants();

    // //Creating Query Builders
    // QueryBuilder* selectQueryBuilder = new SelectQueryBuilder();
    // QueryBuilder* insertQueryBuilder = new InsertQueryBuilder();
    // QueryBuilder* deleteQueryBuilder = new DeleteQueryBuilder();

    // //Assign DeadHandler to use DeleteQueryBuilder
    // deadHandler->setQueryBuilder(deleteQueryBuilder);
    // QueryProduct* product = new QueryProduct(proxyGreenHouseInventory);

    // Create Staff System and add handlers

    // staffSystem->addHandler(waterHandler);
    // staffSystem->addHandler(fertilizerHandler);
    // staffSystem->addHandler(deadHandler);

    // Create Monitors and link to Staff System
    //  WaterMonitor* waterMonitor = new WaterMonitor();
    //  FertilizerMonitor* fertilizerMonitor = new FertilizerMonitor();
    //  DeadMonitor* deadMonitor = new DeadMonitor();
    //  waterMonitor->setStaffSystem(staffSystem);
    //  fertilizerMonitor->setStaffSystem(staffSystem);
    //  deadMonitor->setStaffSystem(staffSystem);

    // Create Inventory and add some plants

    // while (true) {
    //     std::cout << "\n===== Welcome to the Greenhouse Management System =====\n"
    //               << "1. Customer\n"
    //               << "2. Staff\n"
    //               << "q. Quit\n"
    //               << "Enter your choice (1, 2, or q): ";

    //     std::string choice;
    //     std::getline(std::cin, choice);

    //     if (choice == "1") {
    //         std::cout << "\nYou selected Customer.\n";
    //         // TODO: Call customerMenu() or whatever logic goes here.

    //     }
    //     else if (choice == "2") {
    //         std::cout << "\nYou selected Staff.\n";
    //         // TODO: Call staffMenu() or related function.
    //     }
    //     else if (choice == "q" || choice == "Q") {
    //         std::cout << "\nExiting program...\n";
    //         break;
    //     }
    //     else {
    //         std::cout << "\nInvalid option. Please try again.\n";
    //     }
    // }

    return 0;
}
