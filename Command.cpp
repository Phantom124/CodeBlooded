#include "Command.h"

Command::Command(const cmdType type): type(type){
}

cmdType Command::getType(){
    return type;
}