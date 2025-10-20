#ifndef COMMAND_H
#define COMMAND_H

class Command {

protected:
	String type;

public:
	Command(String type);

	virtual void execute() = 0;

	String getType();
};

#endif
