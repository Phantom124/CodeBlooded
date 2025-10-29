#include "NonFertilizerState.h"
#include "FertilizedState.h"
int NonFertilizerState::effect(){
    return -5;
}

Fertilizer *NonFertilizerState::getNextState(int currentLevel, int lowFertilizerLevel){
    if(currentLevel >= lowFertilizerLevel){
        return new FertilizedState();
    } else {
        return nullptr;
    }
}

std::string NonFertilizerState::getStateName()
{
    return "NonFertilized";
}