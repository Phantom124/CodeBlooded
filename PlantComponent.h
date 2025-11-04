/**
 * @file PlantComponent.h
 * @brief PlantComponent.h — Header and declarations for the PlantComponent.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H

#include <string>
#include <vector>

class PlantComponent
{
public:
    // PlantComponent() = default;
    virtual ~PlantComponent() = default;

    virtual double getPrice() = 0;
    virtual std::string getName() = 0;
    virtual void add(PlantComponent *plantComponent) = 0;
    virtual void printPlant() = 0;

    // virtual std::vector<PlantComponent *> getPlants() { return; }
};

#endif
