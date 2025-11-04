/**
 * @file Caretaker.h
 * @brief Caretaker that manages OrderMemento objects for order restoration and returns.
 *
 * The Caretaker stores mementos (snapshots) of orders keyed by receipt ID. When a return
 * is processed, the Caretaker can look up the saved state and restore plants to the inventory.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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

/**
 * @brief Execute the function's primary operation.
 * @param receiptID The receiptID parameter used by the function.
 * @param memento The memento parameter used by the function.
 */
         void addMemento(const std::string& receiptID, const OrderMemento& memento);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param receiptID The receiptID parameter used by the function.
 */
         OrderMemento* getMemento(const std::string& receiptID) const;

/**
 * @brief Execute the function's primary operation.
 * @param receiptID The receiptID parameter used by the function.
 */
         void removeMemento(const std::string& receiptID);
/**
 * @brief Restore plants from a saved memento back into the greenhouse inventory.
 * @param receipt The receipt representing the returned order (used to locate the memento).
 * @param inventory The GreenHouseInventory to which plants should be restored.
 */

         void restoreOrder(Receipt& receipt, GreenHouseInventory& inventory);
};

#endif
