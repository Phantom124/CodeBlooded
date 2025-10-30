#include "PlantSnapshot.h"
#include <stdexcept> 

PlantSnapshot::PlantSnapshot(Plant *plant) {
    if(plant == nullptr) {
        throw std::invalid_argument("Plant pointer cannot be null");
    }
    this->plantType = plant->type;
    this->careCount = plant->careCount;
    this->waterLevel = plant->waterLevel;
    this->fertilizerLevel = plant->fertilizerLevel;
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
    plant->checkWaterLevel();
    plant->checkFertilizerLevel();
    plant->checkGrowthLevel();

    return plant;
}
