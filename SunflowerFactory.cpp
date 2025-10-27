#include "SunflowerFactory.h"
#include "Sunflower.h"

SunflowerFactory::SunflowerFactory(){
    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;
}

SunflowerFactory::~SunflowerFactory(){
    delete this->state;
    this->state = nullptr;
}

Plant* SunflowerFactory::createSunflower(){
    return new Sunflower();
}

Plant* SunflowerFactory::createSunflower(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
    return new Sunflower(state, waterLevel, fertilizerLevel);
}
