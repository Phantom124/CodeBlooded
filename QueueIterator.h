#ifndef QUEUEITERATOR_H
#define QUEUEITERATOR_H

#include "Command.h"

class QueueIterator {
	public:
		void emptyQueue();
		Command* dequeue();
		Command* front();
		bool isEmpty();
		void enqueue(Command* command);
};

#endif
