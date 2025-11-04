/**
 * @file Scent.cpp
 * @brief Scent.cpp — Header and declarations for the Scent.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Scent.h"
#include <iostream>
#include <string>

Scent::Scent() : PlantDecorator() {}

double Scent::getPrice()
{
    return 50.00 + PlantDecorator::getPrice();
}

std::string Scent::getName()
{
    return ", Scent" + PlantDecorator::getName();
}

void Scent::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
