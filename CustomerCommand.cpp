/**
 * @file CustomerCommand.cpp
 * @brief CustomerCommand.cpp — Header and declarations for the CustomerCommand.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "CustomerCommand.h"

CustomerCommand::CustomerCommand(const cmdType type, Customer *customer)
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param type
 * @param customer
 */

    : Command(type), customer(customer){}

CustomerCommand::~CustomerCommand()
{
}
