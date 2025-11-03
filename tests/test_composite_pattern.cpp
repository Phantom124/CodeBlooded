/**
 * @file test_composite_pattern.cpp
 * @brief Unit tests for Composite Pattern implementation
 * 
 * Tests PlantComponent, Plant, and PlantGroup classes.
 */

#include <gtest/gtest.h>
#include "PlantComponent.h"
#include "Plant.h"
#include "PlantGroup.h"
#include "Rose.h"
#include "Cactus.h"
#include "RoseFactory.h"
#include "CactusFactory.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class CompositePatternTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    RoseFactory* roseFactory;
    CactusFactory* cactusFactory;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
        roseFactory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
        cactusFactory = new CactusFactory(waterMonitor, fertilizerMonitor, deadMonitor);
    }
    
    void TearDown() override {
        delete roseFactory;
        delete cactusFactory;
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

TEST_F(CompositePatternTest, PlantGroupCreatesSuccessfully) {
    PlantGroup* group = new PlantGroup();
    EXPECT_NE(group, nullptr);
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupCanAddPlant) {
    PlantGroup* group = new PlantGroup();
    Plant* plant = roseFactory->createPlant();
    
    EXPECT_NO_THROW(group->addPlant(plant));
    
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupCanRemovePlant) {
    PlantGroup* group = new PlantGroup();
    Plant* plant = roseFactory->createPlant();
    
    group->addPlant(plant);
    EXPECT_NO_THROW(group->removePlant(plant));
    
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupCanGetPlants) {
    PlantGroup* group = new PlantGroup();
    Plant* plant1 = roseFactory->createPlant();
    Plant* plant2 = cactusFactory->createPlant();
    
    group->addPlant(plant1);
    group->addPlant(plant2);
    
    std::vector<PlantComponent*> plants = group->getPlantComponents();
    EXPECT_EQ(plants.size(), 2);
    
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupCalculatesTotalPrice) {
    PlantGroup* group = new PlantGroup();
    Plant* plant1 = roseFactory->createPlant();
    Plant* plant2 = cactusFactory->createPlant();
    
    double expectedPrice = plant1->getPrice() + plant2->getPrice();
    
    group->addPlant(plant1);
    group->addPlant(plant2);
    
    EXPECT_DOUBLE_EQ(group->getPrice(), expectedPrice);
    
    delete group;
}

TEST_F(CompositePatternTest, EmptyPlantGroupHasZeroPrice) {
    PlantGroup* group = new PlantGroup();
    
    EXPECT_DOUBLE_EQ(group->getPrice(), 0.0);
    
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupDescriptionIncludesAllPlants) {
    PlantGroup* group = new PlantGroup();
    Plant* rose = roseFactory->createPlant();
    Plant* cactus = cactusFactory->createPlant();
    
    group->addPlant(rose);
    group->addPlant(cactus);
    
    std::string description = group->getDescription();
    EXPECT_GT(description.length(), 0);
    
    delete group;
}

TEST_F(CompositePatternTest, PlantAndPlantGroupShareSameInterface) {
    Plant* plant = roseFactory->createPlant();
    PlantGroup* group = new PlantGroup();
    
    // Both should support getPrice() and getDescription()
    EXPECT_NO_THROW(plant->getPrice());
    EXPECT_NO_THROW(group->getPrice());
    EXPECT_NO_THROW(plant->getDescription());
    EXPECT_NO_THROW(group->getDescription());
    
    delete plant;
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupCanContainMultiplePlants) {
    PlantGroup* group = new PlantGroup();
    
    for (int i = 0; i < 5; i++) {
        Plant* plant = roseFactory->createPlant();
        group->addPlant(plant);
    }
    
    std::vector<PlantComponent*> plants = group->getPlantComponents();
    EXPECT_EQ(plants.size(), 5);
    
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupHandlesMixedPlantTypes) {
    PlantGroup* group = new PlantGroup();
    Plant* rose1 = roseFactory->createPlant();
    Plant* cactus1 = cactusFactory->createPlant();
    Plant* rose2 = roseFactory->createPlant();
    
    group->addPlant(rose1);
    group->addPlant(cactus1);
    group->addPlant(rose2);
    
    std::vector<PlantComponent*> plants = group->getPlantComponents();
    EXPECT_EQ(plants.size(), 3);
    
    delete group;
}

TEST_F(CompositePatternTest, RemovingPlantUpdatesPrice) {
    PlantGroup* group = new PlantGroup();
    Plant* plant1 = roseFactory->createPlant();
    Plant* plant2 = cactusFactory->createPlant();
    
    group->addPlant(plant1);
    group->addPlant(plant2);
    double priceWithBoth = group->getPrice();
    
    group->removePlant(plant2);
    double priceWithOne = group->getPrice();
    
    EXPECT_LT(priceWithOne, priceWithBoth);
    EXPECT_DOUBLE_EQ(priceWithOne, plant1->getPrice());
    
    delete group;
}

TEST_F(CompositePatternTest, PlantGroupSupportsIterativeTreatment) {
    PlantGroup* group = new PlantGroup();
    
    for (int i = 0; i < 3; i++) {
        group->addPlant(roseFactory->createPlant());
    }
    
    // Should be able to iterate through plants uniformly
    std::vector<PlantComponent*> components = group->getPlantComponents();
    for (auto component : components) {
        EXPECT_NE(component, nullptr);
        EXPECT_GT(component->getPrice(), 0);
    }
    
    delete group;
}
