#ifndef ROADNETWORK_H
#define ROADNETWORK_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>

class RoadNetwork {
public:
    void addIntersection(const std::string &name) {
        adjacencyList[name] = {};
    }

    void addRoad(const std::string &from, const std::string &to, int weight) {
        adjacencyList[from].emplace_back(to, weight);
    }

    const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> &getAdjacencyList() const {
        return adjacencyList;
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjacencyList;
};

#endif // ROADNETWORK_H
