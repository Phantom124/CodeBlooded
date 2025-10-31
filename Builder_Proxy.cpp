#include <string>
#include <iostream>
#include <cassert>

#include "QueryProduct.h"
#include "QueryBuilder.h"
#include "SelectQueryBuilder.h"
#include "InsertQueryBuilder.h"
#include "DeleteQueryBuilder.h"
#include "StaffHandler.h"
#include "Customer.h"
#include "RealGreenHouseInventory.h"
#include "Item.h"
#include "ProxyGreenHouseInventory.h"
#include "Plant.h"
#include "SeedState.h"
#include "Rose.h"
#include "Sunflower.h"

void Builder();

void SelectQuery() {
    std::cout << "\n[SELECT QUERY BUILDER TEST]\n";
    SelectQueryBuilder builder;
    Customer customer;
    customer.setQueryBuilder(&builder);

    {
        auto product = customer.createSelectQuery("1", "Rose", "Mature");
        assert(product.getQuery() == "SELECT 1, Rose, Mature FROM INVENTORY;");
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }

    {
        auto product = customer.createSelectQuery("", "Sunflower", "");
        assert(product.getQuery() == "SELECT Sunflower FROM INVENTORY;");
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }

    //PLANT OVERLOAD
    {
        ProxyGreenHouseInventory proxyInventory;
        SelectQueryBuilder builder;

        Rose rose;                    // stack object
        Plant* rosePtr = &rose;

        Customer customer;
        customer.setQueryBuilder(&builder);

        QueryProduct product(&proxyInventory);
        builder.selectQueryBuilder(rosePtr);
        product.setQueryProduct("SELECT " + std::to_string(rosePtr->getPlantId()) + ", " + rosePtr->getName() + ", " + rosePtr->getMaturityStateName() + " FROM INVENTORY;");

        std::cout << "[Plant* SELECT] " << product.getQuery() << std::endl;

        proxyInventory.handleControlRights(&customer, product);
    }
}

void InsertQuery() {
    std::cout << "\n[INSERT QUERY BUILDER TEST]\n";
    InsertQueryBuilder builder;
    StaffHandler staff;
    staff.setQueryBuilder(&builder);

    {
        auto product = staff.createInsertQuery("2", "Daffodil", "Young");
        assert(product->getQuery() ==
               "INSERT INTO INVENTORY (PlantID, PlantType, MaturityState) VALUES ('2', 'Daffodil', 'Young');");
        std::cout << "In CRUD Operation: " << product->getQuery() << std::endl;
    }

    {
        auto product = staff.createInsertQuery("", "Iris", "");
        assert(product->getQuery() == "INSERT INTO INVENTORY (PlantType) VALUES ('Iris');");
        std::cout << "In CRUD Operation: " << product->getQuery() << std::endl;
    }

    //PLANT OVERLOAD
    {
        ProxyGreenHouseInventory proxyInventory;
        InsertQueryBuilder builder;
        staff.setQueryBuilder(&builder); // only staff can insert

        QueryProduct product(&proxyInventory);
        Rose rose;                     // stack object
        Plant* rosePtr = &rose;
        builder.insertQueryBuilder(rosePtr);

        product.setQueryProduct(
            "INSERT INTO INVENTORY VALUES('" +
            std::to_string(rose.getPlantId()) + "', '" +
            rose.getName() + "', '" +
            rose.getMaturityStateName() + "');"
        );

        std::cout << "\n[TEST] INSERT QUERY\n";
        std::cout << "[Plant* INSERT] " << product.getQuery() << std::endl;
        proxyInventory.handleControlRights(&staff, product); // allowed
    }
}

void DeleteQuery() {
    std::cout << "\n[DELETE QUERY BUILDER TEST]\n";
    DeleteQueryBuilder builder;
    StaffHandler staff;
    staff.setQueryBuilder(&builder);

    {
        auto product = staff.createDeleteQuery("2", "", "");
        assert(product->getQuery() == "DELETE FROM INVENTORY WHERE PlantID = '2';");
        std::cout << "In CRUD Operation: " << product->getQuery() << std::endl;
    }

    {
        auto product = staff.createDeleteQuery("3", "Rose", "Mature");
        assert(product->getQuery() ==
               "DELETE FROM INVENTORY WHERE PlantID = '3' AND PlantType = 'Rose' AND MaturityState = 'Mature';");
        std::cout << "In CRUD Operation: " << product->getQuery() << std::endl;
    }

    {
        auto product = staff.createDeleteQuery("", "", "");
        assert(product->getQuery().empty());
        std::cout << "In CRUD Operation: " << product->getQuery() << std::endl;
    }

    //PLANT OVERLOAD
    {
        ProxyGreenHouseInventory proxyInventory;
        DeleteQueryBuilder builder;
        staff.setQueryBuilder(&builder); // only staff can delete

        QueryProduct product(&proxyInventory);
        Rose rose;                     // stack object
        Plant* rosePtr = &rose;
        builder.deleteQueryBuilder(rosePtr);

        product.setQueryProduct(
            "DELETE FROM INVENTORY WHERE PlantID='" +
            std::to_string(rose.getPlantId()) + "';"
        );

        std::cout << "\n[TEST] DELETE QUERY\n";
        std::cout << "[Plant* DELETE] " << product.getQuery() << std::endl;
        proxyInventory.handleControlRights(&staff, product);
    }
}

