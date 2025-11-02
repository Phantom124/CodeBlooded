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
#include "DiscountPrice.h"
#include "PriceStrategies.h"
#include <string>
#include <vector>
#include <unordered_set>

class CustomerFacade {
    private:
        ProxyGreenHouseInventory* inventory;
        Caretaker* caretaker;
        Order* currentOrder;
        PlantGroup* currentPlantGroup;
        Customer* customer;
        bool discountApplied;
        std::string discountCode;

    public:
        enum class DecorationType {
            RedPot,
            Ribbon,
            Scent,
            GiftWrap
        };

        struct CartEntry {
            Plant* plant;
            std::vector<DecorationType> decorations;
        };

        CustomerFacade(ProxyGreenHouseInventory* sharedInventory, Caretaker* sharedCaretaker);
        ~CustomerFacade();
        
        // Order management
        void createNewOrder();
        void addPlantToOrder(Plant* plant, const std::vector<DecorationType>& decorations = {});
        void removeFromOrder(PlantComponent* component);
        void clearOrder();
        double getOrderTotal();
        double getSubtotal() const;
        std::vector<PlantComponent*> getOrderItems();
        int getOrderItemCount();
        std::vector<CartEntry> getCartEntries() const;
        double getEntryTotal(const CartEntry& entry) const;
        double getEntryDecorationsTotal(const CartEntry& entry) const;
        
        // Decoration management
        PlantComponent* applyRedPot(PlantComponent* component);
        PlantComponent* applyRibbon(PlantComponent* component);
        PlantComponent* applyScent(PlantComponent* component);
        PlantComponent* applyGiftWrap(PlantComponent* component);
        static std::string decorationName(DecorationType type);
        static double decorationPrice(DecorationType type);
        
        // Discount management
        void applyDiscount(bool apply, const std::string& code = "");
        bool isDiscountApplied() const;
        bool hasManualDiscount() const;
        bool hasAutomaticDiscount() const;
        double getDiscountRate() const;
        std::string getDiscountCode() const;
        
        // Checkout
        Receipt* checkout();
        
        // Returns
        OrderMemento* searchOrder(const std::string& receiptID);
        void returnOrder(const std::string& receiptID);
        
        // Inventory browsing
        std::vector<Plant*> browsePlants();
        std::vector<Plant*> searchPlants(const std::string& type, const std::string& maturity);
        
        // Customer management
        void setCustomer(Customer* customer);
        Customer* getCustomer() const;

    private:
        // GUI helpers
        std::vector<CartEntry> cartEntries;
        std::unordered_set<int> reservedPlantIds;
        std::vector<Plant*> purchasedPlants;

        double calculateEntryDecorationsTotal(const CartEntry& entry) const;
        std::vector<Plant*> filterVisiblePlants(const std::vector<Plant*>& plants) const;
};

#endif