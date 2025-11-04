#include "Caretaker.h"

Caretaker::~Caretaker() {
    for (auto& pair : mementos) {
        delete pair.second;
    }
}

void Caretaker::addMemento(const std::string& receiptID, const OrderMemento& memento) {
    auto it = mementos.find(receiptID);
    if (it != mementos.end()){
        delete it->second;  
        it->second = nullptr;
    }

    mementos[receiptID] = new OrderMemento(memento);
}

OrderMemento* Caretaker::getMemento(const std::string& receiptID) const {
    auto it = mementos.find(receiptID);
    if (it != mementos.end()) {
        return it->second;
    }
    return nullptr;
}

void Caretaker::removeMemento(const std::string& receiptID) {
    auto it = mementos.find(receiptID);
    if (it != mementos.end()) {
        delete it->second;
        mementos.erase(it);
    }
}

void Caretaker::restoreOrder(Receipt& receipt, GreenHouseInventory& inventory) {
    OrderMemento* memento = getMemento(receipt.getReceiptID());
    if (!memento) return;

    if (receipt.getIsValid()) {
        auto snapshots = memento->getPlants(); // std::vector<PlantSnapshot*>
        std::vector<PlantComponent*> components;
        components.reserve(snapshots.size());

        for (PlantSnapshot* snap : snapshots) {
            if (!snap) continue;
            // convertToPlant() should return a Plant* (allocated or transferred ownership)
            Plant* p = snap->convertToPlant();
            if (p) components.push_back(static_cast<PlantComponent*>(p));
        }

        inventory.restorePlants(components);
        // NOTE: ensure restorePlants takes ownership of the Plant/PlantComponent pointers
        // otherwise you'll leak the converted Plant objects.
    }

    removeMemento(receipt.getReceiptID());
}