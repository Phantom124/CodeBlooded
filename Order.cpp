#include "Order.h"
#include "Receipt.h"
#include "DiscountPrice.h"
#include "NormalPrice.h"
#include <iostream>

Order::Order(PlantGroup *plantGroup) : plantGroup(plantGroup), priceStrategy(nullptr)
{
    static unsigned long long counter = 0;
    receiptID = "RCPT-" + std::to_string(++counter);
}

Order::~Order()
{
    if (priceStrategy)
    {
        delete priceStrategy;
        priceStrategy = nullptr;
    }
    if (plantGroup)
    {
        delete plantGroup;
    }
}

// OrderMemento *Order::createMemento()
// {
//     return new OrderMemento(plantGroup->getPlantComponents(), this->getPrice(), receiptID);
// }

// Receipt *Order::generateReceipt()
// {
//     return new Receipt(receiptID, this->getPrice(), this->generateInfo());
// }

std::string Order::getReceiptID() const
{
    return receiptID;
}

std::string Order::generateInfo()
{
    std::string info = "";

    if (!plantGroup)
        return info;

    for (size_t i = 0; i < plantGroup->getPlantComponents().size(); ++i)
    {
        auto p = plantGroup->getPlantComponents()[i];
        if (!p)
            continue;
        info += p->getName();
        info += " : R";
        info += std::to_string(p->getPrice());
        if (i + 1 < plantGroup->getPlantComponents().size())
            info += "\n";
    }
    return info;
}

double Order::getPrice()
{
    if (priceStrategy)
    {
        return priceStrategy->applyPriceStrategy(plantGroup->getPrice());
    }
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
    plantGroup->add(plant);
}

void Order::setPriceStrategy(PriceStrategies *priceStrategy)
{
    if (this->priceStrategy)
    {
        delete this->priceStrategy;
    }
    this->priceStrategy = priceStrategy;
}

double Order::applyPriceStrategy()
{
    if (!priceStrategy)
    {
        return plantGroup->getPrice();
    }

    return priceStrategy->applyPriceStrategy(plantGroup->getPrice());
}
