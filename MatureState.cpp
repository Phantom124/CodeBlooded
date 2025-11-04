/**
 * @file MatureState.cpp
 * @brief MatureState.cpp — Header and declarations for the MatureState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "MatureState.h"

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param careCount The careCount parameter used by the function.
 */

PlantGrowthState *MatureState::getNextState(int careCount) {
    return nullptr;
}

double MatureState::getPriceEffect(){
    return 2.0;
}

std::string MatureState::getStateName(){
    return std::string("Mature");
}
