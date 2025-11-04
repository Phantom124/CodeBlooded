#include "DeleteQueryBuilder.h"
#include "QueryProduct.h"
#include <vector>

DeleteQueryBuilder::DeleteQueryBuilder(): QueryBuilder() {}

void DeleteQueryBuilder::buildOriginator(std::string org){
    if(this->query != nullptr){
        this->query->setOriginator(org);
    }else{
        QueryBuilder::createNewQuery();
        this->query->setOriginator(org);
    }
}
void DeleteQueryBuilder::buildOperation(){
    if(this->query != nullptr){
        this->query->setOperation("DELETE");
    }else{
        QueryBuilder::createNewQuery();
        this->query->setOperation("DELETE");
    }
}

void DeleteQueryBuilder::buildValues(Plant *p){
    if(p == nullptr){
        throw std::invalid_argument("DeleteQueryBuilder::buildValues received a null Plant pointer");
    }

    if(this->query != nullptr){
        this->query->setPlant(p);
    }else{
        QueryBuilder::createNewQuery();
        this->query->setPlant(p);
    }
}

// void DeleteQueryBuilder::buildAndSendQuery(){
//     if (!this->inventory) {
//         throw std::runtime_error("DeleteQueryBuilder: Inventory is null.");
//     }
//     if (!this->query) {
//         throw std::runtime_error("DeleteQueryBuilder: Query has not been built.");
//     }

//     // std::cout << "DEBUG: Sending DELETE query from "
//     //           << this->query->getOriginator() << std::endl;

//     this->inventory->handle(this->query);
// }
