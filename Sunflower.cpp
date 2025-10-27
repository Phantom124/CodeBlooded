#include "Sunflower.h"

Sunflower::Sunflower():Plant(){
    this->name = "Sunflower";
    this->price = 25;
    this->waterRetention = 0.72;
    this->lowWaterLevel = 55;
    this->fertilizerRetention = 0.85;
    this->lowFertilizerLevel = 20;
}

// Sunflower::Sunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     this->state = state;
//     this->waterLevel = waterLevel;
//     this->fertilizerLevel = fertilizerLevel;
// }

Sunflower::~Sunflower(){}

std::string Sunflower::getName(){
    return "Sunflower";
}
