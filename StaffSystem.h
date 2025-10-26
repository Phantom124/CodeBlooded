#ifndef STAFFSYSTEM_H
#define STAFFSYSTEM_H

#include "QueueIterator.h"
#include "Command.h"
#include <queue>

class StaffSystem {
	private:
		std::queue<Command*> queue;
	public:
		StaffSystem();
		QueueIterator createIterator();
		friend class QueueIterator;
};

#endif
