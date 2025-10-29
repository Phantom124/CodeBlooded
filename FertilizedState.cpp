#include "FertilizedState.h"
#include "NonFertilizerState.h"

int FertilizedState::effect(){
    return 5;
}

Fertilizer *FertilizedState::getNextState(int currentLevel, int lowFertilizerLevel){
    if(currentLevel < lowFertilizerLevel){
        return new NonFertilizerState();
    } else {
        return nullptr;
    }
}

std::string FertilizedState::getStateName()
{
    return "Fertilized";
}
