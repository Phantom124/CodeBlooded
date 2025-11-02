#include "QueueIterator.h"
#include "StaffSystem.h"
#include "StaffHandler.h"

#include <iostream>

QueueIterator::QueueIterator(StaffSystem* sys){
    this->sys = sys;
}

void QueueIterator::emptyQueue(StaffHandler* head){
    if(!this->sys || !head) return;

    while(!this->sys->queue.empty()){
        Command* cmd = this->sys->queue.front();
        bool marked = cmd->getMarked();

        if (!marked){
            cmd->setMarked(true);
            this->sys->queue.pop();
            head->handleRequest(cmd, sys);
        } else {
            break;
        }
    }

    while (!this->sys->queue.empty()){
        Command* cmd = this->sys->queue.front();
        if (!cmd) break;
        if (cmd->getMarked()) {
            cmd->setMarked(false);
            this->sys->queue.pop();
            this->sys->queue.push(cmd);
        } else {
            break;
        }

    }
}

Command* QueueIterator::dequeue(){
    if(!this->sys || this->sys->queue.empty()) return nullptr;
    Command* cmd = this->sys->queue.front();
    this->sys->queue.pop();
    return cmd;
}

Command* QueueIterator::front(){
    if(!this->sys || this->sys->queue.empty()) return nullptr;
    return this->sys->queue.front();
}

bool QueueIterator::isEmpty(){
    if(!this->sys) return true;
    return this->sys->queue.empty();
}

void QueueIterator::enqueue(Command* command){
    if(!this->sys) return;
    this->sys->queue.push(command);
}

void QueueIterator::deleteQueue(){
    if (!this->sys) return;
    while (!this->sys->queue.empty()){
        Command* cmd = this->sys->queue.front();
        this->sys->queue.pop();
        delete cmd;
    }
}
