#include "SaplingState.h"
#include "MatureState.h"

PlantGrowthState *SaplingState::getNextState(int careCount) {
    if(careCount > 35){
        return new MatureState();
    }else{
        return nullptr;
    }
}

double SaplingState::getPriceEffect(){
    return 1.5;
}

std::string SaplingState::getStateName(){
    return std::string("Sapling");
}