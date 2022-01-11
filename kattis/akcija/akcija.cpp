#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::vector<int> costs{};
    for (int i = 0; i < n; i++) {
        int price; std::cin >> price;
        costs.push_back(price);
    }
    std::sort(costs.rbegin(), costs.rend());
    int total = 0;
    for (int i= 0; i < costs.size(); i++) {
        if ((i+1) % 3 == 0) {
            continue;
        }
        total += costs[i];
    }
    std::cout << total << std::endl;
}