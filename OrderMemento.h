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
        OrderMemento(const std::vector<PlantComponent*>& plants, double price, const std::string& receiptID);
        OrderMemento(const OrderMemento& other);
        OrderMemento& operator=(const OrderMemento& other);
        ~OrderMemento();
        std::vector<PlantSnapshot*> getPlants() const;
        double getOrderPrice() const;
        std::chrono::system_clock::time_point getOrderDate() const;
        std::string getReceiptID() const;
        std::vector<PlantSnapshot*> createSnapshots(const std::vector<PlantComponent*>& plants); 
};

#endif