#include "GetPlantCommand.h"
#include "Order.h"

GetPlantCommand::GetPlantCommand(const cmdType type, Plant *plant, Customer *customer) : CustomerCommand(type, customer){
    this->customer = customer;
}

void GetPlantCommand::execute(){
    // The order should be removal from the list before actually adding it to the customer
    // TODO: Figure out how Josh's thing works with the items 
    
    // Order* order = customer->getOrder();
    // order->addToOrder(plant);
}