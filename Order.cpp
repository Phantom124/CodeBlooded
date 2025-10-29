#include "Order.h"
#include "OrderMemento.h"
#include "Receipt.h"
#include "DiscountPrice.h"
#include "NormalPrice.h"
#include <iostream>

Order::Order(PlantGroup *plantGroup) : plantGroup(plantGroup) {
    static unsigned long long counter = 0;
    receiptID = "RCPT-" + std::to_string(++counter);
}

OrderMemento* Order::createMemento(){
    return new OrderMemento(plantGroup->getPlantComponents(), this->getPrice(), receiptID);
}

Receipt* Order::generateReceipt(){
    return new Receipt(receiptID, this->getPrice(), this->generateInfo());
}

std::string Order::getReceiptID() const{
    return receiptID;
}

std::string Order::generateInfo(){
    std::string info = "";

    if (!plantGroup) return info;

    for (size_t i = 0; i < plantGroup->getPlantComponents().size(); ++i) {
        auto p = plantGroup->getPlantComponents()[i];
        if (!p) continue;
        info += p->getName();
        info += " : R";
        info += std::to_string(p->getPrice());
        if (i + 1 < plantGroup->getPlantComponents().size()) info += "\n";
    }
    return info;
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
