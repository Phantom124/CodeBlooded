#ifndef PLANTGROWTHSTATE_H
#define PLANTGROWTHSTATE_H

class PlantGrowthState {
	public:
		virtual PlantGrowthState* getNextState(int careCount) = 0;
		virtual int effect() = 0;
		virtual std::string getStateName() = 0;

};

#endif
