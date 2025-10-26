#include "SeedState.h"
#include "GerminationState.h"

PlantGrowthState *SeedState::getNextState(int careCount) {
    if(careCount > 10){
        return new GerminationState();
    }else{
        return nullptr;
    }
}

double SeedState::getPriceEffect(){
    return 1.0; // No effect on price
}

std::string SeedState::getStateName(){
    return std::string("Seed");
}
