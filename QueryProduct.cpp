#include "QueryProduct.h"
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

Query::Query(){
    this->originator = "";
    this->operation = "";
    this->plant = nullptr;
}

Query::~Query(){
    plant = nullptr;
}

void Query::setOriginator(std::string originator){
    this->originator = originator;
}

void Query::setOperation(std::string operation){
    this->operation = operation;
}

void Query::setPlant(Plant* plant){
    if(plant == nullptr){
        throw std::invalid_argument("Query::setPlant received a null Plant pointer");
    }
    this->plant = plant;
}

std::string Query::getOriginator(){
    return this->originator;
}

std::string Query::getOperation(){
    return this->operation;
}

Plant* Query::getPlant(){
    return this->plant;
}
