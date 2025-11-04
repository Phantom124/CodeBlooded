/**
 * @file StaffInterface.h
 * @brief StaffInterface.h — Header and declarations for the StaffInterface.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef STAFFINTERFACE_H
#define STAFFINTERFACE_H

#include "GreenHouseInventory.h"
#include "ProxyGreenHouseInventory.h"
#include "RealGreenHouseInventory.h"
#include "QueryProduct.h"

#include "StaffSystem.h"
#include "StaffHandler.h"
#include "DeadHandler.h"
#include "FertilizerHandler.h"
#include "WaterHandler.h"

#include "DeleteQueryBuilder.h"
#include "QueryBuilder.h"

#include "RoseFactory.h"
#include "SunflowerFactory.h"
#include "CactusFactory.h"

class StaffInterface {
    public:
/**
 * @brief Execute the function's primary operation.
 * @param inventory The inventory parameter used by the function.
 * @param staffSystem The staffSystem parameter used by the function.
 */

        StaffInterface(ProxyGreenHouseInventory* inventory, StaffSystem* staffSystem);
        void startInterface();
        virtual ~StaffInterface();

        void addPlant();
        void addHandler();
        void elapseTime();



    protected:
        GreenHouseInventory* GreenHouse;
        StaffSystem* staffSystem;
        RoseFactory* roseFactory;
        SunflowerFactory* sunflowerFactory;
        CactusFactory* cactusFactory;

};

#endif // STAFFINTERFACE_H
