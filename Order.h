/**
 * @file Order.h
 * @brief Order.h — Header and declarations for the Order.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param *plant
 */

    void addToOrder(Plant *plant);
/**
 * @brief Execute the function's primary operation.
 * @param *priceStrategy 
 */

    void setPriceStrategy(PriceStrategies *priceStrategy);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param code The code parameter used by the function.
 */

    double applyPriceStrategy(std::string code);
/**
 * @brief Execute the function's primary operation.
 * @param *plantComponent 
 */

    void removeFromOrder(PlantComponent *plantComponent);
    int quantity();
    OrderMemento *createMemento();
    Receipt *generateReceipt();
    std::string getReceiptID() const;
    std::string generateInfo();
};

#endif
