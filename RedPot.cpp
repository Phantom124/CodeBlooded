/**
 * @file RedPot.cpp
 * @brief RedPot.cpp — Header and declarations for the RedPot.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "RedPot.h"
#include <iostream>
#include <string>

RedPot::RedPot() : PlantDecorator() {}

double RedPot::getPrice()
{
    return 40.00 + PlantDecorator::getPrice();
}

std::string RedPot::getName()
{
    return ", RedPot" + PlantDecorator::getName();
}

void RedPot::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
