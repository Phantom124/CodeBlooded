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

// Plant.cpp
Plant::Plant(std::string type, double price, double waterRetention, int lowWaterLevel, double fertilizerRetention, int lowFertilizerLevel) : type(type), price(price), waterRetention(waterRetention), lowWaterLevel(lowWaterLevel), fertilizerRetention(fertilizerRetention), lowFertilizerLevel(lowFertilizerLevel)
{
    // Initialize the rest too (health, states, etc.)
    this->careCount = 0;
    this->health = 100;
    this->plantId = nextPlantId++;
    this->waterLevel = 100;
    this->fertilizerLevel = 100;

    this->waterState = new HydratedState();
    this->fertilizerState = new FertilizedState();
    this->growthState = new SeedState();

    checkWaterLevel();
    checkFertilizerLevel();
}

int Plant::getHealthEffects()
{
    int totalEffect = -1000; // will kill plant if not effected
    if (waterState != nullptr && fertilizerState != nullptr)
    {
        totalEffect = this->waterState->effect() + this->fertilizerState->effect();
        // can add extra abilities
        // if +10 can increase to +15
        // if -10 can decrease to -12
        if (totalEffect == 0)
        {                     // If One state needs attention
            totalEffect = -2; // Small decrease
        }
    }
    return totalEffect;
}

void Plant::healthEffects()
{

    // if(this->health <= 0){//CHECK IF DEAD
    //     return;
    // }
    // Normal health effects
    this->health += getHealthEffects();
    if (this->health < 0)
    { // DEAD
        this->health = 0;
        setGrowthState(new DeadState()); // MAKE DEAD MAKE DEAD
        if (deadMonitor != nullptr)
        {
            deadMonitor->update(this);
        }
        // NOTIFY OBSERVERS
        // TRANSITION TO DEAD STATE
    }
    else if (this->health > 100)
    { // MAX HEALTH
        this->health = 100;
    }
}

void Plant::setWaterState(Water *waterState)
{ // Changes Water State
    if (this->waterState != nullptr)
    {
        delete this->waterState;
    }
    this->waterState = waterState;
}

void Plant::setFertilizerState(Fertilizer *fertilizerState)
{ // Changes Fertilizer State
    if (this->fertilizerState != nullptr)
    {
        delete this->fertilizerState;
    }
    this->fertilizerState = fertilizerState;
}

void Plant::checkWaterLevel()
{
    if (waterState != nullptr)
    {
        Water *nextState = waterState->getNextState(this->waterLevel, this->lowWaterLevel);
        if (nextState != nullptr)
        { // CHANGE state (nextState is a new state object)
            this->setWaterState(nextState);
            if (nextState->getStateName() == "NotHydrated")
            {

                if (waterMonitor != nullptr)
                {
                    waterMonitor->update(this); // NOTIFY Monitor
                }
            }
        }
        // If nextState is nullptr, STAY in current state
    }
}

void Plant::checkFertilizerLevel()
{
    if (fertilizerState != nullptr)
    {
        Fertilizer *nextState = fertilizerState->getNextState(this->fertilizerLevel, this->lowFertilizerLevel);
        if (nextState != nullptr)
        { // CHANGE state (nextState is a new state object)
            this->setFertilizerState(nextState);
            if (nextState->getStateName() == "NonFertilized")
            {
                std::cout << "Fertilizer level low, notifying monitor." << std::endl;
                if (fertilizerMonitor != nullptr)
                {
                    fertilizerMonitor->update(this); // NOTIFY Monitor
                }
                // else ignore or log warning
            }
        }
        // If nextState is nullptr, STAY in current state
    }
}

void Plant::decreaseWaterLevel()
{
    if (health <= 0)
    { // IF DEAD DO NOT DECREASE LEVELS
        this->waterLevel = 0;
    }
    else
    {                                                                      // Only decrease if not dead
        this->waterLevel = this->waterLevel - (10 * this->waterRetention); // Decrease water level based on retention
        if (waterLevel < 0)
        {
            this->waterLevel = 0;
        }
    }
    checkWaterLevel();
}

void Plant::decreaseFertilizerLevel()
{
    if (health <= 0)
    { // IF DEAD DO NOT DECREASE LEVELS
        this->fertilizerLevel = 0;
    }
    else
    {                                                                                    // Only decrease if not dead
        this->fertilizerLevel = this->fertilizerLevel - (8 * this->fertilizerRetention); // Decrease fertilizer level based on retention
        if (fertilizerLevel < 0)
        {
            this->fertilizerLevel = 0;
        }
    }
    checkFertilizerLevel();
}

