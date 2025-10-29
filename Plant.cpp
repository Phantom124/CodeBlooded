#include "Plant.h"
#include <string>
#include <sstream>
#include <iostream>
#include "DeadState.h"
#include "SeedState.h"
#include "GerminationState.h"
#include "SaplingState.h"
#include "MatureState.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"

int Plant::nextPlantId = 1;

Plant::Plant()
    : type(""),
      price(0.0),
      careCount(0),
      health(75),
      waterState(nullptr),
      waterLevel(100),
      waterRetention(1.0),
      lowWaterLevel(20),
      fertilizerState(nullptr),
      fertilizerLevel(100),
      fertilizerRetention(1.0),
      lowFertilizerLevel(20),
      plantId(nextPlantId++),
      growthState(nullptr),
      waterMonitor(nullptr),
      fertilizerMonitor(nullptr),
      deadMonitor(nullptr)
{
    // now it's safe to allocate default states
    this->waterState = new HydratedState();
    this->fertilizerState = new FertilizedState();
    this->growthState = new SeedState();

    // safe to call checks because all relevant fields are initialized
    checkWaterLevel();
    checkFertilizerLevel();
}

// If you keep the string ctor, initialize members there as well:
Plant::Plant(std::string plantID, std::string plantType, std::string maturityState)
    : type(std::move(plantType)),
      price(0.0),
      careCount(0),
      health(75),
      waterState(nullptr),
      waterLevel(100),
      waterRetention(1.0),
      lowWaterLevel(20),
      fertilizerState(nullptr),
      fertilizerLevel(100),
      fertilizerRetention(1.0),
      lowFertilizerLevel(20),
      plantId(nextPlantId++),
      growthState(nullptr),
      waterMonitor(nullptr),
      fertilizerMonitor(nullptr),
      deadMonitor(nullptr)
{
    // map maturityState -> growthState safely (fallback to SeedState)
    if (maturityState == "Germination") growthState = new GerminationState();
    else if (maturityState == "Sapling" || maturityState == "Young") growthState = new SaplingState();
    else if (maturityState == "Mature") growthState = new MatureState();
    else growthState = new SeedState();

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

    // if(this->health <= 0){//CHECK IF DEAD
    //     return;
    // }
    //Normal health effects
    this->health += getHealthEffects();
    if(this->health < 0 ){//DEAD
        this->health = 0;
        setGrowthState(new DeadState());//MAKE DEAD MAKE DEAD
        //NOTIFY OBSERVERS
        //TRANSITION TO DEAD STATE
    }else if(this->health > 100){//MAX HEALTH
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
                if(waterMonitor != nullptr){
                    waterMonitor->update(this);
                }
                
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
                fertilizerMonitor->update(this);
            }
        }
        // If nextState is nullptr, STAY in current state
    }
}

void Plant::decreaseWaterLevel(){
    if(health <= 0){//IF DEAD DO NOT DECREASE LEVELS
        this->waterLevel = 0;
    }else{//Only decrease if not dead
        this->waterLevel = this->waterLevel - (10 * this->waterRetention);//Decrease water level based on retention
        if(waterLevel < 0){
            this->waterLevel = 0;
        }
    }
    checkWaterLevel();
}

void Plant::decreaseFertilizerLevel(){
    if(health <= 0){//IF DEAD DO NOT DECREASE LEVELS
        this->fertilizerLevel = 0;
    }else{//Only decrease if not dead
        this->fertilizerLevel = this->fertilizerLevel - (8 * this->fertilizerRetention);//Decrease fertilizer level based on retention
        if(fertilizerLevel < 0){
            this->fertilizerLevel = 0;
        }
    }
    checkFertilizerLevel();
}

void Plant::internalsTimeElapse(){//ADD CARECOUNT LATER ON FOR GROWTH STATE
    //Growth state update would go here based on careCount
    //CHECK IF PLANT IS DEAD!!!
    std::cout << "Effecting Plant Health...\n";
    healthEffects();//Calculate new health // Can put plant in deadState
    std::cout<< "Increasing Care Count...\n";
    increaseCareCount();
    std::cout << "Decreasing Water and Fertilizer Levels...\n";
    decreaseWaterLevel();//Decrease water level//
    decreaseFertilizerLevel(); 
    
}



Plant::~Plant() {
    delete waterState;
    delete fertilizerState;
    delete growthState;
    delete waterMonitor;
    delete fertilizerMonitor;
    delete deadMonitor;
}

