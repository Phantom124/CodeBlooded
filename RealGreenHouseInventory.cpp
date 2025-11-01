#include "RealGreenHouseInventory.h"
#include <vector>
#include "Rose.h"
#include "Sunflower.h"
// #include "Cactus.h"

RealGreenHouseInventory::RealGreenHouseInventory(){
    // this->plants.push_back(new Rose());
    // this->plants.push_back(new Sunflower());
    // this->plant.push_back(Plant("3", "Rose", "Adult"));
}

RealGreenHouseInventory::~RealGreenHouseInventory(){
    for (Plant *plant : this->plants) {
        delete plant;
    }
    this->plants.clear();
}

void RealGreenHouseInventory::showPlant(std::string parameters)
{
    bool found = false;

    for (size_t i = 0; i < plants.size(); ++i) {
        if (std::to_string(plants.at(i)->getPlantId()) == parameters){
            std::cout << "FOUND => " << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "NOT FOUND => SELECT " << parameters << " FROM INVENTORY;" << std::endl;

}

void RealGreenHouseInventory::showAllPlants(){
    std::cout << " === WELCOME TO THE GREENHOUSE INVENTORY === \n" << std::endl;

    for (size_t i = 0; i < this->plants.size(); i++){
        std::cout << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
    }


}

void RealGreenHouseInventory::addPlant(Plant* plant){
    this->plants.push_back(plant);

    std::cout << "PLANT ADDED => " << plant->getPlantId() << " " << plant->getName() << " " << plant->getMaturityStateName() << std::endl;

}

void RealGreenHouseInventory::removePlant(std::string parameters){
    for (size_t i = 0; i < plants.size(); ++i) {
        if (std::to_string(plants[i]->getPlantId()) == parameters){
            std::cout << "PLANT REMOVED => " << plants[i]->getPlantId() << " " << plants[i]->getName() << " " << plants[i]->getMaturityStateName() << std::endl;
            plants.erase(plants.begin() + i);
            return;
        }
    }
    std::cout << "NO MATCH FOR => DELETE FROM INVENTORY WHERE PlantID=" << parameters << ";" << std::endl;
}
