#include "StaffSystem.h"

StaffSystem::StaffSystem(){
    //aint nothing in here, grootman
}

QueueIterator StaffSystem::createIterator(){
    QueueIterator out(this);
    return out;
}
