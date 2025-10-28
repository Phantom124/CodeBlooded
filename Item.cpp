#include "Item.h"

Item::Item(std::string plantID, std::string plantType, std::string maturityState){
    this->plantID = this->plantReference->getPlantId();
    this->plantType = this->plantReference->getName();
    this->maturityState = this->plantReference->getMaturityStateName();
}

std::string Item::getPlantID(){
    return std::to_string(this->plantReference->getPlantId());
}

std::string Item::getPlantType(){
    return this->plantReference->getName();
}

std::string Item::getMaturityState(){
    return this->plantReference->getMaturityStateName();
}

std::string Item::toString(){
    return this->plantReference->getPlantId() + " " + this->plantReference->getName() + " " + this->plantReference->getMaturityStateName();
}
