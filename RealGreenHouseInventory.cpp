#include "RealGreenHouseInventory.h"
#include "Plant.h"


RealGreenHouseInventory::RealGreenHouseInventory()
{
    // this->plants.push_back(new Rose());
    // this->plants.push_back(new Sunflower());
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

void RealGreenHouseInventory::restorePlants(std::vector<PlantComponent *> plants){
    //MUST IMPLEMENT
}

std::vector<Plant *> RealGreenHouseInventory::getAllPlants()
{
    return this->plants;
}

void RealGreenHouseInventory::printPlant(){
    // std::cout << "REAL GREENHOUSE INVENTORY" << std::endl;
    // GreenHouseInventory::printPlant();
}

void RealGreenHouseInventory::handle(Query *query){
    return;
}

void RealGreenHouseInventory::insertPlant(Plant *plant) {
    if(plant != nullptr) {
        this->plants.push_back(plant);
        std::cout << "PLANT ADDED => " << plant->getPlantId() << " " << plant->getName() << " " << plant->getMaturityStateName() << std::endl;
    }else{
    throw std::invalid_argument("RealGreenHouseInventory::insertPlant received a null Plant pointer");
    }
}

void RealGreenHouseInventory::deletePlant(Plant *plant){
    if(plant == nullptr){
        throw std::invalid_argument("RealGreenHouseInventory::deletePlant received a null Plant pointer");
    }

    for (size_t i = 0; i < plants.size(); ++i){
        if (plants[i]->getPlantId() == plant->getPlantId())
        {
            std::cout << "PLANT REMOVED => " << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
            plants.erase(plants.begin() + i);
            return;
        }
    }
    std::cout << "NO MATCH FOR => DELETE FROM INVENTORY WHERE PlantID=" << plant->getPlantId() << ";" << std::endl;
}

void RealGreenHouseInventory::displayPlants(){
    std::cout<<"GreenHouseInventory:\n";
    for(size_t i = 0; i < this->plants.size(); i++){
        if (plants[i] != nullptr) {
            std::cout << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
        }
    }
}
