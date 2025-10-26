#include "CareCard.h"
#include <iostream>
#include <string>

CareCard::CareCard() : PlantDecorator() {}

double CareCard::getPrice()
{
    return PlantDecorator::getPrice() + 14.99;
}

std::string CareCard::getName()
{
    return PlantDecorator::getName() + ", CareCard";
}

void CareCard::print()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}