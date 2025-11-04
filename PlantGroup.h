/**
 * @file PlantGroup.h
 * @brief PlantGroup.h — Header and declarations for the PlantGroup.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef PLANTGROUP_H
#define PLANTGROUP_H

#include "PlantComponent.h"
#include <string>
#include <vector>

class PlantGroup : public PlantComponent
{
private:
	std::vector<PlantComponent *> plants;

public:
	PlantGroup();
	virtual ~PlantGroup();
	virtual double getPrice();
	virtual std::string getName();
	std::vector<PlantComponent *> getPlants();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param *plantComponent 
 */

	virtual void add(PlantComponent *plantComponent);
	virtual void printPlant() {};
	std::vector<PlantComponent *> getPlantComponents();
/**
 * @brief Execute the function's primary operation.
 * @param *plantComponent 
 */

	void removePlantComponent(PlantComponent *plantComponent);
};

#endif
