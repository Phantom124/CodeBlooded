#include "OrderMemento.h"
#include <chrono>

OrderMemento::OrderMemento(const std::vector<PlantComponent*>& plants, double price, const std::string& receiptID) 
    : orderPrice(price), receiptID(receiptID) {
    orderDate = std::chrono::system_clock::now();
    plantSnapshots = createSnapshots(plants);
}

OrderMemento::OrderMemento(const OrderMemento& other)
    : orderPrice(other.orderPrice)
    , orderDate(other.orderDate)
    , receiptID(other.receiptID)
{
    plantSnapshots.reserve(other.plantSnapshots.size());
    for (PlantSnapshot* snapshot : other.plantSnapshots){
        if (snapshot != nullptr){
            plantSnapshots.push_back(new PlantSnapshot(*snapshot));  // deep copy to own snapshot data
        }
    }
}

OrderMemento& OrderMemento::operator=(const OrderMemento& other){
    if (this == &other){
        return *this;
    }

    for (PlantSnapshot* snapshot : plantSnapshots){
        delete snapshot;
    }
    plantSnapshots.clear();

    orderPrice = other.orderPrice;
    orderDate = other.orderDate;
    receiptID = other.receiptID;

    plantSnapshots.reserve(other.plantSnapshots.size());
    for (PlantSnapshot* snapshot : other.plantSnapshots){
        if (snapshot != nullptr){
            plantSnapshots.push_back(new PlantSnapshot(*snapshot));  // deep copy to prevent double free
        }
    }

    return *this;
}

OrderMemento::~OrderMemento(){
    for (PlantSnapshot* snapshot : plantSnapshots){
        delete snapshot;
    }
    plantSnapshots.clear();
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
    snapshots.reserve(plants.size());
    for (auto plantComponent : plants) {
        Plant* plant = dynamic_cast<Plant*>(plantComponent);
        if (plant) {
            snapshots.push_back(new PlantSnapshot(plant));
        }
    }
    return snapshots;
}