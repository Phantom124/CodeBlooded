#include "FertilizerMonitor.h"
#include <iostream>
#include "Plant.h"
#include "FertilizerCommand.h"
FertilizerMonitor::FertilizerMonitor(){
    this->type = "FertilizerMonitor";
}

FertilizerMonitor::~FertilizerMonitor(){}

void FertilizerMonitor::update(Plant *plant){
    if(!plant){
        throw std::invalid_argument("FertilizerMonitor got a null plant pointer");
    }
    if(plant->getFertilizerStateName() != "NonFertilized"){
            return; // No action needed
    }
    
    if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
        // std::cout<< "Fertilizer Monitor Recieved Update: Sending to Staff System.\n";
        FertilizerCommand* command = new FertilizerCommand(plant);//MAKE FERTILIZER COMMAND CORRECTLY
        staffSystem->attemptCommand(command);
    }
    
    
}
