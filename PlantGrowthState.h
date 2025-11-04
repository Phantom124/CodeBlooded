/**
 * @file PlantGrowthState.h
 * @brief PlantGrowthState.h — Header and declarations for the PlantGrowthState.h component.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#ifndef PLANTGROWTHSTATE_H
#define PLANTGROWTHSTATE_H

#include <string>
class PlantGrowthState {
    public:
        // removed health parameter
        PlantGrowthState() {}
        virtual ~PlantGrowthState() {}
        virtual PlantGrowthState* getNextState(int careCount) = 0;
        virtual double getPriceEffect() = 0;
        virtual std::string getStateName() = 0;

};

#endif
	
