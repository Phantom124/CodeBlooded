#include "MatureState.h"
#include "DeadState.h"

PlantGrowthState *MatureState::getNextState(int careCount, int health) {
    if(health <= 0){
        return new DeadState();
    }
    return nullptr;
}

double MatureState::getPriceEffect(){
    return 2.0;
}

std::string MatureState::getStateName(){
    return std::string("Mature");
}
