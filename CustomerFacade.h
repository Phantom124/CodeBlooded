#ifndef CUSTOMERFACADE_H
#define CUSTOMERFACADE_H

#include "RealGreenHouseInventory.h"
#include "Caretaker.h"
#include "StaffHandler.h"
#include "Order.h"
#include "Customer.h"
#include "PlantComponent.h"
#include "Receipt.h"
#include <string>

class CustomerFacade {
    private:
        RealGreenHouseInventory* inventory;
        Caretaker* caretaker;
        StaffHandler* staff;
        Order* order;
        Customer* customer;
        
    public:
        CustomerFacade();
        ~CustomerFacade();
        Order* createOrder();
        void addPlantToOrder(std::string plantType);
        PlantComponent* addDecoration(Plant* plant, std::string decorationType);
        Receipt* checkout();
        void cancelOrder();
        void returnOrder(Receipt* receipt);
        void viewPlants();
        void sendCustomerRequest(std::string request);
        void setCustomer(Customer* customer);
        Customer* getCustomer() const;
        void removeCustomer();
};

#endif