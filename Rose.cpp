#include "Rose.h"
#include <string>

Rose::Rose()
  : Plant("Rose", 20, 0.85, 30, 0.60, 70) {}


// Rose::Rose(PlantGrowthState* state, int waterLevel, int fertilizerLevel){
//     // this->state = state;
//     // this->waterLevel = waterLevel;
//     // this->fertilizerLevel = fertilizerLevel;
// }

Rose::~Rose(){}



std::string Rose::getName(){
    return "Rose";
}
