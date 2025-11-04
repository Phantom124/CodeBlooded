/**
 * @file StaffSystem.h
 * @brief StaffSystem.h — Header and declarations for the StaffSystem.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef STAFFSYSTEM_H
#define STAFFSYSTEM_H

#include "QueueIterator.h"
#include "Command.h"
#include <queue>

class StaffHandler;

class StaffSystem {
	private:
		std::queue<Command*> queue;
		StaffHandler* staffHandler;
	public:
		StaffSystem();
		~StaffSystem();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param staff The staff parameter used by the function.
 */

		// void setHandler(StaffHandler* staff);
		void timeElapsed();
/**
 * @brief Execute the function's primary operation.
 * @param staff The staff parameter used by the function.
 */

		void addHandler(StaffHandler* staff);
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 */

		void attemptCommand(Command* cmd);	
		QueueIterator createIterator();
		friend class QueueIterator;
};

#endif
