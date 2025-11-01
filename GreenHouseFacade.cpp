#include "GreenHouseFacade.h"
#include "QueueIterator.h"
#include "Common/SharedInstances.h"

#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

namespace
{
std::string toLower(const std::string& value)
{
    std::string out = value;
    std::transform(out.begin(), out.end(), out.begin(), [](unsigned char ch) { return static_cast<char>(std::tolower(ch)); });
    return out;
}
}

GreenHouseFacade::GreenHouseFacade(ProxyGreenHouseInventory* sharedInventory, StaffSystem* sharedStaffSystem)
    : inventory(sharedInventory)
    , staffSystem(sharedStaffSystem)
    , waterMonitor(nullptr)
    , fertilizerMonitor(nullptr)
    , deadMonitor(nullptr)
    , roseFactory(nullptr)
    , sunflowerFactory(nullptr)
    , cactusFactory(nullptr)
    , handlerChain(nullptr)
{
    waterMonitor = new WaterMonitor();
    fertilizerMonitor = new FertilizerMonitor();
    deadMonitor = new DeadMonitor();

    // Connect monitors to staff system
    waterMonitor->setStaffSystem(staffSystem);
    fertilizerMonitor->setStaffSystem(staffSystem);
    deadMonitor->setStaffSystem(staffSystem);

    roseFactory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
    sunflowerFactory = new SunflowerFactory(waterMonitor, fertilizerMonitor, deadMonitor);
    cactusFactory = new CactusFactory(waterMonitor, fertilizerMonitor, deadMonitor);

    if (inventory)
    {
        const std::vector<Plant*> existing = inventory->getPlants();
        managedPlants.insert(managedPlants.end(), existing.begin(), existing.end());
    }

    setupHandlerChain();
}

GreenHouseFacade::~GreenHouseFacade()
{
    destroyHandlers();
    delete roseFactory;
    delete sunflowerFactory;
    delete cactusFactory;
    delete waterMonitor;
    delete fertilizerMonitor;
    delete deadMonitor;
}

Plant* GreenHouseFacade::createPlant(const std::string& plantType)
{
    Plant* plant = nullptr;

    if (plantType == "Rose")
    {
        plant = roseFactory->createPlant();
    }
    else if (plantType == "Sunflower")
    {
        plant = sunflowerFactory->createPlant();
    }
    else if (plantType == "Cactus")
    {
        plant = cactusFactory->createPlant();
    }

    ensurePlantTracked(plant);
    return plant;
}

void GreenHouseFacade::addPlantToInventory(Plant* plant)
{
    if (!inventory || !plant) return;

    inventory->addPlant(plant);
    ensurePlantTracked(plant);
}

void GreenHouseFacade::removePlantFromInventory(const std::string& plantID)
{
    if (!inventory) return;

    inventory->removePlant(plantID);
    purgePlantFromCache(plantID);
}

std::vector<Plant*> GreenHouseFacade::getAllPlants()
{
    return managedPlants;
}

void GreenHouseFacade::simulateHourPassed()
{
    for (Plant* plant : managedPlants)
    {
        if (plant)
        {
            plant->hoursHasPassed();
        }
    }

    resetHandlerStatuses();

    if (staffSystem)
    {
        staffSystem->timeElapsed();
    }
}

void GreenHouseFacade::processCommandQueue()
{
    if (!staffSystem || !handlerChain)
    {
        return;
    }

    std::vector<Command*> queued = getQueuedCommands();
    if (queued.empty())
    {
        return;
    }

    QueueIterator iterator = staffSystem->createIterator();
    iterator.emptyQueue(handlerChain);

    markHandlersBusyForCommands(queued);

    staffSystem->timeElapsed();
}

void GreenHouseFacade::setupHandlerChain()
{
    destroyHandlers();
    handlerRegistry.clear();

    handlerRegistry.push_back({ HandlerType::Water, createHandlerInstance(HandlerType::Water), false });
    handlerRegistry.push_back({ HandlerType::Fertilizer, createHandlerInstance(HandlerType::Fertilizer), false });
    handlerRegistry.push_back({ HandlerType::Dead, createHandlerInstance(HandlerType::Dead), false });
    handlerRegistry.push_back({ HandlerType::Sales, createHandlerInstance(HandlerType::Sales), false });

    rebuildHandlerChain();
}

StaffHandler* GreenHouseFacade::getHandlerChain()
{
    return handlerChain;
}

std::vector<std::pair<std::string, bool>> GreenHouseFacade::getHandlerSnapshot() const
{
    std::vector<std::pair<std::string, bool>> snapshot;
    snapshot.reserve(handlerRegistry.size());

    for (const HandlerRecord& record : handlerRegistry)
    {
        snapshot.emplace_back(handlerTypeToString(record.type), record.busy);
    }

    return snapshot;
}

bool GreenHouseFacade::addHandlerOfType(const std::string& handlerName)
{
    const std::string key = toLower(handlerName);

    HandlerType type;
    if (key == "water" || key == "waterhandler" || key == "water handler")
    {
        type = HandlerType::Water;
    }
    else if (key == "fertilizer" || key == "fertilizerhandler" || key == "fertilizer handler")
    {
        type = HandlerType::Fertilizer;
    }
    else if (key == "dead" || key == "deadhandler" || key == "dead handler")
    {
        type = HandlerType::Dead;
    }
    else if (key == "sales" || key == "saleshandler" || key == "sales handler")
    {
        type = HandlerType::Sales;
    }
    else
    {
        return false;
    }

    StaffHandler* newHandler = createHandlerInstance(type);
    if (!newHandler)
    {
        return false;
    }

    handlerRegistry.push_back({ type, newHandler, false });
    rebuildHandlerChain();
    return true;
}

