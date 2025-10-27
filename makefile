#Compiler
CXX = g++

#Compiler flags
CXXFLAGS = -Wall -g

#Target executable
TARGET = ./Builder_Proxy

#For deleting the target
TARGET_DEL = Builder_Proxy.cpp

#Source files (all .cpp in workspace)
SRCS = Builder_Proxy.cpp QueryBuilder.cpp QueryProduct.cpp SelectQueryBuilder.cpp InsertQueryBuilder.cpp DeleteQueryBuilder.cpp StaffHandler.cpp Customer.cpp RealGreenHouseInventory.cpp Item.cpp ProxyGreenHouseInventory.cpp

#Object files
OBJS = $(SRCS:.cpp=.o)

#Default rule to build and run the executable
all: $(TARGET) run

#Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

#Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Rule to run the executable
run: $(TARGET)
	$(TARGET)

#Clean rule to remove the generated files
clean:
	rm -f *.o $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(TARGET)