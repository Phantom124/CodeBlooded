/**
 * @file WaterMonitor.cpp
 * @brief Monitor that observes plant hydration state and generates water commands when needed.
 * @author Zaman Bassa
 * @date 2025-11-04
 */

#include "WaterMonitor.h"
#include <iostream>
#include "Plant.h"
WaterMonitor::WaterMonitor(){
    this->type = "WaterMonitor";
}

WaterMonitor::~WaterMonitor(){}

/**
 * @brief Receive updates from a Plant and enqueue watering commands when hydration is low.
 * @param plant Pointer to the Plant that triggered the update (must not be null).
 */
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */
void WaterMonitor::update(Plant* plant){
    // std::cout << "DEBUG: WaterMonitor received plant @" << static_cast<void*>(plant) << std::endl;

    if(!plant){
        // Invalid input: plant pointer is required
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param pointer" TODO - describe parameter
 */
        throw std::invalid_argument("WaterMonitor got a null plant pointer");
    }

    if(plant->getWaterStateName() != "NotHydrated"){
        return; // No action needed
    }
    if(staffSystem != nullptr){//SEND TO STAFF SYSTEM IF EXISTS
    // Create a watering command for the plant and send it to the staff system
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param plant The plant parameter used by the function.
 */
    WaterCommand* cmd = new WaterCommand(plant);
        // std::cout << "DEBUG: Created WaterCommand for plant @" << static_cast<void*>(cmd->getPlant()) << std::endl;
    // Attempt to schedule/execute the water command via the StaffSystem
/**
 * @brief Execute the function's primary operation.
 * @param cmd The cmd parameter used by the function.
 */
    staffSystem->attemptCommand(cmd);
    }

}
