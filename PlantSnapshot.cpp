#include "PlantSnapshot.h"
#include <stdexcept> 
#include "SeedState.h"
#include "GerminationState.h"
#include "SaplingState.h"
#include "MatureState.h"
#include "DeadState.h"

PlantSnapshot::PlantSnapshot(Plant *plant) {
    if(plant == nullptr) {
        throw std::invalid_argument("Plant pointer cannot be null");
    }
    this->plantType = plant->type;
    this->careCount = plant->careCount;
    this->waterLevel = plant->waterLevel;
    this->fertilizerLevel = plant->fertilizerLevel;
    if (plant->growthState != nullptr)
    {
        this->growthStateName = plant->growthState->getStateName();
    }
    else
    {
        this->growthStateName = "Seed";
    }
}

Plant *PlantSnapshot::convertToPlant(){
    Plant *plant;
    if(plantType == "Cactus"){
        plant = new Cactus();
    }else if(plantType == "Rose"){
        plant = new Rose();
    }else if(plantType == "Sunflower"){
        plant = new Sunflower();
    }else{
        throw std::invalid_argument("Unknown plant type: " + plantType);
    }

    plant->careCount = this->careCount;
    plant->waterLevel = this->waterLevel;
    plant->fertilizerLevel = this->fertilizerLevel;

    if (plant->growthState != nullptr)
    {
        delete plant->growthState;
        plant->growthState = nullptr;
    }

    if (growthStateName == "Seed")
    {
        plant->growthState = new SeedState();
    }
    else if (growthStateName == "Germination")
    {
        plant->growthState = new GerminationState();
    }
    else if (growthStateName == "Sapling")
    {
        plant->growthState = new SaplingState();
    }
    else if (growthStateName == "Mature")
    {
        plant->growthState = new MatureState();
    }
    else if (growthStateName == "Dead")
    {
        plant->growthState = new DeadState();
    }
    else
    {
        plant->growthState = new SeedState();
    }

    plant->checkWaterLevel();
    plant->checkFertilizerLevel();
    plant->checkGrowthLevel();

    return plant;
}
