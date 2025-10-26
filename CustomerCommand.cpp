#include "CustomerCommand.h"

CustomerCommand::CustomerCommand(const std::string &type, Customer *customer)
    : Command(type), customer(customer){}