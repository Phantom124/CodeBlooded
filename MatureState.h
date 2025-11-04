/**
 * @file MatureState.h
 * @brief MatureState.h — Header and declarations for the MatureState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */


#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantGrowthState.h"

class MatureState : public PlantGrowthState {
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
