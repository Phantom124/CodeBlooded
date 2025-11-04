/**
 * @file GerminationState.h
 * @brief GerminationState.h — Header and declarations for the GerminationState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef GERMINATIONSTATE_H
#define GERMINATIONSTATE_H

#include "PlantGrowthState.h"
#include "SaplingState.h"

class GerminationState : public PlantGrowthState {
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
