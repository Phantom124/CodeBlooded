#include "PlantGroup.h"

std::vector<PlantComponent *> PlantGroup::getPlantComponents()
{
    return plants;
}

PlantGroup::PlantGroup() : PlantComponent() {}

PlantGroup::~PlantGroup()
{
    for (std::vector<PlantComponent *>::iterator it = plants.begin(); it != plants.end(); ++it)
    {
        delete *it;
    }
}

double PlantGroup::getPrice()
{
    auto size = static_cast<int>(plants.size());
    double price = 0.0;
    for (long int i = 0; i < size; i++)
    {
        price += plants[i]->getPrice();
    }

    return price;
}

std::string PlantGroup::getName()
{
    std::string plantGroup = "(";
    auto size = static_cast<int>(plants.size());
    // std::cout << "size is " << size << std::endl;
    for (int i = 0; i < size; i++)
    {
        plantGroup += plants[i]->getName();
        if (i < size - 1)
        {
            plantGroup += ", ";
        }
    }

    plantGroup += ")";
    return plantGroup;
}

std::vector<PlantComponent *> PlantGroup::getPlants()
{
    return this->plants;
}

void PlantGroup::addPlantComponent(PlantComponent *plantComponent)
{
    this->plants.push_back(plantComponent);
}

void PlantGroup::removePlantComponent(PlantComponent *plantComponent)
{
    for (std::vector<PlantComponent *>::iterator it = this->plants.begin(); it != this->plants.end(); it++)
    {
        if ((*it) == plantComponent)
        {
            delete *it;
            this->plants.erase(it);
            break;
        }
    }
}