bool GreenHouseFacade::removeHandlerAtIndex(int index)
{
    if (index < 0 || static_cast<std::size_t>(index) >= handlerRegistry.size())
    {
        return false;
    }

    HandlerRecord removed = handlerRegistry[static_cast<std::size_t>(index)];
    handlerRegistry.erase(handlerRegistry.begin() + index);
    delete removed.handler;

    rebuildHandlerChain();
    return true;
}

void GreenHouseFacade::refreshHandlerAvailability()
{
    resetHandlerStatuses();

    if (staffSystem)
    {
        staffSystem->timeElapsed();
    }
}

int GreenHouseFacade::getQueueSize()
{
    return static_cast<int>(getQueuedCommands().size());
}

std::vector<Command*> GreenHouseFacade::getQueuedCommands()
{
    std::vector<Command*> commands;

    if (!staffSystem)
    {
        return commands;
    }

    QueueIterator iterator = staffSystem->createIterator();
    std::vector<Command*> requeueBuffer;

    while (!iterator.isEmpty())
    {
        Command* cmd = iterator.dequeue();
        if (cmd)
        {
            commands.push_back(cmd);
            requeueBuffer.push_back(cmd);
        }
    }

    for (Command* cmd : requeueBuffer)
    {
        iterator.enqueue(cmd);
    }

    return commands;
}

StaffSystem* GreenHouseFacade::getStaffSystem()
{
    return staffSystem;
}

StaffHandler* GreenHouseFacade::createHandlerInstance(HandlerType type)
{
    switch (type)
    {
        case HandlerType::Water:
            return new WaterHandler();
        case HandlerType::Fertilizer:
            return new FertilizerHandler();
        case HandlerType::Dead:
            return new DeadHandler();
        case HandlerType::Sales:
            return new SalesHandler();
    }
    return nullptr;
}

void GreenHouseFacade::rebuildHandlerChain()
{
    if (!staffSystem)
    {
        return;
    }

    // Collect pending commands from the current system
    std::vector<Command*> pendingCommands;
    {
        QueueIterator iterator = staffSystem->createIterator();
        while (!iterator.isEmpty())
        {
            Command* cmd = iterator.dequeue();
            if (cmd)
            {
                pendingCommands.push_back(cmd);
            }
        }
    }

    StaffSystem* oldSystem = staffSystem;
    staffSystem = new StaffSystem();

    for (HandlerRecord& record : handlerRegistry)
    {
        record.handler->setSuccessor(nullptr);
        record.handler->resetAvailable();
        record.busy = false;
    }

    for (auto it = handlerRegistry.rbegin(); it != handlerRegistry.rend(); ++it)
    {
        staffSystem->addHandler(it->handler);
    }

    handlerChain = handlerRegistry.empty() ? nullptr : handlerRegistry.front().handler;

    QueueIterator newIterator = staffSystem->createIterator();
    for (Command* cmd : pendingCommands)
    {
        newIterator.enqueue(cmd);
    }

    waterMonitor->setStaffSystem(staffSystem);
    fertilizerMonitor->setStaffSystem(staffSystem);
    deadMonitor->setStaffSystem(staffSystem);

    g_sharedStaffSystem = staffSystem;

    delete oldSystem;
}

void GreenHouseFacade::destroyHandlers()
{
    for (HandlerRecord& record : handlerRegistry)
    {
        delete record.handler;
        record.handler = nullptr;
    }
    handlerRegistry.clear();
    handlerChain = nullptr;
}

std::string GreenHouseFacade::handlerTypeToString(HandlerType type) const
{
    switch (type)
    {
        case HandlerType::Water:
            return "Water Handler";
        case HandlerType::Fertilizer:
            return "Fertilizer Handler";
        case HandlerType::Dead:
            return "Dead Handler";
        case HandlerType::Sales:
            return "Sales Handler";
    }
    return "Handler";
}

void GreenHouseFacade::markHandlersBusyForCommands(const std::vector<Command*>& commands)
{
    if (commands.empty())
    {
        return;
    }

    resetHandlerStatuses();

    for (Command* cmd : commands)
    {
        if (!cmd)
        {
            continue;
        }

        HandlerType handlerType = commandTypeToHandler(cmd->getType());

        for (HandlerRecord& record : handlerRegistry)
        {
            if (record.type == handlerType)
            {
                record.busy = true;
                break;
            }
        }
    }
}

GreenHouseFacade::HandlerType GreenHouseFacade::commandTypeToHandler(cmdType type) const
{
    switch (type)
    {
        case WATER:
            return HandlerType::Water;
        case FERTILIZER:
            return HandlerType::Fertilizer;
        case DEAD:
            return HandlerType::Dead;
        case GET_PLANT:
            return HandlerType::Sales;
    }
    return HandlerType::Water;
}

void GreenHouseFacade::resetHandlerStatuses()
{
    for (HandlerRecord& record : handlerRegistry)
    {
        record.busy = false;
    }
}

void GreenHouseFacade::ensurePlantTracked(Plant* plant)
{
    if (!plant)
    {
        return;
    }

    auto it = std::find(managedPlants.begin(), managedPlants.end(), plant);
    if (it == managedPlants.end())
    {
        managedPlants.push_back(plant);
    }
}

void GreenHouseFacade::purgePlantFromCache(const std::string& plantID)
{
    if (plantID.empty())
    {
        return;
    }

    managedPlants.erase(
        std::remove_if(
            managedPlants.begin(),
            managedPlants.end(),
            [&plantID](Plant* plant)
            {
                return plant && std::to_string(plant->getPlantId()) == plantID;
            }),
        managedPlants.end());
}
