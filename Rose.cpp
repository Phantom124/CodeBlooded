#include "Rose.h"

Rose::Rose(){
    this->name = name;
    this->price = price;

    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;
}

Rose::Rose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;
}

Rose::~Rose(){
    if (this->state != nullptr){
        delete this->state;

    }
    this->state = nullptr;
}

PlantGrowthState* Rose::getState(){
    return this->state;
}

int Rose::getWaterLevel(){
    return this->waterLevel;
}

int Rose::getFertilizerLevel(){
    return this->fertilizerLevel;
}

PlantGrowthState* Rose::setState(PlantGrowthState* state){
    this->state = state;
}

int Rose::setWaterLevel(int waterLevel){
    this->waterLevel = waterLevel;
}

int Rose::setFertilizerLevel(int fertilizerLevel){
    this->fertilizerLevel = fertilizerLevel;
}