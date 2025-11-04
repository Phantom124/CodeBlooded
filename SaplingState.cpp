/**
 * @file SaplingState.cpp
 * @brief SaplingState.cpp — Header and declarations for the SaplingState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "SaplingState.h"
#include "MatureState.h"

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param careCount The careCount parameter used by the function.
 */

PlantGrowthState *SaplingState::getNextState(int careCount) {
    if(careCount > 35){
        return new MatureState();
    }else{
        return nullptr;
    }
}

double SaplingState::getPriceEffect(){
    return 1.5;
}

std::string SaplingState::getStateName(){
    return std::string("Sapling");
}
