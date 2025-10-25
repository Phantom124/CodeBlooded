#include "Caretaker.h"

Caretaker::~Caretaker() {
    for (auto& pair : mementos) {
        delete pair.second;
    }
}

void Caretaker::addMemento(std::string receiptID, const OrderMemento& memento) {
    mementos[receiptID] = new OrderMemento(memento);
}

OrderMemento* Caretaker::getMemento(std::string receiptID) const {
    auto it = mementos.find(receiptID);
    if (it != mementos.end()) {
        return it->second;
    }
    return nullptr;
}

void Caretaker::removeMemento(std::string receiptID) {
    auto it = mementos.find(receiptID);
    if (it != mementos.end()) {
        delete it->second;
        mementos.erase(it);
    }
}

void Caretaker::restoreOrder(Receipt& receipt, RealGreenHouseInventory& inventory) {
    OrderMemento* memento = getMemento(receipt.getReceiptID());
    if (!memento) return;

    if (receipt.getIsValid()) {
        auto plants = memento->getPlants();
        inventory.restorePlants(plants);
    }

    removeMemento(receipt.getReceiptID());
}