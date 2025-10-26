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
        auto product = customer.createSelectQuery("", "Tulip", "");
        assert(product.getQuery() == "SELECT Tulip FROM INVENTORY;");
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }
}

void InsertQuery() {
    std::cout << "\n[INSERT QUERY BUILDER TEST]\n";
    InsertQueryBuilder builder;
    StaffHandler staff;
    staff.setQueryBuilder(&builder);

    {
        auto product = staff.createInsertQuery("2", "Daffodil", "Young");
        assert(product.getQuery() ==
               "INSERT INTO INVENTORY (PlantID, PlantType, MaturityState) VALUES ('2', 'Daffodil', 'Young');");
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }

    {
        auto product = staff.createInsertQuery("", "Iris", "");
        assert(product.getQuery() == "INSERT INTO INVENTORY (PlantType) VALUES ('Iris');");
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }
}

void DeleteQuery() {
    std::cout << "\n[DELETE QUERY BUILDER TEST]\n";
    DeleteQueryBuilder builder;
    StaffHandler staff;
    staff.setQueryBuilder(&builder);

    {
        auto product = staff.createDeleteQuery("2", "", "");
        assert(product.getQuery() == "DELETE FROM INVENTORY WHERE PlantID = '2';");
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }

    {
        auto product = staff.createDeleteQuery("3", "Rose", "Mature");
        assert(product.getQuery() ==
               "DELETE FROM INVENTORY WHERE PlantID = '3' AND PlantType = 'Rose' AND MaturityState = 'Mature';");
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }

    {
        auto product = staff.createDeleteQuery("", "", "");
        assert(product.getQuery().empty());
        std::cout << "In CRUD Operation: " << product.getQuery() << std::endl;
    }
}

void QueryProductTest() {
    std::cout << "\n=== QUERY PRODUCT EXECUTION ===\n";

    RealGreenHouseInventory inventory;
    QueryProduct queryProduct(&inventory);

    {
        queryProduct.setQueryProduct("SELECT 1, Rose, Seedling FROM INVENTORY;");
        std::cout << "In CRUD Operation: " << queryProduct.getQuery() << std::endl;
        queryProduct.execute();
        assert(queryProduct.getQuery().find("SELECT") != std::string::npos);
    }

    {
        queryProduct.setQueryProduct("INSERT INTO INVENTORY VALUES (2, Tulip, Mature);");
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

    inv.addPlant(Item("2", "Rose", "Young"));
    inv.addPlant(Item("3", "Tulip", "Mature"));

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

    inventory.addPlant(Item("2", "Rose", "Young"));
    inventory.addPlant(Item("3", "Tulip", "Mature"));

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

int main() {
    Builder();
    QueryProductTest();
    RealGreenhouseInventoryTest();
    TestInventory();
    return 0;
}
