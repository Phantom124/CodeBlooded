/**
 * @file test_proxy_pattern.cpp
 * @brief Unit tests for Proxy Pattern implementation
 * 
 * Tests ProxyGreenHouseInventory as a proxy to RealGreenHouseInventory.
 */

#include <gtest/gtest.h>
#include "ProxyGreenHouseInventory.h"
#include "RealGreenHouseInventory.h"
#include "GreenHouseInventory.h"
#include "Rose.h"
#include "RoseFactory.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class ProxyPatternTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    RoseFactory* factory;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    }
    
    void TearDown() override {
        delete factory;
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

TEST_F(ProxyPatternTest, ProxyInventoryCreatesSuccessfully) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    EXPECT_NE(proxy, nullptr);
    delete proxy;
}

TEST_F(ProxyPatternTest, RealInventoryCreatesSuccessfully) {
    RealGreenHouseInventory* realInventory = new RealGreenHouseInventory();
    EXPECT_NE(realInventory, nullptr);
    delete realInventory;
}

TEST_F(ProxyPatternTest, ProxyCanAddPlant) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    Plant* plant = factory->createPlant();
    
    EXPECT_NO_THROW(proxy->addPlant(plant));
    
    delete proxy;
}

TEST_F(ProxyPatternTest, ProxyCanRemovePlant) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    Plant* plant = factory->createPlant();
    
    proxy->addPlant(plant);
    EXPECT_NO_THROW(proxy->removePlant(plant));
    
    delete proxy;
}

TEST_F(ProxyPatternTest, ProxyCanGetAllPlants) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    Plant* plant = factory->createPlant();
    
    proxy->addPlant(plant);
    
    std::vector<Plant*> plants;
    EXPECT_NO_THROW(plants = proxy->getAllPlants());
    EXPECT_GE(plants.size(), 1);
    
    delete proxy;
}

TEST_F(ProxyPatternTest, ProxyDelegatesOperationsToRealObject) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    Plant* plant1 = factory->createPlant();
    Plant* plant2 = factory->createPlant();
    
    proxy->addPlant(plant1);
    proxy->addPlant(plant2);
    
    std::vector<Plant*> plants = proxy->getAllPlants();
    EXPECT_EQ(plants.size(), 2);
    
    delete proxy;
}

TEST_F(ProxyPatternTest, ProxyControlsAccessToRealObject) {
    // Proxy should control access to the real inventory
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    
    // Proxy should create real inventory lazily or control access
    Plant* plant = factory->createPlant();
    proxy->addPlant(plant);
    
    EXPECT_NO_THROW(proxy->getAllPlants());
    
    delete proxy;
}

TEST_F(ProxyPatternTest, ProxyAndRealInventoryHaveSameInterface) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    RealGreenHouseInventory* real = new RealGreenHouseInventory();
    
    Plant* plant1 = factory->createPlant();
    Plant* plant2 = factory->createPlant();
    
    // Both should support the same operations
    EXPECT_NO_THROW(proxy->addPlant(plant1));
    EXPECT_NO_THROW(real->addPlant(plant2));
    
    EXPECT_NO_THROW(proxy->getAllPlants());
    EXPECT_NO_THROW(real->getAllPlants());
    
    delete proxy;
    delete real;
}

TEST_F(ProxyPatternTest, ProxyCanFindPlantByID) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    Plant* plant = factory->createPlant();
    
    proxy->addPlant(plant);
    
    Plant* found = proxy->findPlantByID(plant->getPlantID());
    EXPECT_EQ(found, plant);
    
    delete proxy;
}

TEST_F(ProxyPatternTest, ProxyCanUpdatePlant) {
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    Plant* plant = factory->createPlant();
    
    proxy->addPlant(plant);
    
    plant->grow();
    EXPECT_NO_THROW(proxy->updatePlant(plant));
    
    delete proxy;
}

TEST_F(ProxyPatternTest, ProxyProvidesProtection) {
    // Proxy should provide protection or access control
    ProxyGreenHouseInventory* proxy = new ProxyGreenHouseInventory();
    
    // Test that proxy can handle operations safely
    EXPECT_NO_THROW(proxy->getAllPlants());
    
    Plant* plant = factory->createPlant();
    EXPECT_NO_THROW(proxy->addPlant(plant));
    EXPECT_NO_THROW(proxy->removePlant(plant));
    
    delete proxy;
}
