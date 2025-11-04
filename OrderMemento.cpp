/**
 * @file OrderMemento.cpp
 * @brief OrderMemento.cpp — Header and declarations for the OrderMemento.cpp component.
 * @author Ange Yehouessi
 * @date 2025-11-04
 */

#include "OrderMemento.h"
#include <chrono>

OrderMemento::OrderMemento(const std::vector<PlantComponent*>& plants, double price, const std::string& receiptID) 
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param price
 * @param receiptID
 */

    : orderPrice(price), receiptID(receiptID) {
    orderDate = std::chrono::system_clock::now();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plants The plants parameter used by the function.
 */

    plantSnapshots = createSnapshots(plants);
}

OrderMemento::OrderMemento(const OrderMemento& other)
    : orderPrice(other.orderPrice)
    , orderDate(other.orderDate)
    , receiptID(other.receiptID)
{
/**
 * @brief Execute the function's primary operation.
 * @param other.plantSnapshots.size()
 */

    plantSnapshots.reserve(other.plantSnapshots.size());
    for (PlantSnapshot* snapshot : other.plantSnapshots){
        if (snapshot != nullptr){
/**
 * @brief Execute the function's primary operation.
 * @param PlantSnapshot(*snapshot) 
 */

            plantSnapshots.push_back(new PlantSnapshot(*snapshot));  // deep copy to own snapshot data
        }
    }
}

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param other The other parameter used by the function.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param plants.size() 
 */

    snapshots.reserve(plants.size());
    for (auto plantComponent : plants) {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantComponent The plantComponent parameter used by the function.
 */

        Plant* plant = dynamic_cast<Plant*>(plantComponent);
        if (plant) {
/**
 * @brief Execute the function's primary operation.
 * @param PlantSnapshot(plant) 
 */

            snapshots.push_back(new PlantSnapshot(plant));
        }
    }
    return snapshots;
}
