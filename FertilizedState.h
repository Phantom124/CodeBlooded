#ifndef FERTILIZERSTATE_H
#define FERTILIZERSTATE_H

#include "Fertilizer.h"
class NonFertilizerState;
class FertilizedState : public Fertilizer {
	public:
		int effect();
		Fertilizer* getNextState(int currentLevel, int lowFertilizerLevel);
		std::string getStateName();
};

#endif
