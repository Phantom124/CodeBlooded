/**
 * @file RedPot.h
 * @brief RedPot.h — Header and declarations for the RedPot.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef REDPOT_H
#define REDPOT_H

#include "PlantDecorator.h"
#include <string>

class RedPot : public PlantDecorator
{

public:
	RedPot();
	~RedPot() = default;
	virtual double getPrice();
	virtual std::string getName();
	virtual void print();
};

#endif
