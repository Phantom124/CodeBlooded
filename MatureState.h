
#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantGrowthState.h"

class MatureState : public PlantGrowthState {
    public:
        PlantGrowthState* getNextState(int careCount);
        double getPriceEffect();
        std::string getStateName();
};

#endif
