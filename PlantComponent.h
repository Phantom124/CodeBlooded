#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H

#include <string>
#include <vector>

class PlantComponent {
    public:
        PlantComponent() = default;
        virtual ~PlantComponent() = default; 

        virtual double getPrice() = 0;
        virtual std::string getName() = 0;
        virtual std::vector<PlantComponent*> getPlants() { return {}; }
};

#endif
