#include "DeadMonitor.h"
#include <iostream>
#include "Plant.h"
#include "DeadCommand.h"
DeadMonitor::DeadMonitor(){
    this->type = "DeadMonitor";
}

DeadMonitor::~DeadMonitor(){}

void DeadMonitor::update(Plant *plant){
    if(plant != nullptr){//Passed in plant is valid
        if(plant->getHealth() == 0){
            DeadCommand* command = new DeadCommand(plant);//MAKE DEAD COMMAND CORRECTLY
            if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
                staffSystem->attemptCommand(command);
                std::cout<< "Dead Monitor Recieved Update: sending to Staff System.\n";
            }
        }
    }
}
