#ifndef GET_PLANT_COMMAND_H
#define GET_PLANT_COMMAND_H

#include "CustomerCommand.h"
#include "Plant.h"

class GetPlantCommand : public CustomerCommand {
    Customer* customer;
    Plant* plant;
	std::string type;
public:
	GetPlantCommand(const cmdType type, Plant* plant, Customer* customer);
	virtual void execute();
};

#endif