/**
 * @file QueueIterator.cpp
 * @brief Iterator and utility functions for managing the StaffSystem command queue.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "QueueIterator.h"
#include "StaffSystem.h"
#include "StaffHandler.h"
#include "PlantCommand.h"
#include "Plant.h"
#include <iostream>

QueueIterator::QueueIterator(StaffSystem *sys)
{
    this->sys = sys;
}

void QueueIterator::emptyQueue(StaffHandler *head)
{
    if (!this->sys || !head)
        return;

    while (!this->sys->queue.empty())
    {
        Command *cmd = this->sys->queue.front();
        bool marked = cmd->getMarked();

        if (!marked)
        {
            // Mark this command so it is not processed again this cycle
/**
 * @brief Execute the function's primary operation.
 * @param true The true parameter used by the function.
 */
            cmd->setMarked(true);
            this->sys->queue.pop();
            // Attempt to handle the command starting from the head handler
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 * @param sys The sys parameter used by the function.
 */
            head->handleRequest(cmd, sys);
        }
        else
        {
            break;
        }
    }

    while (!this->sys->queue.empty())
    {
        Command *cmd = this->sys->queue.front();
        if (!cmd)
            break;
        if (cmd->getMarked())
        {
            // Unmark the command so it can be considered in the next cycle, and rotate it to the back
/**
 * @brief Execute the function's primary operation.
 * @param false The false parameter used by the function.
 */
            cmd->setMarked(false);
            this->sys->queue.pop();
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 */
            this->sys->queue.push(cmd);
        }
        else
        {
            break;
        }
    }
}

Command *QueueIterator::dequeue()
{
    if (!this->sys || this->sys->queue.empty())
        return nullptr;
    Command *cmd = this->sys->queue.front();
    this->sys->queue.pop();
    return cmd;
}

Command *QueueIterator::front()
{
    if (!this->sys || this->sys->queue.empty())
        return nullptr;
    return this->sys->queue.front();
}

bool QueueIterator::isEmpty()
{
    if (!this->sys)
        return true;
    return this->sys->queue.empty();
}

void QueueIterator::enqueue(Command *command)
{
    if (!this->sys)
        return;
    // Enqueue a command into the staff system's queue
/**
 * @brief Execute the function's primary operation.
 * @param command The command parameter used by the function.
 */
    this->sys->queue.push(command);
}

void QueueIterator::deleteQueue()
{
    if (!this->sys)
        return;
    while (!this->sys->queue.empty())
    {
        Command *cmd = this->sys->queue.front();
        this->sys->queue.pop();
        delete cmd;
    }
}

void QueueIterator::deleteAllWithId(int plantID)
{
    if (!this->sys)
    {
        return;
    }
    queue<Command *> tempQueue;

    while (!this->sys->queue.empty())
    {
        Command *cmd = this->sys->queue.front();
        this->sys->queue.pop();

    // Try to cast to a PlantCommand to inspect the target plant id
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param cmd The cmd parameter used by the function.
 */
    PlantCommand *plantCmd = dynamic_cast<PlantCommand *>(cmd);
        int cmdPlantID = -1;
        if (plantCmd)
        {
            cmdPlantID = plantCmd->getPlant()->getPlantId();
        }

        if (cmdPlantID == plantID)
        {
            // Remove and delete commands matching the specified plant ID
            delete cmd;
        }
        else
        {
            // Keep other commands in the queue

            this->sys->queue.push(cmd);
        }
    }

    while (!tempQueue.empty())
    {
        Command *cmd = tempQueue.front();
        tempQueue.pop();
        // Restore commands that were temporarily removed back into the system queue

        this->sys->queue.push(cmd);
    }
}
