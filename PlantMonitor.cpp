#include "PlantMonitor.h"
#include "Plant.h"

PlantMonitor::PlantMonitor(){
    chain = nullptr;
}

PlantMonitor::~PlantMonitor(){
    chain = nullptr;
}

void PlantMonitor::setChain(StaffHandler *chain){
    if(chain != nullptr){
        this->chain = chain;
    }else{
        throw std::invalid_argument("Chain cannot be null");
    }
}
