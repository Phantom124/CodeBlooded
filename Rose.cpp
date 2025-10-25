#include "Rose.h"
#include <iostream>
#include <string>
Rose::Rose()
{
    this->price = 80;
    this->name = "Rose";
}

double Rose::getPrice()
{
    return this->price;
}

std::string Rose::getName()
{
    return this->name;
}

void Rose::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
