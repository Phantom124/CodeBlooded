/**
 * @file GetPlantCommand.cpp
 * @brief GetPlantCommand.cpp — Header and declarations for the GetPlantCommand.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "GetPlantCommand.h"
#include "Order.h"

#include <stdexcept>

GetPlantCommand::GetPlantCommand(Plant *plant, Customer *customer)
    : CustomerCommand(GET_PLANT, customer), plant(plant), customer(customer)
{
    if (customer == nullptr){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr
 */

        throw std::invalid_argument("customer is a nullptr");
    }
    if (plant == nullptr){


        throw std::invalid_argument("plant is a nullptr");
    }
}

GetPlantCommand::~GetPlantCommand(){
}

void GetPlantCommand::execute()
{
    if (!plant){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param nullptr
 */

        throw std::runtime_error("plant is a nullptr.");
    }
    if (!customer){


        throw std::runtime_error("customer is a nullptr.");
    }
    // The order should be removed from the list before actually adding it to the customer
    // TODO: Figure out how Josh's thing works with the items 
    
    // Order* order = customer->getOrder();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant The plant parameter used by the function.
 */

    // order->addToOrder(plant);
}
