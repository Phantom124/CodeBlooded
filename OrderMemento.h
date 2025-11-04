/**
 * @file OrderMemento.h
 * @brief OrderMemento.h — Header and declarations for the OrderMemento.h component.
 * @author Ange Yehouessi
 * @date 2025-11-04
 */

#ifndef ORDER_MEMENTO_H
#define ORDER_MEMENTO_H

#include "Order.h"
#include "PlantComponent.h"
#include "PlantSnapshot.h"
#include <chrono>
#include <string>
#include <vector>

class OrderMemento {
    private:
        std::vector<PlantSnapshot*> plantSnapshots;
        double orderPrice;
        std::chrono::system_clock::time_point orderDate;
        std::string receiptID;

    public:
/**
 * @brief Execute the function's primary operation.
 * @param plants The plants parameter used by the function.
 * @param price The price parameter used by the function.
 * @param receiptID The receiptID parameter used by the function.
 */

        OrderMemento(const std::vector<PlantComponent*>& plants, double price, const std::string& receiptID);
/**
 * @brief Execute the function's primary operation.
 * @param other The other parameter used by the function.
 */

        OrderMemento(const OrderMemento& other);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param other The other parameter used by the function.
 */

        OrderMemento& operator=(const OrderMemento& other);
        ~OrderMemento();
        std::vector<PlantSnapshot*> getPlants() const;
        double getOrderPrice() const;
        std::chrono::system_clock::time_point getOrderDate() const;
        std::string getReceiptID() const;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plants The plants parameter used by the function.
 */

        std::vector<PlantSnapshot*> createSnapshots(const std::vector<PlantComponent*>& plants); 
};

#endif
