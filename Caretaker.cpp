/**
 * @file Caretaker.cpp
 * @brief Caretaker.cpp — Header and declarations for the Caretaker.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "Caretaker.h"

Caretaker::~Caretaker() {
    for (auto& pair : mementos) {
        delete pair.second;
    }
}

/**
 * @brief Execute the function's primary operation.
 * @param receiptID The receiptID parameter used by the function.
 * @param memento The memento parameter used by the function.
 */

void Caretaker::addMemento(const std::string& receiptID, const OrderMemento& memento) {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param receiptID The receiptID parameter used by the function.
 */
    auto it = mementos.find(receiptID);
    if (it != mementos.end()){
        delete it->second;  
        it->second = nullptr;
    }

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param memento The memento parameter used by the function.
 */
    mementos[receiptID] = new OrderMemento(memento);
}

OrderMemento* Caretaker::getMemento(const std::string& receiptID) const {

    auto it = mementos.find(receiptID);
    if (it != mementos.end()) {
        return it->second;
    }
    return nullptr;
}

/**
 * @brief Execute the function's primary operation.
 * @param receiptID The receiptID parameter used by the function.
 */
void Caretaker::removeMemento(const std::string& receiptID) {

    auto it = mementos.find(receiptID);
    if (it != mementos.end()) {
        delete it->second;
/**
 * @brief Execute the function's primary operation.
 * @param it The it parameter used by the function.
 */
        mementos.erase(it);
    }
}

/**
 * @brief Execute the function's primary operation.
 * @param receipt The receipt parameter used by the function.
 * @param inventory The inventory parameter used by the function.
 */

void Caretaker::restoreOrder(Receipt& receipt, GreenHouseInventory& inventory) {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param receipt.getReceiptID()
 */
    OrderMemento* memento = getMemento(receipt.getReceiptID());
    if (!memento) return;

    if (receipt.getIsValid()) {
        auto snapshots = memento->getPlants(); // std::vector<PlantSnapshot*>
        std::vector<PlantComponent*> components;
/**
 * @brief Execute the function's primary operation.
 * @param snapshots.size() 
 */
        components.reserve(snapshots.size());

        for (PlantSnapshot* snap : snapshots) {
            if (!snap) continue;
            // convertToPlant() should return a Plant* (allocated or transferred ownership)
            Plant* p = snap->convertToPlant();
            if (p) components.push_back(static_cast<PlantComponent*>(p));
        }


/**
 * @brief Execute the function's primary operation.
 * @param components The components parameter used by the function.
 */
        inventory.restorePlants(components);
        // NOTE: ensure restorePlants takes ownership of the Plant/PlantComponent pointers
        // otherwise you'll leak the converted Plant objects.
    }

/**
 * @brief Execute the function's primary operation.
 * @param receipt.getReceiptID()
 */
    removeMemento(receipt.getReceiptID());
}
