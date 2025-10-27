#include "Sunflower.h"
#include <iostream>
#include <string>

Sunflower::Sunflower()
{
    this->price = 55;
    this->name = "Sunflower";
}

double Sunflower::getPrice()
{
    return this->price;
}

std::string Sunflower::getName()
{
    return this->name;
}

void Sunflower::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
