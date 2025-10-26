#include "Command.h"

Command::Command(const std::string &type): type(type){
}

std::string Command::getType(){
    return type;
}
