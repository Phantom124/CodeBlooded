/**
 * @file RealGreenHouseInventory.cpp
 * @brief RealGreenHouseInventory.cpp — Header and declarations for the RealGreenHouseInventory.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "RealGreenHouseInventory.h"
#include "Plant.h"

RealGreenHouseInventory::RealGreenHouseInventory()
{
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Rose() TODO - describe parameter
 */

    // this->plants.push_back(new Rose());
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Sunflower() TODO - describe parameter
 */

    // this->plants.push_back(new Sunflower());
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Cactus() TODO - describe parameter
 */

    // this->plants.push_back(new Cactus());
}

RealGreenHouseInventory::~RealGreenHouseInventory()
{
    for (Plant *plant : this->plants)
    {
        delete plant;
    }
    this->plants.clear();
}

void RealGreenHouseInventory::showPlant(std::string parameters)
{
    bool found = false;

    for (size_t i = 0; i < plants.size(); ++i)
    {
        if (std::to_string(plants.at(i)->getPlantId()) == parameters)
        {
            std::cout << "FOUND => " << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
            found = true;
        }
    }
    if (!found)
        std::cout << "NOT FOUND => SELECT " << parameters << " FROM INVENTORY;" << std::endl;
}

void RealGreenHouseInventory::showAllPlants()
{
    std::cout << " === WELCOME TO THE GREENHOUSE INVENTORY === \n"
              << std::endl;

    for (size_t i = 0; i < this->plants.size(); i++)
    {
        std::cout << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
    }
}

void RealGreenHouseInventory::addPlant(Plant *plant)
{
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

    this->plants.push_back(plant);

    std::cout << "PLANT ADDED => " << plant->getPlantId() << " " << plant->getName() << " " << plant->getMaturityStateName() << std::endl;
}

void RealGreenHouseInventory::removePlant(std::string parameters)
{
    showAllPlants();

    for (size_t i = 0; i < plants.size(); ++i)
    {
        if (std::to_string(plants[i]->getPlantId()) == parameters)
        {
            std::cout << "PLANT REMOVED => " << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
/**
 * @brief Execute the function's primary operation.
 * @param i The i parameter used by the function.
 */

            plants.erase(plants.begin() + i);
            showAllPlants();
            return;
        }
    }
    std::cout << "NO MATCH FOR => DELETE FROM INVENTORY WHERE PlantID=" << parameters << ";" << std::endl;
}

void RealGreenHouseInventory::hourHasPassed()
{
    for (size_t i = 0; i < this->plants.size(); i++)
    {
        if (this->plants[i] != nullptr)
        {
            this->plants[i]->hoursHasPassed();
        }
    }
}

std::vector<Plant *> RealGreenHouseInventory::getAllPlants()
{
    return this->plants;
}

void RealGreenHouseInventory::printPlant(){
    std::cout << "REAL GREENHOUSE INVENTORY" << std::endl;
    GreenHouseInventory::printPlant();
}
