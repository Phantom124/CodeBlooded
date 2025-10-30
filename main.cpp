#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "PlantComponent.h"
#include "PlantGroup.h"
#include "PlantDecorator.h"

#include "Plant.h"
#include "RedPot.h"
#include "Ribbon.h"
#include "Scent.h"

#include "Sunflower.h"
#include "Rose.h"

#include "PlantMonitor.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"

#include "RoseFactory.h"
#include "SunflowerFactory.h"
#include "DeadMonitor.h"

void CompAndDec()
{
    FertilizerMonitor *fertMon = new FertilizerMonitor();
    WaterMonitor *watMon = new WaterMonitor();
    DeadMonitor *deadMon = new DeadMonitor();

    RoseFactory *rFact = new RoseFactory(watMon, fertMon, deadMon);

    Plant *myPlant = rFact->createPlant();
    std::cout << "OE print plant" << std::endl;
    myPlant->printPlant();
    std::cout << "OE price is: " << myPlant->getPrice() << std::endl;

    myPlant->add(new Ribbon());

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "added ribbon:" << std::endl;
    myPlant->printPlant();
    std::cout << "OE price is: " << myPlant->getPrice() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    myPlant->add(new RedPot());

    std::cout << "added red pot:" << std::endl;
    myPlant->printPlant();
    std::cout << "OE price is: " << myPlant->getPrice() << std::endl;

        myPlant->add(new Scent());

    std::cout << "added scent:" << std::endl;
    myPlant->printPlant();
    std::cout << "OE price is: " << myPlant->getPrice() << std::endl;
}

int main()
{
    CompAndDec();
    return 0;
}