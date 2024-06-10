#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <iostream>
#include <string>
#include "TrafficData.h"

class Intersection {
public:
    Intersection(const std::string &name) : name(name) {}

    void optimizeTrafficSignal(const TrafficData &trafficData) {
        // Simple optimization logic
        int trafficLoad = trafficData.getTrafficLoad(name);
        std::cout << "Optimizing traffic signal at " << name
                  << " with traffic load: " << trafficLoad << std::endl;
    }

private:
    std::string name;
};

#endif // INTERSECTION_H
