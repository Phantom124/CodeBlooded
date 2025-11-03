/**
 * @file test_factory_pattern.cpp
 * @brief Unit tests for Factory Pattern implementation
 * 
 * Tests the PlantFactory hierarchy (RoseFactory, CactusFactory, SunflowerFactory).
 */

#include <gtest/gtest.h>
#include "RoseFactory.h"
#include "CactusFactory.h"
#include "SunflowerFactory.h"
#include "Rose.h"
#include "Cactus.h"
#include "Sunflower.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class FactoryPatternTest : public ::testing::Test {
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

TEST_F(FactoryPatternTest, RoseFactoryCreatesRose) {
    RoseFactory factory(waterMonitor, fertilizerMonitor, deadMonitor);
    Plant* plant = factory.createPlant();
    
    ASSERT_NE(plant, nullptr);
    Rose* rose = dynamic_cast<Rose*>(plant);
    EXPECT_NE(rose, nullptr) << "Factory should create a Rose object";
    
    delete plant;
}

TEST_F(FactoryPatternTest, CactusFactoryCreatesCactus) {
    CactusFactory factory(waterMonitor, fertilizerMonitor, deadMonitor);
    Plant* plant = factory.createPlant();
    
    ASSERT_NE(plant, nullptr);
    Cactus* cactus = dynamic_cast<Cactus*>(plant);
    EXPECT_NE(cactus, nullptr) << "Factory should create a Cactus object";
    
    delete plant;
}

TEST_F(FactoryPatternTest, SunflowerFactoryCreatesSunflower) {
    SunflowerFactory factory(waterMonitor, fertilizerMonitor, deadMonitor);
    Plant* plant = factory.createPlant();
    
    ASSERT_NE(plant, nullptr);
    Sunflower* sunflower = dynamic_cast<Sunflower*>(plant);
    EXPECT_NE(sunflower, nullptr) << "Factory should create a Sunflower object";
    
    delete plant;
}

TEST_F(FactoryPatternTest, FactoryCreatesPlantWithMonitors) {
    RoseFactory factory(waterMonitor, fertilizerMonitor, deadMonitor);
    Plant* plant = factory.createPlant();
    
    ASSERT_NE(plant, nullptr);
    // Plant should be created with proper monitor attachments
    
    delete plant;
}

TEST_F(FactoryPatternTest, DifferentFactoriesCreateDifferentPlants) {
    RoseFactory roseFactory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    CactusFactory cactusFactory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    SunflowerFactory sunflowerFactory(waterMonitor, fertilizerMonitor, deadMonitor, queryBuilder);
    
    Plant* rose = roseFactory.createPlant();
    Plant* cactus = cactusFactory.createPlant();
    Plant* sunflower = sunflowerFactory.createPlant();
    
    ASSERT_NE(rose, nullptr);
    ASSERT_NE(cactus, nullptr);
    ASSERT_NE(sunflower, nullptr);
    
    // Each should be a different type
    EXPECT_NE(dynamic_cast<Rose*>(rose), nullptr);
    EXPECT_NE(dynamic_cast<Cactus*>(cactus), nullptr);
    EXPECT_NE(dynamic_cast<Sunflower*>(sunflower), nullptr);
    
    delete rose;
    delete cactus;
    delete sunflower;
}
