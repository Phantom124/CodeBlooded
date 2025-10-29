#include "WaterMonitor.h"
#include <iostream>
#include "Plant.h"
WaterMonitor::WaterMonitor(){
    this->type = "WaterMonitor";
}

WaterMonitor::~WaterMonitor(){}

void WaterMonitor::update(Plant* plant){
    // std::cout << "DEBUG: WaterMonitor received plant @" << static_cast<void*>(plant) << std::endl;

    if(!plant){
        throw std::invalid_argument("WaterMonitor got a null plant pointer");
    }

    if(plant->getWaterStateName() != "NotHydrated"){
        return; // No action needed
    }
    if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
        std::cout<< "Water Monitor Recieved Update: Sending to Staff System.\n";
        WaterCommand* cmd = new WaterCommand(plant);
        // std::cout << "DEBUG: Created WaterCommand for plant @" << static_cast<void*>(cmd->getPlant()) << std::endl;
        staffSystem->attemptCommand(cmd);
    }

}
