/**
 * @file Fertilizer.h
 * @brief Fertilizer.h — Header and declarations for the Fertilizer.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */


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
