#ifndef WATERCOMMAND_H
#define WATERCOMMAND_H

class WaterCommand : PlantCommand {

protected:
	Plant* plant;
	String type;

public:
	WaterCommand(String type, Plant* plant);
};

#endif
