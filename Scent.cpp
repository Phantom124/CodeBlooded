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