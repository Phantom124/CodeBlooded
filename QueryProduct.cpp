/**
 * @file QueryProduct.cpp
 * @brief QueryProduct.cpp — Header and declarations for the QueryProduct.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "QueryProduct.h"
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

QueryProduct::QueryProduct(ProxyGreenHouseInventory* inventory)
/**
 * @brief Execute the function's primary operation.
 * @param inventory The inventory parameter used by the function.
 */

    :inventory(inventory){}

QueryProduct::~QueryProduct(){
    this->inventory = nullptr;
}

void QueryProduct::setQueryProduct(std::string q)
{
    this->query = q;
}

std::string QueryProduct::getQuery() {
    return this->query;
}

void QueryProduct::execute(){
    if (!this->inventory) return;

    std::string q = this->getQuery();

    if (q.find("SELECT") != std::string::npos){
/**
 * @brief Execute the function's primary operation.
 * @param q The q parameter used by the function.
 */

        executeSelect(q);
    }
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param ! TODO - describe parameter
 */

    else if (q.find("INSERT") != std::string::npos){


        executeInsert(q);
    }


    else if (q.find("DELETE") != std::string::npos){


        executeDelete(q);
    }
}

/**
 * @brief Execute the function's primary operation.
 * @param query The query parameter used by the function.
 */

void QueryProduct::executeSelect(std::string query){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param "SELECT" TODO - describe parameter
 */

    size_t select = query.find("SELECT");
    if (select != std::string::npos) select += 6;
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param "FROM" TODO - describe parameter
 */

    size_t from = query.find("FROM");

    if (from == std::string::npos) return;

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param select The select parameter used by the function.
 * @param from-select TODO - describe parameter
 */

    std::string parameters = query.substr(select, from-select);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param parameters The parameters parameter used by the function.
 */

    std::stringstream ss(parameters);
    std::string storage;

    while (std::getline(ss, storage, ',')){
        while (!storage.empty() && storage.front() == ' '){
/**
 * @brief Execute the function's primary operation.
 * @param 0 The 0 parameter used by the function.
 * @param 1 The 1 parameter used by the function.
 */

            storage.erase(0,1);
        }
        while (!storage.empty() && storage.back() == ' '){
            storage.pop_back();
        }
        if (!storage.empty() && inventory) {
/**
 * @brief Execute the function's primary operation.
 * @param storage The storage parameter used by the function.
 */

            this->inventory->showPlant(storage);
        }
    }
}


void QueryProduct::executeInsert(std::string query){

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param "VALUES" TODO - describe parameter
 */

    size_t valuesPos = query.find("VALUES");
    if (valuesPos == std::string::npos) {
        // std::cout << "[ERROR] Invalid INSERT syntax.\n";
        return;
    }


/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param '(' TODO - describe parameter
 * @param valuesPos The valuesPos parameter used by the function.
 */

    size_t openParen = query.find('(', valuesPos);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param ')' TODO - describe parameter
 * @param openParen The openParen parameter used by the function.
 */

    size_t closeParen = query.find(')', openParen);
    if (openParen == std::string::npos || closeParen == std::string::npos) {
        // std::cout << "[ERROR] Missing parentheses in INSERT.\n";
        return;
    }

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param 1 The 1 parameter used by the function.
 * @param 1 The 1 parameter used by the function.
 */

    std::string inside = query.substr(openParen + 1, closeParen - openParen - 1);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param inside The inside parameter used by the function.
 */

    std::stringstream ss(inside);
    std::string token;
    std::string values[3];
    int i = 0;

    while (std::getline(ss, token, ',') && i < 3) {
        while (!token.empty() && (token.front() == ' ' || token.front() == '\'')) token.erase(0, 1);
        while (!token.empty() && (token.back() == ' ' || token.back() == '\'')) token.pop_back();
        values[i++] = token;
    }

    if (i < 3) {
        // std::cout << "[ERROR] Missing values for INSERT.\n";
        return;
    }

    
    Plant* newPlant = nullptr;

    if (values[1] == "Rose"){
        newPlant = new Rose();
    }
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    else if (values[1] == "Sunflower"){
        newPlant = new Sunflower();
    }


    else if (values[1] == "Cactus"){
        newPlant = new Cactus();
    }
    else{
        std::cout << "Unknown Plant Type: " << values[1] << std::endl;
        return;
    }

    if (this->inventory && newPlant){
/**
 * @brief Execute the function's primary operation.
 * @param newPlant The newPlant parameter used by the function.
 */

        this->inventory->addPlant(newPlant);
    }
    else{
        std::cout << "Inventory Unavailable or Invalid Plant.\n";
        delete newPlant;
    }
}



void QueryProduct::executeDelete(std::string query){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param "WHERE" TODO - describe parameter
 */

    size_t where = query.find("WHERE");

    if (where != std::string::npos){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param where+6 TODO - describe parameter
 */

        std::string condition = query.substr(where+6);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param " TODO - describe parameter
 */

        size_t equals = condition.find("=");

        if (equals != std::string::npos){
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param equals+1 TODO - describe parameter
 */

            std::string value = condition.substr(equals+1);

            if (!value.empty() && value.front() == ' ') value.erase(0,1);
            if (!value.empty() && value.front() == '\'') value = value.substr(1, value.size() - 2);

            if (inventory) this->inventory->removePlant(value);
        }
    }
}
