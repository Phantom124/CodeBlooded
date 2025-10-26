#include "NotHydratedState.h"

int NotHydratedState::effect(){
    return -5;
}

Water *NotHydratedState::getNextState(int currentLevel, int lowWaterLevel){
    if(currentLevel < lowWaterLevel){
        return new NotHydratedState();
    } else {
        return nullptr;
    }

}

std::string NotHydratedState::getStateName()
{
    return "NotHydrated";
}
