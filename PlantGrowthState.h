#ifndef PLANTGROWTHSTATE_H
#define PLANTGROWTHSTATE_H

#include <string>
class PlantGrowthState {
    public:
        // removed health parameter
        virtual PlantGrowthState* getNextState(int careCount) = 0;
        virtual double getPriceEffect() = 0;
        virtual std::string getStateName() = 0;

};

#endif
	