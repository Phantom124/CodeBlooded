#include "GerminationState.h"
#include "SaplingState.h"

PlantGrowthState *GerminationState::getNextState(int careCount) {
    if(careCount > 20){
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
