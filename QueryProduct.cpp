#include "QueryProduct.h"
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

QueryProduct::QueryProduct(ProxyGreenHouseInventory* inventory)
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
        executeSelect(q);
    }
    else if (q.find("INSERT") != std::string::npos){
        executeInsert(q);
    }
    else if (q.find("DELETE") != std::string::npos){
        executeDelete(q);
    }
}

void QueryProduct::executeSelect(std::string query){
    size_t select = query.find("SELECT");
    if (select != std::string::npos) select += 6;
    size_t from = query.find("FROM");

    if (from == std::string::npos) return;

    std::string parameters = query.substr(select, from-select);

    std::stringstream ss(parameters);
    std::string storage;

    while (std::getline(ss, storage, ',')){
        while (!storage.empty() && storage.front() == ' '){
            storage.erase(0,1);
        }
        while (!storage.empty() && storage.back() == ' '){
            storage.pop_back();
        }
        if (!storage.empty() && inventory) {
            this->inventory->showPlant(storage);
        }
    }
}

void QueryProduct::executeInsert(std::string query){

    size_t valuesPos = query.find("VALUES");
    if (valuesPos == std::string::npos) {
        // std::cout << "[ERROR] Invalid INSERT syntax.\n";
        return;
    }


    size_t openParen = query.find('(', valuesPos);
    size_t closeParen = query.find(')', openParen);
    if (openParen == std::string::npos || closeParen == std::string::npos) {
        // std::cout << "[ERROR] Missing parentheses in INSERT.\n";
        return;
    }

    std::string inside = query.substr(openParen + 1, closeParen - openParen - 1);

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
        this->inventory->addPlant(newPlant);
    }
    else{
        std::cout << "Inventory Unavailable or Invalid Plant.\n";
        delete newPlant;
    }
}


void QueryProduct::executeDelete(std::string query){
    size_t where = query.find("WHERE");

    if (where != std::string::npos){
        std::string condition = query.substr(where+6);

        size_t equals = condition.find("=");

        if (equals != std::string::npos){
            std::string value = condition.substr(equals+1);

            if (!value.empty() && value.front() == ' ') value.erase(0,1);
            if (!value.empty() && value.front() == '\'') value = value.substr(1, value.size() - 2);

            if (inventory) this->inventory->removePlant(value);
        }
    }
}
