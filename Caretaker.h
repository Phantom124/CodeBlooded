#ifndef CARETAKER_H
#define CARETAKER_H

#include "OrderMemento.h"
#include "GreenHouseInventory.h"
#include "Receipt.h"
#include <map>
#include <string>

class Caretaker{
    private:
        std::map<std::string, OrderMemento*> mementos;

    public:
        Caretaker() = default;
        ~Caretaker();
        void addMemento(const std::string& receiptID, const OrderMemento& memento);
        OrderMemento* getMemento(const std::string& receiptID) const;
        void removeMemento(const std::string& receiptID);
        void restoreOrder(Receipt& receipt, GreenHouseInventory& inventory);
};

#endif