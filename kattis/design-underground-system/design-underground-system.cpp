#include <bits/stdc++.h>

using namespace std;
int MAX_IDS = 1000000 + 10;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

// struct pairHash {
//     template<class T1, class T2>
//     size_t operator()(const pair<T1, T2> &p) {
//         return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
//     }
// };

class UndergroundSystem {
public:
    vector<pair<string,int>> idToNameTime;
    unordered_map<pair<string,string>,pair<long,long>,pair_hash> m;
    
    UndergroundSystem() {
        idToNameTime.assign(MAX_IDS, {"",-1});
    }
    
    void checkIn(int id, string stationName, int t) {
        idToNameTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [inStn, inTime] = idToNameTime[id];
        auto timeTaken = t - inTime;
        idToNameTime[id].first = "";
        idToNameTime[id].second = 0;
        pair<string,string> key = {inStn, stationName};
        if (m.find(key) == m.end()) {
            m[key] = {0,0};
        }
        auto& [numPpl, totalTime] = m[key];
        numPpl++;
        totalTime += timeTaken;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string,string> key = {startStation, endStation};
        if (m.find(key) == m.end()) {
            cout << startStation << " " << endStation << " missing" << endl;
        }
        auto& [numPpl, totalTime] = m[key];
        return (double) totalTime / numPpl;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */