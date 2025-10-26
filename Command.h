#ifndef COMMAND_H
#define COMMAND_H

#include <string>

enum cmdType {
    WATER,
    FERTILIZER,
    DEAD,
	BUY_PLANT
};

class Command {

protected:
	cmdType type;

public:
	Command(const cmdType type);
	virtual void execute() = 0;
	cmdType getType();
};

#endif
