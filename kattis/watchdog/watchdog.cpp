#include <iostream>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <cmath>

struct pair_hash{
    std::size_t operator() (const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

int main() {
    int N, S, H;
    int x, y; // hatch coorindates
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        bool test_case_ok = false;
        std::cin >> S >> H;
        std::unordered_set<std::pair<int, int>, pair_hash> hatches;
        // read hatches
        for (int j = 0; j < H; j++) {
            std::cin >> x >> y;
            hatches.insert(std::make_pair(x, y));
        }
        // find a coordinate for doggo
        for (int xx = 0; xx < S && !test_case_ok; xx++) {
            for (int yy = 0; yy < S && !test_case_ok; yy++) {
                bool isAns = true;
                std::pair<int, int> coord = std::make_pair(xx, yy);
                if (hatches.find(coord) != hatches.end()) {
                    continue; // skip hatches
                }
                // get shortest distance to edge
                double dist_to_edge = std::min(S - coord.first, std::min(coord.first, std::min(S - coord.second, coord.second)));

                // check dog doesn't fall off
                for (auto& p: hatches) {
                    // straight line distance
                    double sld = std::sqrt(std::pow(coord.first - p.first, 2) + std::pow(coord.second - p.second, 2));
                    if (sld > dist_to_edge) {
                        isAns = false;
                        break;
                    }
                }

                if (isAns) {
                    std::cout << coord.first << ' ' << coord.second << std::endl;
                    test_case_ok = true;
                    break;
                }
            }
        }
        if (!test_case_ok) {
            std::cout << "poodle" << std::endl; // no answer
        }
    }
}