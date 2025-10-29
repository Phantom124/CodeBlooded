#include "GetPlantCommand.h"
#include "Order.h"

#include <stdexcept>

GetPlantCommand::GetPlantCommand(Plant *plant, Customer *customer)
    : CustomerCommand(GET_PLANT, customer), plant(plant), customer(customer)
{
    if (customer == nullptr){
        throw std::invalid_argument("customer is a nullptr");
    }
    if (plant == nullptr){
        throw std::invalid_argument("plant is a nullptr");
    }
}

void GetPlantCommand::execute()
{
    if (!plant){
        throw std::runtime_error("plant is a nullptr.");
    }
    if (!customer){
        throw std::runtime_error("customer is a nullptr.");
    }
    // The order should be removed from the list before actually adding it to the customer
    // TODO: Figure out how Josh's thing works with the items 
    
    // Order* order = customer->getOrder();
    // order->addToOrder(plant);
}
