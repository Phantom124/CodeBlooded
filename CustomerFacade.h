/**
 * @file CustomerFacade.h
 * @brief CustomerFacade.h — Header and declarations for the CustomerFacade.h component.
 * @author Ange Yehouessi
 * @date 2025-11-04
 */

#ifndef CUSTOMERFACADE_H
#define CUSTOMERFACADE_H

#include "ProxyGreenHouseInventory.h"
#include "Caretaker.h"
#include "Order.h"
#include "Customer.h"
#include "PlantComponent.h"
#include "PlantDecorator.h"
#include "Receipt.h"
#include "Plant.h"
#include "PlantGroup.h"
#include "NormalPrice.h"
#include "Save10Discount.h"
#include "BulkDiscount.h"
#include "PriceStrategies.h"
#include <string>
#include <vector>
#include <unordered_set>

class CustomerFacade
{
private:
    ProxyGreenHouseInventory *inventory;
    Caretaker *caretaker;
    Order *currentOrder;
    Customer *customer;
    bool discountApplied;
    std::string discountCode;

public:
    enum class DecorationType
    {
        RedPot,
        Ribbon,
        Scent,
        GiftWrap
    };

    struct CartEntry
    {
        Plant *plant;
        std::vector<DecorationType> decorations;
    };

/**
 * @brief Execute the function's primary operation.
 * @param *sharedInventory 
 * @param *sharedCaretaker 
 */

    CustomerFacade(ProxyGreenHouseInventory *sharedInventory, Caretaker *sharedCaretaker);
    ~CustomerFacade();

    // Order management
    void createNewOrder();
/**
 * @brief Execute the function's primary operation.
 * @param *plant 
 */

    void addPlantToOrder(Plant *plant, const std::vector<DecorationType> &decorations = {});
/**
 * @brief Execute the function's primary operation.
 * @param *component 
 */

    void removeFromOrder(PlantComponent *component);
    void clearOrder();
    double getOrderTotal();
    double getSubtotal() const;
    std::vector<PlantComponent *> getOrderItems();
    int getOrderItemCount();
    std::vector<CartEntry> getCartEntries() const;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param &entry 
 */

    double getEntryTotal(const CartEntry &entry) const;


    double getEntryDecorationsTotal(const CartEntry &entry) const;

    // Decoration management
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param *component 
 */

    PlantComponent *applyRedPot(PlantComponent *component);


    PlantComponent *applyRibbon(PlantComponent *component);


    PlantComponent *applyScent(PlantComponent *component);


    PlantComponent *applyGiftWrap(PlantComponent *component);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param type The type parameter used by the function.
 */

    static std::string decorationName(DecorationType type);


    static double decorationPrice(DecorationType type);

    // Discount management
/**
 * @brief Execute the function's primary operation.
 * @param apply The apply parameter used by the function.
 */

    void applyDiscount(bool apply, const std::string &code = "");
    bool isDiscountApplied() const;
    bool hasManualDiscount() const;
    bool hasAutomaticDiscount() const;
    double getDiscountRate() const;
    std::string getDiscountCode() const;

    // Checkout
    Receipt *checkout();

    // Returns
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param &receiptID 
 */

    OrderMemento *searchOrder(const std::string &receiptID);
/**
 * @brief Execute the function's primary operation.
 * @param &receiptID 
 */

    void returnOrder(const std::string &receiptID);

    // Inventory browsing
    std::vector<Plant *> browsePlants();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param &type
 * @param &maturity
 */

    std::vector<Plant *> searchPlants(const std::string &type, const std::string &maturity);

    // Customer management
/**
 * @brief Execute the function's primary operation.
 * @param *customer 
 */

    void setCustomer(Customer *customer);
    Customer *getCustomer() const;

private:
    // GUI helpers
    std::vector<CartEntry> cartEntries;
    std::unordered_set<int> reservedPlantIds;
    std::vector<Plant *> purchasedPlants;


    double calculateEntryDecorationsTotal(const CartEntry &entry) const;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param &plants 
 */

    std::vector<Plant *> filterVisiblePlants(const std::vector<Plant *> &plants) const;
};

#endif
