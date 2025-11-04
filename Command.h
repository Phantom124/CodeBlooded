/**
 * @file Command.h
 * @brief Command.h — Header and declarations for the Command.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param type The type parameter used by the function.
 */

	Command(const cmdType type);
	virtual ~Command();
	virtual void execute() = 0;
	cmdType getType();
	bool getMarked();
/**
 * @brief Execute the function's primary operation.
 * @param newMarked The newMarked parameter used by the function.
 */

	void setMarked(bool newMarked);
};

#endif
