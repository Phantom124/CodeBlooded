#ifndef CUSTOMERINTERFACE_H
#define CUSTOMERINTERFACE_H
#include "GreenHouseInventory.h"
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
class CustomerInterface {
    private:
        GreenHouseInventory* inventory;
        Customer* customer;
        Caretaker* caretaker;
    public:
        CustomerInterface();//TO BE IMPLEMENTED
        virtual ~CustomerInterface();

        void startInterface();
        void browsePlants();
        void purchasePlant();
        void makeReturn();
};
#endif // CUSTOMERINTERFACE_H