#include "CustomerFacade.h"
#include "RedPot.h"
#include "Ribbon.h"
#include "Scent.h"
#include "GiftWrap.h"
#include "SelectQueryBuilder.h"
#include "QueryProduct.h"

#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>

CustomerFacade::CustomerFacade(ProxyGreenHouseInventory* sharedInventory, Caretaker* sharedCaretaker)
    : inventory(sharedInventory)
    , caretaker(sharedCaretaker)
    , currentOrder(nullptr)
    , currentPlantGroup(nullptr)
    , customer(nullptr)
    , discountApplied(false)
{
    createNewOrder();
}

CustomerFacade::~CustomerFacade()
{
    delete currentOrder;
    delete currentPlantGroup;
    for (Plant* plant : purchasedPlants)
    {
        delete plant;
    }
}

void CustomerFacade::createNewOrder()
{
    if (currentOrder) delete currentOrder;
    if (currentPlantGroup) delete currentPlantGroup;
    
    currentPlantGroup = new PlantGroup();
    currentOrder = new Order(currentPlantGroup);
    discountApplied = false;
    discountCode.clear();
    cartEntries.clear();
    reservedPlantIds.clear();
}

void CustomerFacade::addPlantToOrder(Plant* plant, const std::vector<DecorationType>& decorations)
{
    if (!currentOrder || !currentPlantGroup || !plant)
    {
        return;
    }

    const int plantId = plant->getPlantId();
    if (reservedPlantIds.find(plantId) != reservedPlantIds.end())
    {
        return;
    }

    currentPlantGroup->add(plant);
    cartEntries.push_back({plant, decorations});
    reservedPlantIds.insert(plantId);
}

void CustomerFacade::removeFromOrder(PlantComponent* component)
{
    if (!currentPlantGroup || !component)
    {
        return;
    }

    currentPlantGroup->removePlantComponent(component);

    Plant* plant = dynamic_cast<Plant*>(component);
    if (!plant)
    {
        return;
    }

    reservedPlantIds.erase(plant->getPlantId());
    cartEntries.erase(
        std::remove_if(
            cartEntries.begin(),
            cartEntries.end(),
            [plant](const CartEntry& entry)
            {
                return entry.plant == plant;
            }),
        cartEntries.end());
}

void CustomerFacade::clearOrder()
{
    createNewOrder();
}

double CustomerFacade::getOrderTotal()
{
    const double subtotal = getSubtotal();
    if (subtotal <= 0.0)
    {
        return 0.0;
    }

    if (getDiscountRate() > 0.0)
    {
        DiscountPrice strategy;
        return strategy.apply(subtotal);
    }

    NormalPrice strategy;
    return strategy.apply(subtotal);
}

double CustomerFacade::getSubtotal() const
{
    double subtotal = 0.0;
    for (const CartEntry& entry : cartEntries)
    {
        if (entry.plant)
        {
            subtotal += entry.plant->getPrice();
        }
        subtotal += calculateEntryDecorationsTotal(entry);
    }
    return subtotal;
}

std::vector<PlantComponent*> CustomerFacade::getOrderItems()
{
    if (currentPlantGroup)
    {
        return currentPlantGroup->getPlantComponents();
    }
    return std::vector<PlantComponent*>();
}

int CustomerFacade::getOrderItemCount()
{
    return static_cast<int>(cartEntries.size());
}

std::vector<CustomerFacade::CartEntry> CustomerFacade::getCartEntries() const
{
    return cartEntries;
}

double CustomerFacade::getEntryTotal(const CartEntry& entry) const
{
    double total = 0.0;
    if (entry.plant)
    {
        total += entry.plant->getPrice();
    }
    total += calculateEntryDecorationsTotal(entry);
    return total;
}

double CustomerFacade::getEntryDecorationsTotal(const CartEntry& entry) const
{
    return calculateEntryDecorationsTotal(entry);
}

PlantComponent* CustomerFacade::applyRedPot(PlantComponent* component)
{
    if (!component) return nullptr;

    RedPot* decorator = new RedPot();
    decorator->add(component);
    return decorator;
}

PlantComponent* CustomerFacade::applyRibbon(PlantComponent* component)
{
    if (!component) return nullptr;

    Ribbon* decorator = new Ribbon();
    decorator->add(component);
    return decorator;
}

PlantComponent* CustomerFacade::applyScent(PlantComponent* component)
{
    if (!component) return nullptr;

    Scent* decorator = new Scent();
    decorator->add(component);
    return decorator;
}

PlantComponent* CustomerFacade::applyGiftWrap(PlantComponent* component)
{
    if (!component) return nullptr;

    GiftWrap* decorator = new GiftWrap();
    decorator->add(component);
    return decorator;
}

std::string CustomerFacade::decorationName(DecorationType type)
{
    switch (type)
    {
        case DecorationType::RedPot:
            return "Red Pot";
        case DecorationType::Ribbon:
            return "Ribbon";
        case DecorationType::Scent:
            return "Scent";
        case DecorationType::GiftWrap:
            return "Gift Wrap";
        default:
            return "Decoration";
    }
}

