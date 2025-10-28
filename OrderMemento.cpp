#include "OrderMemento.h"

OrderMemento::OrderMemento(const std::vector<PlantComponent*>& plants, double price, const std::string& receiptID) 
    : orderPrice(price), receiptID(receiptID) {
    orderDate = std::chrono::system_clock::now();
    plantSnapshots = createSnapshots(plants);
}

std::vector<PlantSnapshot*> OrderMemento::getPlants() const {
    return plantSnapshots;
}

double OrderMemento::getOrderPrice() const {
    return orderPrice;
}

std::chrono::system_clock::time_point OrderMemento::getOrderDate() const {
    return orderDate;
}

std::string OrderMemento::getReceiptID() const {
    return receiptID;
}

std::vector<PlantSnapshot*> OrderMemento::createSnapshots(const std::vector<PlantComponent*>& plants) {
    std::vector<PlantSnapshot*> snapshots;
    for (auto plantComponent : plants) {
        Plant* plant = dynamic_cast<Plant*>(plantComponent);
        if (plant) {
            snapshots.push_back(new PlantSnapshot(plant));
        }
    }
    return snapshots;
}