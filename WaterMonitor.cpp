#include "WaterMonitor.h"
#include <iostream>
#include "Plant.h"
WaterMonitor::WaterMonitor(){
    this->type = "WaterMonitor";
}

WaterMonitor::~WaterMonitor(){}

void WaterMonitor::update(Plant* plant) {
    if(plant != nullptr){//Passed in plant is valide
        if(plant->getWaterStateName() == "NotHydrated"){
            //Create Water Command
            //Send to chain of command
            std::cout<< "Water Monitor Recieved Update: Plant needs water.\n";
        }
    }
}