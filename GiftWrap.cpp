#include "GiftWrap.h"
#include <iostream>
#include <string>

GiftWrap::GiftWrap() : PlantDecorator() {}

double GiftWrap::getPrice()
{
    return PlantDecorator::getPrice() + 20.00;
}

std::string GiftWrap::getName()
{
    return PlantDecorator::getName() + ", GiftWrap";
}

void GiftWrap::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}