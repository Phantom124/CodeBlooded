#include "QueueIterator.h"
#include "StaffSystem.h"

QueueIterator::QueueIterator(StaffSystem* sys){
    this->sys = sys;
}

void QueueIterator::emptyQueue(){
    if(!this->sys) return;
    while(!this->sys->queue.empty()){
        this->sys->queue.pop();
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