#include "Ribbon.h"
#include <iostream>
#include <string>
Ribbon::Ribbon() : PlantDecorator() {}

double Ribbon::getPrice()
{
    return PlantDecorator::getPrice() + 25.00;
}

std::string Ribbon::getName()
{
    return PlantDecorator::getName() + ", Ribbon";
}

void Ribbon::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
