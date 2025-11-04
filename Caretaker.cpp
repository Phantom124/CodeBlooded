#include "Caretaker.h"
#include "SharedInventory.h"
Caretaker::~Caretaker()
{
    for (auto &pair : mementos)
    {
        delete pair.second;
    }
}

void Caretaker::addMemento(const std::string &receiptID, const OrderMemento &memento)
{
    mementos[receiptID] = new OrderMemento(memento);
}

OrderMemento *Caretaker::getMemento(const std::string &receiptID) const
{
    auto it = mementos.find(receiptID);
    if (it != mementos.end())
    {
        return it->second;
    }
    return nullptr;
}

void Caretaker::removeMemento(const std::string &receiptID)
{
    auto it = mementos.find(receiptID);
    if (it != mementos.end())
    {

        std::cout << "Processing return for Receipt ID: " << receiptID << ", Order Price: " << it->second->getOrderPrice() << std::endl;
        std::vector<PlantSnapshot *> snapshots = it->second->getPlants();
        for (const auto &snap : snapshots)
        {
            std::cout << "returning " << snap->convertToPlant()->getName() << std::endl;
            g_inventory->insertPlant(snap->convertToPlant());
            
        }
        delete it->second;
        mementos.erase(it);
    }
}

void Caretaker::restoreOrder(Receipt &receipt, GreenHouseInventory &inventory)
{
    OrderMemento *memento = getMemento(receipt.getReceiptID());
    if (!memento)
        return;

    if (receipt.getIsValid())
    {
        auto snapshots = memento->getPlants(); // std::vector<PlantSnapshot*>
        std::vector<PlantComponent *> components;
        components.reserve(snapshots.size());

        for (PlantSnapshot *snap : snapshots)
        {
            if (!snap)
                continue;
            // convertToPlant() should return a Plant* (allocated or transferred ownership)
            Plant *p = snap->convertToPlant();
            if (p)
                components.push_back(static_cast<PlantComponent *>(p));
        }

        inventory.restorePlants(components);
        // NOTE: ensure restorePlants takes ownership of the Plant/PlantComponent pointers
        // otherwise you'll leak the converted Plant objects.
    }

    removeMemento(receipt.getReceiptID());
}