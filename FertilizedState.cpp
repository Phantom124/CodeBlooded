/**
 * @file FertilizedState.cpp
 * @brief FertilizedState.cpp — Header and declarations for the FertilizedState.cpp component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "FertilizedState.h"
#include "NonFertilizerState.h"

int FertilizedState::effect(){
    return 5;
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param currentLevel The currentLevel parameter used by the function.
 * @param lowFertilizerLevel The lowFertilizerLevel parameter used by the function.
 */

Fertilizer *FertilizedState::getNextState(int currentLevel, int lowFertilizerLevel){
    if(currentLevel < lowFertilizerLevel){
        return new NonFertilizerState();
    } else {
        return nullptr;
    }
}

std::string FertilizedState::getStateName()
{
    return "Fertilized";
}
