#include "Cactus.h"
#include "Rose.h"
#include "Sunflower.h"
#include "SeedState.h"
#include "GerminationState.h"
#include "SaplingState.h"
#include "MatureState.h"
#include "DeadState.h"
#include "HydratedState.h"
#include "NotHydratedState.h"
#include "FertilizedState.h"
#include "NonFertilizerState.h"
#include "PlantMonitor.h"
#include "DeadMonitor.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "WaterHandler.h"
#include "FertilizerHandler.h"
#include "DeadHandler.h"
#include "StaffSystem.h"
#include "PlantFactory.h"
#include "CactusFactory.h"
#include "RoseFactory.h"
#include "SunflowerFactory.h"
#include <iostream>
#include <iomanip>
#include <cassert>

void printSeparator() {
    std::cout << "\n" << std::string(80, '=') << "\n";
}

void printHeader(const std::string& header) {
    printSeparator();
    std::cout << "  " << header << "\n";
    printSeparator();
}

// Test Plant Growth States
void testPlantGrowthStates() {
    printHeader("TESTING PLANT GROWTH STATES");
    
    std::cout << "\n1. Testing SeedState:\n";
    SeedState* seedState = new SeedState();
    assert(seedState->getStateName() == "Seed");
    assert(seedState->getPriceEffect() == 1.0);
    std::cout << "   ✓ State Name: " << seedState->getStateName() << "\n";
    std::cout << "   ✓ Price Effect: " << seedState->getPriceEffect() << "x\n";
    
    PlantGrowthState* nextState1 = seedState->getNextState(5);
    assert(nextState1 == nullptr);
    std::cout << "   ✓ Next State (careCount=5): No change (as expected)\n";
    
    PlantGrowthState* nextState2 = seedState->getNextState(15);
    assert(nextState2 != nullptr);
    assert(nextState2->getStateName() == "Germination");
    std::cout << "   ✓ Next State (careCount=15): " << nextState2->getStateName() << "\n";
    delete seedState;
    delete nextState2;
    
    std::cout << "\n2. Testing GerminationState:\n";
    GerminationState* germState = new GerminationState();
    assert(germState->getStateName() == "Germination");
    assert(germState->getPriceEffect() == 1.25);
    std::cout << "   ✓ State Name: " << germState->getStateName() << "\n";
    std::cout << "   ✓ Price Effect: " << germState->getPriceEffect() << "x\n";
    
    PlantGrowthState* nextState3 = germState->getNextState(15);
    assert(nextState3 == nullptr);
    std::cout << "   ✓ Next State (careCount=15): No change (as expected)\n";
    
    PlantGrowthState* nextState4 = germState->getNextState(25);
    assert(nextState4 != nullptr);
    assert(nextState4->getStateName() == "Sapling");
    std::cout << "   ✓ Next State (careCount=25): " << nextState4->getStateName() << "\n";
    delete germState;
    delete nextState4;
    
    std::cout << "\n3. Testing SaplingState:\n";
    SaplingState* saplingState = new SaplingState();
    assert(saplingState->getStateName() == "Sapling");
    assert(saplingState->getPriceEffect() == 1.5);
    std::cout << "   ✓ State Name: " << saplingState->getStateName() << "\n";
    std::cout << "   ✓ Price Effect: " << saplingState->getPriceEffect() << "x\n";
    
    PlantGrowthState* nextState5 = saplingState->getNextState(30);
    assert(nextState5 == nullptr);
    std::cout << "   ✓ Next State (careCount=30): No change (as expected)\n";
    
    PlantGrowthState* nextState6 = saplingState->getNextState(40);
    assert(nextState6 != nullptr);
    assert(nextState6->getStateName() == "Mature");
    std::cout << "   ✓ Next State (careCount=40): " << nextState6->getStateName() << "\n";
    delete saplingState;
    delete nextState6;
    
    std::cout << "\n4. Testing MatureState:\n";
    MatureState* matureState = new MatureState();
    assert(matureState->getStateName() == "Mature");
    assert(matureState->getPriceEffect() == 2.0);
    std::cout << "   ✓ State Name: " << matureState->getStateName() << "\n";
    std::cout << "   ✓ Price Effect: " << matureState->getPriceEffect() << "x\n";
    
    PlantGrowthState* nextState7 = matureState->getNextState(50);
    assert(nextState7 == nullptr);
    std::cout << "   ✓ Next State (careCount=50): No change (terminal state)\n";
    delete matureState;
    
    std::cout << "\n5. Testing DeadState:\n";
    DeadState* deadState = new DeadState();
    assert(deadState->getStateName() == "Dead");
    assert(deadState->getPriceEffect() == 0.0);
    std::cout << "   ✓ State Name: " << deadState->getStateName() << "\n";
    std::cout << "   ✓ Price Effect: " << deadState->getPriceEffect() << "x\n";
    
    PlantGrowthState* nextState8 = deadState->getNextState(50);
    assert(nextState8 == nullptr);
    std::cout << "   ✓ Next State (careCount=50): No change (terminal state)\n";
    delete deadState;
}

