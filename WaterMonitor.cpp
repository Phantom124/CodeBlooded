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
            // WaterCommand* command = new WaterCommand(plant);//MAKE WATER COMMAND CORRECTLY

            // if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
            //     staffSystem->addCommand(command);
            // }
            std::cout<< "Water Monitor Recieved Update: Plant needs water.\n";
        }
    }
}