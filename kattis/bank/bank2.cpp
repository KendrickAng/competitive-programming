#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<std::tuple<int, int>> lst{};
    for (int i = 0; i < n; i++) {
        int cash, time;
        std::cin >> cash >> time;
        lst.push_back(std::make_tuple(cash, time));
    }
    int elapsed = 0;
    int money = 0;
    while (elapsed < t) {
        int maxIdx = -1;
        double maxVal = -1;
        for (int i = 0; i < lst.size(); i++) {
            double val = std::get<0>(lst[i]) / (1+std::get<1>(lst[i]));
            int time = std::get<1>(lst[i]);
            if (elapsed <= time && val > maxVal) {
                maxIdx = i;
                maxVal = val;
            }
        }
        money += std::get<0>(lst[maxIdx]);
        lst.erase(lst.begin() + maxIdx);
        elapsed++;
    }
    std::cout << money << std::endl;
}