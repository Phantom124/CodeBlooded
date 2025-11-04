/**
 * @file Ribbon.h
 * @brief Ribbon.h — Header and declarations for the Ribbon.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef RIBBON_H
#define RIBBON_H

#include "PlantDecorator.h"
#include <string>

class Ribbon : public PlantDecorator
{

public:
	Ribbon();
	~Ribbon() = default;
	virtual double getPrice();
	virtual std::string getName();
	virtual void print();
};

#endif
