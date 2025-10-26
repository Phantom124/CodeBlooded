#include "Plant.h"
#include <string>
#include <sstream>
#include <iostream>
int Plant::nextPlantId = 1;

Plant::Plant(){
    this->plantId = nextPlantId++;
    this->careCount = 0;
    this->health = 75; // Default health
    
    this->waterLevel = 100;
    this->fertilizerLevel = 100;

    this->waterState = new HydratedState();
    this->fertilizerState = new FertilizedState();
    checkWaterLevel();
    checkFertilizerLevel();
}

int Plant::getHealthEffects(){
    int totalEffect = -1000;//will kill plant if not effected
    if(waterState != nullptr && fertilizerState != nullptr){
        totalEffect = this->waterState->effect() + this->fertilizerState->effect();
        //can add extra abilities 
        //if +10 can increase to +15
        //if -10 can decrease to -12
    }
    return totalEffect;
    
}

void Plant::healthEffects(){
    //CHECK IF DEAD
    this->health += getHealthEffects();
    if(this->health < 0 ){//DEAD
        this->health = 0;
        //TRANSITION TO DEAD STATE
    }else if(this->health > 100){
        this->health = 100;
    }
}

void Plant::setWaterState(Water *waterState)
{ // Changes Water State
    if(this->waterState != nullptr){
        delete this->waterState;
    }
    this->waterState = waterState;
}

void Plant::setFertilizerState(Fertilizer *fertilizerState){//Changes Fertilizer State
    if(this->fertilizerState != nullptr){
        delete this->fertilizerState;
    }
    this->fertilizerState = fertilizerState;
}

void Plant::checkWaterLevel(){
    if(waterState != nullptr){
        Water* nextState = waterState->getNextState(this->waterLevel, this->lowWaterLevel);
        if(nextState != nullptr){  // CHANGE state (nextState is a new state object)
            this->setWaterState(nextState);
            if(nextState->getStateName() == "NotHydrated"){
                //NOTIFY OBSERVERS
            }
        }
        // If nextState is nullptr, STAY in current state
    }
}

void Plant::checkFertilizerLevel(){
    if(fertilizerState != nullptr){
        Fertilizer* nextState = fertilizerState->getNextState(this->fertilizerLevel, this->lowFertilizerLevel);
        if(nextState != nullptr){  // CHANGE state (nextState is a new state object)
            this->setFertilizerState(nextState);
            if(nextState->getStateName() == "NonFertilized"){
                //NOTIFY OBSERVERS
            }
        }
        // If nextState is nullptr, STAY in current state
    }
}

void Plant::decreaseWaterLevel(){
    this->waterLevel = this->waterLevel - (10 * this->waterRetention);//Decrease water level based on retention
    if(this->waterLevel < 0){//Make sure it doesn't go below 0
        this->waterLevel = 0;
    }
    checkWaterLevel();
}

void Plant::decreaseFertilizerLevel(){
    this->fertilizerLevel = this->fertilizerLevel - (8 * this->fertilizerRetention);//Decrease fertilizer level based on retention
    if(this->fertilizerLevel < 0){//Make sure it doesn't go below 0
        this->fertilizerLevel = 0;
    }
    checkFertilizerLevel();
}

void Plant::internalsTimeElapse(){//ADD CARECOUNT LATER ON FOR GROWTH STATE
    //Growth state update would go here based on careCount
    //CHECK IF PLANT IS DEAD!!!
    healthEffects();
    decreaseWaterLevel();
    decreaseFertilizerLevel();
}



Plant::~Plant()
{

    if(this->waterState != nullptr){
        delete this->waterState;
    }

    if(this->fertilizerState != nullptr){
        delete this->fertilizerState;
    }
}

void Plant::hoursHasPassed(){
    this->internalsTimeElapse();
}

void Plant::waterPlant(){
    this->waterLevel = 100;
    checkWaterLevel();
}

void Plant::fertilizePlant(){
    this->fertilizerLevel = 100;
    checkFertilizerLevel();
}

void Plant::print() {
    std::string result = "";

    std::stringstream ss;
    ss << this->plantId;
    std::string strPlantId = ss.str();

    result += this->getName();
    result += ": " + strPlantId;

    ss.str("");
    ss.clear();
    ss << this->waterLevel;
    std::string strWaterLvl = ss.str();
    result += " | Water: " + this->waterState->getStateName() + " " + strWaterLvl + "%";

    ss.str("");
    ss.clear();
    ss << this->fertilizerLevel;
    std::string strFertLvl = ss.str();
    result += " | Fertilizer: " + this->fertilizerState->getStateName() + " " + strFertLvl + "%";


    ss.str("");
    ss.clear();
    ss << this->health;
    std::string strHealth = ss.str();
    result += " | Health: " + strHealth;

    if(getHealthEffects() && health != 100 && health != 0){//is change in health
        ss.str("");
        ss.clear();
        ss << this->getHealthEffects();
        std::string strHealthEffect = ss.str();
        result += " changed by: " + strHealthEffect;
    }

    std::cout << result << std::endl;
}


std::string Plant::getName()
{
    std::stringstream ss;
    ss << this->plantId;
    std::string strPlantId = ss.str();
    return "Plant" + strPlantId;
}
