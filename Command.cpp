#include "Command.h"

Command::Command(const cmdType type): type(type), marked(false){

}

Command::~Command(){
}

cmdType Command::getType(){
    return type;
}

bool Command::getMarked(){
    return marked;
}

void Command::setMarked(bool newMarked){
    marked = newMarked;
}
