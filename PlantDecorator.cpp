#include "PlantDecorator.h"

PlantDecorator::PlantDecorator(Plant *plant){
    this->myPlant = plant;
}

PlantDecorator::~PlantDecorator(){
    delete this->myPlant;
    this->myPlant = nullptr;
}

void PlantDecorator::add(Plant *extra){
    
}

void PlantDecorator::print(){

}

double PlantDecorator::getPrice(){
    return this->myPlant->getPrice();
}

std::string PlantDecorator::getName(){
    return this->myPlant->getName();
}
