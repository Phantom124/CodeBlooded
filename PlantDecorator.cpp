#include "PlantDecorator.h"

#include <iostream>
#include <string>

PlantDecorator::PlantDecorator()
{
    this->myPlant = nullptr;
}

PlantDecorator::~PlantDecorator()
{
    delete this->myPlant;
    this->myPlant = nullptr;
}

void PlantDecorator::add(Plant *extra)
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
        this->myPlant->add(extra);
    }
}

void PlantDecorator::print()
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
