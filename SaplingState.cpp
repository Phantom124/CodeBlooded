#include "SaplingState.h"
#include "MatureState.h"
#include "DeadState.h"

PlantGrowthState *SaplingState::getNextState(int careCount, int health) {
    if(health <= 0){
        return new DeadState();
    }
    else if(careCount > 35){
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
