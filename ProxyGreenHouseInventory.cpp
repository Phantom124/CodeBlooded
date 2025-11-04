/**
 * @file ProxyGreenHouseInventory.cpp
 * @brief ProxyGreenHouseInventory.cpp — Header and declarations for the ProxyGreenHouseInventory.cpp component.
 * @author Joshua Mahabeer
 * @date 2025-11-04
 */

#include "ProxyGreenHouseInventory.h"
#include "RealGreenHouseInventory.h"
#include "QueryProduct.h"
#include "Customer.h"
#include "StaffHandler.h"
#include "PlantFactory.h"

ProxyGreenHouseInventory::ProxyGreenHouseInventory(){
    this->realInventory = new RealGreenHouseInventory();

}

ProxyGreenHouseInventory::~ProxyGreenHouseInventory(){
    if (this->realInventory != nullptr){
        delete this->realInventory;
        this->realInventory = nullptr;
    }

}

/**
 * @brief Execute the function's primary operation.
 * @param parameters The parameters parameter used by the function.
 */

void ProxyGreenHouseInventory::showPlant(std::string parameters){


    this->realInventory->showPlant(parameters);
}

void ProxyGreenHouseInventory::showAllPlants()
{
    this->realInventory->showAllPlants();
}

/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

void ProxyGreenHouseInventory::addPlant(Plant* plant){
    // std::cout << "[CONTROL ACCESS] Access Denied: Customer cannot INSERT.\n";


    this->realInventory->addPlant(plant);
}


void ProxyGreenHouseInventory::removePlant(std::string parameters){
    // std::cout << "[CONTROL ACCESS] Access Denied: Customer cannot DELETE.\n";


    this->realInventory->removePlant(parameters);
}

std::vector<Plant*> ProxyGreenHouseInventory::getPlants()
{
    if (!this->realInventory)
    {
        return {};
    }
    return this->realInventory->getPlants();
}

/**
 * @brief Execute the function's primary operation.
 * @param user The user parameter used by the function.
 * @param query The query parameter used by the function.
 */

void ProxyGreenHouseInventory::handleControlRights(void* user, QueryProduct query){
    //customers can only SELECT (showPlant, showAllPlants)

    std::string queryText = query.getQuery(); //select, insert, delete
    
    if (dynamic_cast<Customer*>((Customer*)user)){
        if (queryText.find("SELECT") != std::string::npos){
            query.execute();
            
        }
        else{
            std::cout << "[CONTROL ACCESS] Customer cannot perform " << queryText << " operations.\n";
        }
    }
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param dynamic_cast<PlantFactory*>((PlantFactory*)user) TODO - describe parameter
 */

    else if (dynamic_cast<StaffHandler*>((StaffHandler*)user) || dynamic_cast<PlantFactory*>((PlantFactory*)user)){
        query.execute();
        
    }
    else{
        std::cout << "[CONTROL ACCESS] Unknown User Type\n";
    }
}

void ProxyGreenHouseInventory::hourHasPassed(){
    if (this->realInventory != nullptr) return;
    
    for (Plant* plant: this->realInventory->getAllPlants()){
        if (plant != nullptr) plant->hoursHasPassed();
        std::cout << plant->getPlantId() << " " << plant->getName() << " " << plant->getMaturityStateName() << std::endl;
    }
}

void ProxyGreenHouseInventory::printPlant(){
    if (this->realInventory){
        this->realInventory->printPlant();
    }
    else{
        GreenHouseInventory::printPlant();
    }
}
