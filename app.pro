QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Output directory configuration
DESTDIR = bin
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
UI_DIR = build/ui
RCC_DIR = build/rcc

TARGET = PlantNurseryGUI

# Ensure generated UI headers can include our custom widgets
INCLUDEPATH += \
    StaffWindows \
    CustomerWindows \
    Common

# Existing backend source files
SOURCES += \
    Cactus.cpp \
    CactusFactory.cpp \
    Caretaker.cpp \
    Command.cpp \
    Customer.cpp \
    CustomerCommand.cpp \
    CustomerFacade.cpp \
    DeadCommand.cpp \
    DeadHandler.cpp \
    DeadMonitor.cpp \
    DeadState.cpp \
    DeleteQueryBuilder.cpp \
    DiscountPrice.cpp \
    FertilizedState.cpp \
    FertilizerCommand.cpp \
    FertilizerHandler.cpp \
    FertilizerMonitor.cpp \
    GerminationState.cpp \
    GetPlantCommand.cpp \
    GiftWrap.cpp \
    GreenHouseFacade.cpp \
    GreenHouseInventory.cpp \
    HydratedState.cpp \
    InsertQueryBuilder.cpp \
    Item.cpp \
    MatureState.cpp \
    NonFertilizerState.cpp \
    NormalPrice.cpp \
    NotHydratedState.cpp \
    Order.cpp \
    OrderMemento.cpp \
    Plant.cpp \
    PlantCommand.cpp \
    PlantDecorator.cpp \
    PlantFactory.cpp \
    PlantGroup.cpp \
    PlantMonitor.cpp \
    PlantSnapshot.cpp \
    ProxyGreenHouseInventory.cpp \
    QueryBuilder.cpp \
    QueryProduct.cpp \
    QueueIterator.cpp \
    RealGreenHouseInventory.cpp \
    Receipt.cpp \
    RedPot.cpp \
    Ribbon.cpp \
    Rose.cpp \
    RoseFactory.cpp \
    SalesHandler.cpp \
    SaplingState.cpp \
    Scent.cpp \
    SeedState.cpp \
    SelectQueryBuilder.cpp \
    StaffHandler.cpp \
    StaffSystem.cpp \
    Sunflower.cpp \
    SunflowerFactory.cpp \
    Water.cpp \
    WaterCommand.cpp \
    WaterHandler.cpp \
    WaterMonitor.cpp

# GUI source files
SOURCES += \
    main.cpp \
    Common/LoginDialog.cpp \
    CustomerWindows/CustomerMainWindow.cpp \
    CustomerWindows/ReturnOrderDialog.cpp \
    CustomerWindows/ReceiptDialog.cpp \
    StaffWindows/StaffMainWindow.cpp \
    StaffWindows/PlantManagementWidget.cpp \
    StaffWindows/StaffManagementWidget.cpp

# Existing backend header files
HEADERS += \
    Cactus.h \
    CactusFactory.h \
    Caretaker.h \
    Command.h \
    Customer.h \
    CustomerCommand.h \
    CustomerFacade.h \
    DeadCommand.h \
    DeadHandler.h \
    DeadMonitor.h \
    DeadState.h \
    DeleteQueryBuilder.h \
    DiscountPrice.h \
    FertilizedState.h \
    Fertilizer.h \
    FertilizerCommand.h \
    FertilizerHandler.h \
    FertilizerMonitor.h \
    GerminationState.h \
    GetPlantCommand.h \
    GiftWrap.h \
    GreenHouseFacade.h \
    GreenHouseInventory.h \
    HydratedState.h \
    InsertQueryBuilder.h \
    Item.h \
    MatureState.h \
    NonFertilizerState.h \
    NormalPrice.h \
    NotHydratedState.h \
    Order.h \
    OrderMemento.h \
    Plant.h \
    PlantCommand.h \
    PlantComponent.h \
    PlantDecorator.h \
    PlantFactory.h \
    PlantGroup.h \
    PlantGrowthState.h \
    PlantMonitor.h \
    PlantSnapshot.h \
    PriceStrategies.h \
    ProxyGreenHouseInventory.h \
    QueryBuilder.h \
    QueryProduct.h \
    QueueIterator.h \
    RealGreenHouseInventory.h \
    Receipt.h \
    RedPot.h \
    Ribbon.h \
    Rose.h \
    RoseFactory.h \
    SalesHandler.h \
    SaplingState.h \
    Scent.h \
    SeedState.h \
    SelectQueryBuilder.h \
    StaffHandler.h \
    StaffSystem.h \
    Sunflower.h \
    SunflowerFactory.h \
    Water.h \
    WaterCommand.h \
    WaterHandler.h \
    WaterMonitor.h

# GUI header files
HEADERS += \
    Common/LoginDialog.h \
    CustomerWindows/CustomerMainWindow.h \
    CustomerWindows/ReturnOrderDialog.h \
    CustomerWindows/ReceiptDialog.h \
    StaffWindows/StaffMainWindow.h \
    StaffWindows/PlantManagementWidget.h \
    StaffWindows/StaffManagementWidget.h

# UI form files
FORMS += \
    Common/LoginDialog.ui \
    CustomerWindows/CustomerMainWindow.ui \
    CustomerWindows/ReturnOrderDialog.ui \
    CustomerWindows/ReceiptDialog.ui \
    StaffWindows/StaffMainWindow.ui \
    StaffWindows/PlantManagementWidget.ui \
    StaffWindows/StaffManagementWidget.ui

# Resource files
RESOURCES += \
    resources.qrc

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
