/**
 * @file GerminationState.cpp
 * @brief GerminationState.cpp — Header and declarations for the GerminationState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "GerminationState.h"
#include "SaplingState.h"

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param careCount The careCount parameter used by the function.
 */

PlantGrowthState *GerminationState::getNextState(int careCount) {
    if(careCount > 20){
        return new SaplingState();
    }else{
        return nullptr;
    }
}

double GerminationState::getPriceEffect(){
    return 1.25;
}

std::string GerminationState::getStateName(){
    return std::string("Germination");
}