void QueryProductTest() {
    std::cout << "\n=== QUERY PRODUCT EXECUTION ===\n";

    ProxyGreenHouseInventory inventory;
    QueryProduct queryProduct(&inventory);

    {
        queryProduct.setQueryProduct("SELECT 1, Rose, Seedling FROM INVENTORY;");
        std::cout << "In CRUD Operation: " << queryProduct.getQuery() << std::endl;
        queryProduct.execute();
        assert(queryProduct.getQuery().find("SELECT") != std::string::npos);
    }

    {
        queryProduct.setQueryProduct("INSERT INTO INVENTORY VALUES (2, Rose, Mature);");
        std::cout << "In CRUD Operation: " << queryProduct.getQuery() << std::endl;
        queryProduct.execute();
        assert(queryProduct.getQuery().find("INSERT") != std::string::npos);
    }

    {
        queryProduct.setQueryProduct("DELETE FROM INVENTORY WHERE PlantID = 3;");
        std::cout << "In CRUD Operation: " << queryProduct.getQuery() << std::endl;
        queryProduct.execute();
        assert(queryProduct.getQuery().find("DELETE") != std::string::npos);
    }

    {
        queryProduct.setQueryProduct("UPDATE INVENTORY SET Maturity='Young';");
        std::cout << "In CRUD Operation: " << queryProduct.getQuery() << std::endl;
        queryProduct.execute();
    }
}

void RealGreenhouseInventoryTest() {
    std::cout << "\n=== REAL GREENHOUSE INVENTORY ===\n";

    RealGreenHouseInventory inv;

    // use concrete Plant subclasses (default ctors). Do not pass Item.
    inv.addPlant(new Rose());
    inv.addPlant(new Sunflower());

    std::cout << "In CRUD Operation: SELECT Rose FROM INVENTORY;\n";
    inv.showPlant("SELECT Rose FROM INVENTORY;");

    std::cout << "In CRUD Operation: DELETE FROM INVENTORY WHERE PlantID=2;\n";
    inv.removePlant("DELETE FROM INVENTORY WHERE PlantID=2;");

    std::cout << "[Assert] INVENTORY methods executed successfully.\n";
}

void TestInventory() {
    std::cout << "\n=== INVENTORY TESTS ===\n";

    RealGreenHouseInventory inventory;
    inventory.showAllPlants();

    // add concrete plants
    inventory.addPlant(new Rose());
    inventory.addPlant(new Sunflower());

    std::cout << "In CRUD Operation: SELECT Rose\n";
    inventory.showPlant("Rose");

    std::cout << "In CRUD Operation: SELECT Daisy\n";
    inventory.showPlant("Daisy");

    std::cout << "In CRUD Operation: DELETE 2\n";
    inventory.removePlant("2");

    std::cout << "In CRUD Operation: DELETE 99\n";
    inventory.removePlant("99");

    std::cout << "\nFINAL INVENTORY:\n";
    inventory.showAllPlants();
}

void Builder() {
    std::cout << "=== BUILDER DESIGN PATTERN ===\n";
    SelectQuery();
    InsertQuery();
    DeleteQuery();
}

void Proxy(){
    std::cout << "=== PROXY GREENHOUSE INVENTORY TEST ===\n";

    // Arrange
    ProxyGreenHouseInventory proxyInventory;
    Customer customer;
    StaffHandler staff;

    // ----------------------------
    // CUSTOMER SELECT (allowed)
    // ----------------------------
    {
        QueryProduct query(&proxyInventory);
        query.setQueryProduct("SELECT Rose FROM INVENTORY;");
        std::cout << "\n[Customer SELECT Test]\n";
        proxyInventory.handleControlRights(&customer, query);
    }

    // ----------------------------
    // CUSTOMER INSERT (denied)
    // ----------------------------
    {
        QueryProduct query(&proxyInventory);
        query.setQueryProduct("INSERT INTO INVENTORY VALUES (4, Cactus, Mature);");
        std::cout << "\n[Customer INSERT Test]\n";
        proxyInventory.handleControlRights(&customer, query);
    }

    // ----------------------------
    // STAFF INSERT (allowed)
    // ----------------------------
    {
        QueryProduct query(&proxyInventory);
        query.setQueryProduct("INSERT INTO INVENTORY VALUES (5, Daisy, Young);");
        std::cout << "\n[Staff INSERT Test]\n";
        proxyInventory.handleControlRights(&staff, query);
    }

    // ----------------------------
    // STAFF DELETE (allowed)
    // ----------------------------
    {
        QueryProduct query(&proxyInventory);
        query.setQueryProduct("DELETE FROM INVENTORY WHERE PlantID = 1;");
        std::cout << "\n[Staff DELETE Test]\n";
        proxyInventory.handleControlRights(&staff, query);
    }

    // ----------------------------
    // CUSTOMER DELETE (denied)
    // ----------------------------
    {
        QueryProduct query(&proxyInventory);
        query.setQueryProduct("DELETE FROM INVENTORY WHERE PlantID = 2;");
        std::cout << "\n[Customer DELETE Test]\n";
        proxyInventory.handleControlRights(&customer, query);
    }

    // ----------------------------
    // Show all remaining plants
    // ----------------------------
    std::cout << "\n[Final Inventory]\n";
    proxyInventory.showAllPlants();    
}

int main() {
    Builder();
    QueryProductTest();
    RealGreenhouseInventoryTest();
    TestInventory();
    Proxy();
    return 0;
}
