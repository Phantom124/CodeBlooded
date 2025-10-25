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
        Caretaker();
        ~Caretaker();
        void addMemento(std::string receiptID, const OrderMemento& memento);
        OrderMemento* getMemento(std::string receiptID) const;
        void removeMemento(std::string receiptID);
        void restoreOrder(Receipt& receipt, RealGreenHouseInventory& inventory);
};

#endif