#include "OrderMemento.h"
#include <chrono>

OrderMemento::OrderMemento(const std::vector<PlantComponent*>& plants, double price, const std::string& receiptID) 
    : plants(plants), orderPrice(price), receiptID(receiptID) {
    // use std::chrono to get current time
    orderDate = std::chrono::system_clock::now();
}

std::vector<PlantComponent*> OrderMemento::getPlants() const {
    return plants;
}

double OrderMemento::getOrderPrice() const {
    return orderPrice;
}

// return the chrono time_point type declared in the header
std::chrono::system_clock::time_point OrderMemento::getOrderDate() const {
    return orderDate;
}

std::string OrderMemento::getReceiptID() const {
    return receiptID;
}