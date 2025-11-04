#ifndef STAFFSYSTEM_H
#define STAFFSYSTEM_H

#include "QueueIterator.h"
#include "Command.h"
#include <queue>
#include "GreenHouseInventory.h"
#include "QueryBuilder.h"

class StaffHandler;

class StaffSystem {
	private:
		std::queue<Command*> queue;
		StaffHandler* staffHandler;
		GreenHouseInventory* inventory;
		QueryBuilder* queryBuilder;
	public:
		StaffSystem(GreenHouseInventory* inventory, QueryBuilder* queryBuilder);
		~StaffSystem();
		// void setHandler(StaffHandler* staff);
		void timeElapsed();
		void addHandler(StaffHandler* staff);
		void attemptCommand(Command* cmd);	
		QueueIterator createIterator();
		friend class QueueIterator;
		GreenHouseInventory* getInventory() { return inventory; }
};

#endif // STAFFSYSTEM_H
