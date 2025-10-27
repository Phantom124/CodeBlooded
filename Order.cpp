#include "Order.h"
#include "NormalPrice.h"
#include "DiscountPrice.h"
#include <string>
#include <iostream>
Order::Order(PlantGroup *plantGroup) : plantGroup(plantGroup)
{
}

double Order::getPrice()
{
    return plantGroup->getPrice();
}

std::string Order::getName()
{
    return plantGroup->getName();
}

void Order::printOrder()
{
    std::cout << "=====================================================";
    std::cout << "Order for #" << getReceiptID() << std::endl;
    std::cout << "=====================================================";
    std::cout << getName() << std::endl;
}

void Order::addToOrder(Plant *plant)
{
    plantGroup->addPlantComponent(plant);
}

void Order::setPriceStrategy(PriceStrategies *priceStrategy)
{
    if (this->priceStrategy != priceStrategy)
    {
        delete this->priceStrategy;
        this->priceStrategy = priceStrategy;
    }
}

void Order::applyPriceStrategy()
{
    std::vector<PlantComponent *> plants = plantGroup->getPlants();
    int plantCount = 0;
    for (std::vector<PlantComponent *>::iterator it = plants.begin(); it != plants.end(); ++it)
    {
        plantCount++;
    }

    if (plantCount >= 10)
    {
        delete priceStrategy;
        priceStrategy = new DiscountPrice();
    }

    else
    {
        delete priceStrategy;
        priceStrategy = new NormalPrice();
    }
}
