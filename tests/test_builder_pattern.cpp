/**
 * @file test_builder_pattern.cpp
 * @brief Unit tests for Builder Pattern implementation
 * 
 * Tests QueryBuilder and its concrete implementations (SelectQueryBuilder, InsertQueryBuilder, DeleteQueryBuilder).
 */

#include <gtest/gtest.h>
#include "QueryBuilder.h"
#include "SelectQueryBuilder.h"
#include "InsertQueryBuilder.h"
#include "DeleteQueryBuilder.h"
#include "QueryProduct.h"
#include "Rose.h"
#include "RoseFactory.h"
#include "WaterMonitor.h"
#include "FertilizerMonitor.h"
#include "DeadMonitor.h"

class BuilderPatternTest : public ::testing::Test {
protected:
    WaterMonitor* waterMonitor;
    FertilizerMonitor* fertilizerMonitor;
    DeadMonitor* deadMonitor;
    QueryBuilder* queryBuilder;
    RoseFactory* factory;
    Plant* plant;
    
    void SetUp() override {
        waterMonitor = new WaterMonitor();
        fertilizerMonitor = new FertilizerMonitor();
        deadMonitor = new DeadMonitor();
        queryBuilder = new QueryBuilder();
        factory = new RoseFactory(waterMonitor, fertilizerMonitor, deadMonitor);
        plant = factory->createPlant();
    }
    
    void TearDown() override {
        delete plant;
        delete factory;
        delete waterMonitor;
        delete fertilizerMonitor;
        delete deadMonitor;
    }
};

TEST_F(BuilderPatternTest, QueryBuilderCreatesSuccessfully) {
    QueryBuilder* builder = new QueryBuilder();
    EXPECT_NE(builder, nullptr);
    delete builder;
}

TEST_F(BuilderPatternTest, SelectQueryBuilderCreatesSuccessfully) {
    SelectQueryBuilder* builder = new SelectQueryBuilder();
    EXPECT_NE(builder, nullptr);
    delete builder;
}

TEST_F(BuilderPatternTest, InsertQueryBuilderCreatesSuccessfully) {
    InsertQueryBuilder* builder = new InsertQueryBuilder();
    EXPECT_NE(builder, nullptr);
    delete builder;
}

TEST_F(BuilderPatternTest, DeleteQueryBuilderCreatesSuccessfully) {
    DeleteQueryBuilder* builder = new DeleteQueryBuilder();
    EXPECT_NE(builder, nullptr);
    delete builder;
}

TEST_F(BuilderPatternTest, SelectQueryBuilderCanBuildQuery) {
    SelectQueryBuilder builder;
    
    builder.setPlantID(plant->getPlantID());
    builder.setPlantType(plant->getPlantType());
    builder.setMaturityState(plant->getMaturityState());
    
    QueryProduct* product = builder.getResult();
    EXPECT_NE(product, nullptr);
    delete product;
}

TEST_F(BuilderPatternTest, InsertQueryBuilderCanBuildQuery) {
    InsertQueryBuilder builder;
    
    builder.setPlantID(plant->getPlantID());
    builder.setPlantType(plant->getPlantType());
    builder.setMaturityState(plant->getMaturityState());
    
    QueryProduct* product = builder.getResult();
    EXPECT_NE(product, nullptr);
    delete product;
}

TEST_F(BuilderPatternTest, DeleteQueryBuilderCanBuildQuery) {
    DeleteQueryBuilder builder;
    
    builder.setPlantID(plant->getPlantID());
    builder.setPlantType(plant->getPlantType());
    builder.setMaturityState(plant->getMaturityState());
    
    QueryProduct* product = builder.getResult();
    EXPECT_NE(product, nullptr);
    delete product;
}

TEST_F(BuilderPatternTest, QueryBuilderCanSetPlantID) {
    SelectQueryBuilder builder;
    std::string testID = "TEST-123";
    
    builder.setPlantID(testID);
    QueryProduct* product = builder.getResult();
    
    EXPECT_NE(product, nullptr);
    EXPECT_EQ(product->getPlantID(), testID);
    delete product;
}

TEST_F(BuilderPatternTest, QueryBuilderCanSetPlantType) {
    SelectQueryBuilder builder;
    std::string testType = "Rose";
    
    builder.setPlantType(testType);
    QueryProduct* product = builder.getResult();
    
    EXPECT_NE(product, nullptr);
    EXPECT_EQ(product->getPlantType(), testType);
    delete product;
}

