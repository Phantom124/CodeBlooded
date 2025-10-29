#ifndef FERTILIZERSTATE_H
#define FERTILIZERSTATE_H

#include "Fertilizer.h"
#include <string>

class NonFertilizerState;
class FertilizedState : public Fertilizer {
	public:
		int effect();
		Fertilizer* getNextState(int currentLevel, int lowFertilizerLevel);
		std::string getStateName();
};

#endif