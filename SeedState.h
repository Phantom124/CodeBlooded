#ifndef SEEDSTATE_H
#define SEEDSTATE_H

#include "PlantGrowthState.h"

class SeedState : public PlantGrowthState {
    public:
        PlantGrowthState* getNextState(int careCount);
        double getPriceEffect();
        std::string getStateName();
};

#endif
