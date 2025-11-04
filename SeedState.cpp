/**
 * @file SeedState.cpp
 * @brief SeedState.cpp — Header and declarations for the SeedState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "SeedState.h"
#include "GerminationState.h"

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param careCount The careCount parameter used by the function.
 */

PlantGrowthState *SeedState::getNextState(int careCount) {
    if(careCount > 10){
        return new GerminationState();
    }else{
        return nullptr;
    }
}

double SeedState::getPriceEffect(){
    return 1.0; // No effect on price
}

std::string SeedState::getStateName(){
    return std::string("Seed");
}
