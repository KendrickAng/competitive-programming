#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Shipment{
    std::string name{};
    int count{};
};

int main() {
    int T, N;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> N;
        // start a test case
        std::vector<Shipment> sm{};
        std::unordered_map<std::string, int> smMap{};
        for (int j = 0; j < N; j++) {
            std::string name;
            int count;
            std::cin >> name >> count;
            // add to map, create new entry if doesn't exist
            if (smMap.find(name) != smMap.end()) {
                smMap[name] = smMap[name] + count;
            } else {
                smMap[name] = count;
            }
        }
        // populate vector and sort
        for (auto s = smMap.begin(); s != smMap.end(); s++) {
            sm.push_back(Shipment{s->first, s->second});
        }
        // sort array and print
        std::sort(sm.begin(), sm.end(), [](Shipment a, Shipment b) -> bool {
            if (a.count < b.count) {
                return true;
            } else if (b.count < a.count) {
                return false;
            } else if (a.name < b.name) {
                return true;
            } else {
                return false;
            }
        });
        std::cout << smMap.size() << std::endl;
        for (auto& s: sm) {
            std::cout << s.name << ' ' << s.count << std::endl;
        }
    }
}
