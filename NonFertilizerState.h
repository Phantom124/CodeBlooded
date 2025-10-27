#ifndef NONFERTILIZERSTATE_H
#define NONFERTILIZERSTATE_H
#include <string>
#include "Fertilizer.h"

class NonFertilizerState : public Fertilizer {
	public:
		int effect();
		Fertilizer* getNextState(int currentLevel, int lowFertilizerLevel);
		std::string getStateName();
};

#endif