TEST_F(BuilderPatternTest, QueryBuilderCanSetMaturityState) {
    SelectQueryBuilder builder;
    std::string testState = "Mature";
    
    builder.setMaturityState(testState);
    QueryProduct* product = builder.getResult();
    
    EXPECT_NE(product, nullptr);
    EXPECT_EQ(product->getMaturityState(), testState);
    delete product;
}

TEST_F(BuilderPatternTest, BuilderCreatesCompleteQuery) {
    SelectQueryBuilder builder;
    
    builder.setPlantID("ROSE-001");
    builder.setPlantType("Rose");
    builder.setMaturityState("Mature");
    
    QueryProduct* product = builder.getResult();
    
    EXPECT_NE(product, nullptr);
    EXPECT_EQ(product->getPlantID(), "ROSE-001");
    EXPECT_EQ(product->getPlantType(), "Rose");
    EXPECT_EQ(product->getMaturityState(), "Mature");
    
    delete product;
}

TEST_F(BuilderPatternTest, DifferentBuildersCreateDifferentQueries) {
    SelectQueryBuilder selectBuilder;
    InsertQueryBuilder insertBuilder;
    DeleteQueryBuilder deleteBuilder;
    
    selectBuilder.setPlantID("TEST-001");
    insertBuilder.setPlantID("TEST-001");
    deleteBuilder.setPlantID("TEST-001");
    
    QueryProduct* selectQuery = selectBuilder.getResult();
    QueryProduct* insertQuery = insertBuilder.getResult();
    QueryProduct* deleteQuery = deleteBuilder.getResult();
    
    EXPECT_NE(selectQuery, nullptr);
    EXPECT_NE(insertQuery, nullptr);
    EXPECT_NE(deleteQuery, nullptr);
    
    // All should have the same ID but different query types
    EXPECT_EQ(selectQuery->getPlantID(), insertQuery->getPlantID());
    EXPECT_EQ(insertQuery->getPlantID(), deleteQuery->getPlantID());
    
    delete selectQuery;
    delete insertQuery;
    delete deleteQuery;
}

TEST_F(BuilderPatternTest, QueryBuilderAllowsIncrementalConstruction) {
    SelectQueryBuilder builder;
    
    // Build incrementally
    builder.setPlantID("INCREMENTAL-001");
    
    QueryProduct* partial = builder.getResult();
    EXPECT_NE(partial, nullptr);
    EXPECT_EQ(partial->getPlantID(), "INCREMENTAL-001");
    delete partial;
    
    // Continue building
    builder.setPlantType("Rose");
    builder.setMaturityState("Sapling");
    
    QueryProduct* complete = builder.getResult();
    EXPECT_NE(complete, nullptr);
    EXPECT_EQ(complete->getPlantType(), "Rose");
    EXPECT_EQ(complete->getMaturityState(), "Sapling");
    
    delete complete;
}

TEST_F(BuilderPatternTest, QueryProductReturnsCorrectValues) {
    InsertQueryBuilder builder;
    
    builder.setPlantID("TEST-999");
    builder.setPlantType("Cactus");
    builder.setMaturityState("Seed");
    
    QueryProduct* product = builder.getResult();
    
    ASSERT_NE(product, nullptr);
    EXPECT_EQ(product->getPlantID(), "TEST-999");
    EXPECT_EQ(product->getPlantType(), "Cactus");
    EXPECT_EQ(product->getMaturityState(), "Seed");
    
    delete product;
}

TEST_F(BuilderPatternTest, BuilderSeparatesConstructionFromRepresentation) {
    // The builder pattern should separate construction from representation
    SelectQueryBuilder selectBuilder;
    InsertQueryBuilder insertBuilder;
    
    // Same data, different representations
    selectBuilder.setPlantID("SAME-ID");
    insertBuilder.setPlantID("SAME-ID");
    
    QueryProduct* selectProduct = selectBuilder.getResult();
    QueryProduct* insertProduct = insertBuilder.getResult();
    
    EXPECT_NE(selectProduct, nullptr);
    EXPECT_NE(insertProduct, nullptr);
    
    // Both have same ID but different query purposes
    EXPECT_EQ(selectProduct->getPlantID(), insertProduct->getPlantID());
    
    delete selectProduct;
    delete insertProduct;
}
