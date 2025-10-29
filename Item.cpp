#include "Item.h"

Item::Item(std::string plantID, std::string plantType, std::string maturityState)
    : plantID(std::move(plantID)),
      plantType(std::move(plantType)),
      maturityState(std::move(maturityState)),
      plantReference(nullptr)
{
}

std::string Item::getPlantID(){
    return this->plantID;
}

std::string Item::getPlantType(){
    return this->plantType;
}

std::string Item::getMaturityState(){
    return this->maturityState;
}

std::string Item::toString(){
    return this->plantID + " " + this->plantType + " " + this->maturityState;
}
