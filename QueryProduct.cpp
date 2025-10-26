#include "QueryProduct.h"

QueryProduct::QueryProduct(RealGreenHouseInventory* inventory){
    this->inventory = inventory;
}

QueryProduct::~QueryProduct(){
    // delete this->inventory;
    this->inventory = nullptr;
}

void QueryProduct::setQueryProduct(std::string query)
{
    this->query = query;
}

std::string QueryProduct::getQuery(){
    return this->query;
}

void QueryProduct::execute(){
    std::string query = this->getQuery();

    if (query.find("SELECT") != std::string::npos){
        executeSelect(query);
    }
    else if (query.find("INSERT") != std::string::npos){
        executeInsert(query);
    }
    else if (query.find("DELETE") != std::string::npos){
        executeDelete(query);
    }
}

void QueryProduct::executeSelect(std::string query){
    size_t select = query.find("SELECT") + 6;
    size_t from = query.find("FROM");

    if (from == std::string::npos) return;

    std::string paramemeters = query.substr(select, from-select);

    std::stringstream ss(paramemeters);
    std::string storage;

    //removing whitespaces
    while (std::getline(ss, storage, ',')){
        // if (storage[0] == ' '){
        //     storage = storage.substr(1);
        //     this->inventory->showPlant(storage);
        // }

        while (!storage.empty() && storage[0] == ' '){
            storage = storage.substr(1);
        }

        while (!storage.empty() && storage[storage.size()-1] == ' '){
            storage.pop_back();
        }

        if (!storage.empty()){
            this->inventory->showPlant(storage);
        }
    }
}

void QueryProduct::executeInsert(std::string query){
    size_t values = query.find("VALUES(");
    
    if (values == std::string::npos) return;

    values += 7;
    size_t endOfInsert = query.find(")", values);
    std::string parameters = query.substr(values, endOfInsert-values);

    std::stringstream ss(parameters);
    std::string storage;
    std::string redcord;

    std::vector<std::string> fields;

    while (std::getline(ss, storage, ',')){
        // if (storage[0] == ' '){
        //     storage = storage.substr(1);
        // }
        
        // if (storage[0] == '\''){
        //     storage = storage.substr(1, storage.size() - 2);
        
        // }

        // if (!redcord.empty()){
        //     redcord += ", ";

        // }

        // redcord += storage;

        while (!storage.empty() && storage[0] == ' '){
            storage = storage.substr(1);
        }

        if (storage[0] == '\''){
            storage = storage.substr(1, storage.size() - 2);
        }

        fields.push_back(storage);
    }

    while (fields.size() < 3){
        fields.push_back("");
    }

    Item item(fields[0], fields[1], fields[3]);

    this->inventory->addPlant(item);
}

void QueryProduct::executeDelete(std::string query){
    size_t where = query.find("WHERE");

    if (where != std::string::npos){
        std::string condition = query.substr(where+6);

        size_t equals = condition.find("=");

        if (equals != std::string::npos){
            std::string value = condition.substr(equals+1);

            if (value[0] == ' ') value = value.substr(1);
            if (value[0] == '\'') value = value.substr(1, value.size() - 2);

            this->inventory->removePlant(value);
        }
    }
}
