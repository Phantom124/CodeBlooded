/**
 * @file DeadState.h
 * @brief DeadState.h — Header and declarations for the DeadState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantGrowthState.h"

class DeadState : public PlantGrowthState {
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
