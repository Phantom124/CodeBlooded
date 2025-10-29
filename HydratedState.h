#ifndef HYDRATEDSTATE_H
#define HYDRATEDSTATE_H

#include "Water.h"
class NotHydratedState;
class HydratedState : public Water {
	public:
		int effect();
		Water* getNextState(int currentLevel, int lowWaterLevel);
		std::string getStateName();
};

#endif