// Test Water States
void testWaterStates() {
    printHeader("TESTING WATER STATES");
    
    std::cout << "\n1. Testing HydratedState:\n";
    HydratedState* hydratedState = new HydratedState();
    assert(hydratedState->getStateName() == "Hydrated");
    assert(hydratedState->effect() == 5);
    std::cout << "   ✓ State Name: " << hydratedState->getStateName() << "\n";
    std::cout << "   ✓ Effect: " << hydratedState->effect() << "\n";
    
    Water* nextWaterState1 = hydratedState->getNextState(50, 30);
    assert(nextWaterState1 == nullptr);
    std::cout << "   ✓ Next State (currentLevel=50, lowLevel=30): No change\n";
    
    Water* nextWaterState2 = hydratedState->getNextState(20, 30);
    assert(nextWaterState2 != nullptr);
    assert(nextWaterState2->getStateName() == "NotHydrated");
    std::cout << "   ✓ Next State (currentLevel=20, lowLevel=30): " 
              << nextWaterState2->getStateName() << "\n";
    delete hydratedState;
    delete nextWaterState2;
    
    std::cout << "\n2. Testing NotHydratedState:\n";
    NotHydratedState* notHydratedState = new NotHydratedState();
    assert(notHydratedState->getStateName() == "NotHydrated");
    assert(notHydratedState->effect() == -5);
    std::cout << "   ✓ State Name: " << notHydratedState->getStateName() << "\n";
    std::cout << "   ✓ Effect: " << notHydratedState->effect() << "\n";
    
    Water* nextWaterState3 = notHydratedState->getNextState(20, 30);
    assert(nextWaterState3 == nullptr);
    std::cout << "   ✓ Next State (currentLevel=20, lowLevel=30): No change (stays NotHydrated)\n";
    
    Water* nextWaterState4 = notHydratedState->getNextState(40, 30);
    assert(nextWaterState4 != nullptr);
    assert(nextWaterState4->getStateName() == "Hydrated");
    std::cout << "   ✓ Next State (currentLevel=40, lowLevel=30): " 
              << nextWaterState4->getStateName() << " (restored!)\n";
    delete notHydratedState;
    delete nextWaterState4;
}

