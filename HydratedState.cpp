#include "HydratedState.h"
#include "NotHydratedState.h"

int HydratedState::effect(){
    return 5;
}

Water *HydratedState::getNextState(int currentLevel, int lowWaterLevel){
    if(currentLevel < lowWaterLevel){
        return new NotHydratedState();
    } else {
        return nullptr;
    }
}

std::string HydratedState::getStateName(){
    return "Hydrated";
}
