#include "CustomerInterface.h"

void CustomerInterface::setCustomer(Customer *customer)
{
    this->customer = customer;
}

Customer *CustomerInterface::getCustomer() const
{
    return customer;
}

void CustomerInterface::DisplayPlants()
{
    // std::cout << "Displaying available plants...\n";
    // Add logic to display plants
    // PrintPlantFuncion
    if (g_inventory)
    {
        g_inventory->displayPlants();
    }
}

void CustomerInterface::chooseDecorators(PlantComponent *plant)
{
    std::cout << "Would you like to add decorations to your plant? (y/n): ";
    char choice;
    std::cin >> choice;
    while (choice == 'y' || choice == 'Y')
    {
        std::cout << "Select a decoration to add:\n";
        std::cout << "1. Ribbon\n2. Redpot\n3. Scent\n4. Gift Wrap\n";
        std::cout << "\nPlease select an option: ";
        int decorChoice;
        std::cin >> decorChoice;

        switch (decorChoice)
        {
        case 1:
            plant->add(new Ribbon());
            std::cout << "Ribbon added to your plant.\n";
            break;
        case 2:
            plant->add(new RedPot());
            std::cout << "Red Pot added to your plant.\n";
            break;
        case 3:
            plant->add(new Scent());
            std::cout << "Scent added to your plant.\n";
            break;
        case 4:
            plant->add(new GiftWrap());
            std::cout << "Gift Wrap added to your plant.\n";
            break;
        default:
            std::cout << "Invalid choice. No decoration added.\n";
            break;
        }

        std::cout << "Would you like to add another decoration? (y/n): ";
        std::cin >> choice;
    }
}

void CustomerInterface::processDiscountCode()
{
    std::cout << "Price before discount: " << getOrderTotal() << "\n";
    std::cout << "Enter discount code: ";
    std::string code;
    std::cin >> code;

    std::cout << "Price after discount: " << currentOrder->applyPriceStrategy(code) << std::endl;
}

void CustomerInterface::customerMenu()
{
    std::cout << "Customer Menu\n";
    std::cout << "1. View Plants\n2. Purchase Plant\n3. Return Order\n4. Order Summary\n5. Apply Discount Code & Checkout\nb. Back to Main Menu\n";
    while (true)
    {
        std::cout << "\nPlease select an option: ";
        std::string choice;
        std::cin >> choice;
        if (choice == "b" || choice == "B")
        {
            std::cout << "Returning to Main Menu...\n";
            return;
        }
        if (choice == "1")
        {
            std::cout << "Displaying available plants...\n";
            DisplayPlants();
        }
        else if (choice == "2")
        {
            std::cout << "Processing plant purchase...\n";
            std::string plantID;
            std::cout << "Enter Plant ID to purchase: ";
            std::cin >> plantID;
            PlantComponent *plant = g_inventory->orderPlant(plantID);
            if (plant)
            {
                if (!currentOrder)
                {
                    createNewOrder();
                }
                addPlantToOrder(plant);
                chooseDecorators(plant);
                std::cout << "Plant added to order: " << plant->getName() << "\n";
            }
            else
            {
                std::cout << "Plant with ID " << plantID << " not found.\n";
            }
        }
        else if (choice == "3")
        {
            std::string receiptID;
            std::cout << "Enter Receipt ID to return: ";
            std::cin >> receiptID;
            returnOrder(receiptID);
        }
        else if (choice == "4")
        {
            std::cout << "Order Price: " << getOrderTotal() << "\n";
            std::cout << "Order Items:\n";
            for (const auto &item : getOrderItems())
            {
                std::cout << "- " << item->getName() << "\n";
            }
            std::cout << "Total Plants: " << getOrderItemCount() << "\n";
        }
        else if (choice == "5")
        {
            if (getOrderItemCount() == 0)
            {
                std::cout << "No items in order to apply discount.\n";
                continue;
            }
            std::cout << "Applying discount code...\n";
            processDiscountCode();
            std::cout << "Discount code processed.\n";
            std::cout << "New Order Price: " << getOrderTotal() << "\n";
            std::cout << "Checking out...\n";
            Receipt *receipt = checkout();
            if (receipt)
            {
                std::cout << "Checkout complete. Receipt ID: " << receipt->getReceiptID() << "\n";
                delete receipt;
            }
            else
            {
                std::cout << "Checkout failed. No items in order.\n";
            }
        }
        else
        {
            std::cout << "Invalid option. Please try again.\n";
        }
        // Add more customer functionalities here
        // std::cout << "Functionality not implemented yet.\n";
    }
}

CustomerInterface::CustomerInterface(GreenHouseInventory *sharedInventory, Caretaker *sharedCaretaker, Customer *customer)
{
    inventory = nullptr;
    caretaker = sharedCaretaker;
    currentOrder = nullptr;
    this->customer = customer;
    discountApplied = false;
    discountCode = "";
}

CustomerInterface::~CustomerInterface()
{
    delete currentOrder;
}

void CustomerInterface::createNewOrder()
{
    currentOrder = new Order();
}

void CustomerInterface::addPlantToOrder(PlantComponent *plant)
{
    if (currentOrder)
    {
        currentOrder->addToOrder(plant);
    }
}

double CustomerInterface::getOrderTotal()
{
    if (currentOrder)
    {
        return currentOrder->getPrice();
    }
    return 0.0;
}

std::vector<PlantComponent *> CustomerInterface::getOrderItems()
{
    if (currentOrder)
    {
        return currentOrder->getOrderPlants();
    }
    return std::vector<PlantComponent *>();
}

int CustomerInterface::getOrderItemCount()
{
    if (currentOrder)
    {
        return currentOrder->quantity();
    }
    return 0;
}

Receipt *CustomerInterface::checkout()
{
    if (currentOrder)
    {
        Receipt *receipt = currentOrder->generateReceipt();
        OrderMemento *memento = currentOrder->createMemento();
        caretaker->addMemento(receipt->getReceiptID(), *memento);
        delete currentOrder;
        currentOrder = nullptr;
        return receipt;
    }
    return nullptr;
}

OrderMemento *CustomerInterface::searchOrder(const std::string &receiptID)
{
    return caretaker->getMemento(receiptID);
}

void CustomerInterface::returnOrder(const std::string &receiptID)
{
    caretaker->removeMemento(receiptID);
}
