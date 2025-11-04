/**
 * @file QueueIterator.h
 * @brief QueueIterator.h — Header and declarations for the QueueIterator.h component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef QUEUEITERATOR_H
#define QUEUEITERATOR_H

#include "Command.h"

class StaffSystem;
class StaffHandler;

class QueueIterator
{
private:
	StaffSystem *sys;

public:
/**
 * @brief Execute the function's primary operation.
 * @param *sys TODO - describe parameter
 */

	QueueIterator(StaffSystem *sys);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param it The it parameter used by the function.
 */

	// QueueIterator(const QueueIterator& it);
/**
 * @brief Execute the function's primary operation.
 * @param *head TODO - describe parameter
 */

	void emptyQueue(StaffHandler *head);
	Command *dequeue();
	Command *front();
	bool isEmpty();
/**
 * @brief Execute the function's primary operation.
 * @param *command TODO - describe parameter
 */

	void enqueue(Command *command);
	void deleteQueue();
/**
 * @brief Execute the function's primary operation.
 * @param plantID The plantID parameter used by the function.
 */

	void deleteAllWithId(int plantID);
};

#endif