// Test Fertilizer States
void testFertilizerStates() {
    printHeader("TESTING FERTILIZER STATES");
    
    std::cout << "\n1. Testing FertilizedState:\n";
    FertilizedState* fertilizedState = new FertilizedState();
    assert(fertilizedState->getStateName() == "Fertilized");
    assert(fertilizedState->effect() == 5);
    std::cout << "   ✓ State Name: " << fertilizedState->getStateName() << "\n";
    std::cout << "   ✓ Effect: " << fertilizedState->effect() << "\n";
    
    Fertilizer* nextFertState1 = fertilizedState->getNextState(80, 70);
    assert(nextFertState1 == nullptr);
    std::cout << "   ✓ Next State (currentLevel=80, lowLevel=70): No change\n";
    
    Fertilizer* nextFertState2 = fertilizedState->getNextState(60, 70);
    assert(nextFertState2 != nullptr);
    assert(nextFertState2->getStateName() == "NonFertilized");
    std::cout << "   ✓ Next State (currentLevel=60, lowLevel=70): " 
              << nextFertState2->getStateName() << "\n";
    delete fertilizedState;
    delete nextFertState2;
    
    std::cout << "\n2. Testing NonFertilizerState:\n";
    NonFertilizerState* nonFertState = new NonFertilizerState();
    assert(nonFertState->getStateName() == "NonFertilized");
    assert(nonFertState->effect() == -5);
    std::cout << "   ✓ State Name: " << nonFertState->getStateName() << "\n";
    std::cout << "   ✓ Effect: " << nonFertState->effect() << "\n";
    
    Fertilizer* nextFertState3 = nonFertState->getNextState(60, 70);
    assert(nextFertState3 == nullptr);
    std::cout << "   ✓ Next State (currentLevel=60, lowLevel=70): No change (stays NonFertilized)\n";
    
    Fertilizer* nextFertState4 = nonFertState->getNextState(80, 70);
    assert(nextFertState4 != nullptr);
    assert(nextFertState4->getStateName() == "Fertilized");
    std::cout << "   ✓ Next State (currentLevel=80, lowLevel=70): " 
              << nextFertState4->getStateName() << " (restored!)\n";
    delete nonFertState;
    delete nextFertState4;
}

// Test Plant Classes
void testPlantClasses() {
    printHeader("TESTING PLANT CLASSES");
    
    std::cout << "\n1. Testing Cactus (Default Constructor):\n";
    Cactus* cactus = new Cactus();
    assert(cactus->getName() == "Cactus");
    std::cout << "   ✓ Name: " << cactus->getName() << "\n";
    std::cout << "   ✓ Water Level: " << cactus->getWaterLevel() << "\n";
    std::cout << "   ✓ Fertilizer Level: " << cactus->getFertilizerLevel() << "\n";
    delete cactus;
    
    // std::cout << "\n2. Testing Cactus (Parameterized Constructor):\n";
    // SeedState* seedState = new SeedState();
    // Cactus* cactus2 = new Cactus(seedState, 85, 75);
    // assert(cactus2->getName() == "Cactus");
    // assert(cactus2->getWaterLevel() == 85);
    // assert(cactus2->getFertilizerLevel() == 75);
    // std::cout << "   ✓ Name: " << cactus2->getName() << "\n";
    // std::cout << "   ✓ Water Level: " << cactus2->getWaterLevel() << "\n";
    // std::cout << "   ✓ Fertilizer Level: " << cactus2->getFertilizerLevel() << "\n";
    // delete cactus2;
    // delete seedState;
    
    std::cout << "\n3. Testing Rose (Default Constructor):\n";
    Rose* rose = new Rose();
    assert(rose->getName() == "Rose");
    std::cout << "   ✓ Name: " << rose->getName() << "\n";
    std::cout << "   ✓ Water Level: " << rose->getWaterLevel() << "\n";
    std::cout << "   ✓ Fertilizer Level: " << rose->getFertilizerLevel() << "\n";
    delete rose;
    
    // std::cout << "\n4. Testing Rose (Parameterized Constructor):\n";
    // GerminationState* germState = new GerminationState();
    // Rose* rose2 = new Rose(germState, 90, 80);
    // assert(rose2->getName() == "Rose");
    // assert(rose2->getWaterLevel() == 90);
    // assert(rose2->getFertilizerLevel() == 80);
    // assert(rose2->getState()->getStateName() == "Germination");
    // std::cout << "   ✓ Name: " << rose2->getName() << "\n";
    // std::cout << "   ✓ Water Level: " << rose2->getWaterLevel() << "\n";
    // std::cout << "   ✓ Fertilizer Level: " << rose2->getFertilizerLevel() << "\n";
    // std::cout << "   ✓ State: " << rose2->getState()->getStateName() << "\n";
    // delete rose2;
    // delete germState;
    
    std::cout << "\n5. Testing Sunflower (Default Constructor):\n";
    Sunflower* sunflower = new Sunflower();
    assert(sunflower->getName() == "Sunflower");
    std::cout << "   ✓ Name: " << sunflower->getName() << "\n";
    std::cout << "   ✓ Water Level: " << sunflower->getWaterLevel() << "\n";
    std::cout << "   ✓ Fertilizer Level: " << sunflower->getFertilizerLevel() << "\n";
    delete sunflower;
    
    // std::cout << "\n6. Testing Sunflower (Parameterized Constructor):\n";
    // MatureState* matureState = new MatureState();
    // Sunflower* sunflower2 = new Sunflower(matureState, 95, 85);
    // assert(sunflower2->getName() == "Sunflower");
    // assert(sunflower2->getWaterLevel() == 95);
    // assert(sunflower2->getFertilizerLevel() == 85);
    // assert(sunflower2->getState()->getStateName() == "Mature");
    // std::cout << "   ✓ Name: " << sunflower2->getName() << "\n";
    // std::cout << "   ✓ Water Level: " << sunflower2->getWaterLevel() << "\n";
    // std::cout << "   ✓ Fertilizer Level: " << sunflower2->getFertilizerLevel() << "\n";
    // std::cout << "   ✓ State: " << sunflower2->getState()->getStateName() << "\n";
    // delete sunflower2;
    // delete matureState;
}

