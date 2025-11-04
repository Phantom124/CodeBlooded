#include "ProxyGreenHouseInventory.h"
#include "RealGreenHouseInventory.h"
#include "QueryProduct.h"
#include "Customer.h"
#include "StaffHandler.h"
#include "PlantFactory.h"

ProxyGreenHouseInventory::ProxyGreenHouseInventory(){
    this->realInventory = new RealGreenHouseInventory();

}

ProxyGreenHouseInventory::~ProxyGreenHouseInventory(){
    if (this->realInventory != nullptr){
        delete this->realInventory;
        this->realInventory = nullptr;
    }

}

// void ProxyGreenHouseInventory::showPlant(std::string parameters){
//     this->realInventory->showPlant(parameters);
// }

// void ProxyGreenHouseInventory::showAllPlants()
// {
//     this->realInventory->showAllPlants();
// }

// void ProxyGreenHouseInventory::addPlant(Plant* plant){
//     // std::cout << "[CONTROL ACCESS] Access Denied: Customer cannot INSERT.\n";
//     this->realInventory->addPlant(plant);
// }

// void ProxyGreenHouseInventory::removePlant(std::string parameters){
//     // std::cout << "[CONTROL ACCESS] Access Denied: Customer cannot DELETE.\n";
//     this->realInventory->removePlant(parameters);
// }

// std::vector<Plant*> ProxyGreenHouseInventory::getPlants()
// {
    // if (!this->realInventory)
    // {
    //     return {};
    // }
    // return this->realInventory->getPlants();
// }

// void ProxyGreenHouseInventory::handleControlRights(void* user, QueryProduct query){
//     //customers can only SELECT (showPlant, showAllPlants)

//     std::string queryText = query.getQuery(); //select, insert, delete
    
//     if (dynamic_cast<Customer*>((Customer*)user)){
//         if (queryText.find("SELECT") != std::string::npos){
//             query.execute();
            
//         }
//         else{
//             std::cout << "[CONTROL ACCESS] Customer cannot perform " << queryText << " operations.\n";
//         }
//     }
//     else if (dynamic_cast<StaffHandler*>((StaffHandler*)user) || dynamic_cast<PlantFactory*>((PlantFactory*)user)){
//         query.execute();
        
//     }
//     else{
//         std::cout << "[CONTROL ACCESS] Unknown User Type\n";
//     }
// }

void ProxyGreenHouseInventory::hourHasPassed(){
    if( this->realInventory != nullptr ){
        this->realInventory->hourHasPassed();
    }
}

void ProxyGreenHouseInventory::restorePlants(std::vector<PlantComponent *> plants)
{
    //TO BE IMPLEMENTED
}

// void ProxyGreenHouseInventory::printPlant(){
//     if (this->realInventory){
//         this->realInventory->printPlant();
//     }
//     else{
//         GreenHouseInventory::printPlant();
//     }
// }

void ProxyGreenHouseInventory::handle(Query *query){
    if (this->realInventory){
        std::string op = query->getOperation();
        if (op == "SELECT") {
            displayPlants();
        } 
        //Need Permission to carry out DELETE and SELECT
        if(query->getOriginator() == "Staff" || query->getOriginator() == "PlantFactory" || query->getOriginator() == "CheckoutSystem"){
            if (op == "DELETE") {
                deletePlant(query->getPlant());
            } else if (op == "INSERT") {
                insertPlant(query->getPlant());
            }else{
                std::cout << "ProxyGreenHouseInventory::handle received unknown operation: " << op << std::endl;
            }
        } else {
            std::cout << "[CONTROL ACCESS] Access Denied: Unauthorized originator '" << query->getOriginator() << "' for operation '" << op << "'.\n";
        }
    }
}

void ProxyGreenHouseInventory::insertPlant(Plant *plant){
    if (this->realInventory){
        this->realInventory->insertPlant(plant);
    }
}

void ProxyGreenHouseInventory::deletePlant(Plant *plant){
    if (this->realInventory){
        this->realInventory->deletePlant(plant);
    }
}

void ProxyGreenHouseInventory::displayPlants(){
    if (this->realInventory){
        this->realInventory->displayPlants();
    }
}
