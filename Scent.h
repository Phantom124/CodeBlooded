/**
 * @file Scent.h
 * @brief Scent.h — Header and declarations for the Scent.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef SCENT_H
#define SCENT_H

#include "PlantDecorator.h"
#include <string>

class Scent : public PlantDecorator
{

public:
    Scent();
    ~Scent() = default;
    virtual double getPrice();
    virtual std::string getName();
    virtual void print();
};

#endif
