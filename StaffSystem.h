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
		// void setHandler(StaffHandler* staff);
		void timeElapsed();
		void addHandler(StaffHandler* staff);
		void attemptCommand(Command* cmd);	
		QueueIterator createIterator();
		friend class QueueIterator;
		void printStaffHandlers();
};

#endif
