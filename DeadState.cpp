/**
 * @file DeadState.cpp
 * @brief DeadState.cpp — Header and declarations for the DeadState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "DeadState.h"

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param careCount The careCount parameter used by the function.
 */

PlantGrowthState *DeadState::getNextState(int careCount) {
    return nullptr;
}

double DeadState::getPriceEffect(){
    return 0.0;
}

std::string DeadState::getStateName(){
    return std::string("Dead");
}
