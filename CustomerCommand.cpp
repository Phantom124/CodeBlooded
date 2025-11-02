#include "CustomerCommand.h"

CustomerCommand::CustomerCommand(const cmdType type, Customer *customer)
    : Command(type), customer(customer){}

CustomerCommand::~CustomerCommand()
{
}
