/**
 * @file NotHydratedState.h
 * @brief NotHydratedState.h — Header and declarations for the NotHydratedState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef NOTHYDRATEDSTATE_H
#define NOTHYDRATEDSTATE_H

#include "Water.h"
#include "HydratedState.h"

class NotHydratedState : public Water {
	public:
		int effect();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param currentLevel The currentLevel parameter used by the function.
 * @param lowWaterLevel The lowWaterLevel parameter used by the function.
 */

		Water* getNextState(int currentLevel, int lowWaterLevel);
		std::string getStateName();
};

#endif
