#include <iostream>
#include <string>
#include "GreenHouseInventory.h"
#include "ProxyGreenHouseInventory.h"
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



class CustomerInterface{
    private:
    GreenHouseInventory* inventory;
    public:
    void DisplayPlants(){
        // std::cout << "Displaying available plants...\n";
        // Add logic to display plants
        //PrintPlantFuncion
        std::vector<Plant*> plants = inventory->getPlants();
        for (const auto& plant : plants) {
            plant->print();
        }



    }
    void customerMenu() {
    std::cout << "Customer Menu\n";
    while(true) {
        std::cout << "1. View Plants\n2. Purchase Plant\n3. Return Order\nb. Back to Main Menu\nEnter choice: ";
        std::string choice;
        std::cin >> choice;
        if (choice == "b" || choice == "B") {
            std::cout<<"Returning to Main Menu...\n";
            break;
        }
        if(choice == "1") {
            std::cout << "Displaying available plants...\n";
            // Add logic to display plants
        } else if(choice == "2") {
            std::cout << "Processing plant purchase...\n";
            // Add logic to purchase plant
        } else if(choice == "3") {
            std::cout << "Processing order return...\n";
            // Add logic to return order
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
        // Add more customer functionalities here
        // std::cout << "Functionality not implemented yet.\n";
    }
}
};

void customerMenu() {
    std::cout << "Customer Menu\n";
    while(true) {
        std::cout << "1. View Plants\n2. Purchase Plant\n3. Return Order\nb. Back to Main Menu\nEnter choice: ";
        std::string choice;
        std::cin >> choice;
        if (choice == "b" || choice == "B") {
            std::cout<<"Returning to Main Menu...\n";
            break;
        }
        if(choice == "1") {
            std::cout << "Displaying available plants...\n";
            // Add logic to display plants
        } else if(choice == "2") {
            std::cout << "Processing plant purchase...\n";
            // Add logic to purchase plant
        } else if(choice == "3") {
            std::cout << "Processing order return...\n";
            // Add logic to return order
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
        // Add more customer functionalities here
        // std::cout << "Functionality not implemented yet.\n";
    }
}

int main() {
    //Create Handlers
    StaffHandler *waterHandler = new WaterHandler();
    StaffHandler *fertilizerHandler = new FertilizerHandler();
    StaffHandler *deadHandler = new DeadHandler();

    //Create Staff System and add handlers
    StaffSystem* staffSystem = new StaffSystem();
    staffSystem->addHandler(waterHandler);
    staffSystem->addHandler(fertilizerHandler);
    staffSystem->addHandler(deadHandler);

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
