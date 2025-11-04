/**
 * @file Ribbon.cpp
 * @brief Ribbon.cpp — Header and declarations for the Ribbon.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Ribbon.h"
#include <iostream>
#include <string>
Ribbon::Ribbon() : PlantDecorator() {}

double Ribbon::getPrice()
{
    return 25.00 + PlantDecorator::getPrice();
}

std::string Ribbon::getName()
{
    return ", Ribbon" + PlantDecorator::getName();
}

void Ribbon::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
