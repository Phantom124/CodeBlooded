#include "WaterHandler.h"

#include <stdexcept>
#include <iostream>
using namespace std;

WaterHandler::WaterHandler() {
    cout << "Creating Water Handler" << endl;
}

WaterHandler::~WaterHandler(){
}

void WaterHandler::handleRequest(Command* command, StaffSystem* staffSys){
    if (command == nullptr){
        throw std::invalid_argument("Command is a nullptr.");
    } else if (staffSys == nullptr){
        throw std::invalid_argument("StaffSystem is a nullptr.");
    }

    if (isAvailable == true && command->getType() == WATER){//First: Are you available //Second: Is this a water command
        isAvailable = false;
        command->execute();
        delete command;
    } else {
        StaffHandler::handleRequest(command, staffSys);
    }
}
