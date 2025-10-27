#include "FertilizerMonitor.h"
#include <iostream>
#include "Plant.h"
FertilizerMonitor::FertilizerMonitor(){
    this->type = "FertilizerMonitor";
}

FertilizerMonitor::~FertilizerMonitor(){}

void FertilizerMonitor::update(Plant *plant){
    if(plant != nullptr){//Passed in plant is valid
        if(plant->getFertilizerStateName() == "NonFertilized"){
            //Create Fertilizer Command
            //Send to chain of command
            std::cout<< "Fertilizer Monitor Recieved Update: Plant needs fertilizer.\n";
        }
    }
}
