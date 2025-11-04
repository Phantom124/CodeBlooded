/**
 * @file Command.cpp
 * @brief Command.cpp — Header and declarations for the Command.cpp component.
 * @author Jared Williams
 * @date 2025-11-04
 */

#include "Command.h"

/**
 * @brief Execute the function's primary operation.
 * @param type
 * @param marked
 */
Command::Command(const cmdType type): type(type), marked(false){

}

Command::~Command(){
}

// Command::~Command() = default;

cmdType Command::getType(){
    return type;
}

bool Command::getMarked(){
    return marked;
}

/**
 * @brief Execute the function's primary operation.
 * @param newMarked The newMarked parameter used by the function.
 */

void Command::setMarked(bool newMarked){
    marked = newMarked;
}
