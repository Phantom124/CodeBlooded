/**
 * @file GreenHouseFacade.h
 * @brief GreenHouseFacade.h — Header and declarations for the GreenHouseFacade.h component.
 * @author Ange Yehouessi
 * @date 2025-11-04
 */

#ifndef GREENHOUSEFACADE_H
#define GREENHOUSEFACADE_H

#include "ProxyGreenHouseInventory.h"
#include "PlantFactory.h"
#include "RoseFactory.h"
#include "SunflowerFactory.h"
#include "CactusFactory.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "StaffSystem.h"
#include "StaffHandler.h"
#include "WaterHandler.h"
#include "FertilizerHandler.h"
#include "DeadHandler.h"
#include "SalesHandler.h"
#include "Plant.h"
#include "Command.h"
#include <string>
#include <vector>
#include <utility>

class GreenHouseFacade {
    private:
        enum class HandlerType {
            Water,
            Fertilizer,
            Dead,
            Sales
        };

        struct HandlerRecord {
            HandlerType type;
            StaffHandler* handler;
            bool busy;
        };

        ProxyGreenHouseInventory* inventory;
        StaffSystem* staffSystem;
        WaterMonitor* waterMonitor;
        FertilizerMonitor* fertilizerMonitor;
        DeadMonitor* deadMonitor;
        RoseFactory* roseFactory;
        SunflowerFactory* sunflowerFactory;
        CactusFactory* cactusFactory;
        StaffHandler* handlerChain;
        std::vector<HandlerRecord> handlerRegistry;
        std::vector<Plant*> managedPlants;

        // Helper functions
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param type The type parameter used by the function.
 */

        StaffHandler* createHandlerInstance(HandlerType type);
        void rebuildHandlerChain();
        void destroyHandlers();


        std::string handlerTypeToString(HandlerType type) const;
/**
 * @brief Execute the function's primary operation.
 * @param commands The commands parameter used by the function.
 */

        void markHandlersBusyForCommands(const std::vector<Command*>& commands);


        HandlerType commandTypeToHandler(cmdType type) const;
        void resetHandlerStatuses();
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

        void ensurePlantTracked(Plant* plant);
/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 */

        void purgePlantFromCache(const std::string& plantID);

    public:
/**
 * @brief Execute the function's primary operation.
 * @param sharedInventory The sharedInventory parameter used by the function.
 * @param sharedStaffSystem The sharedStaffSystem parameter used by the function.
 */

        GreenHouseFacade(ProxyGreenHouseInventory* sharedInventory, StaffSystem* sharedStaffSystem);
        ~GreenHouseFacade();
        
        // Plant creation and management
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plantType The plantType parameter used by the function.
 */

        Plant* createPlant(const std::string& plantType);


        void addPlantToInventory(Plant* plant);


        void removePlantFromInventory(const std::string& plantID);
        std::vector<Plant*> getAllPlants();
        
        // Time simulation
        void simulateHourPassed();
        void processCommandQueue();
        
        // Handler chain management
        void setupHandlerChain();
        StaffHandler* getHandlerChain();
        std::vector<std::pair<std::string, bool>> getHandlerSnapshot() const;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param handlerName The handlerName parameter used by the function.
 */

        bool addHandlerOfType(const std::string& handlerName);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param index The index parameter used by the function.
 */

        bool removeHandlerAtIndex(int index);
        void refreshHandlerAvailability();
        
        int getQueueSize();
        std::vector<Command*> getQueuedCommands();
        StaffSystem* getStaffSystem();
};

#endif
