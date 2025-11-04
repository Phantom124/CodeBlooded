#include "SelectQueryBuilder.h"
#include "QueryProduct.h"
#include <string>
#include <vector>


SelectQueryBuilder::SelectQueryBuilder(): QueryBuilder() {}

void SelectQueryBuilder::buildOriginator(std::string org){
    if(this->query != nullptr){
        this->query->setOriginator(org);
    }else{
        QueryBuilder::createNewQuery();
        this->query->setOriginator(org);
    }
}
void SelectQueryBuilder::buildOperation(){
    if(this->query != nullptr){
        this->query->setOperation("SELECT");
    }else{
        QueryBuilder::createNewQuery();
        this->query->setOperation("SELECT");
    }
}
void SelectQueryBuilder::buildValues(Plant *p){
    //No check needed... we do not care xD
    // if(p == nullptr){
    //     throw std::invalid_argument("SelectQueryBuilder::buildValues received a null Plant pointer");
    // }

    if(this->query != nullptr){
        this->query->setPlant(p);
    }else{
        QueryBuilder::createNewQuery();
        this->query->setPlant(p);
    }
}

// void SelectQueryBuilder::buildAndSendQuery() {
//     if (!this->inventory) {
//         throw std::runtime_error("SelectQueryBuilder: Inventory is null.");
//     }
//     if (!this->query) {
//         throw std::runtime_error("SelectQueryBuilder: Query has not been built.");
//     }

//     // std::cout << "DEBUG: Sending SELECT query from "
//     //           << this->query->getOriginator() << std::endl;

//     this->inventory->handle(this->query);
// }

