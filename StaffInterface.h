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