#ifndef PLANTGROWTHSTATE_H
#define PLANTGROWTHSTATE_H

#include <string>
class PlantGrowthState {
	public:
		virtual PlantGrowthState* getNextState(int careCount, int health) = 0;
		virtual double getPriceEffect() = 0;
		virtual std::string getStateName() = 0;

};

#endif
