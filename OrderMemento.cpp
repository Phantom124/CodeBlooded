#include "OrderMemento.h"

OrderMemento::OrderMemento(const std::vector<PlantComponent*>& plants, double price, const std::string& receiptID) 
    : plants(plants), orderPrice(price), receiptID(receiptID) {
    orderDate = date::current_time();
}

std::vector<PlantComponent*> OrderMemento::getPlants() const {
    return plants;
}

double OrderMemento::getOrderPrice() const {
    return orderPrice;
}

date::time OrderMemento::getOrderDate() const {
    return orderDate;
}

std::string OrderMemento::getReceiptID() const {
    return receiptID;
}