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
#include "Cactus.h"

#include "PlantMonitor.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"

#include "RoseFactory.h"
#include "SunflowerFactory.h"
#include "CactusFactory.h"
#include "DeadMonitor.h"

#include "Order.h"
#include "PriceStrategies.h"
#include "NormalPrice.h"
#include "DiscountPrice.h"

void CompAndDec()
{
    std::cout << "========================================" << std::endl;
    std::cout << "TESTING COMPOSITE AND DECORATOR PATTERNS" << std::endl;
    std::cout << "========================================" << std::endl
              << std::endl;

    PlantGroup *pg = new PlantGroup();

    FertilizerMonitor *fertMon = new FertilizerMonitor();
    WaterMonitor *watMon = new WaterMonitor();
    DeadMonitor *deadMon = new DeadMonitor();

    RoseFactory *rFact = new RoseFactory(watMon, fertMon, deadMon);
    SunflowerFactory *sFact = new SunflowerFactory(watMon, fertMon, deadMon);
    CactusFactory *cFact = new CactusFactory(watMon, fertMon, deadMon);

    // Test 1: Base Rose plant
    std::cout << "--- TEST 1: Base Rose Plant ---" << std::endl;
    Plant *myPlant = rFact->createPlant();
    myPlant->printPlant();
    std::cout << "Base price: R" << myPlant->getPrice() << std::endl
              << std::endl;

    // Test 2: Add Ribbon decorator
    std::cout << "--- TEST 2: Rose + Ribbon ---" << std::endl;
    myPlant->add(new Ribbon());
    myPlant->printPlant();
    std::cout << "Price after ribbon: R" << myPlant->getPrice() << std::endl
              << std::endl;

    // Test 3: Add RedPot decorator
    std::cout << "--- TEST 3: Rose + Ribbon + RedPot ---" << std::endl;
    myPlant->add(new RedPot());
    myPlant->printPlant();
    std::cout << "Price after red pot: R" << myPlant->getPrice() << std::endl
              << std::endl;

    // Test 4: Add Scent decorator
    std::cout << "--- TEST 4: Rose + Ribbon + RedPot + Scent ---" << std::endl;
    myPlant->add(new Scent());
    myPlant->printPlant();
    std::cout << "Final price: R" << myPlant->getPrice() << std::endl
              << std::endl;

    // Test 5: Create Sunflower with decorations
    std::cout << "--- TEST 5: Sunflower with Multiple Decorations ---" << std::endl;
    Plant *sunflower = sFact->createPlant();
    sunflower->printPlant();
    std::cout << "Base sunflower price: R" << sunflower->getPrice() << std::endl;

    sunflower->add(new RedPot());
    sunflower->add(new Scent());
    sunflower->printPlant();
    std::cout << "Decorated sunflower price: R" << sunflower->getPrice() << std::endl
              << std::endl;

    // Test 6: Create Cactus with decorations
    std::cout << "--- TEST 6: Cactus with Decorations ---" << std::endl;
    Plant *cactus = cFact->createPlant();
    cactus->add(new Ribbon());
    cactus->add(new RedPot());
    cactus->printPlant();
    std::cout << "Decorated cactus price: R" << cactus->getPrice() << std::endl
              << std::endl;

    // Test 7: Composite - Group of plants
    std::cout << "--- TEST 7: Plant Group (Composite) ---" << std::endl;
    pg->add(myPlant);
    pg->add(sunflower);
    pg->add(cactus);
    std::cout << "Complete order contents:" << std::endl;
    pg->printOrder();
    std::cout << "Total group price: R" << pg->getPrice() << std::endl
              << std::endl;

    // Test 8: Nested groups
    std::cout << "--- TEST 8: Nested Plant Groups ---" << std::endl;
    PlantGroup *subGroup = new PlantGroup();
    Plant *rose2 = rFact->createPlant();
    rose2->add(new Ribbon());
    Plant *sunflower2 = sFact->createPlant();
    sunflower2->add(new Scent());

    subGroup->add(rose2);
    subGroup->add(sunflower2);

    PlantGroup *mainGroup = new PlantGroup();
    mainGroup->add(pg);
    mainGroup->add(subGroup);

    std::cout << "Nested group structure:" << std::endl;
    mainGroup->printOrder();
    std::cout << "Total nested group price: R" << mainGroup->getPrice() << std::endl
              << std::endl;

    // Test 9: Single heavily decorated plant
    std::cout << "--- TEST 9: Heavily Decorated Plant ---" << std::endl;
    Plant *fancyRose = rFact->createPlant();
    fancyRose->add(new Ribbon());
    fancyRose->add(new RedPot());
    fancyRose->add(new Scent());
    fancyRose->add(new Ribbon()); // Double ribbon
    fancyRose->printPlant();
    std::cout << "Fancy rose total price: R" << fancyRose->getPrice() << std::endl
              << std::endl;

    std::cout << "========================================" << std::endl;
    std::cout << "TESTING STRATEGY PATTERN WITH ORDERS" << std::endl;
    std::cout << "========================================" << std::endl
              << std::endl;

    // Test 10: Order with Normal Pricing Strategy
    std::cout << "--- TEST 10: Small Order (Normal Pricing) ---" << std::endl;
    PlantGroup *smallOrder = new PlantGroup();
    Plant *rose3 = rFact->createPlant();
    rose3->add(new Ribbon());
    smallOrder->add(rose3);

    std::cout << "========================================" << std::endl;
    std::cout << "ALL TESTS COMPLETED" << std::endl;
    std::cout << "========================================" << std::endl;

    // Cleanup
    delete mainGroup;
    delete fancyRose;
    delete fertMon;
    delete watMon;
    delete deadMon;
    delete rFact;
    delete sFact;
    delete cFact;
}

int main()
{
    CompAndDec();
    return 0;
}