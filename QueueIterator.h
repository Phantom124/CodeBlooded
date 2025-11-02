#ifndef QUEUEITERATOR_H
#define QUEUEITERATOR_H

#include "Command.h"

class StaffSystem;
class StaffHandler;

class QueueIterator {
	private:
		StaffSystem* sys;
	public:
		QueueIterator(StaffSystem* sys);
		// QueueIterator(const QueueIterator& it);
		void emptyQueue(StaffHandler* head);
		Command* dequeue();
		Command* front();
		bool isEmpty();
		void enqueue(Command* command);
		void deleteQueue();
};

#endif