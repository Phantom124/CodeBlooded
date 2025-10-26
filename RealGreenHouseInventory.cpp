#include "RealGreenHouseInventory.h"
#include <vector>

RealGreenHouseInventory::RealGreenHouseInventory(){
    this->plant.push_back(Item("1","Rose", "Seedling"));
    this->plant.push_back(Item("2", "Sunflower", "Germination"));
    this->plant.push_back(Item("3", "Rose", "Adult"));
}

RealGreenHouseInventory::~RealGreenHouseInventory(){
    this->plant.clear();
}

void RealGreenHouseInventory::showPlant(std::string parameters)
{
    bool found = false;

    for (size_t i = 0; i < plant.size(); ++i) {
        if (plant[i].getPlantType() == parameters) {
            std::cout << "FOUND => " << plant[i].toString() << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "NOT FOUND => SELECT " << parameters << " FROM INVENTORY;" << std::endl;

}

void RealGreenHouseInventory::showAllPlants(){
    std::cout << " === WELCOME TO THE GREENHOUSE INVENTORY === \n" << std::endl;

    for (size_t i = 0; i < this->plant.size(); i++){
        std::cout << (this->plant[i].toString()) << std::endl;
    }


}

void RealGreenHouseInventory::addPlant(Item item){
    this->plant.push_back(item);

    std::cout << "PLANT ADDED => " << item.toString() << std::endl;

}

void RealGreenHouseInventory::removePlant(std::string parameters){
    for (size_t i = 0; i < plant.size(); ++i) {
        if (plant[i].getPlantID() == parameters) {
            std::cout << "PLANT REMOVED => " << plant[i].toString() << std::endl;
            plant.erase(plant.begin() + i);
            return;
        }
    }
    std::cout << "NO MATCH FOR => DELETE FROM INVENTORY WHERE PlantID=" << parameters << ";" << std::endl;
}
