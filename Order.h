#ifndef ORDER_H
#define ORDER_H

#include "PlantGroup.h"
#include "PriceStrategies.h"
#include "OrderMemento.h"
#include "Receipt.h"
#include "Plant.h"
#include <string>

class OrderMemento; // forward declaration

class Order
{
private:
    PlantGroup *plantGroup;
    PriceStrategies *priceStrategy;
    std::string receiptID;

public:
    Order();
    ~Order();
    double getPrice();
    std::string getName();
    void printOrder();
    std::vector<PlantComponent *> getOrderPlants();
    void addToOrder(PlantComponent *plant);
    void setPriceStrategy(PriceStrategies *priceStrategy);
    double applyPriceStrategy(std::string code);
    void removeFromOrder(PlantComponent *plantComponent);
    int quantity();
    OrderMemento *createMemento();
    Receipt *generateReceipt();
    std::string getReceiptID() const;
    std::string generateInfo();
};

#endif
