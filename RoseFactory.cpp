#include "RoseFactory.h"
#include "Rose.h"

RoseFactory::RoseFactory(){
    this->state = state;
    this->waterLevel = waterLevel;
    this->fertilizerLevel = fertilizerLevel;    
}

RoseFactory::~RoseFactory(){
    delete this->state;
    this->state = nullptr;
}

Plant* RoseFactory::createRose(){
    return new Rose();
}

Plant* RoseFactory::createRose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
    return new Rose(state, waterLevel, fertilizerLevel);
}