#include <iostream>
#include "Intersection.h"
#include "RoadNetwork.h"
#include "TrafficData.h"
#include "RouteSuggestion.h"

int main() {
    try {
        // Initialize road network
        RoadNetwork roadNetwork;
        roadNetwork.addIntersection("A");
        roadNetwork.addIntersection("B");
        roadNetwork.addIntersection("C");
        roadNetwork.addIntersection("D");

        roadNetwork.addRoad("A", "B", 5);
        roadNetwork.addRoad("B", "C", 10);
        roadNetwork.addRoad("C", "D", 5);
        roadNetwork.addRoad("A", "C", 15);

        // Initialize traffic data
        TrafficData trafficData;
        trafficData.updateTraffic("A", "B", 7);
        trafficData.updateTraffic("B", "C", 15);
        trafficData.updateTraffic("C", "D", 6);
        trafficData.updateTraffic("A", "C", 20);

        // Traffic Signal Optimization
        Intersection intersectionA("A");
        intersectionA.optimizeTrafficSignal(trafficData);

        // Route Suggestion
        RouteSuggestion routeSuggestion(roadNetwork, trafficData);
        routeSuggestion.suggestOptimalRoute("A", "D");

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
