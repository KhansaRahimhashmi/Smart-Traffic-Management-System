#ifndef ROUTESUGGESTION_H
#define ROUTESUGGESTION_H

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <limits>
#include "RoadNetwork.h"
#include "TrafficData.h"

class RouteSuggestion {
public:
    RouteSuggestion(const RoadNetwork &network, const TrafficData &trafficData)
        : network(network), trafficData(trafficData) {}

    void suggestOptimalRoute(const std::string &start, const std::string &end) {
        std::unordered_map<std::string, int> distances;
        std::unordered_map<std::string, std::string> previous;
        std::set<std::pair<int, std::string>> nodes;

        for (const auto &node : network.getAdjacencyList()) {
            if (node.first == start) {
                distances[node.first] = 0;
                nodes.insert({0, node.first});
            } else {
                distances[node.first] = std::numeric_limits<int>::max();
                nodes.insert({std::numeric_limits<int>::max(), node.first});
            }
        }

        while (!nodes.empty()) {
            std::string minNode = nodes.begin()->second;
            nodes.erase(nodes.begin());

            if (minNode == end) {
                break;
            }

            for (const auto &neighbor : network.getAdjacencyList().at(minNode)) {
                int alt = distances[minNode] + neighbor.second + trafficData.getTrafficLoad(minNode + "-" + neighbor.first);
                if (alt < distances[neighbor.first]) {
                    nodes.erase({distances[neighbor.first], neighbor.first});
                    distances[neighbor.first] = alt;
                    previous[neighbor.first] = minNode;
                    nodes.insert({alt, neighbor.first});
                }
            }
        }

        if (distances[end] == std::numeric_limits<int>::max()) {
            std::cout << "No route found from " << start << " to " << end << std::endl;
        } else {
            std::cout << "Optimal route from " << start << " to " << end << ": " << std::endl;
            for (std::string at = end; !at.empty(); at = previous[at]) {
                std::cout << at << " ";
                if (at == start) break;
            }
            std::cout << "\nTotal distance: " << distances[end] << std::endl;
        }
    }

private:
    const RoadNetwork &network;
    const TrafficData &trafficData;
};

#endif // ROUTESUGGESTION_H
