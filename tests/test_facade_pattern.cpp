/**
 * @file test_facade_pattern.cpp
 * @brief Unit tests for Facade Pattern implementation
 * 
 * Tests CustomerFacade and GreenHouseFacade (excluding GUI dependencies).
 */

#include <gtest/gtest.h>
#include "CustomerFacade.h"
#include "GreenHouseFacade.h"
#include "Rose.h"
#include "RoseFactory.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class FacadePatternTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
    }
    
    void TearDown() override {
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

TEST_F(FacadePatternTest, CustomerFacadeCreatesSuccessfully) {
    CustomerFacade* facade = CustomerFacade::getInstance();
    EXPECT_NE(facade, nullptr);
}

TEST_F(FacadePatternTest, CustomerFacadeIsSingleton) {
    CustomerFacade* facade1 = CustomerFacade::getInstance();
    CustomerFacade* facade2 = CustomerFacade::getInstance();
    
    EXPECT_EQ(facade1, facade2) << "CustomerFacade should be a singleton";
}

TEST_F(FacadePatternTest, GreenHouseFacadeCreatesSuccessfully) {
    GreenHouseFacade* facade = GreenHouseFacade::getInstance();
    EXPECT_NE(facade, nullptr);
}

TEST_F(FacadePatternTest, GreenHouseFacadeIsSingleton) {
    GreenHouseFacade* facade1 = GreenHouseFacade::getInstance();
    GreenHouseFacade* facade2 = GreenHouseFacade::getInstance();
    
    EXPECT_EQ(facade1, facade2) << "GreenHouseFacade should be a singleton";
}

TEST_F(FacadePatternTest, GreenHouseFacadeCanAddPlant) {
    GreenHouseFacade* facade = GreenHouseFacade::getInstance();
    RoseFactory factory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    Plant* plant = factory.createPlant();
    
    EXPECT_NO_THROW(facade->addPlant(plant));
}

TEST_F(FacadePatternTest, GreenHouseFacadeCanGetAllPlants) {
    GreenHouseFacade* facade = GreenHouseFacade::getInstance();
    
    std::vector<Plant*> plants;
    EXPECT_NO_THROW(plants = facade->getAllPlants());
}

TEST_F(FacadePatternTest, GreenHouseFacadeCanRemovePlant) {
    GreenHouseFacade* facade = GreenHouseFacade::getInstance();
    RoseFactory factory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    Plant* plant = factory.createPlant();
    
    facade->addPlant(plant);
    EXPECT_NO_THROW(facade->removePlant(plant));
}

TEST_F(FacadePatternTest, GreenHouseFacadeSimplifilesComplexOperations) {
    GreenHouseFacade* facade = GreenHouseFacade::getInstance();
    RoseFactory factory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    Plant* plant = factory.createPlant();
    
    // Facade should simplify adding and removing plants
    facade->addPlant(plant);
    std::vector<Plant*> plants = facade->getAllPlants();
    
    bool found = false;
    for (auto p : plants) {
        if (p == plant) {
            found = true;
            break;
        }
    }
    
    EXPECT_TRUE(found) << "Added plant should be in the collection";
    
    facade->removePlant(plant);
}

TEST_F(FacadePatternTest, CustomerFacadeProvideSimplifiedInterface) {
    CustomerFacade* facade = CustomerFacade::getInstance();
    
    // Customer facade should provide simplified access
    EXPECT_NO_THROW(facade->browsePlants());
}

TEST_F(FacadePatternTest, CustomerFacadeCanCreateOrder) {
    CustomerFacade* facade = CustomerFacade::getInstance();
    RoseFactory factory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    Plant* plant = factory.createPlant();
    
    std::vector<Plant*> plants = {plant};
    
    EXPECT_NO_THROW(facade->createOrder(plants));
    
    delete plant;
}

TEST_F(FacadePatternTest, FacadesHideComplexity) {
    // Both facades should hide the complexity of the subsystem
    CustomerFacade* customerFacade = CustomerFacade::getInstance();
    GreenHouseFacade* greenhouseFacade = GreenHouseFacade::getInstance();
    
    EXPECT_NE(customerFacade, nullptr);
    EXPECT_NE(greenhouseFacade, nullptr);
    
    // Simple interface without exposing internal components
    EXPECT_NO_THROW(customerFacade->browsePlants());
    EXPECT_NO_THROW(greenhouseFacade->getAllPlants());
}
