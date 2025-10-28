#include "FertilizerMonitor.h"
#include <iostream>
#include "Plant.h"
#include "FertilizerCommand.h"
FertilizerMonitor::FertilizerMonitor(){
    this->type = "FertilizerMonitor";
}

FertilizerMonitor::~FertilizerMonitor(){}

void FertilizerMonitor::update(Plant *plant){
    if(plant != nullptr){//Passed in plant is valid
        if(plant->getFertilizerStateName() == "NonFertilized"){
            FertilizerCommand* command = new FertilizerCommand(plant);//MAKE FERTILIZER COMMAND CORRECTLY

            if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
                staffSystem->attemptCommand(command);
                std::cout<< "Fertilizer Monitor Recieved Update: Sending to Staff System.\n";
            }
        }
    }
}
