#include "Sunflower.h"

Sunflower::Sunflower(){
    this->name = name;
    this->price = price;

    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;
}

Sunflower::Sunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;
}

Sunflower::~Sunflower()
{
    if (this->state != nullptr){
        delete this->state;

    }
    this->state = nullptr;
}

PlantGrowthState* Sunflower::getState(){
    return this->state;
}

int Sunflower::getWaterLevel(){
    return this->waterLevel;
}

int Sunflower::getFertilizerLevel(){
    return this->fertilizerLevel;
}

PlantGrowthState* Sunflower::setState(PlantGrowthState* state){
    this->state = state;

}

int Sunflower::setWaterLevel(int waterLevel){
    this->waterLevel = waterLevel;
}

int Sunflower::setFertilizerLevel(int fertilizerLevel){
    this->fertilizerLevel = fertilizerLevel;
}