// Test Monitor Classes
void testMonitorClasses() {
    printHeader("TESTING PLANT MONITOR CLASSES");
    
    std::cout << "\n1. Testing DeadMonitor:\n";
    DeadMonitor* deadMonitor = new DeadMonitor();
    assert(deadMonitor != nullptr);
    std::cout << "   ✓ DeadMonitor created successfully\n";
    std::cout << "   Testing with nullptr plant:\n";
    deadMonitor->update(nullptr);
    std::cout << "   ✓ Handles nullptr gracefully\n";
    delete deadMonitor;
    
    std::cout << "\n2. Testing WaterMonitor:\n";
    WaterMonitor* waterMonitor = new WaterMonitor();
    assert(waterMonitor != nullptr);
    std::cout << "   ✓ WaterMonitor created successfully\n";
    std::cout << "   Testing with nullptr plant:\n";
    waterMonitor->update(nullptr);
    std::cout << "   ✓ Handles nullptr gracefully\n";
    delete waterMonitor;
    
    std::cout << "\n3. Testing FertilizerMonitor:\n";
    FertilizerMonitor* fertilizerMonitor = new FertilizerMonitor();
    assert(fertilizerMonitor != nullptr);
    std::cout << "   ✓ FertilizerMonitor created successfully\n";
    std::cout << "   Testing with nullptr plant:\n";
    fertilizerMonitor->update(nullptr);
    std::cout << "   ✓ Handles nullptr gracefully\n";
    delete fertilizerMonitor;
}

// Test Monitor Updates with Plants
void testMonitorUpdates() {
    printHeader("TESTING MONITOR UPDATES WITH PLANTS");
    
    std::cout << "\n1. Testing WaterMonitor with Hydrated Plant:\n";
    WaterMonitor* waterMonitor = new WaterMonitor();
    Rose* rose = new Rose();
    std::cout << "   Current water state: " << rose->getWaterStateName() << "\n";
    std::cout << "   Calling waterMonitor->update():\n   ";
    waterMonitor->update(rose);
    delete waterMonitor;
    delete rose;
    
    std::cout << "\n2. Testing FertilizerMonitor with Fertilized Plant:\n";
    FertilizerMonitor* fertMonitor = new FertilizerMonitor();
    Cactus* cactus = new Cactus();
    std::cout << "   Current fertilizer state: " << cactus->getFertilizerStateName() << "\n";
    std::cout << "   Calling fertMonitor->update():\n   ";
    fertMonitor->update(cactus);
    delete fertMonitor;
    delete cactus;
    
    std::cout << "\n3. Testing DeadMonitor with Living Plant:\n";
    DeadMonitor* deadMonitor = new DeadMonitor();
    Sunflower* sunflower = new Sunflower();
    std::cout << "   Current health: " << sunflower->getHealth() << "\n";
    std::cout << "   Calling deadMonitor->update():\n   ";
    deadMonitor->update(sunflower);
    std::cout << "   (No output expected - plant is alive)\n";
    delete deadMonitor;
    delete sunflower;
}