void Plant::hoursHasPassed(){
    this->internalsTimeElapse();
}

void Plant::waterPlant(){
    if(this->health <= 0){//IF DEAD DO NOT WATER
        this->waterLevel = 0;
        checkWaterLevel();
        return;
    }
    this->waterLevel = 100;
    checkWaterLevel();
}

void Plant::fertilizePlant(){
    if(this->health <= 0){//IF DEAD DO NOT FERTILIZE
        this->fertilizerLevel = 0;
        checkFertilizerLevel();
        return;
    }
    this->fertilizerLevel = 100;
    checkFertilizerLevel();
}

void Plant::print() {
    std::string result = "";
    //UNCOMMENT TO SHOW FULL DETAILS UNCOMMENT TO SHOW FULL DETAILS UNCOMMENT TO SHOW FULL DETAILS UNCOMMENT TO SHOW FULL DETAILS
    std::stringstream ss;
    ss << this->plantId;
    std::string strPlantId = ss.str();

    cout << "Getting the name of the plant" << endl;

    result += this->getName();
    cout << "Got the name of the plant" << endl;

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

    // if(getHealthEffects() && health != 100 && health != 0){//is change in health
    //     ss.str("");
    //     ss.clear();
    //     ss << this->getHealthEffects();
    //     std::string strHealthEffect = ss.str();
    //     result += " changed by: " + strHealthEffect;
    // }

    ss.str("");
    ss.clear();
    ss << this->careCount;
    std::string strCareCount = ss.str();
    result += " | Growth State: " + this->growthState->getStateName();
    result += " | Care Count: " + strCareCount;

    std::cout << result << std::endl;
}

std::string Plant::getWaterStateName(){
    if(this->waterState == nullptr){
        return "No Water State";
    }
    return this->waterState->getStateName();
}

std::string Plant::getFertilizerStateName(){
    if(this->fertilizerState == nullptr){
        return "No Fertilizer State";
    }
    return this->fertilizerState->getStateName();
}

std::string Plant::getMaturityStateName(){
    return this->growthState->getStateName();
}

int Plant::getHealth(){
    return this->health;
}

void Plant::attachWaterMonitor(WaterMonitor *observer){
    if(observer != nullptr){
        this->waterMonitor = observer;
    }else{
        throw std::invalid_argument("Observer cannot be null");
    }

}

void Plant::attachFertilizerMonitor(FertilizerMonitor *observer){
    if(observer != nullptr){
        this->fertilizerMonitor = observer;
    }else{
        throw std::invalid_argument("Observer cannot be null");
    }
}

void Plant::attachDeadMonitor(DeadMonitor *observer){
    if(observer != nullptr){
        this->deadMonitor = observer;
    }else{
        throw std::invalid_argument("Observer cannot be null");
    }
}

std::string Plant::getName(){
    return this->type;
}

PlantGrowthState *Plant::getState(){
    return this->growthState;
}

int Plant::getWaterLevel(){
    return this->waterLevel;
}

int Plant::getFertilizerLevel(){
    return this->fertilizerLevel;
}

int Plant::getPlantId(){
    return plantId;
}

double Plant::getPrice(){
    return this->price * this->growthState->getPriceEffect();//multiply price by how big the plant is 1.1 1.2 1.3 1.5 2.0
}



int Plant::getCareCount()
{
    return this->careCount;
}

int Plant::getCareCountEffect(){
    int waterEffect = (this->waterState->getStateName() == "Hydrated") ? 2 : 0;
    int fertilizerEffect = (this->fertilizerState->getStateName() == "Fertilized") ? 2 : 0;
    return waterEffect + fertilizerEffect;
}

void Plant::increaseCareCount(){
    if(this->health <= 0){//IF DEAD DO NOT INCREASE CARE COUNT
        return;
    }
    this->careCount += getCareCountEffect();
    checkGrowthLevel();
    // PlantGrowthState* nextState = this->growthState->getNextState(this->careCount);
    // if(nextState != nullptr){
    //     delete this->growthState;
    //     this->growthState = nextState;
    // }
}

void Plant::setGrowthState(PlantGrowthState *state){
    if(this->growthState != nullptr){
        delete this->growthState;
    }
    this->growthState = state;
}

void Plant::checkGrowthLevel(){
    if(growthState == nullptr){
        return;
    }
    PlantGrowthState* nextState = this->growthState->getNextState(this->careCount);
    if(nextState != nullptr){
        delete this->growthState;
        this->growthState = nextState;
    }
}