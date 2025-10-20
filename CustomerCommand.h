#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

class CustomerCommand : Command {

protected:
	String type;
	Customer* customer;

public:
	CustomerCommand(String type, Customer* customer);
};

#endif