void Plant::internalsTimeElapse()
{ // ADD CARECOUNT LATER ON FOR GROWTH STATE
    // Growth state update would go here based on careCount
    // CHECK IF PLANT IS DEAD!!!
    std::cout << "Effecting Plant Health...\n";
    healthEffects(); // Calculate new health // Can put plant in deadState
    std::cout << "Increasing Care Count...\n";
    increaseCareCount();
    std::cout << "Decreasing Water and Fertilizer Levels...\n";
    decreaseWaterLevel(); // Decrease water level//
    decreaseFertilizerLevel();
}

Plant::~Plant()
{

    if (this->waterState != nullptr)
    {
        delete this->waterState;
    }

    if (this->fertilizerState != nullptr)
    {
        delete this->fertilizerState;
    }
    if (this->growthState != nullptr)
    {
        delete this->growthState;
    }
}

void Plant::hoursHasPassed()
{
    this->internalsTimeElapse();
}

void Plant::waterPlant()
{
    if (this->health <= 0)
    { // IF DEAD DO NOT WATER
        this->waterLevel = 0;
        checkWaterLevel();
        return;
    }
    this->waterLevel = 100;
    checkWaterLevel();
}

void Plant::fertilizePlant()
{
    std::cout << "Fertilizing Plant...\n";
    if (this->health <= 0)
    { // IF DEAD DO NOT FERTILIZE
        this->fertilizerLevel = 0;
        checkFertilizerLevel();
        return;
    }
    this->fertilizerLevel = 100;
    checkFertilizerLevel();
}

void Plant::print()
{
    std::string result = "";
    // UNCOMMENT TO SHOW FULL DETAILS UNCOMMENT TO SHOW FULL DETAILS UNCOMMENT TO SHOW FULL DETAILS UNCOMMENT TO SHOW FULL DETAILS
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

std::string Plant::getWaterStateName()
{
    if (this->waterState == nullptr)
    {
        return "No Water State";
    }
    return this->waterState->getStateName();
}

std::string Plant::getFertilizerStateName()
{
    if (this->fertilizerState == nullptr)
    {
        return "No Fertilizer State";
    }
    return this->fertilizerState->getStateName();
}

std::string Plant::getMaturityStateName()
{
    return this->growthState->getStateName();
}

int Plant::getHealth()
{
    return this->health;
}

void Plant::attachWaterMonitor(WaterMonitor *observer)
{
    if (observer != nullptr)
    {
        this->waterMonitor = observer;
    }
    else
    {
        throw std::invalid_argument("Observer cannot be null");
    }
}

void Plant::attachFertilizerMonitor(FertilizerMonitor *observer)
{
    if (observer != nullptr)
    {
        this->fertilizerMonitor = observer;
    }
    else
    {
        throw std::invalid_argument("Observer cannot be null");
    }
}

void Plant::attachDeadMonitor(DeadMonitor *observer)
{
    if (observer != nullptr)
    {
        this->deadMonitor = observer;
    }
    else
    {
        throw std::invalid_argument("Observer cannot be null");
    }
}

std::string Plant::getName()
{
    return this->type;
}

PlantGrowthState *Plant::getState()
{
    return this->growthState;
}

int Plant::getWaterLevel()
{
    return this->waterLevel;
}

int Plant::getFertilizerLevel()
{
    return this->fertilizerLevel;
}

int Plant::getPlantId()
{
    return plantId;
}

void Plant::printPlant()
{
    std::cout << "Plant: " << this->getName() << " | Price: R" << this->getPrice() << std::endl;
}

double Plant::getPrice()
{
    return this->price * this->growthState->getPriceEffect(); // multiply price by how big the plant is 1.1 1.2 1.3 1.5 2.0
}

int Plant::getCareCount()
{
    return this->careCount;
}

int Plant::getCareCountEffect()
{
    int waterEffect = (this->waterState->getStateName() == "Hydrated") ? 2 : 0;
    int fertilizerEffect = (this->fertilizerState->getStateName() == "Fertilized") ? 2 : 0;
    return waterEffect + fertilizerEffect;
}

void Plant::increaseCareCount()
{
    if (this->health <= 0)
    { // IF DEAD DO NOT INCREASE CARE COUNT
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

void Plant::setGrowthState(PlantGrowthState *state)
{
    if (this->growthState != nullptr)
    {
        delete this->growthState;
    }
    this->growthState = state;
}

void Plant::checkGrowthLevel()
{
    if (growthState == nullptr)
    {
        return;
    }
    PlantGrowthState *nextState = this->growthState->getNextState(this->careCount);
    if (nextState != nullptr)
    {
        delete this->growthState;
        this->growthState = nextState;
    }
}
