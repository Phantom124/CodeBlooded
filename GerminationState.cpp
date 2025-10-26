#include "GerminationState.h"
#include "DeadState.h"
PlantGrowthState *GerminationState::getNextState(int careCount, int health) {
    if(health <= 0){
        return new DeadState();
    }
    else if(careCount > 20){
        return new SaplingState();
    }else{
        return nullptr;
    }
}

double GerminationState::getPriceEffect(){
    return 1.25;
}

std::string GerminationState::getStateName(){
    return std::string("Germination");
}
