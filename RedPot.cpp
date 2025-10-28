#include "RedPot.h"
#include <iostream>
#include <string>

RedPot::RedPot() : PlantDecorator() {}

double RedPot::getPrice()
{
    return PlantDecorator::getPrice() + 40.00;
}

std::string RedPot::getName()
{
    return PlantDecorator::getName() + ", RedPot";
}

void RedPot::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
