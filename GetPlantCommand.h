/**
 * @file GetPlantCommand.h
 * @brief GetPlantCommand.h — Header and declarations for the GetPlantCommand.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef GET_PLANT_COMMAND_H
#define GET_PLANT_COMMAND_H

#include "CustomerCommand.h"
#include "Plant.h"

class GetPlantCommand : public CustomerCommand {
    Customer* customer;
    Plant* plant;
	std::string type;
public:
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 * @param customer The customer parameter used by the function.
 */

	GetPlantCommand(Plant* plant, Customer* customer);
	~GetPlantCommand();
	virtual void execute();
};

#endif
