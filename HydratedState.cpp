/**
 * @file HydratedState.cpp
 * @brief HydratedState.cpp — Header and declarations for the HydratedState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "HydratedState.h"
#include "NotHydratedState.h"

int HydratedState::effect(){
    return 5;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param currentLevel The currentLevel parameter used by the function.
 * @param lowWaterLevel The lowWaterLevel parameter used by the function.
 */

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
