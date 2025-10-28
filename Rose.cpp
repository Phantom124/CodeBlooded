#include "Rose.h"
#include <iostream>
#include <string>
Rose::Rose()
{
    this->price = 80;
    this->name = "Rose";
}

double Rose::getPrice()//Obed
{
    return this->price;
}

std::string Rose::getName()//Obed
{
    return this->name;
}

void Rose::print()//Obed
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}
