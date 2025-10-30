#include "PlantDecorator.h"

#include <iostream>
#include <string>

PlantDecorator::PlantDecorator() : nextDecorator(nullptr) {}

PlantDecorator::~PlantDecorator()
{
    if (nextDecorator != nullptr)
    {
        delete nextDecorator;
        nextDecorator = nullptr;
    }
}

void PlantDecorator::add(PlantComponent *extra)
{
    if (extra == nullptr)
    {
        return;
    }

    if (nextDecorator == nullptr)
    {
        nextDecorator = extra;
    }
    else
    {
        nextDecorator->add(extra);
    }
}
void PlantDecorator::printPlant()
{

    // std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}

double PlantDecorator::getPrice()
{
    if (this->nextDecorator == nullptr)
    {
        return 0.0;
    }
    return this->nextDecorator->getPrice();
}

std::string PlantDecorator::getName()
{
    if (this->nextDecorator == nullptr)
    {
        return "";
    }
    return this->nextDecorator->getName();
}
