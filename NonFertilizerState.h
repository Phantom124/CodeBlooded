/**
 * @file NonFertilizerState.h
 * @brief NonFertilizerState.h — Header and declarations for the NonFertilizerState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef NONFERTILIZERSTATE_H
#define NONFERTILIZERSTATE_H
#include <string>
#include "Fertilizer.h"

class NonFertilizerState : public Fertilizer {
	public:
		int effect();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param currentLevel The currentLevel parameter used by the function.
 * @param lowFertilizerLevel The lowFertilizerLevel parameter used by the function.
 */

		Fertilizer* getNextState(int currentLevel, int lowFertilizerLevel);
		std::string getStateName();
};

#endif
