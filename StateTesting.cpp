#include "Rose.h"
#include <iostream>

int main(){
    Rose* rose1 = new Rose();
    rose1->print();
    bool doIt = true;
    while(doIt){
        rose1->hoursHasPassed();
        rose1->print();
        std::cin >> doIt;
    }

    std::cout<<"\nDONE";
}