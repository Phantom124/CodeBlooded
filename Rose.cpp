#include "Rose.h"
#include <string>

Rose::Rose(){
    this->name = "Rose";
    this->price = 20;
    this->waterRetention = 0.85;
    this->lowWaterLevel = 30;
    this->fertilizerRetention = 0.60;
    this->lowFertilizerLevel = 70;
}

Rose::Rose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;
}

Rose::~Rose(){}



std::string Rose::getName(){
    return "Rose";
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
