#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include <string>
#include "Command.h"
#include "Customer.h"

class CustomerCommand : public Command {

protected:
	std::string type;
	Customer* customer;

public:
	CustomerCommand(const std::string& type, Customer* customer);
};

#endif
