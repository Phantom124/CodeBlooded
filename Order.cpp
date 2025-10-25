#include "Order.h"
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

void Order::priceStrategy()
{
}
