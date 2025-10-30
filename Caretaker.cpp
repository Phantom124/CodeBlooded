#include "Caretaker.h"

Caretaker::~Caretaker() {
    for (auto& pair : mementos) {
        delete pair.second;
    }
}

void Caretaker::addMemento(const std::string& receiptID, const OrderMemento& memento) {
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
        auto snapshots = memento->getPlants();
        std::vector<PlantComponent*> components;
        components.reserve(snapshots.size());
        for (PlantSnapshot* ps : snapshots) {
            PlantComponent* pc = dynamic_cast<PlantComponent*>(ps);
            if (pc) {
                components.push_back(pc);
            } else {
                // conversion failed: skip or log as appropriate
            }
        }
        inventory.restorePlants(components);
    }

    removeMemento(receipt.getReceiptID());
}