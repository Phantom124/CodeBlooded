/**
 * @file SaplingState.h
 * @brief SaplingState.h — Header and declarations for the SaplingState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef SAPLINGSTATE_H
#define SAPLINGSTATE_H

#include "PlantGrowthState.h"
#include <string>

class SaplingState : public PlantGrowthState {
    public:
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param careCount The careCount parameter used by the function.
 */

        PlantGrowthState* getNextState(int careCount);
        double getPriceEffect();
        std::string getStateName();
};

#endif
