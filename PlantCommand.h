#ifndef PLANTCOMMAND_H
#define PLANTCOMMAND_H

class PlantCommand : Command {

protected:
	Plant* plant;
	String type;

public:
	PlantCommand(String type, Plant* plant);
};

#endif
