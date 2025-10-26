#include "Rose.h"
#include <iostream>

int main(){
    Rose* rose1 = new Rose();
    // rose1->print();
    bool doIt = true;
    while(doIt){
        rose1->hoursHasPassed();
        rose1->print();
        std::cin >> doIt;
    }
    std::cout<<"\nWatering and Fertilizing Rose\n";
    rose1->waterPlant();
    rose1->fertilizePlant();
    // rose1->print();

    do{
        rose1->hoursHasPassed();
        rose1->print();
        std::cin >> doIt;
    }while(doIt);

    std::cout<<"\nDONE";
}