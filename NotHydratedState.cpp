/**
 * @file NotHydratedState.cpp
 * @brief NotHydratedState.cpp — Header and declarations for the NotHydratedState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "NotHydratedState.h"

int NotHydratedState::effect(){
    return -5;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param currentLevel The currentLevel parameter used by the function.
 * @param lowWaterLevel The lowWaterLevel parameter used by the function.
 */

Water *NotHydratedState::getNextState(int currentLevel, int lowWaterLevel){
    if(currentLevel >= lowWaterLevel){
        return new HydratedState();
    } else {
        return nullptr;
    }

}

std::string NotHydratedState::getStateName()
{
    return "NotHydrated";
}
