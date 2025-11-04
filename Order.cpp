/**
 * @file Order.cpp
 * @brief Order.cpp — Header and declarations for the Order.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Order.h"
#include "Receipt.h"
#include "NormalPrice.h"
#include "BulkDiscount.h"
#include "Save10Discount.h"
#include <iostream>
#include <map>

Order::Order()
{
    priceStrategy = new NormalPrice();
    static unsigned long long counter = 0;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param ++counter 
 */

    receiptID = "RCPT-" + std::to_string(++counter);
    plantGroup = new PlantGroup();
}

Order::~Order()
{

    delete priceStrategy;
    priceStrategy = nullptr;

    if (plantGroup)
    {
        delete plantGroup;
    }
}

OrderMemento *Order::createMemento()
{
    return new OrderMemento(plantGroup->getPlantComponents(), this->getPrice(), receiptID);
}

Receipt *Order::generateReceipt()
{
    return new Receipt(receiptID, this->getPrice(), this->generateInfo());
}

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param p->getPrice() 
 */

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

std::vector<PlantComponent *> Order::getOrderPlants()
{

    if (plantGroup)
    {
        return plantGroup->getPlants();
    }

    return std::vector<PlantComponent *>();
}

void Order::addToOrder(Plant *plant)
{
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

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

double Order::applyPriceStrategy(std::string code)
{
    if (!priceStrategy)
    {
        return plantGroup->getPrice();
    }

    if (code == "BULK")
    {
/**
 * @brief Execute the function's primary operation.
 * @param BulkDiscount() 
 */

        setPriceStrategy(new BulkDiscount());
    }
    else if (code == "SAVE10")
    {
/**
 * @brief Execute the function's primary operation.
 * @param Save10Discount() 
 */

        setPriceStrategy(new Save10Discount());
    }
    else
    {
/**
 * @brief Execute the function's primary operation.
 * @param NormalPrice() 
 */

        setPriceStrategy(new NormalPrice());
    }
    return priceStrategy->applyPriceStrategy(plantGroup->getPrice());
}

void Order::removeFromOrder(PlantComponent *plantComponent)
{
/**
 * @brief Execute the function's primary operation.
 * @param plantComponent The plantComponent parameter used by the function.
 */

    plantGroup->removePlantComponent(plantComponent);
}

int Order::quantity()
{
    std::vector<PlantComponent *> plants = plantGroup->getPlants();
    int plantCount = 0;
    for (std::vector<PlantComponent *>::iterator it = plants.begin(); it != plants.end(); ++it)
    {
        plantCount++;
    }

    return plantCount;
}
