#ifndef CUSTOMERINTERFACE_H
#define CUSTOMERINTERFACE_H

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
#include <iostream>
#include <string>
#include "GreenHouseInventory.h"
#include "ProxyGreenHouseInventory.h"
#include "Plant.h"
#include <vector>

#include "StaffHandler.h"
#include "DeadHandler.h"
#include "FertilizerHandler.h"
#include "WaterHandler.h"

#include "StaffSystem.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"

#include "Ribbon.h"
#include "RedPot.h"
#include "Scent.h"
#include "GiftWrap.h"
#include "SharedInventory.h"
class CustomerInterface
{
private:
    ProxyGreenHouseInventory *inventory;
    Caretaker *caretaker;
    Order *currentOrder;
    Customer *customer;
    bool discountApplied;
    std::string discountCode;

public:

    CustomerInterface(GreenHouseInventory*sharedInventory, Caretaker *sharedCaretaker, Customer* customer = nullptr);
    ~CustomerInterface();

    // Order management
    void createNewOrder();
    void addPlantToOrder(PlantComponent *plant);
    double getOrderTotal();
    std::vector<PlantComponent *> getOrderItems();
    int getOrderItemCount();
    void chooseDecorators(PlantComponent* plant);
    void processDiscountCode();




    Receipt *checkout();

    // Returns
    OrderMemento *searchOrder(const std::string &receiptID);
    void returnOrder(const std::string &receiptID);

    // Inventory browsing

    // Customer management
    void setCustomer(Customer *customer);
    Customer *getCustomer() const;

    // GUI functions
    void DisplayPlants();
    void customerMenu();


};

#endif