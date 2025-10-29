#include "DeadState.h"

PlantGrowthState *DeadState::getNextState(int careCount) {
    return nullptr;
}

double DeadState::getPriceEffect(){
    return 0.0;
}

std::string DeadState::getStateName(){
    return std::string("Dead");
}
