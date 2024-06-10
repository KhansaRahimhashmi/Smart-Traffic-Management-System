#ifndef TRAFFICDATA_H
#define TRAFFICDATA_H

#include <iostream>
#include <unordered_map>
#include <string>

class TrafficData {
public:
    void updateTraffic(const std::string &from, const std::string &to, int load) {
        trafficLoads[from + "-" + to] = load;
    }

    int getTrafficLoad(const std::string &intersection) const {
        int totalLoad = 0;
        for (const auto &entry : trafficLoads) {
            if (entry.first.find(intersection) != std::string::npos) {
                totalLoad += entry.second;
            }
        }
        return totalLoad;
    }

private:
    std::unordered_map<std::string, int> trafficLoads;
};

#endif // TRAFFICDATA_H
