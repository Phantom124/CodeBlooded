#ifndef NOTHYDRATEDSTATE_H
#define NOTHYDRATEDSTATE_H

#include "Water.h"
#include "HydratedState.h"

class NotHydratedState : public Water {
	public:
		int effect();
		Water* getNextState(int currentLevel, int lowWaterLevel);
		std::string getStateName();
};

#endif
