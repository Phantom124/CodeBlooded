
#ifndef FERTILIZER_H
#define FERTILIZER_H
#include <string> 


class Fertilizer {
	public:
		virtual ~Fertilizer() = default; 
		virtual int effect() = 0;
		virtual Fertilizer* getNextState(int currentLevel, int lowFertilizerLevel) = 0;
		virtual std::string getStateName() = 0;
};

#endif
