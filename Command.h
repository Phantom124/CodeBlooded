#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {

protected:
	std::string type;

public:
	Command(const std::string& type);

	virtual void execute() = 0;

	std::string getType();
};

#endif
