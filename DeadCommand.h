#ifndef DEADCOMMAND_H
#define DEADCOMMAND_H

class DeadCommand : PlantCommand {

protected:
	Plant* plant;
	String type;

public:
	DeadCommand(String type, Plant* plant);
};

#endif
