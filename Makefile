CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = plant_test
OBJS = Plant.o FertilizedState.o NonFertilizerState.o HydratedState.o NotHydratedState.o Water.o Rose.o StateTesting.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

Plant.o: Plant.cpp Plant.h Water.h Fertilizer.h HydratedState.h NotHydratedState.h FertilizedState.h NonFertilizerState.h
	$(CXX) $(CXXFLAGS) -c Plant.cpp

FertilizedState.o: FertilizedState.cpp FertilizedState.h Fertilizer.h
	$(CXX) $(CXXFLAGS) -c FertilizedState.cpp

NonFertilizerState.o: NonFertilizerState.cpp NonFertilizerState.h Fertilizer.h
	$(CXX) $(CXXFLAGS) -c NonFertilizerState.cpp

HydratedState.o: HydratedState.cpp HydratedState.h Water.h
	$(CXX) $(CXXFLAGS) -c HydratedState.cpp

NotHydratedState.o: NotHydratedState.cpp NotHydratedState.h Water.h
	$(CXX) $(CXXFLAGS) -c NotHydratedState.cpp

Water.o: Water.cpp Water.h
	$(CXX) $(CXXFLAGS) -c Water.cpp

Rose.o: Rose.cpp Rose.h Plant.h
	$(CXX) $(CXXFLAGS) -c Rose.cpp

StateTesting.o: StateTesting.cpp Plant.h Rose.h
	$(CXX) $(CXXFLAGS) -c StateTesting.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run clean
