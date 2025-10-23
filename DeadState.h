#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantGrowthState.h"

class DeadState : public PlantGrowthState {
	public:
		void handle();
};

#endif
