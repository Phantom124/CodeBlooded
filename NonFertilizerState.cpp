/**
 * @file NonFertilizerState.cpp
 * @brief NonFertilizerState.cpp — Header and declarations for the NonFertilizerState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "NonFertilizerState.h"
#include "FertilizedState.h"
int NonFertilizerState::effect(){
    return -5;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param currentLevel The currentLevel parameter used by the function.
 * @param lowFertilizerLevel The lowFertilizerLevel parameter used by the function.
 */

Fertilizer *NonFertilizerState::getNextState(int currentLevel, int lowFertilizerLevel){
    if(currentLevel >= lowFertilizerLevel){
        return new FertilizedState();
    } else {
        return nullptr;
    }
}

std::string NonFertilizerState::getStateName()
{
    return "NonFertilized";
}
