#ifndef COMMAND_H
#define COMMAND_H

#include <string>

enum cmdType {
    WATER,
    FERTILIZER,
    DEAD,
	GET_PLANT
};

class Command {

protected:
	cmdType type;
	bool marked;

public:
	Command(const cmdType type);
	virtual ~Command();
	virtual void execute() = 0;
	cmdType getType();
	bool getMarked();
	void setMarked(bool newMarked);
};

#endif