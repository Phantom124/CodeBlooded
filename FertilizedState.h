/**
 * @file FertilizedState.h
 * @brief FertilizedState.h — Header and declarations for the FertilizedState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef FERTILIZERSTATE_H
#define FERTILIZERSTATE_H

#include "Fertilizer.h"
class NonFertilizerState;
class FertilizedState : public Fertilizer {
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
