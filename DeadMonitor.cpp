#include "DeadMonitor.h"
#include <iostream>
#include "Plant.h"
DeadMonitor::DeadMonitor(){
    this->type = "DeadMonitor";
}

DeadMonitor::~DeadMonitor(){}

void DeadMonitor::update(Plant *plant){
    if(plant != nullptr){//Passed in plant is valid
        if(plant->getHealth() == 0){
            //Create Dead Command
            //Send to chain of responsibility
            std::cout<< "Dead Monitor Recieved Update: Plant is dead.\n";
        }
    }
}
