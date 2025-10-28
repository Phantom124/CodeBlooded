#include "Scent.h"
#include <iostream>
#include <string>

Scent::Scent() : PlantDecorator() {}

double Scent::getPrice()
{
    return PlantDecorator::getPrice() + 50.00;
}

std::string Scent::getName()
{
    return PlantDecorator::getName() + ", Scent";
}

void Scent::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}