#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
    int n, t;
    std::cin >> n >> t;
    std::vector<std::tuple<int, int>> lst{};
    for (int i = 0; i < n; i++) {
        int cash, time;
        std::cin >> cash >> time;
        lst.push_back(std::make_tuple(cash, time));
    }
    std::sort(lst.rbegin(), lst.rend(), [](auto &lhs, auto &rhs){
        if (std::get<1>(lhs) != std::get<1>(rhs)) {
            return std::get<1>(lhs) < std::get<1>(rhs);
        } else {
            return std::get<0>(lhs) > std::get<0>(rhs);
        }
    });
    int elapsed = 0;
    int money = 0;
    for (auto [cash, time]: lst) {
        if (time > elapsed) {
            continue;
        }
        if (elapsed >= t) {
            break;
        }
        money += cash;
        elapsed++;
    }
    std::cout << money << std::endl;
}