// Test State Transitions
void testStateTransitions() {
    printHeader("TESTING STATE TRANSITIONS");
    
    std::cout << "\n1. Full Growth Cycle (Seed -> Germination -> Sapling -> Mature):\n";
    PlantGrowthState* currentState = new SeedState();
    int careCount = 0;
    
    assert(currentState->getStateName() == "Seed");
    assert(currentState->getPriceEffect() == 1.0);
    std::cout << "   ✓ Initial State: " << currentState->getStateName() 
              << " (Price Effect: " << currentState->getPriceEffect() << "x)\n";
    
    careCount = 11;
    PlantGrowthState* tempState = currentState->getNextState(careCount);
    assert(tempState != nullptr);
    delete currentState;
    currentState = tempState;
    assert(currentState->getStateName() == "Germination");
    assert(currentState->getPriceEffect() == 1.25);
    std::cout << "   ✓ After " << careCount << " care: " << currentState->getStateName() 
              << " (Price Effect: " << currentState->getPriceEffect() << "x)\n";
    
    careCount = 21;
    tempState = currentState->getNextState(careCount);
    assert(tempState != nullptr);
    delete currentState;
    currentState = tempState;
    assert(currentState->getStateName() == "Sapling");
    assert(currentState->getPriceEffect() == 1.5);
    std::cout << "   ✓ After " << careCount << " care: " << currentState->getStateName() 
              << " (Price Effect: " << currentState->getPriceEffect() << "x)\n";
    
    careCount = 36;
    tempState = currentState->getNextState(careCount);
    assert(tempState != nullptr);
    delete currentState;
    currentState = tempState;
    assert(currentState->getStateName() == "Mature");
    assert(currentState->getPriceEffect() == 2.0);
    std::cout << "   ✓ After " << careCount << " care: " << currentState->getStateName() 
              << " (Price Effect: " << currentState->getPriceEffect() << "x)\n";
    
    delete currentState;
    
    std::cout << "\n2. Water State Transitions:\n";
    Water* waterState = new HydratedState();
    assert(waterState->getStateName() == "Hydrated");
    assert(waterState->effect() == 5);
    std::cout << "   ✓ Initial: " << waterState->getStateName() 
              << " (Effect: " << waterState->effect() << ")\n";
    
    Water* newWaterState = waterState->getNextState(25, 30);
    assert(newWaterState != nullptr);
    assert(newWaterState->getStateName() == "NotHydrated");
    assert(newWaterState->effect() == -5);
    delete waterState;
    waterState = newWaterState;
    std::cout << "   ✓ After dropping below threshold: " << waterState->getStateName() 
              << " (Effect: " << waterState->effect() << ")\n";
    
    Water* restoredWaterState = waterState->getNextState(35, 30);
    assert(restoredWaterState != nullptr);
    assert(restoredWaterState->getStateName() == "Hydrated");
    assert(restoredWaterState->effect() == 5);
    delete waterState;
    waterState = restoredWaterState;
    std::cout << "   ✓ After rising above threshold: " << waterState->getStateName() 
              << " (Effect: " << waterState->effect() << ") - Restored!\n";
    delete waterState;
    
    std::cout << "\n3. Fertilizer State Transitions:\n";
    Fertilizer* fertState = new FertilizedState();
    assert(fertState->getStateName() == "Fertilized");
    assert(fertState->effect() == 5);
    std::cout << "   ✓ Initial: " << fertState->getStateName() 
              << " (Effect: " << fertState->effect() << ")\n";
    
    Fertilizer* newFertState = fertState->getNextState(65, 70);
    assert(newFertState != nullptr);
    assert(newFertState->getStateName() == "NonFertilized");
    assert(newFertState->effect() == -5);
    delete fertState;
    fertState = newFertState;
    std::cout << "   ✓ After dropping below threshold: " << fertState->getStateName() 
              << " (Effect: " << fertState->effect() << ")\n";
    
    Fertilizer* restoredFertState = fertState->getNextState(75, 70);
    assert(restoredFertState != nullptr);
    assert(restoredFertState->getStateName() == "Fertilized");
    assert(restoredFertState->effect() == 5);
    delete fertState;
    fertState = restoredFertState;
    std::cout << "   ✓ After rising above threshold: " << fertState->getStateName() 
              << " (Effect: " << fertState->effect() << ") - Restored!\n";
    delete fertState;
}

