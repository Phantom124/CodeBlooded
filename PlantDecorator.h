/**
 * @file PlantDecorator.h
 * @brief PlantDecorator.h — Header and declarations for the PlantDecorator.h component.
 * @author Obed Edom Mbaya
 * @date 2025-11-04
 */

#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "Plant.h"
#include "PlantComponent.h"
#include <string>

class PlantDecorator : public PlantComponent
{
protected:
	PlantComponent *nextDecorator;
	// PlantComponent *plantComponent;

public:
	PlantDecorator();
	~PlantDecorator();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param *extra 
 */

	virtual void add(PlantComponent *extra);
	virtual void printPlant(); // Removed due to no one calling the function
	virtual double getPrice();
	virtual std::string getName();
};

#endif
