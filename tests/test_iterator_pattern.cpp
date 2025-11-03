/**
 * @file test_iterator_pattern.cpp
 * @brief Unit tests for Iterator Pattern implementation
 * 
 * Tests QueueIterator for iterating through StaffSystem.
 */

#include <gtest/gtest.h>
#include "QueueIterator.h"
#include "StaffSystem.h"
#include "StaffHandler.h"
#include "WaterHandler.h"
#include "FertilizerHandler.h"
#include "QueryBuilder.h"

class IteratorPatternTest : public ::testing::Test {
protected:
    StaffSystem* staffSystem;
    QueryBuilder* queryBuilder;
    
    void SetUp() override {
        staffSystem = new StaffSystem();
        queryBuilder = new QueryBuilder();
    }
    
    void TearDown() override {
        delete staffSystem;
    }
};

TEST_F(IteratorPatternTest, IteratorCreatesSuccessfully) {
    QueueIterator iterator = staffSystem->createIterator();
    
    // Iterator should be created without throwing
    SUCCEED();
}

TEST_F(IteratorPatternTest, IteratorCanCheckIfDone) {
    QueueIterator iterator = staffSystem->createIterator();
    
    // Should be able to call isDone without throwing
    EXPECT_NO_THROW(iterator.isDone());
}

TEST_F(IteratorPatternTest, EmptySystemIteratorIsDone) {
    QueueIterator iterator = staffSystem->createIterator();
    
    // Empty staff system should have iterator that is done
    EXPECT_TRUE(iterator.isDone()) << "Iterator should be done for empty system";
}

TEST_F(IteratorPatternTest, IteratorCanMoveToNext) {
    WaterHandler* handler = new WaterHandler();
    handler->setQueryBuilder(queryBuilder);
    staffSystem->addHandler(handler);
    
    QueueIterator iterator = staffSystem->createIterator();
    
    if (!iterator.isDone()) {
        EXPECT_NO_THROW(iterator.next());
    }
}

TEST_F(IteratorPatternTest, IteratorCanGetCurrentElement) {
    WaterHandler* handler = new WaterHandler();
    handler->setQueryBuilder(queryBuilder);
    staffSystem->addHandler(handler);
    
    QueueIterator iterator = staffSystem->createIterator();
    
    if (!iterator.isDone()) {
        StaffHandler* current = iterator.currentItem();
        EXPECT_NE(current, nullptr);
    }
}

TEST_F(IteratorPatternTest, IteratorIteratesThroughAllHandlers) {
    WaterHandler* handler1 = new WaterHandler();
    FertilizerHandler* handler2 = new FertilizerHandler();
    
    handler1->setQueryBuilder(queryBuilder);
    handler2->setQueryBuilder(queryBuilder);
    
    staffSystem->addHandler(handler1);
    staffSystem->addHandler(handler2);
    
    QueueIterator iterator = staffSystem->createIterator();
    
    int count = 0;
    while (!iterator.isDone()) {
        StaffHandler* current = iterator.currentItem();
        EXPECT_NE(current, nullptr);
        count++;
        iterator.next();
    }
    
    EXPECT_EQ(count, 2) << "Iterator should visit all handlers";
}

TEST_F(IteratorPatternTest, IteratorDoesNotSkipElements) {
    WaterHandler* handler1 = new WaterHandler();
    FertilizerHandler* handler2 = new FertilizerHandler();
    WaterHandler* handler3 = new WaterHandler();
    
    handler1->setQueryBuilder(queryBuilder);
    handler2->setQueryBuilder(queryBuilder);
    handler3->setQueryBuilder(queryBuilder);
    
    staffSystem->addHandler(handler1);
    staffSystem->addHandler(handler2);
    staffSystem->addHandler(handler3);
    
    QueueIterator iterator = staffSystem->createIterator();
    
    std::vector<StaffHandler*> visited;
    while (!iterator.isDone()) {
        visited.push_back(iterator.currentItem());
        iterator.next();
    }
    
    EXPECT_EQ(visited.size(), 3) << "Should visit exactly 3 handlers";
    
    // All visited handlers should be non-null
    for (auto handler : visited) {
        EXPECT_NE(handler, nullptr);
    }
}

TEST_F(IteratorPatternTest, MultipleIteratorsAreIndependent) {
    WaterHandler* handler1 = new WaterHandler();
    FertilizerHandler* handler2 = new FertilizerHandler();
    
    handler1->setQueryBuilder(queryBuilder);
    handler2->setQueryBuilder(queryBuilder);
    
    staffSystem->addHandler(handler1);
    staffSystem->addHandler(handler2);
    
    QueueIterator iterator1 = staffSystem->createIterator();
    QueueIterator iterator2 = staffSystem->createIterator();
    
    // Advance first iterator
    if (!iterator1.isDone()) {
        iterator1.next();
    }
    
    // Second iterator should still be at the beginning
    EXPECT_FALSE(iterator2.isDone());
    StaffHandler* first = iterator2.currentItem();
    EXPECT_NE(first, nullptr);
}

TEST_F(IteratorPatternTest, IteratorCanResetByRecreating) {
    WaterHandler* handler = new WaterHandler();
    handler->setQueryBuilder(queryBuilder);
    staffSystem->addHandler(handler);
    
    QueueIterator iterator1 = staffSystem->createIterator();
    
    // Consume the iterator
    while (!iterator1.isDone()) {
        iterator1.next();
    }
    
    EXPECT_TRUE(iterator1.isDone());
    
    // Create new iterator - should start from beginning
    QueueIterator iterator2 = staffSystem->createIterator();
    EXPECT_FALSE(iterator2.isDone());
}
