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
        StaffHandler* createHandlerInstance(HandlerType type);
        void rebuildHandlerChain();
        void destroyHandlers();
        std::string handlerTypeToString(HandlerType type) const;
        void markHandlersBusyForCommands(const std::vector<Command*>& commands);
        HandlerType commandTypeToHandler(cmdType type) const;
        void resetHandlerStatuses();
        void ensurePlantTracked(Plant* plant);
        void purgePlantFromCache(const std::string& plantID);

    public:
        GreenHouseFacade(ProxyGreenHouseInventory* sharedInventory, StaffSystem* sharedStaffSystem);
        ~GreenHouseFacade();
        
        // Plant creation and management
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
        bool addHandlerOfType(const std::string& handlerName);
        bool removeHandlerAtIndex(int index);
        void refreshHandlerAvailability();
        
        int getQueueSize();
        std::vector<Command*> getQueuedCommands();
        StaffSystem* getStaffSystem();
};

#endif