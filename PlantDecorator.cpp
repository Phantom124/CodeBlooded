#include "PlantDecorator.h"

#include <iostream>
#include <string>

PlantDecorator::PlantDecorator() : myPlant(0) {}

PlantDecorator::~PlantDecorator()
{
    delete this->myPlant;
    this->myPlant = nullptr;
}

void PlantDecorator::addPlant(PlantComponent *extra)
{
    if (extra == nullptr)
    {
        return;
    }
    if (this->myPlant == nullptr)
    {
        this->myPlant = extra;
    }

    else
    {
        this->myPlant->addPlant(extra);
    }
}

void PlantDecorator::printPlant()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}

double PlantDecorator::getPrice()
{
    if (this->myPlant == nullptr)
    {
        return 0.0;
    }

    return this->myPlant->getPrice();
}

std::string PlantDecorator::getName()
{
    if (this->myPlant == nullptr)
    {
        return "";
    }

    return this->myPlant->getName();
}
