# Compiler
CXX = g++
CXXFLAGS = -Wall -g

# Target executable
TARGET = ./main

# Source files (explicit list: builder/proxy + required dependencies)
SRCS = Builder_Proxy.cpp \
       QueryBuilder.cpp QueryProduct.cpp SelectQueryBuilder.cpp InsertQueryBuilder.cpp DeleteQueryBuilder.cpp \
       StaffHandler.cpp Customer.cpp \
       RealGreenHouseInventory.cpp GreenHouseInventory.cpp ProxyGreenHouseInventory.cpp \
       Plant.cpp Rose.cpp Sunflower.cpp Cactus.cpp \
       SeedState.cpp GerminationState.cpp SaplingState.cpp MatureState.cpp DeadState.cpp \
       HydratedState.cpp FertilizedState.cpp \
       QueueIterator.cpp StaffSystem.cpp Command.cpp PlantMonitor.cpp PlantCommand.cpp NotHydratedState.cpp NonFertilizerState.cpp \
       Water.cpp WaterMonitor.cpp FertilizerMonitor.cpp DeadMonitor.cpp WaterCommand.cpp FertilizerCommand.cpp DeadCommand.cpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all run clean valgrind

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(TARGET)

clean:
	rm -f *.o $(TARGET)