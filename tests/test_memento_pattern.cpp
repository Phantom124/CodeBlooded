/**
 * @file test_memento_pattern.cpp
 * @brief Unit tests for Memento Pattern implementation
 * 
 * Tests OrderMemento and Caretaker classes.
 */

#include <gtest/gtest.h>
#include "Order.h"
#include "OrderMemento.h"
#include "Caretaker.h"
#include "PlantGroup.h"
#include "Rose.h"
#include "RoseFactory.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"
#include "QueryBuilder.h"

class MementoPatternTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    RoseFactory* factory;
    Caretaker* caretaker;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
        caretaker = new Caretaker();
    }
    
    void TearDown() override {
        delete caretaker;
        delete factory;
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

TEST_F(MementoPatternTest, OrderCreatesMemento) {
    PlantGroup* group = new PlantGroup();
    Plant* plant = factory->createPlant();
    group->addPlant(plant);
    
    Order* order = new Order(group);
    OrderMemento* memento = order->createMemento();
    
    ASSERT_NE(memento, nullptr);
    EXPECT_GT(memento->getReceiptID().length(), 0) << "Memento should have a receipt ID";
    
    delete memento;
    delete order;
}

TEST_F(MementoPatternTest, MementoStoresOrderPrice) {
    PlantGroup* group = new PlantGroup();
    Plant* plant = factory->createPlant();
    group->addPlant(plant);
    
    Order* order = new Order(group);
    double expectedPrice = order->getPrice();
    
    OrderMemento* memento = order->createMemento();
    
    EXPECT_DOUBLE_EQ(memento->getOrderPrice(), expectedPrice);
    
    delete memento;
    delete order;
}

TEST_F(MementoPatternTest, MementoStoresPlants) {
    PlantGroup* group = new PlantGroup();
    Plant* plant1 = factory->createPlant();
    Plant* plant2 = factory->createPlant();
    group->addPlant(plant1);
    group->addPlant(plant2);
    
    Order* order = new Order(group);
    OrderMemento* memento = order->createMemento();
    
    std::vector<PlantSnapshot*> plants = memento->getPlants();
    EXPECT_EQ(plants.size(), 2) << "Memento should store all plants";
    
    delete memento;
    delete order;
}

TEST_F(MementoPatternTest, MementoStoresOrderDate) {
    PlantGroup* group = new PlantGroup();
    Plant* plant = factory->createPlant();
    group->addPlant(plant);
    
    Order* order = new Order(group);
    OrderMemento* memento = order->createMemento();
    
    auto orderDate = memento->getOrderDate();
    auto now = std::chrono::system_clock::now();
    
    // Order date should be close to current time (within 1 second)
    auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - orderDate);
    EXPECT_LE(diff.count(), 1) << "Order date should be recent";
    
    delete memento;
    delete order;
}

TEST_F(MementoPatternTest, CaretakerStoresMemento) {
    PlantGroup* group = new PlantGroup();
    Plant* plant = factory->createPlant();
    group->addPlant(plant);
    
    Order* order = new Order(group);
    OrderMemento* memento = order->createMemento();
    
    std::string receiptID = memento->getReceiptID();
    caretaker->addMemento(receiptID, *memento);
    
    OrderMemento* retrieved = caretaker->getMemento(receiptID);
    ASSERT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->getReceiptID(), receiptID);
    
    delete memento;
    delete order;
}

TEST_F(MementoPatternTest, CaretakerRetrievesCorrectMemento) {
    // Create multiple orders
    PlantGroup* group1 = new PlantGroup();
    Plant* plant1 = factory->createPlant();
    group1->addPlant(plant1);
    Order* order1 = new Order(group1);
    OrderMemento* memento1 = order1->createMemento();
    
    PlantGroup* group2 = new PlantGroup();
    Plant* plant2 = factory->createPlant();
    group2->addPlant(plant2);
    Order* order2 = new Order(group2);
    OrderMemento* memento2 = order2->createMemento();
    
    // Store both
    caretaker->addMemento(memento1->getReceiptID(), *memento1);
    caretaker->addMemento(memento2->getReceiptID(), *memento2);
    
    // Retrieve specific memento
    OrderMemento* retrieved = caretaker->getMemento(memento1->getReceiptID());
    ASSERT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->getReceiptID(), memento1->getReceiptID());
    EXPECT_DOUBLE_EQ(retrieved->getOrderPrice(), memento1->getOrderPrice());
    
    delete memento1;
    delete memento2;
    delete order1;
    delete order2;
}

TEST_F(MementoPatternTest, CaretakerReturnsNullForNonexistentReceipt) {
    OrderMemento* retrieved = caretaker->getMemento("NONEXISTENT-ID");
    EXPECT_EQ(retrieved, nullptr);
}

TEST_F(MementoPatternTest, MementoCanBeRestored) {
    PlantGroup* group = new PlantGroup();
    Plant* plant = factory->createPlant();
    group->addPlant(plant);
    
    Order* order = new Order(group);
    OrderMemento* memento = order->createMemento();
    
    // Store memento
    caretaker->addMemento(memento->getReceiptID(), *memento);
    
    // Retrieve and verify
    OrderMemento* restored = caretaker->getMemento(memento->getReceiptID());
    ASSERT_NE(restored, nullptr);
    EXPECT_EQ(restored->getReceiptID(), memento->getReceiptID());
    EXPECT_DOUBLE_EQ(restored->getOrderPrice(), memento->getOrderPrice());
    
    delete memento;
    delete order;
}