// Summary of Plant Properties
void testPlantProperties() {
    printHeader("PLANT PROPERTIES SUMMARY");
    
    std::cout << "\n" << std::setw(15) << "Plant" 
              << std::setw(12) << "Price" 
              << std::setw(18) << "Water Retention" 
              << std::setw(18) << "Low Water Lvl"
              << std::setw(20) << "Fert Retention"
              << std::setw(18) << "Low Fert Lvl" << "\n";
    std::cout << std::string(100, '-') << "\n";
    
    std::cout << std::setw(15) << "Cactus" 
              << std::setw(12) << "15" 
              << std::setw(18) << "0.95" 
              << std::setw(18) << "15"
              << std::setw(20) << "0.90"
              << std::setw(18) << "10" << "\n";
              
    std::cout << std::setw(15) << "Rose" 
              << std::setw(12) << "20" 
              << std::setw(18) << "0.85" 
              << std::setw(18) << "30"
              << std::setw(20) << "0.60"
              << std::setw(18) << "70" << "\n";
              
    std::cout << std::setw(15) << "Sunflower" 
              << std::setw(12) << "25" 
              << std::setw(18) << "0.72" 
              << std::setw(18) << "55"
              << std::setw(20) << "0.85"
              << std::setw(18) << "20" << "\n";
}
#include "RoseFactory.h"
int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║           COMPREHENSIVE PLANT GROWTH SIMULATION TEST SUITE                 ║\n";
    std::cout << "║                      With Assertion Testing                                ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";
    
    try {
        // // Run all tests
        // testPlantGrowthStates();
        // testWaterStates();
        // testFertilizerStates();
        // testPlantClasses();
        // testMonitorClasses();
        // testMonitorUpdates();
        // testStateTransitions();
        // testPlantProperties();
        
        // printSeparator();
        // std::cout << "\n  ✓✓✓ ALL TESTS PASSED SUCCESSFULLY! ✓✓✓\n";
        // printSeparator();
        // std::cout << "\n";


        WaterMonitor* waterMonitor = new WaterMonitor();
        FertilizerMonitor* fertilizerMonitor = new FertilizerMonitor();
        DeadMonitor* deadMonitor = new DeadMonitor();

        WaterHandler* waterHandler = new WaterHandler();
        FertilizerHandler* fertilizerHandler = new FertilizerHandler();
        DeadHandler* deadHandler = new DeadHandler();

        StaffSystem* staffSystem = new StaffSystem();//staff system should be able to empty
        staffSystem->addHandler(fertilizerHandler);
        staffSystem->addHandler(deadHandler);
        staffSystem->addHandler(waterHandler);

        waterMonitor->setStaffSystem(staffSystem);
        fertilizerMonitor->setStaffSystem(staffSystem);
        deadMonitor->setStaffSystem(staffSystem);

        RoseFactory* roseFactory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
        Plant* rosePlant = roseFactory->createPlant();

        rosePlant->print();

        bool doIt;
        std::cin >> doIt;
        while(doIt){
            std::cout << "Simulating growth for 1 hour...\n";
            rosePlant->hoursHasPassed();
            std::cout << "Current state of the plant:\n";
            rosePlant->print();
            std::cin >> doIt;
        }
        delete rosePlant;
        std::cout<< "\nDONE\n" ;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n\n❌ TEST FAILED WITH EXCEPTION: " << e.what() << "\n\n";
        return 1;
    } catch (...) {
        std::cerr << "\n\n❌ TEST FAILED WITH UNKNOWN EXCEPTION\n\n";
        return 1;
    }
}