#include "MatureState.h"

PlantGrowthState *MatureState::getNextState(int careCount) {
    return nullptr;
}

double MatureState::getPriceEffect(){
    return 2.0;
}

std::string MatureState::getStateName(){
    return std::string("Mature");
}