double CustomerFacade::decorationPrice(DecorationType type)
{
    switch (type)
    {
        case DecorationType::RedPot:
            return 40.0;
        case DecorationType::Ribbon:
            return 25.0;
        case DecorationType::Scent:
            return 50.0;
        case DecorationType::GiftWrap:
            return 20.0;
        default:
            return 0.0;
    }
}

void CustomerFacade::applyDiscount(bool apply, const std::string& code)
{
    discountApplied = apply;
    if (apply)
    {
        discountCode = code;
    }
    else
    {
        discountCode.clear();
    }
}

bool CustomerFacade::isDiscountApplied() const
{
    return getDiscountRate() > 0.0;
}

bool CustomerFacade::hasManualDiscount() const
{
    return discountApplied;
}

bool CustomerFacade::hasAutomaticDiscount() const
{
    return cartEntries.size() >= 10;
}

double CustomerFacade::getDiscountRate() const
{
    return (discountApplied || hasAutomaticDiscount()) ? 0.10 : 0.0;
}

std::string CustomerFacade::getDiscountCode() const
{
    return discountCode;
}

Receipt* CustomerFacade::checkout()
{
    if (!currentOrder || cartEntries.empty())
    {
        return nullptr;
    }

    const double subtotal = getSubtotal();
    const double total = getOrderTotal();
    const double discountAmount = subtotal - total;

    std::ostringstream info;
    info << std::fixed << std::setprecision(2);
    info << "Items:\n";

    int index = 1;
    for (const CartEntry& entry : cartEntries)
    {
        if (!entry.plant)
        {
            continue;
        }

        info << index++ << ". " << entry.plant->getName() << " (Plant) - R" << entry.plant->getPrice() << '\n';
        for (DecorationType decoration : entry.decorations)
        {
            info << "   + " << decorationName(decoration) << " (Decoration) - R" << decorationPrice(decoration) << '\n';
        }
    }

    info << "\nSubtotal: R" << subtotal << '\n';
    if (discountAmount > 0.0)
    {
        info << "Discount: -R" << discountAmount << '\n';
    }
    info << "Total: R" << total << '\n';

    const std::string receiptID = currentOrder->getReceiptID();
    Receipt* receipt = new Receipt(receiptID, total, info.str());

    if (caretaker)
    {
        OrderMemento memento(currentPlantGroup->getPlantComponents(), total, receiptID);
        caretaker->addMemento(receiptID, memento);
    }

    if (inventory)
    {
        for (const CartEntry& entry : cartEntries)
        {
            if (!entry.plant)
            {
                continue;
            }
            reservedPlantIds.erase(entry.plant->getPlantId());
            inventory->removePlant(std::to_string(entry.plant->getPlantId()));
            purchasedPlants.push_back(entry.plant);
        }
    }
    else
    {
        for (const CartEntry& entry : cartEntries)
        {
            if (entry.plant)
            {
                purchasedPlants.push_back(entry.plant);
            }
        }
    }

    cartEntries.clear();
    createNewOrder();

    return receipt;
}

OrderMemento* CustomerFacade::searchOrder(const std::string& receiptID)
{
    if (caretaker)
    {
        return caretaker->getMemento(receiptID);
    }
    return nullptr;
}

void CustomerFacade::returnOrder(const std::string& receiptID)
{
    if (!caretaker || !inventory) return;
    
    OrderMemento* memento = caretaker->getMemento(receiptID);
    if (!memento) return;
    
    // Create a receipt object to pass to restoreOrder
    // Note: OrderMemento doesn't have getOrderInfo(), so we'll create an empty receipt
    Receipt receipt(receiptID, memento->getOrderPrice(), "");
    
    // Restore order (adds plants back to inventory)
    caretaker->restoreOrder(receipt, *inventory);
}

std::vector<Plant*> CustomerFacade::browsePlants()
{
    if (!inventory)
    {
        return {};
    }
    return filterVisiblePlants(inventory->getPlants());
}

std::vector<Plant*> CustomerFacade::searchPlants(const std::string& type, const std::string& maturity)
{
    if (!inventory) return std::vector<Plant*>();
    
    // Use query builder to search
    SelectQueryBuilder builder;
    builder.addPlantType(type);
    builder.addMaturityState(maturity);
    QueryProduct* product = builder.getQueryProduct();
    
    if (product)
    {
        product->execute();
        delete product;
    }
    
    return filterVisiblePlants(inventory->getPlants());
}

void CustomerFacade::setCustomer(Customer* cust)
{
    customer = cust;
}

Customer* CustomerFacade::getCustomer() const
{
    return customer;
}

double CustomerFacade::calculateEntryDecorationsTotal(const CartEntry& entry) const
{
    double total = 0.0;
    for (DecorationType decoration : entry.decorations)
    {
        total += decorationPrice(decoration);
    }
    return total;
}

std::vector<Plant*> CustomerFacade::filterVisiblePlants(const std::vector<Plant*>& plants) const
{
    std::vector<Plant*> visible;
    visible.reserve(plants.size());

    for (Plant* plant : plants)
    {
        if (!plant)
        {
            continue;
        }

        if (reservedPlantIds.find(plant->getPlantId()) != reservedPlantIds.end())
        {
            continue;
        }

        if (plant->getMaturityStateName() == "Dead")
        {
            continue;
        }

        visible.push_back(plant);
    }

    return visible;
}
