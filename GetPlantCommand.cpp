#include "GetPlantCommand.h"
#include "Order.h"

#include <stdexcept>

GetPlantCommand::GetPlantCommand(Plant *plant, Customer *customer) : CustomerCommand(GET_PLANT, customer){
    if (this->customer == nullptr){
        this->customer = customer;
    } else {
        throw std::invalid_argument("Customer is a nullptr");
    
}

void GetPlantCommand::execute(){
    if (!plant){
        throw std::runtime_error("Command is a nullptr.");
    }
    if (!customer){
        throw std::runtime_error("Command is a nullptr.");
    }
    // The order should be removed from the list before actually adding it to the customer
    // TODO: Figure out how Josh's thing works with the items 
    
    // Order* order = customer->getOrder();
    // order->addToOrder(plant);
}
