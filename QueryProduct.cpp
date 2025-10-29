#include "QueryProduct.h"
#include <sstream>
#include <vector>

QueryProduct::QueryProduct(ProxyGreenHouseInventory* inventory){
    this->inventory = inventory;
}

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
    size_t values = query.find("VALUES(");
    if (values == std::string::npos) return;

    values += 7;
    size_t endOfInsert = query.find(")", values);
    if (endOfInsert == std::string::npos) return;

    std::string parameters = query.substr(values, endOfInsert-values);
    std::stringstream ss(parameters);
    std::string storage;

    std::vector<std::string> fields;
    while (std::getline(ss, storage, ',')){
        while (!storage.empty() && storage.front() == ' '){
            storage.erase(0,1);
        }
        if (!storage.empty() && storage.front() == '\''){
            if (storage.size() >= 2) storage = storage.substr(1, storage.size() - 2);
            else storage.clear();
        }
        fields.push_back(storage);
    }

    while (fields.size() < 3){
        fields.push_back("");
    }

    // fields[0], fields[1], fields[2] -> id, type, maturity
    // Item item(fields[0], fields[1], fields[2]);

    class TempPlant : public Plant {
    public:
        TempPlant(const std::string& id, const std::string& type, const std::string& maturity) {
            this->type = type;
            try { this->plantId = std::stoi(id); } catch (...) { this->plantId = 0; }
            this->growthState = new SeedState();
        }
        std::string getName() override { return type; }
    };

    // ---- Create plant dynamically and add it ----
    Plant* plant = new TempPlant(fields[0], fields[1], fields[2]);
    this->inventory->addPlant(plant);
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
