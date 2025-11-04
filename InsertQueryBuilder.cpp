#include "InsertQueryBuilder.h"
#include "QueryProduct.h"
#include <vector>

InsertQueryBuilder::InsertQueryBuilder() : QueryBuilder() {

}

InsertQueryBuilder::~InsertQueryBuilder(){}

void InsertQueryBuilder::buildOriginator(std::string org){
    if(this->query != nullptr){
        this->query->setOriginator(org);
    }else{
        QueryBuilder::createNewQuery();
        this->query->setOriginator(org);
    }
}

void InsertQueryBuilder::buildOperation(){
    if(this->query != nullptr){
        this->query->setOperation("INSERT");
    }else{
        QueryBuilder::createNewQuery();
        this->query->setOperation("INSERT");
    }
}

void InsertQueryBuilder::buildValues(Plant *p){
    if(p == nullptr){
        throw std::invalid_argument("InsertQueryBuilder::buildValues received a null Plant pointer");
    }

    if(this->query != nullptr){
        this->query->setPlant(p);
    }else{
        QueryBuilder::createNewQuery();
        this->query->setPlant(p);
    }
}

// void InsertQueryBuilder::buildAndSendQuery() {
//     if (!this->inventory) {
//         throw std::runtime_error("InsertQueryBuilder: Inventory is null.");
//     }
//     if (!this->query) {
//         throw std::runtime_error("InsertQueryBuilder: Query has not been built.");
//     }

//     // std::cout << "DEBUG: Sending INSERT query from " 
//     //           << this->query->getOriginator() << std::endl;

//     this->inventory->handle(this->query);
// }

