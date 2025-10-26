#include "Cactus.h"

Cactus::Cactus(){
    this->name = "Cactus";
    this->price = 15;
    this->waterRetention = 0.95;
    this->lowWaterLevel = 15;
    this->fertilizerRetention = 0.90;
    this->lowFertilizerLevel = 10;
}

Cactus::Cactus(PlantGrowthState *state, int waterLevel, int fertilizerLevel){
    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;
}

Cactus::~Cactus(){}

std::string Cactus::getName(){
    return this->name;
}

int Cactus::getWaterLevel(){
    return this->waterLevel;
}

int Cactus::getFertilizerLevel(){
    return this->fertilizerLevel;
}
